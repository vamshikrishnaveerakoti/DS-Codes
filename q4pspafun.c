//Implementation of Queue on Pointer structure,pointer array with function.

#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int *a;
	int f;
	int r;
	int max;
};
void enqueue(struct queue *s)
{
	if(s->r==s->max-1)
	{
		printf("The Queue is full\n");
	}
	else
	{
		s->r++;
		int ele;
		printf("Enter the element: ");
		scanf("%d",&ele);
		s->a[s->r]=ele;
	}
}
void dequeue(struct queue *s)
{
	if(s->r==s->f)
	{
		printf("The Queue is Empty\n");
	}
	else
	{
		s->f++;
		printf("The DeQueued element is:%d\n",s->a[s->f]);
	}
}
void main()
{
	struct queue *s;
	s=(struct queue*)malloc(sizeof(struct queue));
	s->f=-1;
	s->r=-1;
	printf("Enter the size of the queue: ");
	scanf("%d",&s->max);
	s->a=(int *)malloc(s->max*sizeof(int));
	int op;
	do
	{
		printf("\n 1.EnQueue\n 2.DeQueue\n 3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				enqueue(s);
				break;
			case 2:
				dequeue(s);
				break;
			case 3:
				printf("Exited from Program\n");
				break;
			default:
				printf("Invalid Entry\n");
				break;
		}
	}while(op!=3);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
