#include<iostream>

using namespace std;


class node

{

    char data;

    node *left;

    node *right;

    int lbit,rbit;

    friend class tbt;

   public:

    node();

};


node::node()

{

    lbit=rbit=1;

}


class tbt

{

    node *root;

  public:

    tbt();

    node* create_tbt();

    void display_in(node*);

    void display_pre(node*);

    node* in_successor(node*);

};


tbt::tbt()

{

    root=NULL;

}


node* tbt::create_tbt()

{

    int flag;

    char choice,ch;

    node *head;

    head=new node();

    root=new node();

    cout<<"\nEnter the root data- \n";

    cin>>root->data;

    head->left=root;

    head->right=head;

    head->lbit=head->rbit=0;

    root->left=root->right=head;

    do

    {

        flag=0;

        node *temp, *curr;

        temp=root;

        curr=new node();

        cout<<"\nEnter the data- \n";

        cin>>curr->data;

        while(flag==0)

        {

            cout<<"\nWhere do you want to attach the node on "<<temp->data<<"(l/r)- \n";

            cin>>choice;

            if(choice=='l')

            {

                if(temp->lbit==1)

                {

                    curr->left=temp->left;

                    curr->right=temp;

                    temp->left=curr;

                    temp->lbit=0;

                    flag=1;

                }

                else

                {

                    temp=temp->left;

                }

            }

            else

            {

                if(temp->rbit==1)

                {

                    curr->left=temp;

                    curr->right=temp->right;

                    temp->right=curr;

                    temp->rbit=0;

                    flag=1;

                }

                else

                {

                    temp=temp->right;

                }

            }

        }

        cout<<"\nDo you want to continue- (y/n)\n";

        cin>>ch;

    }

    while(ch=='y');

    return head;

}


void tbt::display_pre(node *head)

{

    node *temp;

    temp=head->left;

    while(temp!=head)

    {

        cout<<temp->data<<" ";

        while(temp->lbit!=1)

        {

            temp=temp->left;

            cout<<temp->data<<" ";

        }

        while(temp->rbit==1)

        {

            temp=temp->right;

        }

        if(temp->rbit==0)

        {

            temp=temp->right;

        }

    }

    cout<<endl;

}


node* tbt::in_successor(node *temp)

{

    node *x;

    x=temp->right;

    if(temp->rbit==0)

    {

        while(x->lbit==0)

        {

            x=x->left;

        }

    }

    return x;

}


void tbt::display_in(node *head)

{

    node *temp;

    temp=head;

    while(1)

    {

        temp=in_successor(temp);

        if(temp==head)

        {

            break;

        }

        cout<<temp->data<<" ";

    }

    cout<<endl;

}


int main()

{

    tbt t;

    node *H;

    int choice;

    char ch;

    do

    {

        cout<<"\nEnter the choice of operaton- \n1)Create\n2)Preorder Display\n3)Inorder Display\n";

        cin>>choice;

        switch(choice)

        {

            case 1:

                H=t.create_tbt();

                cout<<"\nThe threaded binary tree is created successfully\n";

                break;

            case 2:

                cout<<"\nThe threaded binary in preorder- \n";

                t.display_pre(H);

                break;

            case 3:

                cout<<"\nThe threaded binary in inorder- \n";

                t.display_in(H);

                break;

            default:

                cout<<"\nInvalid choice of operation\n";

        }

        cout<<"\nDo you want to continue with the operation on tree (y/n)\n";

        cin>>ch;

    }

    while(ch=='y');

    return 0;

}



/*

Enter the choice of operaton- 
1)Create
2)Preorder Display
3)Inorder Display
1

Enter the root data- 
a

Enter the data- 
b

Where do you want to attach the node on a(l/r)- 
l

Do you want to continue- (y/n)
y

Enter the data- 
c

Where do you want to attach the node on a(l/r)- 
r

Do you want to continue- (y/n)
y

Enter the data- 
d

Where do you want to attach the node on a(l/r)- 
l

Where do you want to attach the node on b(l/r)- 
l

Do you want to continue- (y/n)
y

Enter the data- 
e

Where do you want to attach the node on a(l/r)- 
l

Where do you want to attach the node on b(l/r)- 
l

Where do you want to attach the node on d(l/r)- 
r

Do you want to continue- (y/n)
y

Enter the data- 
f

Where do you want to attach the node on a(l/r)- 
l

Where do you want to attach the node on b(l/r)- 
l

Where do you want to attach the node on d(l/r)- 
r

Where do you want to attach the node on e(l/r)- 
l

Do you want to continue- (y/n)
y

Enter the data- 
g

Where do you want to attach the node on a(l/r)- 
r

Where do you want to attach the node on c(l/r)- 
r

Do you want to continue- (y/n)
y

Enter the data- 
h

Where do you want to attach the node on a(l/r)- 
r

Where do you want to attach the node on c(l/r)- 
r

Where do you want to attach the node on g(l/r)- 
l

Do you want to continue- (y/n)
y

Enter the data- 
l

Where do you want to attach the node on a(l/r)- 
r

Where do you want to attach the node on c(l/r)- 
r

Where do you want to attach the node on g(l/r)- 
r

Do you want to continue- (y/n)
n

The threaded binary tree is created successfully

Do you want to continue with the operation on tree (y/n)
y

Enter the choice of operaton- 
1)Create
2)Preorder Display
3)Inorder Display
2

The threaded binary in preorder- 
a b d e f c g h l 

Do you want to continue with the operation on tree (y/n)
y

Enter the choice of operaton- 
1)Create
2)Preorder Display
3)Inorder Display
3

The threaded binary in inorder- 
d f e b a c h g l 

Do you want to continue with the operation on tree (y/n)
n

*/

