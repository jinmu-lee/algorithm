#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITED_PAGES 20
#define TRUE  1
#define FALSE 0

#define offsetof(TYPE,MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr,type,member) ({\
		const typeof(((type *)0)->member) *__mptr = (ptr); \
		(type *)((char *)__mptr - offsetof(type,member));})


struct list_head{
        struct list_head *next,*prev;
};

struct lru_list{
         int pfn;
         struct list_head lru_head;
};

void INIT_LIST_HEAD(struct list_head *list)
{
#if 0
         WRITE_ONCE(list->next, list);
#endif
	 list->next = list;
         list->prev = list;
}


/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next){
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}
/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */

void list_add(struct list_head *new,struct list_head *head){
         __list_add(new,head,head->next);
}

/*
* Delete a list entry by making the prev/next entries
* point to each other.
*
* This is only for internal list manipulation where we know
* the prev/next entries already!
*/
void __list_del(struct list_head * prev, struct list_head * next)
{
         next->prev = prev;
#if 0
         WRITE_ONCE(prev->next, next);
#else
	 prev->next = next;
#endif
}
/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
void list_del(struct list_head *entry)
{
         __list_del(entry->prev, entry->next);
#if 1
	 entry->next = 0;
	 entry->prev = 0;
#else
	INIT_LIST_HEAD(entry);
#endif
}

#if 0
void list_add_tail(struct list_head *new,struct list_head *head){
         __list_add(new,head->prev,head);
}
#endif

struct hlist_node{
	struct hlist_node *next,**pprev;
};

struct hlist_head{
	struct hlist_node *first;
};

#define HASH_MAX 8
typedef struct page{
	int pfn;
	int data;
	struct hlist_node hnode;
	struct hlist_head list;
}PAGE;

//insert front
void hlist_add_head(struct hlist_node *n,struct hlist_head *h){
	struct hlist_node *first = h->first;
	n->next = first;
	if( first ) first->pprev = &n->next;
#if 0
	WRITE_ONCE(h->first, n);
#else
	h->first = n;
#endif
	n->pprev = &h->first;
}

void hlist_del(struct hlist_node *n)
{
        struct hlist_node *next = n->next;
        struct hlist_node **pprev = n->pprev;
#if 0
        WRITE_ONCE(*pprev, next);
#else
	*pprev = next;
#endif
        if (next)
                 next->pprev = pprev;
}

int hlist_find_key(struct hlist_head *heads,int pfn){
	struct hlist_node *temp;
	PAGE *pg;
	for(temp=heads->first;temp;temp=temp->next){
		pg = container_of(temp,PAGE,hnode);
		if( pg->pfn == pfn ) return TRUE;
	}
	return FALSE;
}

int hlist_del_by_key(struct hlist_head *heads,int pfn){
	struct hlist_node *temp;
	PAGE *pg;
	for(temp=heads->first;temp;temp=temp->next){
		pg = container_of(temp,PAGE,hnode);
		if( pg->pfn == pfn ){
			hlist_del(temp);
			return TRUE;
		}
	}
	return FALSE;
}

#define GOLDEN_RATIO_PRIME_32 0x9e370001UL
unsigned int hash_32(unsigned int val,unsigned int bits){
	unsigned int hash = val * GOLDEN_RATIO_PRIME_32;
	// Ex) bits=3
	// 32-3 = 29
	// hash>>29
	// 1110 0000 0000 0000 0000 0000 0000 >> 29 = 0b111
	return hash>>(32-bits);
}
int hash_func(int num){
	return hash_32(num,3);
}
void display(struct hlist_head *page_htable,struct list_head *lru_head,int *page_count){
	int i,pfn,data;
	struct hlist_node *temp;
	struct list_head *ltemp;
        struct lru_list *p;
	PAGE *pg;
	struct lru_list *lru_list;
#if 0
	system("clear");
#endif
	printf("[HASH TABLE]\n");
	for(i=0;i<HASH_MAX;i++){
		printf("[%d]",i);
		for(temp=page_htable[i].first;temp;temp=temp->next){
			pg = container_of(temp,PAGE,hnode);
			printf("<->[%d]",pg->pfn);
		}
		printf("\n");
	}
	printf("[LRU LIST]\n");
        printf("[lru]");
	i=0;
        for(ltemp=lru_head->next;ltemp!=lru_head;ltemp=ltemp->next){
                 p = container_of(ltemp,struct lru_list,lru_head);
                 printf("<->[%d]",p->pfn);
		 i++;
		 if( (i+1) % 10 == 0 ) printf("\n");
        }
	getchar();
}
int main(){
	struct list_head lhead = {&lhead,&lhead};
	struct lru_list page_list[LIMITED_PAGES] = {0,};
	struct hlist_head page_htable[HASH_MAX] = {0,};
	PAGE pages[LIMITED_PAGES] = {0,};
	int page_count=0;
	unsigned int key;
//	display(pages,&lhead);
	srand(time(0));
	while(1){
		int pfn;
		system("clear");
		if( page_count >= LIMITED_PAGES ){
			struct list_head *temp = lhead.prev;
                 	struct lru_list *llist = container_of(temp,struct lru_list,lru_head);
			list_del(&lhead);
			//__list_del(lhead.prev,lhead.next);
			key = hash_func(hash_func(llist->pfn));
			if( hlist_del_by_key(&page_htable[key],pfn) == FALSE) printf("[DEBUG] 삭제 실패\n");
			printf("page 꽉 참, pfn=%2d 퇴출\n",llist->pfn);
			page_count--;
		}
		pfn = rand()%40;	
		key = hash_func(hash_func(pfn));
		pages[page_count].pfn = pfn;
		pages[page_count].data = 1000+pfn;;
		printf("pfn = %d 접근\n",pfn);
		if (hlist_find_key(&page_htable[key],pfn) == TRUE){
			printf("기존 페이지 접근, data =%d\n",pages[key].data);
		}else{
			page_list[page_count].pfn = pfn;
			list_add(&page_list[page_count].lru_head,&lhead);
			hlist_add_head(&pages[page_count].hnode,&page_htable[key]);
			printf("새로운 page hash에 추가, 현재 page 수= %d\n",++page_count);
		}
		//display(pages,&lhead);
		display(page_htable,&lhead,&page_count);
	}
	return 0;
}
