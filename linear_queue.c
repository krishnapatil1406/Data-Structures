#include<stdio.h>

int front = -1;
int rear = -1;
int size = 3;

void addque(int q[],int elem)
{
    if (rear == size-1){
        printf("\nQueue is Full\n");
    }
    else{
        rear = rear + 1;
        q[rear] = elem;
    }
}

int delque(int q[])
{
    if(front==rear){
        printf("\nQueue is Empty\n");
        return -1;
    }
    else{
        return q[++front];
    }

}

void display(int q[]) {
    int i;
    for (i=front+1; i<=rear; i++) {
        printf("\n%d",q[i]);

    }
}

int main() {

    int que[size],ch=1,elem,x=1;

    do{

        printf("\nYour Choices :- \n");
        printf("1). Add element in queue \n");
        printf("2). Delete element from queue \n");
        printf("3). Display queue \n");
        printf("\nEnter Choice :- ");
        scanf("%d",&ch);

        switch (ch){

            case 1:
                printf("\nEnter Element :- ");
                scanf("%d",&elem);
                addque(que,elem);
                break;

            case 2:
                printf("\n Deleted Element :- %d\n",delque(que));
                break;

            case 3:
                display(que);
                break;

            default:
                printf("\nYou Have Entered Wrong Choice!!!");
                break;
        }

        printf("\nDo You Want to Continue?? (Press 1 to continue) :- ");
        scanf("%d",&x);

        }while(x==1);

    return 0;
}