//Implementation of Double Linked List.

#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *pre;
	struct node *next;
	int e;
};
struct node *head;
void insert_at_begin()
{
	struct node *temp;
	int ele;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&ele);
		if(head==NULL)
		{
			temp->next=NULL;
			temp->pre=NULL;
			temp->e=ele;
			head=temp;
		}
		else
		{
			temp->e=ele;
			temp->pre=NULL;
			temp->next=head;
			head->pre=temp;
			head=temp;
		}
		printf("\nNode Inserted\n");
	}
}
void insert_at_last()
{
	struct node *temp,*newnode;
	int ele;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&ele);
		temp->e=ele;
		if(head==NULL)
		{
			temp->next=NULL;
			temp->pre=NULL;
			head=temp;
		}
		else
		{
			newnode=head;
			while(newnode->next!=NULL)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
			temp->pre=NULL;
			temp->next=NULL;
		}
	}
	printf("\nNode inserted\n");
}
void insert_at_pos()
{
	struct node *temp,*temp1;
	int ele,loc,i;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		temp1=head;
		printf("Enter the location: ");
		scanf("%d",&loc);
		for(i=0;i<loc;i++)
		{
			temp1=temp1->next;
			if(temp1==NULL)
			{
				printf("\n There are less than %d elements",loc);
				return;
			}
		}
		printf("Enter the element: ");
		scanf("%d",&ele);
		temp->e=ele;
		temp->next=temp1->next;
		temp->pre=temp1;
		temp1->next=temp;
		temp1->next->pre=temp;
		printf("\nNode Inserted\n");
	}
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nUnderFlow\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNode Deleted\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->pre=NULL;
		free(temp);
		printf("\nNode Deleted\n");
	}
}
void delete_at_end()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nUnderFlow\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNode Deleted\n");
	}
	else
	{
		temp=head;
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->pre->next=NULL;
		free(temp);
		printf("\nNode Deleted\n");
	}
}
void delete_at_pos()
{
	struct node *temp,*temp1;
	int val;
	printf("Enter the data after which the node is to be deleted: ");
	scanf("%d",&val);
	temp=head;
	while(temp->e!=val)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("\nCannot Delete\n");
	}
	else if(temp->next->next==NULL)
	{
		temp->next=NULL;
	}
	else
	{
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->pre=temp;
		free(temp);
		printf("\nNode Deleted\n");
	}
}
void display()
{
	struct node *temp;
	printf("\nPrinting The Values...\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->e);
		temp=temp->next;
	}
}
void search()
{
	struct node *temp;
	int ele,i=0,flag;
	temp=head;
	if(temp==NULL)
	{
		printf("\nEmpty List\n");
	}
	else
	{
		printf("Enter the searchkey: ");
		scanf("%d",&ele);
		while(temp!=NULL)
		{
			if(temp->e==ele)
			{
				printf("\n Item Found at location: %d",i+1);
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			i++;
			temp=temp->next;
		}
		if(flag==1)
		{
			printf("\nElement Not found\n");
		}
	}
}

void main()
{
	int ch;
	do
	{
		printf("\n 1.Insert at Begining\n 2.Insert at End\n 3.Insert at position\n 4.Delete at begin\n 5.Delete at end\n 6.Delete at position\n 7.display\n 8.Search\n 9.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_at_begin();
				break;
			case 2:
				insert_at_last();
				break;
			case 3:
				insert_at_pos();
				break;
			case 4:
				delete_at_begin();
				break;
			case 5:
				delete_at_end();
				break;
			case 6:
				delete_at_pos();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				printf("\nEXITING FROM THE LIST\n");
				break;
			default:
				printf("\nInvalid OPtion\n");
				break;
		}
	}while(ch!=9);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
