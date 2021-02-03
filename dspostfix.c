#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int a[100];
	int top;
	int max;
};

char push(struct stack *s,char c)
{
	if(s->top==s->max-1)
	{
		printf("The Stack is full\n");
	}
	else
	{
		s->top++;
		s->a[s->top]=c;
	}
}

char pop(struct stack *s)
{
	char c;
	if(s->top==-1)
	{
		printf("THe Stack is Empty\n");
	}
	else
	{
		c=s->a[s->top--];
		return c;
	}
}

char top(struct stack *s)
{
	if(s->top==0)
		return '(';
	else
		return s->a[s->top];
}

int isempty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int prior(char c)
{
	if(c=='(')
		return 0;
	else if(c=='^')
		return 1;
	else if(c=='+'||c=='-')
		return 2;
	else if(c=='*'||c=='/')
		return 3;
	else
		return 4;
}

char main()
{
	char exp[100];
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	printf("Enter the expression: ");
	scanf("%s",exp);
	char *e;
	e=exp;
	s->top=0;
	s->max=20;
	while(*e!='\0')
	{
		if(*e=='(')
		{
			push(s,*e);
		}
		else if(*e=='+' || *e=='-' || *e=='*' || *e=='/' || *e=='^')
		{
			while(prior(top(s))>=prior(*e))
			{
				printf("%c",pop(s));
			}
			push(s,*e);
		}
		else if(*e==')')
		{
			while(top(s)!='(')
			{
				printf("%c",pop(s));
			}
			pop(s);
		}
		else
		{
			printf("%c",*e);
		}
		e++;
	}
	while(!isempty(s))
	{
		printf("%c",pop(s));
		printf("\n");
	}
}
