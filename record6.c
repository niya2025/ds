#include<stdio.h>
struct bit{unsigned char x:1;};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersect(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[10]={0},b[10]={0},c[10]={0};
int n;
printf("no.of elements in set A:");
scanf("%d",&n);
readset(a,n);
printf("no.of elements in set B:");
scanf("%d",&n);
readset(b,n);
printf("set A:"),printset(a);
printf("set B:"),printset(b);
unionset(a,b,c);
printf("AUB="),printset(c);
intersect(a,b,c);
printf("A intersect B="),printset(c);
difference(a,b,c);
printf("A-B="),printset(c);
}
//To read a set and store as bit string
void readset(struct bit a[],int n)
{
int i,x,k;
printf("enter %d elements:",n);
for(i=0;i<n;++i)
{
scanf("%d",&x);
for(k=0;k<size;++k)
if(uset[k]==x)
{
a[k].x=1;
break;
}
}
return;
}
//To print a set from bit string representation
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<size;++k)
if (a[k].x==1)
printf("%d,",uset[k]);
printf("}\n");
return;
}
//To find union 
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x | b[k].x;
return;
}
//intersect
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for (k=0;k<size;++k)
c[k].x=a[k].x & b[k].x;
return;
}
// find the difference
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for (k=0;k<size;++k)
if (a[k].x==1)
c[k].x=a[k].x ^ b[k].x;
return;
}

