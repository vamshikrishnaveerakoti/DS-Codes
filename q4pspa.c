//Implementation of Queue on pointer structure,pointer array.

#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int *a;
	int r;
	int f;
	int max;
};
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
				if(s->r==s->max-1)
				{
					printf("The Queue is Full\n");
				}
				else
				{
					s->r++;
					int ele;
					printf("Enter the element: ");
					scanf("%d",&ele);
					s->a[s->r]=ele;
				}
				break;
			case 2:
				if(s->r==s->f)
				{
					printf("The Queue is Empty\n");
				}
				else
				{
					s->f++;
					printf("The DeQueued element is:%d\n",s->a[s->f]);
				}
				break;
			case 3:
				printf("Program Exited\n");
				break;
			default:
				printf("Invalid Option\n");
				break;
		}
	}while(op!=3);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
