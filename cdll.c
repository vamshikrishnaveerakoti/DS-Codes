//Implementation of Circular Double Linked List.

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
	struct node *temp,*newnode;
	int ele;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&ele);
		temp->e=ele;
		if(head==NULL)
		{
			head=temp;
			temp->next=head;
			temp->pre=head;
		}
		else
		{
			newnode=head;
			while(newnode->next!=head)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
			temp->pre=temp;
			head->pre=temp;
			temp->next=head;
			head=temp;
		}
		printf("\nNODE INSERTED\n");
	}
}
void insert_at_end()
{
	struct node *temp,*newnode;
	int ele;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&ele);
		temp->e=ele;
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
			temp->pre=head;
		}
		else
		{
			newnode=head;
			while(newnode->next!=head)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
			temp->pre=newnode;
			head->pre=temp;
			temp->next=head;
		}
	}
	printf("\nNODE INSERTED\n");
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		printf("\nNODE DELETED\n");
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		head->next->pre=temp;
		free(head);
		head=temp->next;
	}
}
void delete_at_end()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		printf("\nNODE DELETED\n");
	}
	else
	{
		temp=head;
		if(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->pre->next=head;
		head->pre=temp->pre;
		free(temp);
		printf("\nNODE INSERTED\n");
	}
}
void search()
{
	struct node *temp;
	int sk,i=0,flag=1;
	temp=head;
	if(temp==NULL)
	{
		printf("\nEMPTY LIST\n");
	}
	else
	{
		printf("Enter the searchkey: ");
		scanf("%d",&sk);
		if(head->e==sk)
		{
			printf("Searchkey found at %d",i+1);
			flag=0;
		}
		else
		{
			while(temp->next!=head)
			{
				if(temp->e==sk)
				{
					printf("searchkey found at %d",i+1);
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
		}
		if(flag!=0)
		{
			printf("\nSearchkey is not found\n");
		}
	}
}
void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nNOTHING TO PRINT\n");
	}
	else
	{
		printf("\nPRINTING THE VALUES\n");
		while(temp->next!=head)
		{
			printf("%d\n",temp->e);
			temp=temp->next;
		}
		printf("%d\n",temp->e);
	}
}

void main()
{
	int ch;
	do
	{
		printf("\n 1.Insert at the begining\n 2.Insert at the end\n 3.Delete at the begining\n 4.Delete at the end\n 5.Search\n 6.Display\n 7.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_at_begin();
				break;
			case 2:
				insert_at_end();
				break;
			case 3:
				delete_at_begin();
				break;
			case 4:
				delete_at_end();
				break;
			case 5:
				search();
				break;
			case 6:
				display();
				break;
			case 7:
				printf("\nEXITED\n");
				break;
			default:
				printf("\nInvalid Option\n");
		}
	}while(ch!=7);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
