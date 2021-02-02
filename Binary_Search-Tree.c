#include<stdio.h>
#include<stdlib.h>
struct tree
{
int data;
struct tree *lchild;
struct tree *rchild;
}*t,*temp;

int element;
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree * create(struct tree *, int);
void find(struct tree *, int);
struct tree * insert(struct tree *, int);
struct tree * del(struct tree *, int);
struct tree * findmin(struct tree *);
struct tree * findmax(struct tree *);
void main()
{
int ch;
do
{
printf("\n\t\t\tBINARY SEARCH TREE");
printf("\n\t\t\t****** ****** ****");
printf("\nMain Menu\n");
printf("\n1.Create\n2.Insert\n3.Delete\n4.Find\n5.FindMin\n6.FindMax");
printf("\n7.Inorder\n8.Preorder\n9.Postorder\n10.Exit\n");
printf("\nEnter Your Choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter The Data : ");
scanf("%d",&element);
t=create(t,element);
inorder(t);
break;
case 2:
printf("\nEnter The Data : ");
scanf("%d",&element);
t=insert(t,element);
inorder(t);
break;
case 3:
printf("\nEnter The Data : ");
scanf("%d",&element);
t=del(t,element);
inorder(t);
break;
case 4:
printf("\nEnter The Data : ");
scanf("%d",&element);
find(t,element);
break;
case 5:
temp=findmin(t);
printf("\nMinimum Element = %d",temp->data);
break;
case 6:
temp=findmax(t);
printf("\nMaximum Element = %d",temp->data);
break;
case 7:
inorder(t);
break;
case 8:
preorder(t);
break;	
case 9:
postorder(t);
break;
case 10:
exit(0);
}
}while(ch<=10);
}
struct tree * create(struct tree *t, int element)
{
t=(struct tree *)malloc(sizeof(struct tree));
t->data=element;
t->lchild=NULL;
t->rchild=NULL;
return t;
}

void find(struct tree *t, int element)
{
     if(t==NULL)
      {          printf("\nElement Not Found");}
      
     else if(element<t->data)
     {
                   find(t->lchild,element);
     }
     else if(element>t->data)
     {
     find(t->rchild,element);
     }
     else
                printf("\nElement Found : %d", t->data);
   return;
}

struct tree *findmin(struct tree *t)
{
if(t==NULL)
return NULL;
else
if(t->lchild==NULL)
return t;
else
return(findmin(t->lchild));
}

struct tree *findmax(struct tree *t)
{
if(t!=NULL)
{
while(t->rchild!=NULL)
t=t->rchild;
}
return t;
}

struct tree *insert(struct tree *t,int element)
{
if(t==NULL)
{
t=(struct tree *)malloc(sizeof(struct tree));
t->data=element;
t->lchild=NULL;
t->rchild=NULL;
return t;
}
else
{
if(element<t->data)
{
t->lchild=insert(t->lchild,element);
}
else if(element>t->data)
{
t->rchild=insert(t->rchild,element);
}
else if(element==t->data)
{
printf("Element Already Present\n");
}
return t;
}
}

struct tree * del(struct tree *t, int element)
{
if(t==NULL)
printf("Element Not Found\n");
else if(element<t->data)
t->lchild=del(t->lchild,element);
else if(element>t->data)
t->rchild=del(t->rchild,element);
else if(t->lchild&&t->rchild)
{
temp=findmin(t->rchild);
t->data=temp->data;
t->rchild=del(t->rchild,t->data);
}
else	
{
temp=t;
if(t->lchild==NULL)
t=t->rchild;
else if(t->rchild==NULL)
t=t->lchild;
free(temp);
}
return t;
}

void inorder(struct tree *t)
{
if(t==NULL)
return;
else
{
inorder(t->lchild);
printf("\t%d",t->data);
inorder(t->rchild);
}
}

void preorder(struct tree *t)
{
if(t==NULL)
return;
else
{
printf("\t%d",t->data);
preorder(t->lchild);
preorder(t->rchild);
}
}

void postorder(struct tree *t)
{
if(t==NULL)
return;
else
{
postorder(t->lchild);
postorder(t->rchild);
printf("\t%d",t->data);
}
}