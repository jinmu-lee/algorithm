#if 1
// ver 1.0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    struct _node *next;
    struct _node *prev;
} NODE;

void __insert_data( NODE *temp , NODE *prev, NODE *next)
{
   temp->next = next;
   prev->next = temp;
   temp->prev = prev;
   next->prev = temp;
}

void insert_front( NODE *temp , NODE *head)
{
   __insert_data( temp, head, head->next);
}
void insert_back( NODE *temp , NODE *head)
{
   __insert_data( temp, head->prev, head);
}

#define container_of( ptr, type, member )   \
        ((type*)((char*)ptr-(unsigned long)&((type*)0)->member))
//---------------------------------------------------------------

typedef struct
{
   char name[20];
   NODE node1;
   NODE node2;
} SAWON;

void display( NODE *head )
{
   NODE *temp;
   SAWON *s;
   system("cls");
   printf("[head]");
   for( temp = head->prev; temp!=head; temp=temp->prev )
   {
        s = container_of( temp, SAWON, node1);	
	printf("<->[%s]", s->name);
   }
   printf("<->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {&head, &head};
   SAWON s[2] = {{"È«±æµ¿"},{"ÀÓ²©Á¤"}};
   display(&head);
   for(i=0; i<2; i++ )
   {
      insert_back( &s[i].node1, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.9.1
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    struct _node *next;
    struct _node *prev;
} NODE;

void __insert_data( NODE *temp , NODE *prev, NODE *next)
{
   temp->next = next;
   prev->next = temp;
   temp->prev = prev;
   next->prev = temp;
}

void insert_front( NODE *temp , NODE *head)
{
   __insert_data( temp, head, head->next);
}
void insert_back( NODE *temp , NODE *head)
{
   __insert_data( temp, head->prev, head);
}
//---------------------------------------------------------------

typedef struct
{
   char name[20];
   NODE node;
} SAWON;

void display( NODE *head )
{
   NODE *temp;
   SAWON *s;
   system("cls");
   printf("[head]");
   for( temp = head->prev; temp!=head; temp=temp->prev )
   {
	//s = (SAWON*)((char*)temp-20);
        s = (SAWON*)((char*)temp - (sizeof(SAWON)-sizeof(NODE)));
	printf("<->[%s]", s->name);
   }
   printf("<->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {&head, &head};
   SAWON s[2] = {{"È«±æµ¿"},{"ÀÓ²©Á¤"}};
   display(&head);
   for(i=0; i<2; i++ )
   {
      insert_back( &s[i].node, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.9
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    void* data;
    struct _node *next;
    struct _node *prev;
} NODE;

void __insert_data( NODE *temp , NODE *prev, NODE *next)
{
   temp->next = next;
   prev->next = temp;
   temp->prev = prev;
   next->prev = temp;
}

void insert_front( NODE *temp , NODE *head)
{
   __insert_data( temp, head, head->next);
}
void insert_back( NODE *temp , NODE *head)
{
   __insert_data( temp, head->prev, head);
}
//---------------------------------------------------------------

typedef struct
{
   char name[20];
} SAWON;

void display( NODE *head )
{
   NODE *temp;
   SAWON *s;
   system("cls");
   printf("[head]");
   for( temp = head->prev; temp!=head; temp=temp->prev )
   {
	s = (SAWON*)temp->data;
	printf("<->[%s]", s->name);
   }
   printf("<->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,&head, &head};
   NODE temp[2];
   SAWON s[2] = {{"È«±æµ¿"},{"ÀÓ²©Á¤"}};
   display(&head);
   for(i=0; i<2; i++ )
   {
      temp[i].data = s+i;
      insert_back(temp+i, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.8.1
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
    struct _node *prev;
} NODE;


void __insert_data( NODE *temp , NODE *prev, NODE *next)
{
   temp->next = next;
   prev->next = temp;
   temp->prev = prev;
   next->prev = temp;
}

void insert_front( NODE *temp , NODE *head)
{
   __insert_data( temp, head, head->next);
}
void insert_back( NODE *temp , NODE *head)
{
   __insert_data( temp, head->prev, head);
}

void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->prev; temp!=head; temp=temp->prev )
	printf("<->[%d]", temp->data);
   printf("<->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,&head, &head};
   NODE temp[7];
   display(&head);
   for(i=0; i<7; i++ )
   {
      temp[i].data = i+1;
      insert_back(temp+i, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.8
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
    struct _node *prev;
} NODE;


void insert_data( NODE *temp , NODE *head )
{
   temp->next = head->next;
   head->next = temp;
   temp->prev = head;
   temp->next->prev = temp;
}

void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->prev; temp!=head; temp=temp->prev )
	printf("<->[%d]", temp->data);
   printf("<->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,&head, &head};
   NODE temp[7];
   display(&head);
   for(i=0; i<7; i++ )
   {
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.7
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;


void insert_data( NODE *temp , NODE *head )
{
   temp->next = head->next;
   head->next = temp;
}
void reverse( NODE *head )
{
    NODE *prev = head;
    NODE *curr = prev->next;
    NODE *next;
    while( curr != head )
    {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
    }
    curr->next = prev;
}

void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->next; temp!=head; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,&head};
   NODE temp[7];
   display(&head);
   for(i=0; i<7; i++ )
   {
      //temp = malloc( sizeof(NODE) );
      //temp->data = i+1;
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(&head);
   }
   reverse(&head);
   display(&head);
   reverse(&head);
   display(&head);
   return 0;
}
#endif
#if 0
// ver 0.6
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;


void insert_data( NODE *temp , NODE *head )
{
   temp->next = head->next;
   head->next = temp;
}
void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->next; temp!=head; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("->[head]\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,&head};
   NODE temp[7];
   display(&head);
   for(i=0; i<7; i++ )
   {
      //temp = malloc( sizeof(NODE) );
      //temp->data = i+1;
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.5
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;


void insert_data( NODE *temp , NODE *head )
{
   temp->next = head->next;
   head->next = temp;
}
void display( NODE *head, NODE *tail )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->next; temp!=tail; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("->[tail]\n");
   getchar();
}

int main()
{
   int i;
   NODE tail = {0,&tail};
   NODE head = {0,&tail};
   NODE temp[7];
   display(&head,&tail);
   for(i=0; i<7; i++ )
   {
      //temp = malloc( sizeof(NODE) );
      //temp->data = i+1;
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(&head,&tail);
   }
   return 0;
}
#endif
#if 0
// ver 0.4
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;


void insert_data( NODE *temp , NODE *head )
{
   temp->next = head->next;
   head->next = temp;
}
void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("[head]");
   for( temp = head->next; temp; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("\n");
   getchar();
}

int main()
{
   int i;
   NODE head = {0,};
   NODE temp[7];
   display(&head);
   for(i=0; i<7; i++ )
   {
      //temp = malloc( sizeof(NODE) );
      //temp->data = i+1;
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(&head);
   }
   return 0;
}
#endif
#if 0
// ver 0.3
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;

NODE *head;

void insert_data( NODE *temp , NODE **head )
{
   temp->next = *head;
   *head = temp;
}
void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("head");
   for( temp = head; temp; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("\n");
   getchar();
}

int main()
{
   int i;
   NODE temp[7];
   display(head);
   for(i=0; i<7; i++ )
   {
      //temp = malloc( sizeof(NODE) );
      //temp->data = i+1;
      temp[i].data = i+1;
      insert_data(temp+i, &head);
      display(head);
   }
   return 0;
}
#endif
#if 0
// ver 0.2
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;

NODE *head;

void insert_data( int data , NODE **head )
{
   NODE *temp;
   temp = malloc( sizeof(NODE) );
   temp->data = data;
   temp->next = *head;
   *head = temp;
}
void display( NODE *head )
{
   NODE *temp;
   system("cls");
   printf("head");
   for( temp = head; temp; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("\n");
   getchar();
}

int main()
{
   int i;
   display(head);
   for(i=0; i<7; i++ )
   {
      insert_data(i+1, &head);
      display(head);
   }
   return 0;
}
#endif
#if 0
// ver 0.1
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} NODE;

NODE *head;

void insert_data( int data )
{
   NODE *temp;
   temp = malloc( sizeof(NODE) );
   temp->data = data;
   temp->next = head;
   head = temp;
}
void display( void )
{
   NODE *temp;
   system("cls");
   printf("head");
   for( temp = head; temp; temp=temp->next )
	printf("->[%d]", temp->data);
   printf("\n");
   getchar();
}

int main()
{
   int i;
   display();
   for(i=0; i<7; i++ )
   {
      insert_data(i+1);
      display();
   }
   return 0;
}
#endif






