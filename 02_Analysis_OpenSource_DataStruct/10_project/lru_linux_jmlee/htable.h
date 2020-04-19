
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
	h->first = n;
	n->pprev = &h->first;
}

void hlist_del(struct hlist_node *n)
{
	struct hlist_node *next = n->next;
	struct hlist_node **pprev = n->pprev;
	*pprev = next;
	if (next)
		next->pprev = pprev;
}

PAGE* hlist_find_key(struct hlist_head *heads,int pfn){
	struct hlist_node *temp;
	PAGE *pg;
	hlist_for_each(temp, heads) {
		pg = container_of(temp,PAGE,hnode);
		if( pg->pfn == pfn ) return pg;
	}
	return (PAGE*)0;
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
unsigned int hash_func(unsigned int num){
	return hash_32(num,3);
}