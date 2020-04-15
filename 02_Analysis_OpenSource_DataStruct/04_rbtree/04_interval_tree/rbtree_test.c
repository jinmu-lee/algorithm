#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interval_tree.h"
#include "interval_tree_generic.h"
#include "rbtree_augmented.h"

typedef struct {
	unsigned long start;
	unsigned long last;
	unsigned long __subtree_last;
	int color;
}INFO;

void __display(struct rb_node *temp,INFO (*a)[10],int *row,int *col){
	struct interval_tree_node *s;
	int i;
	if(temp==0) return;
	++*row;
	__display(temp->rb_left,a,row,col);
	s=rb_entry(temp,struct interval_tree_node, rb);
	//a[*row][*col].color = temp->rb_color;
	a[*row][*col].color = rb_color(temp);
	a[*row][*col].start = s->start;
	a[*row][*col].last = s->last;
	a[*row][(*col)++].__subtree_last = s->__subtree_last;
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
			if( a[i][j].__subtree_last ){
				if( a[i][j].color & 1 )
					printf("[%2ul,%2ul,%2ul]",a[i][j].start,a[i][j].last,a[i][j].__subtree_last);
				else 				
					printf("<%2ul,%2ul,%2ul>",a[i][j].start,a[i][j].last,a[i][j].__subtree_last);
			}else{
				printf("%10c",' ');
			}
		}
		printf("\n");
	}
	getchar();
}
int main(){
	struct rb_root root={0};
	int i;
	int index;
	struct interval_tree_node nodes[] = { 
		{{0,},17,19},
		{{0,},5,11},
		{{0,},22,23},
		{{0,},4,8},
		{{0,},15,18},
		{{0,},17,10}
	};

	display(&root);
	for(i=0;i<6;i++){
		interval_tree_insert(nodes+i,&root);
		display(&root);
	}

	while(1){
		printf("index 입력: ");
		scanf("%d",&index);
	}
	return 0;
}
