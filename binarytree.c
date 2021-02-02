//Implementation of Binary Tree.

#include <stdio.h>
#include <stdlib.h>

struct tnode
{
	int e;
	struct tnode *left;
	struct tnode *right;
};

struct queue
{
	int f,r;
	struct tnode *a[50];
};

struct queue *q;
struct queue* enqueue(struct queue *q,struct tnode *ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}
struct tnode* dequeue(struct queue *q)
{
	q->f++;
	return q->a[q->f];
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	return 0;
}
struct tnode* insert(struct tnode *root,int ele)
{
	if(root==NULL)
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		struct tnode *temp,*temp1;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		temp->e=ele;
		temp->right=NULL;
		temp->left=NULL;

		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			else
			{
				break;
			}
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->right);
			}
			else
			{
				break;
			}
		}
		if(temp1->left==NULL)
		{
			temp1->left=temp;
		}
		else
		{
			temp1->right=temp;
		}

	}
	return root;
}

void display(struct tnode *root)
{
	if(root==NULL)
	{
		printf("\nTree Is empty\n");
	}
	else
	{
		struct tnode *temp1;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->right);
			}
			printf("%d,",temp1->e);
		}
	}
	printf("\n");
}

struct tnode* finde(struct tnode *root,int ele)
{
	struct tnode *temp1;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			if(temp1->e==ele)
			{
				return temp1;
			}
		}
}
struct tnode* findLast(struct tnode *root)
{
	struct tnode *temp2;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
			q=enqueue(q,root);
		while(!isempty(q))
		{
			temp2=dequeue(q);
			if(temp2->left!=NULL)
			{
				q=enqueue(q,temp2->left);
			}

			if(temp2->right!=NULL)
			{
				q=enqueue(q,temp2->right);
			}
	}
	return temp2;
}
struct tnode* findparent(struct tnode *root,struct tnode *temp)
{
	struct tnode *k;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			k=dequeue(q);

			if(k->left==temp)
			{
				return k;
			}
			else
			{
				if(k->left!=NULL)
				{
					q=enqueue(q,k->left);
				}

			}
			if(k->right==temp)
			{
				return k;
			}
			else
			{
				if(k->right!=NULL)
				{
					q=enqueue(q,k->right);
				}
			}
	}
}

int del(struct tnode *root)
{
    struct tnode *temp1,*temp2;
	if(root==NULL)
	{
		printf("element cannot be removed");
	}
	else
	{
		int ele;
		struct tnode *temp;
		printf("what element you want to delete:");
		scanf("%d",&ele);
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		temp1=finde(root,ele);
		temp2=findLast(root);
		temp=findparent(root,temp2);
		temp1->e=temp2->e;
		if(temp->left==temp2)
			temp->left=NULL;
		else
			temp->right=NULL;
	}
}
int main()
{
	struct node *root=NULL;
	int ch,ele;
	do
	{
		printf("\n 1.Insert\n 2.Display\n 3.Delete\n 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d",&ele);
				root=insert(root,ele);
				break;
			case 2:
				display(root);
				break;
			case 3:
				del(root);
				break;
			case 4:
				printf("\nExited from the program\n");
				break;
			default:
				printf("\nInvalid Choice\n");
		}
	}while(ch!=4);
}

//Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
