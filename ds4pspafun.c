//Implementation of stack on pointer structure,pointer array with functions.

#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int *arr;
	int top;
	int max;
};
void push(struct stack *s)
{
	if(s->top==s->max-1)
	{
		printf("The stack is full\n");
	}
	else
	{
		s->top++;
		int ele;
		printf("Enter the element: ");
		scanf("%d",&ele);
		s->arr[s->top]=ele;
	}
}
void pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("%d",s->arr[s->top]);
		s->top--;
	}
}
void display(struct stack *s)
{
	printf("the elements in the stack:\n");
	for(int i=s->top;i>=0;i--)
	{
		printf("%d\n",s->arr[i]);
	}
}
void main()
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	printf("Enter the size of the stack: ");
	scanf("%d",&s->max);
	s->arr=(int *)malloc(s->max*sizeof(int));
	int op;
	do
	{
		printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				push(s);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				printf("Exited from stack\n");
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	}while(op!=4);
}

//Done By VEERAKOTI.VAMSHI KRISHNA {B171579}
