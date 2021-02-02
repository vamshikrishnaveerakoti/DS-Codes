//Implementation of Linked List.

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
	struct node *temp;
	int ele;
	temp=(struct node*)malloc(sizeof(struct node *));
	if(temp==NULL)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d",&ele);
		temp->e=ele;
		temp->next=head;
		head=temp;
		printf("\nNode inserted\n");
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
			head=temp;
			printf("\nNode Inserted\n");
		}
		else
		{
			newnode=head;
			while(newnode->next!=NULL)
			{
				newnode=newnode->next;
			}
			newnode->next=temp;
			temp->next=NULL;
			printf("\nNode Inserted\n");
		}
	}
}
void insert_at_pos()
{
	int i,ele,loc;
	struct node *temp,*temp1;
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
		printf("Enter the location: ");
		scanf("%d",&loc);
		temp1=head;
		for(i=0;i<loc;i++)
		{
			temp1=temp1->next;
			if(temp1==NULL)
			{
				printf("\nCannot Insert\n");
				return;
			}
		}
		temp->next=temp1->next;
		temp1->next=temp;
		printf("\nNode Inserted\n");
		
	}
}
void delete_at_start()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("\nNode deleted from begining\n");
	}
}
void delete_at_end()
{
	struct node *temp,*temp1;
	if(head==NULL)
	{
		printf("\nList is empty\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nOnly node of the list deleted...\n");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=NULL;
		free(temp);
		printf("\nDeleted Node from the last\n");
	}
}
void delete_at_pos()
{
	struct node *temp,*temp1;
	int i,loc;
	printf("Enter the location: ");
	scanf("%d",&loc);
	temp=head;
	for(i=0;i<loc;i++)
	{
		temp1=temp;
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\nCannot Delete\n");
			return;
		}
	}
	temp1->next=temp->next;
	free(temp);
	printf("\nDeleted Node: %d",loc+1);
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
				printf("Item found at location:%d",i+1);
				flag=0;
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
			printf("\nElement not found\n");
		}
	}
}
void display()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Nothing to print\n");
	}
	else
	{
		printf("\nPrinting the values...\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->e);
			temp=temp->next;
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n 1.Insert at the begining\n 2.Insert at the end\n 3.Insert at a position\n 4.Delete at the begining\n 5.Delete at the end\n 6.Delete at a position\n 7.Display\n 8.Search\n 9.Exit\n");
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
				delete_at_start();
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
				printf("Invalid option\n");
				break;
		}
	}while(ch!=9);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
