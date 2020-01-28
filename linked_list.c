#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(struct node *H) {

    char ch = 'y';
    struct node *curr,*temp;
    temp = H;

    while (ch == 'y' || ch == 'Y'){
        curr = (struct node *) malloc( sizeof(struct node) );
        printf("Enter data :- ");
        scanf("%d",&curr->data);
        curr -> next = NULL;
        temp -> next = curr;
        temp = curr;
        printf("Enter choice (Y/N):- ");
        scanf(" %c",&ch);
    }
}

void display(struct node *H){
    struct node *curr;

    if (H->next == NULL)    {
        printf("List is Empty.");
    }
    else {
        //printf("%d",H->data);
        curr = H->next;

        while(curr!=NULL){
            printf("%d",curr->data);
            curr = curr->next;
        }
    }
}

int len(struct node *H){
    int i=0;
    struct node *curr;

    curr = H->next;
    while(curr != NULL){
        i++;
        curr = curr->next;
    }
    return i;
}

void insertbypos(struct node *H){
    int i=1,pos,k;
    struct node *curr;
    curr = H;
    struct node *new = (struct node *) malloc( sizeof(struct node) );

    printf("Enter new data to be inserted :- ");
    scanf("%d",&new->data);

    printf("Enter Position to be inserted :- ");
    scanf("%d",&pos);

    k = len(H);
    if(pos > k+1){
        printf("Data cannot be inserted ");
    }
    else{
        while(curr != NULL && i<pos){
            i++;
            curr = curr->next;
        }
        new->next = curr->next;
        curr->next = new;
    }
}

void delete(struct node *H){

	int ctr=1,pos,k;
	struct node *curr,*temp,*prev;
	prev = H;

	curr = H->next;
	printf("Enter Position to be deleted :- ");
	scanf("%d",&pos);

	k = len(H);
	if(k<pos){
		printf("Data cannot be deleted ");
	}
	else{
		while(ctr<pos && curr!=NULL){
			ctr++;
			prev = curr;
			curr = curr->next;
		}
		temp=curr;
		prev->next=curr->next;
		curr->next=NULL;
		free(temp);
	}
}

void reverse(struct node *H){
	struct node *prev,*future,*curr;
	prev=NULL;
	curr=head->next;

	while(curr!=NULL){
		future = curr->next;
		curr->next = prev;
		prev=curr;
		curr=future;
	}
	head->next=prev;

}

void sort(struct node *H){
	int leng,i,j;
	struct node *prev,*temp,*curr;

	leng = len(H);

	for(i=1; i < leng-1; i++){
		prev = H;
		curr = H->next;

		for(j=0; j < leng-i; j++){
			temp = curr->next;
			if(curr->data > temp->data){
				prev->next = temp;
				curr->next = temp->next;
				temp->next = curr;
				prev = temp;
			}
			else{
				prev = curr;
				curr = curr->next;
			}

		}
	}
}

void merge(struct node *h1,struct node *h2)
{

	 struct node *h3,*t1,*t2,*t3;
	 h3=(struct node *)malloc(sizeof(struct node*));
	 h3->next=NULL;
	 t1=h1->next;
	 t2=h2->next;
	 t3=h3;
	 while(t1!=NULL && t2!=NULL)
	 {
	   if(t1->data<t2->data)
	   {
		t3->next=t1;
		t1=t1->next;
		t3=t3->next;
	   }
	   else
	   {
		t3->next=t2;
		t2=t2->next;
		t3=t3->next;
	   }
	 }
	 if(t1!=NULL)
	   t3->next=t1;
	 if(t2!=NULL)
	   t3->next=t2;

	 printf("\n Merged linked list:\n");
	 display(h3);
}


int main(){

	int ch,x;
	struct node *head1,*head2;
    head = (struct node *) malloc( sizeof(struct node) );
    head->next = NULL;

    do{

       printf("\nList Operations :- \n");
       printf("1). Create \n");
       printf("2). Display \n");
       printf("3). Length \n");
       printf("4). Insert By Position \n");
       printf("5). Reverse \n");
       printf("6). Delete \n");
       printf("7). Sort \n");
       printf("8). Merge \n");
       printf("\nEnter Choice :- ");
       scanf("%d",&ch);

       switch (ch){
		   case 1:
			   create(head);
			   break;

		   case 2:
			   printf("\n\nDisplayed Data of list :- ");
			   display(head);
			   break;

		   case 3:
			   printf("\n\nLength :- %d",len(head));
			   break;

		   case 4:
			   insertbypos(head);
			   break;

		   case 5:
			   reverse(head);
			   break;

		   case 6:
		   	   delete(head);
		   	   break;

		   case 7:
			   sort(head);
			   break;

		   case 8:
			   printf("\nEnter First List : \n\n");
			   head1 = (struct node *) malloc( sizeof(struct node) );
			   head1->next = NULL;
			   create(head1);
			   printf("\n\nEnter Second List : \n\n");
			   head2 = (struct node *) malloc( sizeof(struct node) );
			   head2->next = NULL;
		   	   create(head2);
		   	   sort(head1);
		   	   sort(head2);
		   	   merge(head1,head2);
		   	  break;

		   default:
			   printf("\nYou Have Entered Wrong Choice!!!");
			   break;
       }

       printf("\n\nDo You Want to Continue?? (Press 1 to continue) :- ");
       scanf("%d",&x);

    }while(x==1);

    return 0;
}

/*
Output :-

 List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 1
Enter data :- 6
Enter choice (Y/N):- y
Enter data :- 4
Enter choice (Y/N):- y
Enter data :- 7
Enter choice (Y/N):- y
Enter data :- 2
Enter choice (Y/N):- y
Enter data :- 8
Enter choice (Y/N):- y
Enter data :- 1
Enter choice (Y/N):- n


Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 2


Displayed Data of list :- 647281

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 3


Length :- 6

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 4
Enter new data to be inserted :- 9
Enter Position to be inserted :- 4


Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 2


Displayed Data of list :- 6479281

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 5


Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 2


Displayed Data of list :- 1829746

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 6
Enter Position to be deleted :- 4


Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 2


Displayed Data of list :- 182746

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 7


Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 2


Displayed Data of list :- 124678

Do You Want to Continue?? (Press 1 to continue) :- 1

List Operations :-
1). Create
2). Display
3). Length
4). Insert By Position
5). Reverse
6). Delete
7). Sort
8). Merge

Enter Choice :- 8

Enter First List :

Enter data :- 4
Enter choice (Y/N):- y
Enter data :- 2
Enter choice (Y/N):- 7


Enter Second List :

Enter data :- 5
Enter choice (Y/N):- y
Enter data :- 8
Enter choice (Y/N):- n

 Merged linked list:
4258

Do You Want to Continue?? (Press 1 to continue) :- 0
 */