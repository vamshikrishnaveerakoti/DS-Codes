//Implementation of Queue on structure.

#include <stdio.h>
struct queue
{
	int a[100];
	int front;
	int rear;
	int max;
};
void main()
{
	struct queue s;
	s.front=-1;
	s.rear=-1;
	printf("Enter the size: ");
	scanf("%d",&s.max);
	int op,ele;
	do
	{
		printf("\n 1.EnQueue\n 2.DeQueue\n 3.Exit\n");
		printf("Enter your option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				if(s.rear==s.max-1)
				{
					printf("The Queue is Full\n");
				}
				else
				{
					s.rear++;
					printf("Enter the element to EnQueue: ");
					scanf("%d",&ele);
					s.a[s.rear]=ele;
				}
				break;
			case 2:
				if(s.rear==s.front)
				{
					printf("The Queue is Empty\n");
				}
				else
				{
					s.front++;
					printf("The Dequeued element is:%d\n",s.a[s.front]);
				}
				break;
			case 3:
				printf("Exiting from the Queue\n");
				break;
			default:
				printf("Invalid OPtion\n");
				break;
		}
	}while(op!=3);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
