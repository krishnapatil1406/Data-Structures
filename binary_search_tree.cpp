#include<iostream>
#include<string>
using namespace std;

class bstnode

{
    string data;
    string meaning;
    bstnode *left;
    bstnode *right;
    friend class bst;
}*root;


class bst
{
    bstnode* root;

    public :

    bst();
    void create();
    void inorder_r();
    void inorder_r(bstnode *);
    void del();
    void search();
    int search_r(bstnode *,string);
    bstnode *copy(bstnode *root);
    void breadthfd_nr();
    void mirror_r();
    void mirror_r(bstnode *);
    void mirror_nr();

};

bst :: bst(){
    root=NULL;
}

void bst::create(){

    int flag;
    char c;
    bstnode *temp,*curr;


    if(root==NULL){
        root = new bstnode;
        cout << "Enter data for root node :- ";
        cin >> root->data;
        cout << "Enter meaning for root node :- ";
        cin >> root->meaning;
    }

    do{
        temp = root;
        flag=0;

        curr = new bstnode;
        cout << "Enter Data of Node :- ";
        cin >> curr->data;
        cout << "Enter meaning of node :- ";
        cin >> curr->meaning;

        while(flag==0){

            if (curr->data < temp->data){
                if(temp->left==NULL){
                    temp->left=curr;
                    flag=1;
                }
                else{
                temp=temp->left;
                }
            }
            else{
                if(temp->right==NULL){
                    temp->right=curr;
                    flag=1;
                }
                else{
                    temp=temp->right;
                }
            }

        }

        cout << "Do You Want to continue?(Enter Y/y) :- ";
        cin >> c;

    }while(c=='Y' || c=='y');

}

void bst:: inorder_r(){
    inorder_r(root);
}

void bst:: inorder_r(bstnode *temp){

    if(temp != NULL){
        inorder_r(temp->left);
        cout << temp-> data << "\t";
        cout << temp-> meaning << "\n";
        inorder_r(temp->right);
    }

}

void bst:: del(){

    bstnode *curr,*temp,*s,*parent;
    string str;
    int flag = 0;

    cout << "Enter data to be deleted :- ";
    cin >> str;

    curr = root;

    while (curr != NULL){

        if (str == curr->data){
            flag = 1;
            break;
        }
        if(str < curr->data){
            parent=curr;
            curr=curr->left;
        }
        if(str > curr->data){
            parent=curr;
            curr=curr->right;
        }
    }

    if (flag == 1){

        if (curr == root){              // deletion of root
            if (curr->right == NULL){
                root = root->left;
            }
            else if (curr->left == NULL){
                root = root-> right;
            }
            else if (curr->right != NULL && curr->left != NULL){
                temp = curr -> left;
                root = curr -> right;
                s = curr -> right;

                while(s->left != NULL){
                    bstnode *        s = s->left;
                }
                s->left = temp;
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 1
                Enter data for root node :- karen
                Enter meaning for root node :- m1
                Enter Data of Node :- bob
                Enter meaning of node :- m2
                Do You Want to continue?(Enter Y/y) :- y
                Enter Data of Node :- ellen
                Enter meaning of node :- m3
                Do You Want to continue?(Enter Y/y) :- y
                Enter Data of Node :- alan
                Enter meaning of node :- m4
                Do You Want to continue?(Enter Y/y) :- y
                Enter Data of Node :- tom
                Enter meaning of node :- m5
                Do You Want to continue?(Enter Y/y) :- y
                Enter Data of Node :- wendy
                Enter meaning of node :- m6
                Do You Want to continue?(Enter Y/y) :- n

                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 2
                alan	m4
                bob	m2
                ellen	m3
                karen	m1
                tom	m5
                wendy	m6

                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 4

                 Inorder For Copied Tree :-
                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 5

                The original tree is:
                karen:	m1
                bob:	m2	 	tom:	m5
                alan:	m4	 	ellen:	m3	 	wendy:	m6

                The mirror image is:
                karen:	m1
                tom:	m5	 	bob:	m2
                wendy:	m6	 	ellen:	m3	 	alan:	m4

                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 6

                The original tree is:
                karen:	m1
                tom:	m5	 	bob:	m2
                wendy:	m6	 	ellen:	m3	 	alan:	m4

                The mirror image is:
                karen:	m1
                bob:	m2	 	tom:	m5
                alan:	m4	 	ellen:	m3	 	wendy:	m6

                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 7

                Level Wise Display :-
                karen:	m1
                bob:	m2	 	tom:	m5
                alan:	m4	 	ellen:	m3	 	wendy:	m6

                *Do you want to Continue?  (Y/N) y
                Your Choices :-
                1). Create
                2). Inorder
                3). Delete
                4). Copy
                5). Mirroring(r)
                6). Mirroring(nr)
                7). Breadthfd(nr);
                Enter Choice :- 3
                Enter data to be deleted :- karen
                alan	m4
                bob	m2
                ellen	m3
                tom	m5
                wendy	m6
            }
        }

        else if(curr!=root)   //deletion of node which is not root
        {
              if(curr->left==NULL && curr->right==NULL )   //deletion of a leaf
              {
                  if(parent->left==curr)
                      {parent->left=NULL;}
                  else
                      {parent->right=NULL;}
              }
              else if(curr->left==NULL)     //deletion of a single child
              {
                        if(parent->left==curr)
                        {parent->left=curr->right;}
                        else
                        {parent->right=curr->right;}
              }

              else if(curr->right==NULL)    //deletion of a single child
              {
              if(parent->left==curr)
              {parent->left=curr->left;}
              else
              {parent->right=curr->left;}
              }
        }
        else{
            s=curr->right;
            temp=curr->left;

            while(s->left!=NULL)
            {
                s=s->left;
            }
            s->left=temp;

            if(parent->left==curr)
              {parent->left=curr->right;}
            else
               {parent->right=curr->right;}


        }

        curr->left = NULL;
        curr->right = NULL;

        delete(curr);
    }

    else{
        cout << "Data Not Found";
    }
    inorder_r();
}

