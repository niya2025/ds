#include<stdio.h>
#include<stlib.h>
struct node
{
int data;
struct node*next;
};
void main()
{
struct node*start=(struct node*)0;
struct node*insert(struct node*,int);
struct node*delete(struct node*);
void display(struct node*);
int search(struct node*int),opt,item;
while (1)
{
printf("\n1.insert \n2.delete \n3.display \n4.search \n5.exit \n");
printf("your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
scanf("%d",& item);
start=insert(start,item);
break;
case 2:start=delete(start);
printf("deleted item =%d",item);
break;
case 3:display(start);
break;
case 4:printf("item to search:");
scanf("%d",&item);
ans=search(start,item);
if(ans==1)
printf("founded...");
else
printf("not founded...");
break;
case 5:exit(0);
}
}
return 0;
{
struct node*insert(struct node*list,int data)
{
struct node*t;
t=(struct node*)malloc(size of(struct node));
t->data=data;
t->next=list;
list=t;
return list;
}
struct node*delete(struct node*list)
{struct node*t=list;
if(list!=(struct node*)0)
{
printf("deleted item:%d\n",list->data);
list=list->next;
free(t);
}
else
printf("list is null\n");
return list;
}
voud display(struct node*list)
{
while()list!=(struct node*)0
{
printf("%d",list->data);
list=list->next;
}
printf("\n");
return;
}
int search(struct node*list,int item)
{
while(list!=(struct node*)0&&list->data!=item)
list=list->next;
if(list==(struct node*)0)
return 0;
else 
return 1;
}















