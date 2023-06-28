//Infix to Postfix and Prefix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char postfix[50], stack_c[50], prefix[50];
int top_c = -1, top_e = -1;
float stack_e[50];

void push_c(char sym)
{
	top_c++;
	stack_c[top_c] = sym;
}


char pop_c()
{
	char c;
	c = stack_c[top_c];
	top_c--;
	return c;
}

void push_e(float sym)
{
	top_e++;
	stack_e[top_e] = sym;
}


float pop_e()
{
	float c;
	c = stack_e[top_e];
	top_e--;
	return c;
}

	
int prec(char sym)
{
	if (sym == '^')
		return 3;
		
	else if ((sym == '*') || (sym == '/'))
		return 2;
		
	else if ((sym == '+') || (sym == '-'))
		return 1;
		
	else
		return 0;
}


void infix_to_postfix(char infix[])
{
	int len, i = 0, pos = 0;
	char symbol, temp;
	
	len = strlen(infix);
	
	while (i < len)
	{
		symbol = infix[i];
		switch(symbol)
		{
			case '(':
					push_c(symbol);
					break;
					
			case ')':
					temp = pop_c();
					while (temp != '(')
					{
						postfix[pos] = temp;
						pos++;
						temp = pop_c();
					}
					break;
					
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
					while (prec(stack_c[top_c]) >= prec(symbol))
					{
						temp = pop_c();
						postfix[pos] = temp;
						pos++;
					}
					push_c(symbol);
					break;
					
			default:
					postfix[pos] = symbol;
					pos++;
					break;
		}
		i++;
	}
	
	while (top_c >= 0)
	{
		temp = pop_c();
		postfix[pos] = temp;
		pos++;
	}

	postfix[pos++] = '\0';
	puts(postfix);
}

void evaluate_postfix(char postfix[])
{
	int len, i;
	float x, y;
	char symbol;
	
	len = strlen(postfix);
	
	for (i=0 ; i<len ; i++)
	{
		symbol = postfix[i];
		switch(symbol)
		{
			case '+':
					y = pop_e();
					x = pop_e();
					push_e(x + y);
					break;
					
			case '-':
					y = pop_e();
					x = pop_e();
					push_e(x - y);
					break;

			case '*':
					y = pop_e();
					x = pop_e();
					push_e(x * y);
					break;		

			case '/':
					y = pop_e();
					x = pop_e();
					push_e(x / y);
					break;
					
			case '^':
					y = pop_e();
					x = pop_e();
					push_e(pow(x,y));
					break;

			default:
					push_e(symbol-'0');
					break;
		}
	}
	float c = pop_e();
	printf("\nThe value of the expression is,\n%f\n", c);
}

void infix_to_prefix(char infix[])
{
	int len, i, j, pos = 0;
	char symbol, temp, ch;
	
	len = strlen(infix);
	
	for (i=len-1 ; i>=0 ; i--)
	{
		symbol = infix[i];
		switch(symbol)
		{
			case ')':
					push_c(symbol);
					break;
					
			case '(':
					temp = pop_c();
					while (temp != ')')
					{
						prefix[pos] = temp;
						pos++;
						temp = pop_c();
					}
					break;
					
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
					while (prec(stack_c[top_c]) > prec(symbol))
					{
						temp = pop_c();
						prefix[pos] = temp;
						pos++;
					}
					push_c(symbol);
					break;
					
			default:
					prefix[pos] = symbol;
					pos++;
					break;
		}
	}
	
	while (top_c >= 0)
	{
		temp = pop_c();
		prefix[pos] = temp;
		pos++;
	}

	prefix[pos++] = '\0';
	
	for (i=0,j=pos-2 ; i<j ; i++,j--)
	{
		ch = prefix[i];
		prefix[i] = prefix[j];
		prefix[j] = ch;
	}
	puts(prefix);
}


void evaluate_prefix(char prefix[])
{
	int len, i;
	float x, y;
	char symbol;
	
	len = strlen(prefix);
	
	for (i=len-1 ; i>=0 ; i--)
	{
		symbol = prefix[i];
		switch(symbol)
		{
			case '+':
					y = pop_e();
					x = pop_e();
					push_e(y + x);
					break;
					
			case '-':
					y = pop_e();
					x = pop_e();
					push_e(y - x);
					break;

			case '*':
					y = pop_e();
					x = pop_e();
					push_e(y * x);
					break;		

			case '/':
					y = pop_e();
					x = pop_e();
					push_e(y / x);
					break;
					
			case '^':
					y = pop_e();
					x = pop_e();
					push_e(pow(y,x));
					break;

			default:
					push_e(symbol-'0');
					break;
		}
	}
	float c = pop_e();
	printf("\nThe value of the expression is,\n%f\n", c);
}
	
void main()
{
	char infix[50];
	int ch;
	
	printf("\nEnter the infix expression: ");
	scanf("%s", infix);
		
	while (1)
	{	
		printf("\nMain Menu:");
		printf("\n1: Convert to Postfix Expression");
		printf("\n2: Evaluation of Postfix Expression");
		printf("\n3: Convert to Prefix Expression");
		printf("\n4: Evaluation of Prefix Expression");
		printf("\n5: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
					printf("\nThe postfix expression is,\n");
					infix_to_postfix(infix);
					break;
					
			case 2:
					evaluate_postfix(postfix);
					break;
				
			case 3:
					printf("\nThe prefix expression is,\n");
					infix_to_prefix(infix);
					break;
					
			case 4:
					evaluate_prefix(prefix);
					break;
					
			case 5:
					exit(0);
				
			default:
					printf("\nPlease enter a valid choice");
		}
	}
}	
	
		