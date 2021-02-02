//Implementation of stack on structure with functions.

#include <stdio.h>
struct stack{
	int a[100];
	int top;
	int max;
};
struct stack push(struct stack s){
	if(s.top==s.max-1)
	{
		printf("The stack is full");
		return s;
	}
	else
	{
		s.top++;
		int ele;
		printf("Enter the element: ");
		scanf("%d",&ele);
		s.a[s.top]=ele;
		return s;
	}
}
struct stack pop(struct stack s){
	if(s.top==-1)
	{
		printf("The stack is empty: ");
		return s;
	}
	else
	{
		printf("%d\n",s.a[s.top]);
		s.top=s.top-1;
		return s;
	}
}
struct stack display(struct stack s){
	printf("The elements in stack are:\n");	
	for(int i=s.top;i>=0;i--)
	{
		printf("%d\n",s.a[i]);	
	}
}
void main()
{
	struct stack s;
	s.top=-1;
	printf("Enter the size: ");
	scanf("%d",&s.max);
	int op;
	do{
		printf("\n 1.Push\n 2.Pop\n 3.display\n 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				s=push(s);
				break;
			case 2:
				s=pop(s);
				break;
			case 3:
				s=display(s);
				break;
			case 4:
				printf("Exited the program\n");
				break;
			default:
				printf("Invalid option");
				break;
		}
	}while(op!=4);
}

//Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
