#include<stdio.h>
#include<string.h>

int top=-1;
char infix[50],postfix[50],prefx[50],stack[50];
char s[50][50];
int isempty();
int isfull();
void push(int item);
char pop();
void Pop(char s[50][50],char str[50]);
void Push(char s[50][50],char str[50]);
void infix_postfix();
void prefx_postfix(char prefx[50]);
void postfix_prefx(char postfix[50]);
void main()
{
   int o;
   do
      {
        printf("\t\t\tMENU");
        printf("\n1.Infix to postfix\n2.Prefix to postfix\n3.postfix to prefix\n4.Exit");
        scanf("%d",&o);
        switch(o)
        {
          case 1:
   	 printf("\nEnter the infix expression: ");
   	 scanf("%s",infix);
   	 infix_postfix();
   	 break;

    case 2:
   	 printf("\nEnter the prefix expression: ");
   	 scanf("%s",prefx);
   	 prefx_postfix(prefx);
   	 break;

    case 3:
    	 printf("\nEnter the postfix expression: ");
    	 scanf("%s",postfix);
    	 postfix_prefx(postfix);
    	 break;
    case 4:
          {
             printf("\n\t EXIT POINT ");
             break;
          }

     default:
   	 printf("\nInvalid option");
     }
  }
   while(o!=4);
    return 0;
}

int isempty()
{
	if(top==-1)
	  return 1;
	else
	  return 0;
}
int isfull()
{
	if(top>50)
		return 1;
	else
		return 0;
}
void Push(char s[50][50],char str[50])
{
  int st;
  st=isfull();
  if(st==1)
  printf("\nStack is full !");
  else
  strcpy(s[++top],str);
}

void Pop(char s[50][50],char str[50])
{
  int st;
  st=isempty();
  if(st==1)
  printf("\nStack is empty !");
  else
  strcpy(str,s[top--]);
}

void push(int item)
{
	int st;
	st=isfull();
	if(st==1)
		printf("\nStack is full !");
	else
	{
		top++;
    	stack[top]=item;
	}
}
char pop()
{
	int st;
	char var;
	st=isempty();
	if(st==1)
		printf("\nStack is empty !");
	else
	{
		var=stack[top];
		top--;
	}
   return var;
}
int icp(char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/')
		return 2;
	if(ch=='^')
		return 3;
	if(ch=='(')
		return 4;
	else
		return 0;
}
int isp(char ch)
	{
		if(ch=='+' || ch=='-')
			return 1;
		if(ch=='*' || ch=='/')
			return 2;
		if(ch=='^')
			return 3;
		else
			return 0;
}

void infix_postfix()
{
	int i,j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalpha(infix[i])!=0)
    {
      postfix[j]=infix[i];
      j++;
    }
    else if(infix[i]==')')
    {
      while(stack[top]!='(')
      {
	postfix[j]=pop();
	j++;
      }
      top--;
    }
    if(isalpha(infix[i])==0 && infix[i]!=')')
    {
      while(icp(infix[i])<=isp(stack[top]))
      {
	postfix[j]=pop();
	j++;
		if(top==-1)
	break;
      }
      push(infix[i]);
    }
  }
    if(infix[i]=='\0')
    {
      while(!isempty())
      {
	postfix[j]=pop();
	j++;
      }
    }
    postfix[j]='\0';
    printf("\nThe postfixfix expression is : ") ;
    for(j=0;postfix[j]!='\0';j++)
      printf("%c",postfix[j]);
}

void prefx_postfix(char prefx[50])
{
  char var[50],var1[50],var2[50];
  int i,l;
  l=strlen(prefx);
  for(i=l-1;i>=0;i--)
  {
    if(isalpha(prefx[i])!=0)
    {
      var[0]=prefx[i];
      var[1]='\0';
      Push(s,var);
    }
    else
    {
       Pop(s,var);
       Pop(s,var1);
       var2[0]=prefx[i];
       var2[1]='\0';
       strcpy(postfix,var1);
       strcat(postfix,var);
       strcat(postfix,var2);
       Push(s,postfix);
    }
  }
    Pop(s,postfix);
    printf("\nThe postfix expression is: ");
    printf("\n%s",postfix);
}
void postfix_prefx(char postfix[50])
{
  char Temp[50],Temp1[50],Temp2[50];
  int i;
  for(i=0;postfix[i]!='\0';i++)
  {
    if(isalpha(postfix[i])!=0)
    {
      Temp[0]=postfix[i];
      Temp[1]='\0';
      Push(s,Temp);
    }
    else
    {
       Pop(s,Temp);
       Pop(s,Temp1);
       Temp2[0]=postfix[i];
       Temp2[1]='\0';
       strcpy(prefx,Temp2);
       strcat(prefx,Temp);
       strcat(prefx,Temp1);
       Push(s,prefx);
    }
  }
    Pop(s,prefx);
    printf("\nThe prefix expression is: ");
    printf("\n%s",prefx);
}






/*-------------------------------result----------------------------------------------
 * 			MENU
1.Infix to postfix
2.Prefix to postfix
3.postfix to prefix
4.Exit1

Enter the infix expression: a+b

The postfixfix expression is : ab+			MENU
1.Infix to postfix
2.Prefix to postfix
3.postfix to prefix
4.Exit2

Enter the prefix expression: +ab

The postfix expression is: ba+
			MENU
1.Infix to postfix
2.Prefix to postfix
3.postfix to prefix
4.Exit3

Enter the postfix expression: ab+

The prefix expression is: +ba
			MENU
1.Infix to postfix
2.Prefix to postfix
3.postfix to prefix
4.Exit4

	 EXIT POINT
 */

