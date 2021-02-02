//Implementation of Circular Linked List.

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int e;
	struct node *next;
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
		}
		else
		{
			newnode=head;
			while(newnode->next!=head)
			{
				newnode=newnode->next;
			}
			temp->next=head;
			newnode->next=temp;
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
			temp->next=head;
		}
		else
		{
			newnode=head;
			while(newnode->next!=head)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
			temp->next=head;
		}
		printf("\nNODE INSERTED\n");
	}
}
void delete_at_begin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nNOTHNG TO DELETE\n");
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
		free(head);
		head=temp->next;
		printf("\nNODE DELETED\n");
	}
}
void delete_at_end()
{
	struct node *temp,*temp1;
	if(head==NULL)
	{
		printf("\nNOTHING TO DELETE\n");
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
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=temp->next;
		free(temp);
		printf("\nNODE DELETED\n");
	}
}
void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nEMPTY LIST\n");
	}
	else
	{
		printf("\nTHE VALUES ARE\n");
		while(temp->next!=head)
		{
			printf("%d\n",temp->e);
			temp=temp->next;
		}
		printf("%d\n",temp->e);
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
					printf("Searchkey found at %d\n",i+1);
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
			printf("\nSearchkey not found\n");
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n 1.Insert at begin\n 2.Insert at End\n 3.Delete at begin\n 4.Delete at end\n 5.Display\n 6.Search\n 7.Exit\n");
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
				display();
				break;
			case 6:
				search();
				break;
			case 7:
				printf("\nEXITING FROM THE PROGRAM\n");
				break;
			default:
				printf("\nInvalid Option\n");
				break;
		}
	}while(ch!=7);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