bstnode* bst::copy(bstnode *root) {

    bstnode *temp;

    temp=NULL;

    if (root!=NULL) {

        temp = new bstnode;
        temp->data=root->data;
        temp->meaning=root->meaning;
        temp->left=copy(root->left);
        temp->right=copy(root->right);

    }
    return temp;
}

class queue                       //creating class queue
{
  int front,rear;                   //data members
  bstnode *data[30];
public:
  queue();                      //member functions
  void insert(bstnode *);
  bstnode* remove();
  int empty();
  friend class bst;
};
queue::queue()
{
  front=rear=-1;
}
void queue::insert(bstnode *temp)
{
  rear++;
  data[rear]=temp;
}
bstnode* queue::remove()
{
  front++;
  return(data[front]);
}
int queue::empty()
{
  if(front == rear )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void bst::breadthfd_nr()                 //level wise display
{
  bstnode *temp;
  queue q;
  if(root == NULL)
  {
    cout<<"Binary search tree empty!";
  }
  else
  {
    int p=1,r=0;
    temp=root;
    q.insert(temp);
    while(!q.empty())
    {
      for(int i=0;i<p;i++)
      {
        temp=q.remove();
        cout<<temp->data<<":\t"<<temp->meaning<<"\t \t";
        if(temp->left!=NULL)
        {
          q.insert(temp->left);
          r++;
        }
        if(temp->right!=NULL)
        {
           q.insert(temp->right);
           r++;
        }
      }
      cout<<endl;
      p=r;
      r=0;
    }
  }
}

void bst :: mirror_r()                     //driver
{
  if (root == NULL)
  {
    cout<<"\nBinary search tree empty!";
  }
  else
  {
      mirror_r(root);
  }
}
void bst :: mirror_r(bstnode *temp)         //workhorse
{
  bstnode *swap;
  if (temp!=NULL)
  {
    swap=temp->left ;                         //traversal DLR
    temp->left=temp->right;
    temp->right=swap;
    mirror_r(temp->left);
    mirror_r(temp->right);
  }
}
void bst::mirror_nr()
{
  bstnode *temp,*ptr;
  queue q;
  temp=root;
  q.insert(temp);
  while(!q.empty())
    {
      temp=q.remove();
      ptr=temp->left;
      temp->left=temp->right;
      temp->right=ptr;
      if(temp->left!=NULL)
      {
        q.insert(temp->left);
      }
      if(temp->right!=NULL)
      {
        q.insert(temp->right);
      }
    }
}
int main()
{
    bst b;
    bstnode *cp;
    int choice;
    char ch;

    do{

    cout<<"Your Choices :- "<<endl;
    cout<<"1). Create "<<endl;
    cout<<"2). Inorder"<<endl;
    cout<<"3). Delete"<<endl;
    cout<<"4). Copy"<<endl;
    cout<<"5). Mirroring(r)"<<endl;
    cout<<"6). Mirroring(nr)"<<endl;
    cout<<"7). Breadthfd(nr);"<<endl;
    cout<<"Enter Choice :- ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            b.create();
            break;

        case 2:
            b.inorder_r();
            break;

        case 3:
            b.del();
            break;
        case 4:
            cp = b.copy(root);
            cout << "\n Inorder For Copied Tree :- ";
            b.inorder_r(cp);
            break;
        case 5:
            cout<<"\nThe original tree is:\n";
            b.breadthfd_nr();
            b.mirror_r();
            cout<<"\nThe mirror image is:\n";
            b.breadthfd_nr();
            break;
        case 6:
            cout<<"\nThe original tree is:\n";
            b.breadthfd_nr();
            b.mirror_nr();
            cout<<"\nThe mirror image is:\n";
            b.breadthfd_nr();
            break;
        case 7:
                cout<< "\nLevel Wise Display :- \n";
                b.breadthfd_nr();
                break;

        default:
            cout<<"\nYou have Entered Wrong Choice."<<endl;

    }


    cout<<"\n*Do you want to Continue?  (Y/N) ";
    cin>>ch;

    }while(ch=='y' || ch=='Y');

    return 0;
}




