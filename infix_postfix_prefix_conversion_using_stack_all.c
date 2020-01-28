/*
	Program for Infix, Postfix, Prefix Conversion using Stack.
*/




#include<stdio.h>
#include<string.h>
int top=-1;
char stack[20][20],stack1[20];
void posttoin(char stack[20][20],char exp[20],int top)
{
	int i,len;
	char op1[20],op2[20],str[20],s1[20],test[20];
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'|| exp[i]=='^')
		{
			strcpy(op2,stack[top]);
			top--;
			strcpy(op1,stack[top]);
			top--;
			strcpy(str,"");
			str[0]='(';
			str[1]='\0';
			strcat(str,op1);
			len=strlen(str);
			str[len]=exp[i];
			str[len+1]='\0';
			strcat(str,op2);
			len=strlen(str);
			str[len]=')';
			str[len+1]='\0';
			top++;
			strcpy(stack[top],str);
		}
		else
		{
			strcpy(s1,"");
			top++;
			s1[0]=exp[i];
			s1[1]='\0';
			strcpy(stack[top],s1);	
		}
	}
	strcpy(test,stack[top]);
	top--;
	printf("%s",test);
	printf("\n");
}
char icp(char ch)
{
	if(ch=='(')
	return 5;
	else if(ch=='+' || ch=='-')
	return 1;
	else if(ch=='*' || ch=='/')
	return 2;
	else if(ch=='^')
	return 4;
	else
	return -1;

}
int isp(char ch)
{
	if(ch=='(')
	return 0;
	else if(ch=='+' || ch=='-')
	return 1;
	else if(ch=='*' || ch=='/')
	return 2;
	else if(ch=='^')
	return 3;
	else
	return -1;
}
char pop(){
    char temp;
    temp=stack1[top];
    top--;
    return(temp);
}



void infixtopostfix(char str[20])
{
    char postfix[20];
    int k=0;
    char ch;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')                                        //push whenever opening brace
        {
            top++;
            stack1[top]='(';
        }
        else if(str[i]==')')
        {
            while((ch=pop())!='(')
            {
                postfix[k]=ch;                                //pop till you get opening brace
                k++;
            }
        }
        else if(str[i]=='+' ||str[i]=='-' ||str[i]=='*' ||str[i]=='/' ||str[i]=='^')
        {
            while(top>=0 && isp(stack1[top])>=icp(str[i]))
            {
                postfix[k]=pop();
                k++;
            }
            top++;
            stack1[top]=str[i];
        }
        else
        {
            postfix[k]=str[i];
            k++;
        }
    }
    while(top>=0)
    {
        postfix[k]=pop();
       
        k++;
       
    }
    printf("\n%s",postfix);
}


