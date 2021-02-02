// implementation of stack on array with functions.

#include <stdio.h>
int stack[100],ch,s,top,ele,i;
void push(void);
void pop(void);
void display(void);
int main()
{
	top=-1;
	printf("Enter the size of the stack has to be less than 100: ");
	scanf("%d",&s);
	printf("\n Available Stack operations using Arrays are:\n");
	printf(" 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
	do{
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
			{
				printf("Exited from the Stack\n");
				break;
			}
			default:
			{
				printf("Enter the proper option\n");
			}
		}
	}
	while(ch!=4);
	return 0;
}
void push()
{
	if(top>=s-1)
	{
		printf("The stack is over flowing\n");
	}
	else
	{
		printf("Enter the value to push: ");
		scanf("%d",&ele);
		top++;
		stack[top]=ele;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("\nThe stack is under flow\n");
	}
	else
	{
		printf("\nThe popped element is:%d\n",stack[top]);
		top--;
	}
}
void display()
{
	if(top>=0)
	{
		printf("\n The elements in the stack are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
	else
	{
		printf("\n The stack is empty\n");
	}
}

//Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
