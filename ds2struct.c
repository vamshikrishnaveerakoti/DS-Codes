//implementation of stack on structures.

#include <stdio.h>
struct stack{
	int a[100];
	int top;
	int max;
};
void main()
{
	struct stack s;
	s.top=-1;
	printf("Enter the size: ");
	scanf("%d",&s.max);
	int op;
	do{
		printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				if(s.top==s.max-1)
				{
					printf("The stack is full");
				}
				else
				{
					s.top++;
					int ele;
					printf("Enter the element: ");
					scanf("%d",&ele);
					s.a[s.top]=ele;
				}
				break;
			case 2:
				if(s.top==-1)
				{
					printf("The stack is empty: ");
				}
				else
				{
					printf("%d\n",s.a[s.top]);
					s.top=s.top-1;
				}
				break;
			case 3:
				printf("The elements in stack are:\n");	
				for(int i=s.top;i>=0;i--)
				{
					printf("%d\n",s.a[i]);	
				}
				break;
			case 4:
				printf("The program is exited\n");
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	}while(op!=4);
}

//Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
