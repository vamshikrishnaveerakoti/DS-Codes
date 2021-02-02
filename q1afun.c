//Implementation of Queue on Array with functions

#include <stdio.h>
int a[100],op,ele,f,r,i,max;
void enqueue(void);
void dequeue(void);
void main()
{
	f=-1;
	r=-1;
	printf("Enter the size of the queue: ");
	scanf("%d",&max);
	int a[max];
	do
	{
		printf("\n 1.EnQueue\n 2.DeQueue\n 3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printf("Exited from the Queue\n");
				break;
			default:
				printf("Invalid Option\n");
				break;
		}
	}while(op!=3);
}
void enqueue()
{
	if(r==max-1)
	{
		printf("The Queue is Full\n");
	}
	else
	{
		r++;
		printf("Enter the element: ");
		scanf("%d",&ele);
		a[r]=ele;
	}
}
void dequeue()
{
	if(r==f)
	{
		printf("The Queue is Empty\n");
	}
	else
	{
		f++;
		printf("The element deQueued is:%d\n",a[f]);
	}
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
