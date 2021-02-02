//Implementation of Queue on Queue on Array.

#include <stdio.h>
void main()
{
	int max,op,ele;
	int f=-1;
	int r=-1;
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
				if(r==max-1)
				{
					printf("The Queue is full\n");
				}
				else
				{
					r++;
					printf("Enter the element: ");
					scanf("%d",&ele);
					a[r]=ele;	
				}
				break;
			case 2:
				if(r==f)
				{
					printf("The Queue is Empty\n");
					
				}
				else
				{
					f++;
					printf("The DeQueued Element is:%d\n",a[f]);
				}
				break;
			case 3:
				printf("Exited from Queue\n");
				break;
			default:
				printf("Invalid Option\n");
				break;
		}
	}while(op!=3);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
