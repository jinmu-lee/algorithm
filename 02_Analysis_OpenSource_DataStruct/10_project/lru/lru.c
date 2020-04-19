#include "common.h"
#include "list.h"
#include "htable.h"

void __display_removal(struct hlist_head *page_htable,struct list_head *lru_head,int *page_count);
void __display_add_newpage(struct hlist_head *page_htable,struct list_head *lru_head,
							LRU *list_pages,PAGE *table_pages,int *page_count);
void __display_htable(struct hlist_head *page_htable);
void __display_list(struct list_head *lru_head);

int main(){
	struct list_head list = {&list,&list};
	struct hlist_head htable[HASH_MAX] = {0,};
	LRU list_pages[PAGE_FRAME_MAX_NUM] = {0,};
	PAGE table_pages[PAGE_FRAME_MAX_NUM] = {0,};
	int page_count=0;
	system("cls");
	__display_htable(htable);
	__display_list(&list);
	getchar();
	while(1){
		system("cls");
		if( page_count >= NUM_OF_PAGES ){
			__display_removal(htable,&list,&page_count);
		}
		__display_add_newpage(htable,&list,list_pages,table_pages,&page_count);
		__display_htable(htable);
		__display_list(&list);
		getchar();
	}
	return 0;
}

void __display_removal(struct hlist_head *page_htable,struct list_head *lru_head,int *page_count){
	struct list_head *temp = lru_head->prev;
	LRU *llist = container_of(temp,LRU,lru_head);
	unsigned int pfn = llist->pfn;
	unsigned int key = hash_func(llist->pfn);
	PAGE *page = 0;
	list_del(&llist->lru_head);
	if( page = hlist_find_key(&page_htable[key],pfn)) {
		hlist_del(&page->hnode);
		printf("page 꽉 참, pfn=%2d 퇴출\n",pfn);
		(*page_count)--;
	}else{
		printf("[DEBUG] 삭제 실패\n");
	}			
}
void __display_add_newpage(struct hlist_head *page_htable,struct list_head *lru_head,
							LRU *list_pages,PAGE *table_pages,int *page_count){
	unsigned int pfn = rand()%PAGE_FRAME_MAX_NUM;
	unsigned int key = hash_func(pfn);
	PAGE *page = 0;
	printf("pfn = %d 접근\n",pfn);
	if (page = hlist_find_key(&page_htable[key],pfn) ){
		int data = page->data;
		struct list_head *ltemp;
		list_for_each(ltemp,lru_head){
			LRU *lru = container_of(ltemp,LRU,lru_head);
			if(lru->pfn == pfn){
				list_del(&lru->lru_head);
				break;
			}
		}
		hlist_del(&page->hnode);
		printf("기존 페이지 접근, data =%d\n",data);
	}else{		
		printf("새로운 page hash에 추가, 현재 page 수= %d\n",++(*page_count));
	}
	//table setting
	table_pages[pfn].pfn = pfn;
	table_pages[pfn].data = 1000+pfn;
	hlist_add_head(&table_pages[pfn].hnode,&page_htable[key]);
	//list setting
	list_pages[pfn].pfn = pfn;
	list_add(&list_pages[pfn].lru_head,lru_head);
}
void __display_htable(struct hlist_head *page_htable){
	struct hlist_node *temp;
	int i;
	printf("[HASH TABLE]\n");
	for(i=0;i<HASH_MAX;i++){
		printf("[%d]",i);
		hlist_for_each(temp,(page_htable+i)){
			PAGE *pg = container_of(temp,PAGE,hnode);
			printf("<->[%d]",pg->pfn);
		}
		printf("\n");
	}
	printf("\n");
}
void __display_list(struct list_head *lru_head){
	struct list_head *ltemp;	
	int i=0;
	printf("\n[LRU LIST]\n");
	printf("[lru]");	
	list_for_each(ltemp,lru_head){
		LRU *lru = container_of(ltemp,LRU,lru_head);
		printf("<->[%d]",lru->pfn);
		i++;
		if( (i+1) % 10 == 0 ) printf("\n");
	}
}