//Infix to Prefix

#include<stdio.h>
#include<string.h>
#include<math.h>

char prefix[50], stack[50];
int top = -1;

void push(char sym)
{
	top++;
	stack[top] = sym;
}


char pop()
{
	char c;
	c = stack[top];
	top--;
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
					push(symbol);
					break;
					
			case '(':
					temp = pop();
					while (temp != ')')
					{
						prefix[pos] = temp;
						pos++;
						temp = pop();
					}
					break;
					
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
					while (prec(stack[top]) >= prec(symbol))
					{
						temp = pop();
						prefix[pos] = temp;
						pos++;
					}
					push(symbol);
					break;
					
			default:
					prefix[pos] = symbol;
					pos++;
					break;
		}
	}
	
	while (top >= 0)
	{
		temp = pop();
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
	double x, y;
	char symbol;
	
	len = strlen(prefix);
	
	for (i=len-1 ; i>=0 ; i--)
	{
		symbol = prefix[i];
		switch(symbol)
		{
			case '+':
					y = pop();
					x = pop();
					push(y + x);
					break;
					
			case '-':
					y = pop();
					x = pop();
					push(y - x);
					break;

			case '*':
					y = pop();
					x = pop();
					push(y * x);
					break;		

			case '/':
					y = pop();
					x = pop();
					push(y / x);
					break;
					
			case '^':
					y = pop();
					x = pop();
					push(pow(y,x));
					break;

			default:
					push(symbol-'0');
					break;
		}
	}
	double c = pop();
	printf("\nThe value of the expression is,\n%f", c);
}


void main()
{
	char infix[50];
	
	printf("\nInfix to Prefix Conversion\n");
	printf("\nEnter the infix expression: ");
	scanf("%s", infix);
	printf("\nThe prefix expression is,\n");
	infix_to_prefix(infix);
	evaluate_prefix(prefix);
}