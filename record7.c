//disjoint set representation
#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct rep*repptr;//pointer to header node of the list
struct node*next;
};
//structure to represent header node of linked representation
struct rep{
struct node*head;
struct node*tail;
};
//structure to store key and object node pointer structnodaddr
struct nodaddr
{
int key;
struct node*obj_node_ptr;
struct nodaddr*next;
};
struct nodaddr*ndr=0;
void makeset(int a)
{
//create a object node pointer
struct nodaddr*t=(struct nodaddr*)
malloc(sizeof(struct nodaddr));
//create a new set
struct rep*newset=(struct rep*)
malloc(sizeof(struct rep));
struct node*n=(struct node*)malloc(sizeof(struct node));
//fill values
n->value=a;
n->repptr=newset;
n->next=0;
//initalize head and tail
newset->head=newset->tail=n;
//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//containing x
struct rep * find(int x)
{
struct nodaddr*t=ndr;
while(t!=0&&t->key!=x)
t=t->next;
return t->obj_node_ptr->repptr;
}
//find union of two set
void unionset(int key1, int key2)
{
struct rep*set1,*set2;
struct node*t1;
set1=find(key1);
set2=find(key2);
if(set1==set2)
printf("\n%d & %d belongs to same set \n",key1,key2);
else
{
//chaining the header pointer of onjects of set 2 to that of set1
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set2->tail=set2->tail;//set the tailof set 1 to tail of set 2
free (set2);
}
}
//function to display a set
void display_set(int a)
{
struct rep*r;
struct node*t;
r=find(a);
t=r->head;
printf("set numbers containg %d;",a);
while(t!=0)
{
printf("%d,",t->value);
t=t->next;
}
}
void main()
{
makeset(10);
makeset(20);
makeset(30);
makeset(40);
printf("\nfnd(10)=%X",find(10));
printf("\nfind(20)=%X",find(20));
printf("\nfind(30)=%X",find(30));
printf("\nfind(40)=%X",find(40));
unionset(10,20);
printf("\nafter union of 10&20 find(20)=%X",find(20));
unionset(30,40);
printf("\nafter union of 30&40 find(40)=%X",find(40));
unionset(20,40);
printf("\nafter union of set containg 20 and set containg 40 find(40)=%X\n",find(40));
display_set(40);
}


