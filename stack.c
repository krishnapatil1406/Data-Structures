#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int top=-1;
int MAXSIZE = 50;
char stack[50];

int isFull()
{  
	if (top == MAXSIZE-1) 
		return 1 ;
	else 
		return 0 ;
}


void push (char item)
{
  if ( ! isFull() )
  {
    top=top+1;
    stack[top]=item;
  }
}

int isEmpty()
{
  if (top == -1) 
    return 1 ;
  else 
    return 0 ;
}

char  pop()
{ char temp;
  if ( ! isEmpty() )
  {
    temp=stack[top];
    top=top-1;
    return (temp);
  }
}

int main ()
{
  int ch;char elem;

  while (1)
  {
    printf("\n\n1). push \n 2). pop \n 3). display \n 4). exit \nEnter Ch   :- ");
    scanf("%d",&ch);
  
    switch(ch)
    {
      case 1:
        printf("\nEnter Element :- ");
        scanf(" %c",&elem);
        push(elem);
       break;
      case 2:
        printf("Pop Element :- %c", pop() );
       break;
      case 3:
        for (int i=0; i<= top; i++)
        {
          printf("%c",stack[i]);
        }
       break;
       case 4:
        exit(1);
       break;
      default:
       break;
    }

  }

return 0;
}
