#include<stdio.h>

void accept(int n);
void prints(int n, int i);
void print(int n);
void linear(int n,int roll);
void bubble(int n);
void selection(int n);
void insertion(int n);
void binary(int roll,int high,int low);

struct student
{
    char name[10];
    int rollno;
    int div;
}s[50],temp,key;

int main()
{
    int n=0,roll=0,ch=0, x=0;

    printf("\nEnter No. of Students :- ");
    scanf("%d",&n);

    accept(n);

   do{

    printf("\nOperations :- \n");
    printf("1). Linear Search \n");
    printf("2). Binary search \n");
    printf("3). Bubble Sort \n");
    printf("4). Selection Sort \n");
    printf("5). Insertion Sort \n");
    printf("\nEnter Choice :- ");
    scanf("%d",&ch);

    switch (ch){
    case 1:
        printf("\nEnter Roll no to Search Details :- ");
        scanf("%d",&roll);

        linear(n,roll);
    break;

    case 2:
        printf("\nEnter Roll no to Search Details :- ");
        scanf("%d",&roll);

    bubble(n);
        binary(roll,n,0);
    break;

    case 3:
        bubble(n);
        print(n);
    break;

    case 4:
        selection(n);
        print(n);
    break;

    case 5:
        insertion(n);
        print(n);
    break;

    default :
        printf("\nYou Have Entered Wrong Choice!!!");
    break;

    }

    printf("\n\nDo You Want to Continue?? (Press 1 to continue) :- ");
    scanf("%d",&x);

    }while(x==1);
    return 0;

}

void linear(int n,int roll)
{
    int i= 0;
    for (i=0; i<n; i++)
    {
        if (s[i].rollno == roll)
        {
            printf("\nStudent Data Found !! \n");
            prints(n,i);
            break;
        }
    }
    if (i == n)
    {
        printf("\nStudent Data NOT Found !! \n\n");
    }

}

void accept(int n)
{
    int i= 0;

     for (i=0; i<n; i++)
     {
        printf("\nEnter Name :- ");
        scanf("%s",s[i].name);

        printf("Enter Roll No. :- ");
        scanf("%d",&s[i].rollno);

        printf("Enter Division :- ");
        scanf("%d",&s[i].div);
    }
}

void print(int n)
{
    int i= 0;

   for (i=0; i<n; i++)
    {
        printf("\n\nName :- %s",s[i].name);
        printf("\nRoll No. :- %d",s[i].rollno);
        printf("\nDivision :- %d \n\n",s[i].div);
   }
}

void prints(int n, int i)
{
        printf("\n\nName :- %s",s[i].name);
        printf("\nRoll No. :- %d",s[i].rollno);
        printf("\nDivision :- %d \n\n",s[i].div);
}

void binary(int roll,int high,int low)
{
    int mid,flag=0;
    while(high >= low)
    {
        mid=(high+low)/2;
        if(s[mid].rollno == roll)
        {
            flag=1;
            prints(high,mid);
            break;
        }
        else if(s[mid].rollno < roll)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==0)
    {printf("\nStudent Data NOT Found !! \n");}

}



void bubble(int n)
{
    int i=0,j=0;

    for(i=1; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(s[j].rollno > s[j+1].rollno)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void selection(int n)
{
    int minpos = 0,i,j;
    for (i=0; i<n-1; i++)
    {
        minpos = i;
        for(j = i+1; j < n; j++ )
        {
            if(s[j].rollno < s[minpos].rollno)
            {
                minpos = j;
            }
        }
        if(minpos != i)
        {
            temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
    }
}

void insertion(int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        key = s[i];
        j = i-1;

        while(j>=0 && s[j].rollno > key.rollno)
        {
            s[j+1] = s[j];
            j = j-1;
        }
        s[j+1] = key;
    }
}


/*  OUTPUT :-


Enter No. of Students :- 3

Enter Name :- krishna
Enter Roll No. :- 9
Enter Division :- 8

Enter Name :- cvh
Enter Roll No. :- 7
Enter Division :- 6

Enter Name :- dhyh
Enter Roll No. :- 5
Enter Division :- 4

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 1

Enter Roll no to Search Details :- 7

Student Data Found !!


Name :- cvh
Roll No. :- 7
Division :- 6



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 1

Enter Roll no to Search Details :- 5

Student Data Found !!


Name :- dhyh
Roll No. :- 5
Division :- 4



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 1

Enter Roll no to Search Details :- 9

Student Data Found !!


Name :- krishna
Roll No. :- 9
Division :- 8



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 1

Enter Roll no to Search Details :- 12

Student Data NOT Found !!



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 2

Enter Roll no to Search Details :- 5


Name :- dhyh
Roll No. :- 5
Division :- 4



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 9

You Have Entered Wrong Choice!!!

Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 2

Enter Roll no to Search Details :- 9


Name :- krishna
Roll No. :- 9
Division :- 8



Do You Want to Continue?? (Press 1 to continue) :- 1

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 3


Name :- dhyh
Roll No. :- 5
Division :- 4



Name :- cvh
Roll No. :- 7
Division :- 6



Name :- krishna
Roll No. :- 9
Division :- 8



Do You Want to Continue?? (Press 1 to continue) :- 0

Enter No. of Students :- 3

Enter Name :- krishna
Enter Roll No. :- 34
Enter Division :- 676

Enter Name :- dfghf
Enter Roll No. :- 9
Enter Division :- 43

Enter Name :- tdg
Enter Roll No. :- 23
Enter Division :- 656

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 4


Name :- dfghf
Roll No. :- 9
Division :- 43



Name :- tdg
Roll No. :- 23
Division :- 656



Name :- krishna
Roll No. :- 34
Division :- 676



Do You Want to Continue?? (Press 1 to continue) :- 0

Enter No. of Students :- 3

Enter Name :- dhgfjh
Enter Roll No. :- 657
Enter Division :- 43

Enter Name :- dgd
Enter Roll No. :- 45
Enter Division :- 67

Enter Name :- fxcbf
Enter Roll No. :- 12
Enter Division :- 44

Operations :-
1). Linear Search
2). Binary search
3). Bubble Sort
4). Selection Sort
5). Insertion Sort

Enter Choice :- 5


Name :- fxcbf
Roll No. :- 12
Division :- 44



Name :- dgd
Roll No. :- 45
Division :- 67



Name :- dhgfjh
Roll No. :- 657
Division :- 43



Do You Want to Continue?? (Press 1 to continue) :- 0
*/


