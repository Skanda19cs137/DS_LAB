#include<stdio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	 int info;
	 struct node *llink;
	 struct node *rlink;
	 };
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("mem full\n");
		exit(0);
		}
	return x;
	}
void freenode(NODE x)
{
	free(x);
}
NODE dinsert_front(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->rlink;
head->rlink=temp;
temp->llink=head;
temp->rlink=cur;
cur->llink=temp;
return head;
}
NODE dinsert_rear(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->llink;
head->llink=temp;
temp->rlink=head;
temp->llink=cur;
cur->rlink=temp;
return head;
}
NODE ddelete_front(NODE head)
{
NODE cur,next;
if(head->rlink==head)
{
printf("list is empty\n");
return head;
}
cur=head->rlink;
next=cur->rlink;
head->rlink=next;
next->llink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}
NODE ddelete_rear(NODE head)
{
NODE cur,prev;
if(head->rlink==head)
{
printf("list is empty\n");
return head;
}
cur=head->llink;
prev=cur->llink;
head->llink=prev;
prev->rlink=head;
printf("the node deleted is %d \n",cur->info);
freenode(cur);
return head;
}
void display(NODE head)
{
NODE temp;
if(head->rlink==head)
{
printf("list is empty\n");
return;
}
printf("contents of list is\n");
temp=head->rlink;
while(temp!=head)
{
printf("%d   ",temp->info);
temp=temp->rlink;
}
printf("\n");
}
void main()
{
NODE head,last;
int item, choice;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;)
{
	printf("\n1:insert front 2:insert rear 3:delete front 4:delete rear 5:display 6:exit\n");
	printf("enter the choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("enter the item at front end :");
			scanf("%d",&item);
			last=dinsert_front(item,head);
			break;
		case 2: printf("enter the item at rear end :");
			scanf("%d",&item);
			last=dinsert_rear(item,head);
			break;
		case 3:last=ddelete_front(head);
			break;
		case 4: last=ddelete_rear(head);
			break;
		case 5: display(head);
			break;
		default:exit(0);
		}
	}
getch();
}

