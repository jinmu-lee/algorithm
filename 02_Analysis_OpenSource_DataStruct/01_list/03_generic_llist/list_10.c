#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	struct _node *next;
	struct _node *prev;
}NODE;

void __insert_data(NODE *temp,NODE *prev,NODE *next){
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}
void insert_front(NODE *temp,NODE *head){
	__insert_data(temp,head,head->next);
}
void insert_back(NODE *temp,NODE *head){
	__insert_data(temp,head->prev,head);
}

#define container_of(ptr,type,member) \
	(type *)((char *)ptr - (unsigned long)&((type *)0)->member)


typedef struct{
	char name[20];
	NODE list1;
	NODE list2;
}SAWON;

void display(NODE *head){
	NODE *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for(temp=head->next;temp!=head;temp=temp->next){
//		s = (SAWON *)((char *)temp - (sizeof(SAWON)-sizeof(NODE)));
//		s = (SAWON *)((char *)temp - (unsigned long)&((SAWON *)0)->list1);
//		s = (SAWON *)((char *)temp - (unsigned long)&((SAWON *)0)->list2);
		s = container_of(temp,SAWON,list2);
		printf("->[%s]",s->name);
	}
	printf("->[head]");
	getchar();
}
int main(){
	NODE head = {&head,&head};
	SAWON s[2] = { {"홍길동"},{"임꺽정"} };
	int i;
	for(i=0;i<2;i++){
		display(&head);
//		insert_front(&s[i].list,&head);
//		insert_back(&s[i].list1,&head);
		insert_back(&s[i].list2,&head);
	}
	display(&head);
	return 0;
}