/*
OUTPUT :-



Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 1
Enter data for root node :- karen
Enter meaning for root node :- m1
Enter Data of Node :- bob
Enter meaning of node :- m2
Do You Want to continue?(Enter Y/y) :- y
Enter Data of Node :- ellen
Enter meaning of node :- m3
Do You Want to continue?(Enter Y/y) :- y
Enter Data of Node :- alan
Enter meaning of node :- m4
Do You Want to continue?(Enter Y/y) :- y
Enter Data of Node :- tom
Enter meaning of node :- m5
Do You Want to continue?(Enter Y/y) :- y
Enter Data of Node :- wendy
Enter meaning of node :- m6
Do You Want to continue?(Enter Y/y) :- n

*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 2
alan	m4
bob	m2
ellen	m3
karen	m1
tom	m5
wendy	m6

*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 4

 Inorder For Copied Tree :-
*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 5

The original tree is:
karen:	m1
bob:	m2	 	tom:	m5
alan:	m4	 	ellen:	m3	 	wendy:	m6

The mirror image is:
karen:	m1
tom:	m5	 	bob:	m2
wendy:	m6	 	ellen:	m3	 	alan:	m4

*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 6

The original tree is:
karen:	m1
tom:	m5	 	bob:	m2
wendy:	m6	 	ellen:	m3	 	alan:	m4

The mirror image is:
karen:	m1
bob:	m2	 	tom:	m5
alan:	m4	 	ellen:	m3	 	wendy:	m6

*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 7

Level Wise Display :-
karen:	m1
bob:	m2	 	tom:	m5
alan:	m4	 	ellen:	m3	 	wendy:	m6

*Do you want to Continue?  (Y/N) y
Your Choices :-
1). Create
2). Inorder
3). Delete
4). Copy
5). Mirroring(r)
6). Mirroring(nr)
7). Breadthfd(nr);
Enter Choice :- 3
Enter data to be deleted :- karen
alan	m4
bob	m2
ellen	m3
tom	m5
wendy	m6
*/
