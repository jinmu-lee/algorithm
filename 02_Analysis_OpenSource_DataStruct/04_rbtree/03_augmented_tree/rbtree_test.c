#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "rbtree.h"
#include "rbtree_augmented.h" 

typedef struct {
	char name[20];
	int augmented;
	struct rb_node node;
}SAWON;

typedef struct {
	char name[20];
	int augmented;
	int color;
}INFO;

int my_rank(struct rb_node *node,int x){
	int k=1;
	if( node->rb_left )
		k = rb_entry(node->rb_left,SAWON,node)->augmented+1;
	while(rb_parent(node) != 0){
		if( rb_parent(node)->rb_right == node){
			if(rb_parent(node)->rb_left){
				k+=rb_entry(rb_parent(node)->rb_left,SAWON,node)->augmented+1;
			}else{
				k++;
			}
		}
		node=rb_parent(node);
	}
	return k;
}

SAWON *my_select(struct rb_node *node,int i){
	int k;
	if( node == 0 ) 
		return 0;
	if( node->rb_left )
		k = rb_entry(node->rb_left,SAWON,node)->augmented+1;
	if( i==k ) 
		return rb_entry(node,SAWON,node);
	if( i<k )
		my_select(node->rb_left,i);
	else
		my_select(node->rb_right,i-k);
}

int my_compute(SAWON *s){
	int sum = 0;
	int child_augmented;
	if( s->node.rb_left ){
		child_augmented = rb_entry(s->node.rb_left,SAWON,node)->augmented;
		sum += child_augmented;
	}
	if( s->node.rb_right ){
		child_augmented = rb_entry(s->node.rb_right,SAWON,node)->augmented;
		sum += child_augmented;
	}
	return sum +1;
}
RB_DECLARE_CALLBACKS(static,augment_callbacks, SAWON,node,int,augmented,my_compute);

int my_insert(struct rb_root *root,SAWON *s){
	struct rb_node **p=&root->rb_node;
	struct rb_node *parent=0;
	SAWON *temp;
	while(*p){
		parent = *p;
		temp = rb_entry(parent, SAWON, node);
		if( strcmp(temp->name,s->name) > 0 ){
			p=&(*p)->rb_left;
		}else if( strcmp(temp->name,s->name) < 0 ){
			p=&(*p)->rb_right;
		}else{
			return 0; // unique data 
		}
		temp->augmented++;
	}
	s->augmented = 1;
	rb_link_node(&s->node,parent,p);
	//augment_callbacks_propagate(parent,0);
	//rb_insert_color(&s->node,root);
	rb_insert_augmented(&s->node,root,&augment_callbacks);
	return 1;
}
void __display(struct rb_node *temp,INFO (*a)[10],int *row,int *col){
	SAWON *s;
	int i;
	if(temp==0) return;
	++*row;
	__display(temp->rb_left,a,row,col);
	s=rb_entry(temp,SAWON,node);
	//a[*row][*col].color = temp->rb_color;
	a[*row][*col].color = temp->rb_parent_color;
	a[*row][*col].augmented = s->augmented;
	strcpy(a[*row][(*col)++].name,s->name);
	__display(temp->rb_right,a,row,col);
	--*row;
}
void display(struct rb_root *root){
	int row=-1;
	int col=0;
	INFO a[10][10]={0,};
	int i,j;
	__display(root->rb_node,a,&row,&col);
	system("clear");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(strlen(a[i][j].name)>0){
				if( a[i][j].color & 1 )
					printf("[%s,%d]",a[i][j].name,a[i][j].augmented);
				else 
					printf("<%s,%d>",a[i][j].name,a[i][j].augmented);

			}
			else printf("%4c",' ');					
		}
		printf("\n");
	}
	getchar();
}
int main(){
	struct rb_root root={0};
	int i;
	int index;
	SAWON sawon[8] = {{"임꺽정",},{"홍길동",},{"이순신",}};
	for(i=0;i<3;i++){
		my_insert(&root,sawon+i);
	}
	display(&root);

	while(1){
		printf("index 입력: ");
		scanf("%d",&index);
		s = my_select(root.rb_node, index);
		if( s ) printf("%d번째 name=%s\n",index,s->name);
		else printf("%d번째 사원은 범위에 없습니다.\n",index);
	}
	return 0;
}
