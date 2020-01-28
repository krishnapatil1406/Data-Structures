
#include<iostream>

using namespace std;

class treenode{

    char data;
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree{
    treenode *root;

    public:

        tree();
        void create_r();
        void create_r(treenode *);
        void create_nr();
        void inorder_r();
        void inorder_r(treenode *);
        void preorder_r();
        void preorder_r(treenode *);
        void postorder_r();
        void postorder_r(treenode *);
        void inorder_nr();
        void preorder_nr();
        void postorder_nr();
};

tree :: tree(){
    root=NULL;
}
void tree::create_r(){

    if (root == NULL){
        root = new treenode;
        root->left = NULL;
        root->right = NULL;

        cout << "Enter data for root node :- ";
        cin >> root->data;
        create_r(root);
    }

}

void tree::create_r(treenode *temp)
{

    char ch;
    treenode *curr;

    cout << "Add node to left?(Enter Y/y for Yes) of "<< temp->data<<":- ";
    cin>>ch;

    if(ch == 'y' || ch == 'Y')
    {
        curr = new treenode;
        cout << "Enter Data of Left Node :- ";
        cin >> curr->data;
        temp->left = curr;
        create_r(curr);
    }

    cout << "Add node to right ?(Enter Y/y for Yes) of "<< temp->data <<":- ";
    cin>>ch;

    if(ch == 'y' || ch == 'Y'){
        curr = new treenode;
        cout << "Enter Data of Right Node :- ";
        cin >> curr->data;
        temp->right = curr;
        create_r(curr);
    }

}

void tree:: inorder_r(){
    inorder_r(root);
}

void tree:: inorder_r(treenode *temp){

    if(temp != NULL){
        inorder_r(temp->left);
        cout << temp-> data << "\t";
        inorder_r(temp->right);
    }

}

void tree:: preorder_r(){
    preorder_r(root);
}

void tree:: preorder_r(treenode *temp){

    if(temp != NULL){
    	cout << temp-> data << "\t";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }

}

void tree:: postorder_r(){
    postorder_r(root);
}

void tree:: postorder_r(treenode *temp){

    if(temp != NULL){
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << temp-> data << "\t";
    }

}

class stack{
    int top;
    int *St;
    treenode *data[30];

    public :

        stack(){
            top=-1;

        }

        void push(treenode *);
        treenode* pop();
        int empty();
        friend class tree;

}st;

void stack::push(treenode *temp){
    if ( top != 29 ) {
        top=top+1;
        data[top]=temp;
    }
}

int stack::empty(){
  if (top == -1)
    {return 1;}
  else
    {return 0;}
}

treenode* stack::pop(){
    treenode *item;

    if ( top != -1 ) {
        item=data[top];
        top=top-1;
        return (item);
    }
}

void tree::inorder_nr(){
    treenode *temp;
    temp=root;

    while(1){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }

        if ( st.empty() ){
            break;
        }
        else{
            temp=st.pop();
            cout << temp-> data << "\t";
            temp=temp->right;
        }
    }
}

void tree::preorder_nr(){
    treenode *temp;
    temp=root;

    while(1){
        while(temp!=NULL){
            st.push(temp);
            cout << temp-> data << "\t";
            temp = temp->left;
        }

        if ( st.empty() ){
            break;
        }
        else{
            temp=st.pop();
            temp=temp->right;
        }
    }
}

void tree::postorder_nr(){
    treenode *temp;
    temp=root;

    while(1){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }

        if ( st.data[st.top]->right == NULL ){
            temp = st.pop();
            cout << temp-> data << "\t";
        }
        while( st.empty()==0 && st.data[st.top]->right == temp ){
        	temp = st.pop();
        	cout << temp-> data << "\t";
        }
        if( st.top == -1 ){
        	break;
        }

        temp = st.data[st.top]->right;

     }

}

void tree::create_nr(){

	int flag;
	char ch,c;
	treenode *temp,*curr;


	if(root==NULL){
		root = new treenode;
		cout << "Enter data for root node :- ";
		cin >> root->data;
	}

	do{
		temp = root;
		flag=0;

		curr = new treenode;
		cout << "Enter Data of Node :- ";
		cin >> curr->data;

		while(flag==0){
			cout << "Add node to left/right ?(Enter l/r) of "<< temp->data <<":- ";
			cin>>ch;

			if (ch=='l' || ch=='L'){
				if(temp->left==NULL){
					temp->left=curr;
					flag=1;
				}
				temp=temp->left;
			}
			else{
				if (ch=='r' || ch=='R'){
					if(temp->right==NULL){
						temp->right=curr;
						flag=1;
					}
					temp=temp->right;
				}
			}

		}

		cout << "Do You Want to continue?(Enter Y/y) :- ";
		cin >> c;

	}while(c=='Y' || c=='y');

}


int main()
{
    int choice;
    char ch;
	tree t;


    do{

    cout<<"Your Choices :- "<<endl;
    cout<<"1). Recursive Create "<<endl;
    cout<<"2). Non-Recursive Create "<<endl;
    cout<<"3). Recursive Inorder"<<endl;
    cout<<"4). Recursive Preorder"<<endl;
    cout<<"5). Recursive Postorder"<<endl;
    cout<<"6). Non-Recursive Inorder"<<endl;
    cout<<"7). Non-Recursive Preorder"<<endl;
    cout<<"8). Non-Recursive Postorder"<<endl;
    cout<<"Enter Choice :- ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        	t.create_r();
            break;

        case 2:
        	t.create_nr();
            break;

        case 3:
        	t.inorder_r();
            break;
        case 4:
        	t.preorder_r();
            break;
        case 5:
        	t.postorder_r();
            break;
        case 6:
        	t.inorder_nr();
            break;
        case 7:
        	t.preorder_nr();
            break;
        case 8:
        	t.postorder_nr();
            break;
        default:
            cout<<"\nYou have Entered Wrong Choice."<<endl;

    }


    cout<<"\n*Do you want to Continue?  (Y/N) ";
        cin>>ch;

        }while(ch=='y' || ch=='Y');

    return 0;
}

