//Implementation of Queue on Structure with function.

#include <stdio.h>
int op,ele;
struct queue
{
	int a[100];
	int front;
	int rear;
	int max;
};
struct queue enqueue(struct queue s)
{
	if(s.rear==s.max-1)
	{
		printf("The Queue is full\n");
	}
	else
	{
		s.rear++;
		printf("Enter the element: ");
		scanf("%d",&ele);
		s.a[s.rear]=ele;
		return s;
	}
}
struct queue dequeue(struct queue s)
{
	if(s.rear==s.front)
	{
		printf("The Queue is Empty\n");
	}
	else
	{
		s.front++;
		printf("The Dequeued element is:%d\n",s.a[s.front]);
		return s;
	}
}
void main()
{
	struct queue s;
	s.front=-1;
	s.rear=-1;
	printf("Enter the size: ");
	scanf("%d",&s.max);
	do
	{
		printf("\n 1.EnQueue\n 2.DeQueue\n 3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				s=enqueue(s);
				break;
			case 2:
				s=dequeue(s);
				break;
			case 3:
				printf("Exited from the Program\n");
				break;
			default:
				printf("Invalid OPtion\n");
				break;
		}

	}while(op!=3);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
