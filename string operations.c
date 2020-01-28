#include<stdio.h>       

int length(char*);                        // all functions are declared
void copy(char*,char*);
void concate(char*,char*);
void equal(char str1[10],char str2[10]);
void reverse(char str[10]);
void palindrome(char str[10]);
void substring(char str[10],char substr[10]);

int main()
{
    char str[10],str1[10],str2[10];
    int ch,x;

    do{

	    printf("\nString Operations :- \n");
	    printf("1). Length \n");
	    printf("2). Copy \n");
	    printf("3). Concate \n");
	    printf("4). Equal \n");
	    printf("5). Reverse \n");
	    printf("6). Palindrome \n");
	    printf("7). Substring \n");
	    printf("\nEnter Choice :- ");
	    scanf("%d",&ch);

	    switch (ch){
	    case 1:
	    printf("\nEnter String :- ");
	    scanf("%s",str);

	    printf("Length of String :- %d \n",length(str));    //length function called
	    break;

	    case 2:
	    printf("\nEnter Source string :- ");
	    scanf("%s",str1);

	    printf("\nEnter Destination string :- ");
	    scanf("%s",str2);

	    copy(str1,str2);                                   //copy function called
	    printf("\nDestination string = %s \nSource string = %s",str1,str2);
	    break;

	    case 3:
	    printf("\nEnter String 1 :- ");
	    scanf("%s",str1);

	    printf("\nEnter String 2:- ");
	    scanf("%s",str2);

	    concate(str1,str2);                             // concate function called
	    printf("\nThe Concate of Two String :- %s",str1);
	    break;

	    case 4:
	    printf("\nEnter String 1 :- ");
	    scanf("%s",str1);

	    printf("\nEnter String 2:- ");
	    scanf("%s",str2);

	    equal(str1,str2);                            //equal function called
	    break;

	    case 5:
	    printf("\nEnter String :- ");
	    scanf("%s",str);

	    reverse(str);                             //reverse function called
	    break;

	    case 6:
	    printf("\nEnter String :- ");
	    scanf("%s",str);

	    palindrome(str);                        //palindrome function called
	    break;

	    case 7:
	    printf("\nEnter String :- ");
	    scanf("%s",str1);

	    printf("\nEnter Substring :- ");
	    scanf("%s",str2);

	    substring(str1,str2);                 //substring function called
	    break;

	    default:
	    printf("\nYou Have Entered Wrong Choice!!!");
	    break;}

	    printf("\n\nDo You Want to Continue?? (Press 1 to continue) :- ");
	    scanf("%d",&x);

    }while(x==1);
    return 0;
}


int length(char* str)          // length function using pointer
{
    int count=0;
    for(count=0; *str!='\0'; count++,str++);

    return count;
}

void copy(char* sou,char* des)   //copy function using pointer
{
    int i=0;

    for(i=0; *sou!='\0'; i++,sou++,des++)
    {
        *des=*sou;
    }
    *des='\0';
}

void concate(char* str1,char* str2)   //concate using pointer
{
    int i=0,j=0;

    for(i=0; *str1!='\0'; i++,str1++);

    for(j=0; *str2!='\0'; i++,j++,str1++,str2++)
    {
        *str1=*str2;
    }
    *str1='\0';

}

void equal(char str1[10],char str2[10])   //equal function without pointer
{
    int i=0,flag=0;

    if(length(str1)==length(str2))
    {
    for(i=0; str1[i]!='\0'; i++)
    {
        if(str1[i]==str2[i])
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }
    }
    else
    {
        flag=0;
    }

    if(flag==1)
        printf("\nString is Equal!!!");
    else
        printf("\nString is NOT Equal!!!");

}

void reverse(char str[10])   //reverse function without pointer
{
    int i=0,len;
    char temp[10];
    len = length(str);

    for(i=0; i!=len; i++)
    {
        temp[i]=str[len-i-1];
    }
    temp[i]='\0';

    printf("The Reverse of String :- %s",temp);
}

void palindrome(char str[10])   //palindrome function without pointer
{
    int i=0,len=0,flag=0;
    char temp[10];
    len = length(str);

    for(i=0; i!=len; i++)
    {
        temp[i]=str[len-i-1];
    }
    temp[i]='\0';

    for(i=0; i!=len; i++)
    {
        if(str[i]==temp[i])
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }

    if(flag==1)
        printf("\nString is Palindrome!!!");
    else
        printf("\nString is NOT Palindrome!!!");

}

void substring(char str[10],char substr[10])     //substring function without pointer
{
    int i=0,j=0;

        while(substr[i]!='\0' && str[j]!='\0')
        {
            if(substr[i]==str[j])
                        {
                            i++;
                            j++;
                        }
                        else
                        {
                            j++;
                            i=0;

                        }
        }

        if (substr[j] == '\0')
            {printf("\nSubstring Found ");}
        else
            {printf("\nSubstring NOT Found ");}

}


/*    OUTPUT

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 1

Enter String :- Himanshu
Length of String :- 8


Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 2

Enter Source string :- Source

Enter Destination string :- Destination

Destination string = Source
Source string = Source

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 3

Enter String 1 :- Hello

Enter String 2:- World

The Concate of Two String :- HelloWorld

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 4

Enter String 1 :- Krishna

Enter String 2:- Patil

String is NOT Equal!!!

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 4

Enter String 1 :- HIMANSHU

Enter String 2:- HIMANSHU

String is Equal!!!

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 5

Enter String :- 123456789
The Reverse of String :- 987654321

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 6

Enter String :- 123454321

String is Palindrome!!!

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 6

Enter String :- 12345

String is NOT Palindrome!!!

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 7

Enter String :- 12312345

Enter Substring :- 123

Substring Found

Do You Want to Continue?? (Press 1 to continue) :- 1

String Operations :-
1). Length
2). Copy
3). Concate
4). Equal
5). Reverse
6). Palindrome
7). Substring

Enter Choice :- 7

Enter String :- 12312345

Enter Substring :- 78

Substring NOT Found

Do You Want to Continue?? (Press 1 to continue) :- 0


*/


