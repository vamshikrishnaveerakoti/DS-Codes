//Implementation of stack on array.


#include <stdio.h>
int main()
{
	int s,ch;
	int ele;
	printf("Enter the size of the stack: ");
	scanf("%d",&s);
	int stack[s];
	int top=-1;
	printf("\n Stack Operations using an Integer Array.\n");
	printf(" Please select the choices\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n\n");
	do{
		printf("Enter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				if(top>=s-1){
					printf("\n Stack is overflowing");}
				else{
					printf("Enter the element: ");
					scanf("%d",&ele);
					top++;
					stack[top]=ele;}
				break;
			}
			case 2:
			{
				if(top<=-1){
					printf("\n Stack is underflow\n");}
				else{
					printf("Popped element is: %d\n",stack[top]);
					top--;}
				break;
			}
			case 3:
			{
				if(top>=0){
					printf("\n Elements in the STACK are:\n");
					for(int i=top;i>=0;i--){
						printf("%d,",stack[top]);}}
				else{
					printf("The stack is empty\n");}
				break;

			}
			default:
			{
				printf("Enter the valid option\n");
			}
		}
	}while(ch!=4);
		return 0;
}


// Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