void intopre(char stack[20],char exp[20],int top)
{
	int i,k=0,ch,len,j=0,l=0;
	len=strlen(exp);
	char post[20],expr[20],pre[20];
	strcpy(stack,"");
	strcpy(post,"");
	strcpy(pre,"");
	for(i=0;i<len;i++)
	{
		if(exp[i]=='(')
		{
			exp[i]=')';
		}		
		else if(exp[i]==')')
		{		
			exp[i]='(';
		}	
	}
	for(i=len-1;i>=0;i--)
	{
		expr[j]=exp[i];
		j++;
	}
	expr[j]='\0';
	for(i=0;expr[i]!='\0';i++)
	{
		if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' )
		{
			if(icp(stack[top])>=isp(expr[i]) && top>=0)
			{
					post[k]=pop(stack,top);
					k++;
					stack[top]=expr[i];
			}
			else
			{
				top++;
				stack[top]=expr[i];
			}
		}
		else if(expr[i]=='(')
		{
			top++;
			stack[top]=expr[i];
		}
		else if(expr[i]==')')
		{
			while((ch=pop(stack,top))!='(' && top>=0)
			{
				post[k]=ch;
				k++;
				top--;
			}
			top--;
		}
		else
		{
			post[k]=expr[i];
			k++;
		}
	}
	while(top>=0)
	{
		post[k]=pop(stack,top);
		k++;
		top--;
	}
	post[k]='\0';
	len=strlen(post);
	for(i=len-1;i>=0;i--)
	{
		pre[l]=post[i];
		l++;
	}
	pre[l]='\0';
	printf("%s",pre);
}
void pretoin(char stack[20][20],char exp[20],int top)
{
	int i,len,length;
	char op1[20],op2[20],str[20],s1[20],test[20];
	length=strlen(exp);
	for(i=length-1;i>=0;i--)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'|| exp[i]=='^')
		{
			strcpy(op1,stack[top]);
			top--;
			strcpy(op2,stack[top]);
			top--;
			strcpy(str,"");
			str[0]='(';
			str[1]='\0';
			strcat(str,op1);
			len=strlen(str);
			str[len]=exp[i];
			str[len+1]='\0';
			strcat(str,op2);
			len=strlen(str);
			str[len]=')';
			str[len+1]='\0';
			top++;
			strcpy(stack[top],str);
		}
		else
		{
			strcpy(s1,"");
			top++;
			s1[0]=exp[i];
			s1[1]='\0';
			strcpy(stack[top],s1);	
		}
	}
	strcpy(test,stack[top]);
	top--;
	printf("%s",test);
	printf("\n");
}
void posttopre(char stack[20][20],char exp[20],int top)
{
	int i,len;
	char op1[20],op2[20],str[20],s1[20],test[20];
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
		{
			strcpy(op2,stack[top]);
			top--;
			strcpy(op1,stack[top]);
			top--;
			strcpy(str,"");
			str[0]=exp[i];
			str[1]='\0';
			strcat(str,op1);
			len=strlen(str);
			str[len]='\0';
			strcat(str,op2);
			len=strlen(str);
			str[len]='\0';
			top++;
			strcpy(stack[top],str);
		}
		else
		{
			strcpy(s1,"");
			top++;
			s1[0]=exp[i];
			s1[1]='\0';
			strcpy(stack[top],s1);	
		}
	}
	strcpy(test,stack[top]);
	top--;
	printf("%s",test);
	printf("\n");
}
void pretopost(char stack[20][20],char exp[20],int top)
{
	int i,len,length;
	char op1[20],op2[20],str[20],s1[20],test[20];
	length=strlen(exp);
	for(i=length-1;i>=0;i--)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'|| exp[i]=='^')
		{
			strcpy(op1,stack[top]);
			top--;
			strcpy(op2,stack[top]);
			top--;
			strcpy(str,"");
			strcat(str,op1);
			len=strlen(str);
			str[len]='\0';
			strcat(str,op2);
			len=strlen(str);
			str[len]=exp[i];
			str[len+1]='\0';
			top++;
			strcpy(stack[top],str);
		}
		else
		{
			strcpy(s1,"");
			top++;
			s1[0]=exp[i];
			s1[1]='\0';
			strcpy(stack[top],s1);	
		}
	}
	strcpy(test,stack[top]);
	top--;
	printf("%s",test);
	printf("\n");
}
int main()
{
	char expr[20];
	int ch;
	while(ch!=7)
	{
		printf("\n1:Postfix to infix\n2:Prefix to infix\n3:Infix to Postfix\n4:Infix to prefix\n5:Postfix to Prefix\n6:Prefix to Postfix\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the postfix Expression:\n");
					scanf("%s",expr);
					printf("Infix notation:\n");
					posttoin(stack,expr,top);
			break;
			case 2:printf("Enter the prefix Expression:\n");
					scanf("%s",expr);
					printf("Infix notation:\n");
					pretoin(stack,expr,top);
			break;
			case 3:printf("Enter the infix Expression:\n");
					scanf("%s",expr);
					printf("Postfix notation:\n");
					infixtopostfix(expr);
			break;
			case 4:printf("Enter the infix Expression:\n");
					scanf("%s",expr);
					printf("Prefix notation:\n");
					intopre(stack1,expr,top);
			break;
			case 5:printf("Enter the postfix Expression:\n");
					scanf("%s",expr);
					printf("Prefix notation:\n");
					posttopre(stack,expr,top);
			break;
			case 6:printf("Enter the prefix Expression:\n");
					scanf("%s",expr);
					printf("Postfix notation:\n");
					pretopost(stack,expr,top);
			break;
		}
	}
}