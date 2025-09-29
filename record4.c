#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left,*right;
};
void main()
{
struct node*start=(struct node*)0;
struct node*insert(struct node*,int);
struct node*search(struct node*,int);
struct node*delete(struct node*,int);
void display(struct node*);
int item,op;
while(1)
{
printf("\n1.insert \n2.delete \n3.search \n4.display \n5.exit \n");
printf("your option:");
scanf("%d",&op);
switch(op)
{
case 1:printf("item to insert:\n");
scanf("%d",& item);
start=insert(start,item);
break;
case 2:printf("\n item to delete:\n");
scanf("%d",&item);
start=delete(start,item);
break;
case 3:printf("\n item to search :\n");
scanf("%d",& item);
if(search(start,item)==(struct node*)0)
printf("\n not found");
else
printf("\n found");
break;
case 4:display(start);
break;
case 5:exit(0);
}
}
}
struct node*insert(struct node*s,int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->left=(struct node*)0;
t->right=s;
if(s!=0)
s->left=t;
return t;
}
void display(struct node*s)
{
while(s!=0)
{
printf("%d\n",s->data);
s=s->right;
}
return;
}
struct node*search(struct node*s,int data)
{
while(s!=0&&data!=s->data)
s=s->right;
return s;
}
struct node*delete(struct node*s,int data)
{
struct node*t;
t=search(s,data);
if(t==0)
printf("not found");
else
if(t->left==0)
{
s=s->right;
if(t->right!=0)
s->left=0;
}
else
t->left->right=t->right;
if(t->right!=0)
{
t->right->left=t->left;
free(t);
}
return s;
}




