#include<stdio.h>

int front;
int rear;
int size = 5;

void addcirque(int q[],int elem)
{
    if ( (rear+1)%size == front){
        printf("\nMaximum Order limit reached\n");
    }
    else{
        rear = (rear+1)%size;
        q[rear] = elem;
    }
}

int delcirque(int q[])
{
    if(front==rear){
        printf("\nNo Pending Orders\n");
        return -1;
    }
    else{
        front = (front+1) %size;
        return q[front];
    }

}

void display(int q[]) {
    int i;
    for (i=front+1; i<=rear; i++) {
        printf("\n%d",q[i]);

    }
}

void addlinque(int q[],int elem)
{
    if (rear == size-1){
        printf("\nMaximum Order limit reached\n");
    }
    else{
        rear = rear + 1;
        q[rear] = elem;
    }
}

int dellinque(int q[])
{
    if(front==rear){
        printf("\nNo Pending Orders\n");
        return -1;
    }
    else{
        return q[++front];
    }

}

int main() {

    int que[size],ch=1,elem,x=1;

    do{
        printf("\n\nYour Choices :- \n");
        printf("1). Linear Queue \n");
        printf("2). Circular Queue \n");
        printf("Enter Choice :- ");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                rear = -1;
                front = -1;

                do{
                        printf("\nYour Choices :- \n");
                        printf("1). New Pizza Order \n");
                        printf("2). Pizza Order Delivered \n");
                        printf("3). Display Orders \n");
                        printf("\nEnter Choice :- ");
                        scanf("%d",&ch);

                        switch (ch){

                            case 1:
                                printf("\nEnter Order Number :- ");
                                scanf("%d",&elem);
                                addlinque(que,elem);
                                break;

                            case 2:
                                printf("\nDelivered Order Number :- %d\n",dellinque(que));
                                break;

                            case 3:
                                display(que);
                                break;

                            default:
                                printf("\nYou Have Entered Wrong Choice!!!");
                                break;
                        }

                        printf("\nDo You Want to Continue with same queue?? (Press 1 to continue) :- ");
                        scanf("%d",&x);

                        }while(x==1);

                break;

            case 2:
                rear = 0;
                front = 0;

                do{
                        printf("\nYour Choices :- \n");
                        printf("1). New Pizza Order \n");
                        printf("2). Pizza Order Delivered \n");
                        printf("3). Display Orders \n");
                        printf("\nEnter Choice :- ");
                        scanf("%d",&ch);

                        switch (ch){

                            case 1:
                                printf("\nEnter Order Number :- ");
                                scanf("%d",&elem);
                                addcirque(que,elem);
                                break;

                            case 2:
                                printf("\nDelivered Order Number :- %d\n",delcirque(que));
                                break;

                            case 3:
                                display(que);
                                break;

                            default:
                                printf("\nYou Have Entered Wrong Choice!!!");
                                break;
                        }

                        printf("\nDo You Want to Continue with same queue?? (Press 1 to continue) :- ");
                        scanf("%d",&x);

                       }while(x==1);

                break;

            default:
                   printf("\nYou Have Entered Wrong Choice!!!");
                   break;
        }

        printf("\nDo You Want to Change queue?? (Press 1 to continue) :- ");
        scanf("%d",&x);

        }while(x==1);

    return 0;
}


/*


Your Choices :-
1). Linear Queue
2). Circular Queue
Enter Choice :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 51

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 52

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 53

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 54

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 55

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 56

Maximum Order limit reached

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

51
52
53
54
55
Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 51

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

52
53
54
55
Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 52

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

53
54
55
Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 53

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 54

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 55

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

No Pending Orders

Delivered Order Number :- -1

Do You Want to Continue with same queue?? (Press 1 to continue) :- 0

Do You Want to Change queue?? (Press 1 to continue) :- 1


Your Choices :-
1). Linear Queue
2). Circular Queue
Enter Choice :- 2

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 51

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 52

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 53

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 54

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 1

Enter Order Number :- 55

Maximum Order limit reached

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

51
52
53
54
Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 51

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 3

52
53
54
Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 52

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 53

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

Delivered Order Number :- 54

Do You Want to Continue with same queue?? (Press 1 to continue) :- 1

Your Choices :-
1). New Pizza Order
2). Pizza Order Delivered
3). Display Orders

Enter Choice :- 2

No Pending Orders

Delivered Order Number :- -1

Do You Want to Continue with same queue?? (Press 1 to continue) :- 0

Do You Want to Change queue?? (Press 1 to continue) :- 0

 */

