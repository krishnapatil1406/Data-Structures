/*CONSIDER FRIENDS NETWORK ON FACEBOOK SOCIAL WEBSITE. MODEL IT AS A GRAPH TO REPRESENT EACH NODE AS A USER AND A LINK TO REPRESENT THE FRIEND RELATIONSHIP BETWEEN THEM USING AFDJACENCY LIST REPRESENTATION AND PERFORM BFS AND DFS TRAVERSAL.*/
#include<iostream>
#include<string.h>
using namespace std;

class gnode{
int vertex;
string name;
gnode * next;
friend class graph;
};

class graph{
gnode * head[20];
int i;
int n;
public:
      graph(){
            cout<<"Enter Number of users: ";
            cin>>n;
            for(i=0;i<n;i++)
                  {head[i]= new gnode;
                  head[i]->vertex=i;
                  cout<<"Name for "<<i<<"\t:";
                  cin>>head[i]->name;
                  head[i]->next=NULL;
                  }
             }     
       void create(); 
       void display();
};

void graph :: create(){
      int i=0;
      char ch;
      gnode * temp,* curr;
      for(i=0;i<n;i++)
      {
            cout<<"Do you want to add a friend for "<<head[i]->name;
            //cout<<<<"\t";
            cin>>ch;
            temp=head[i];
            while(ch=='y'){
            curr = new gnode;
            cout<<"Vertex";
            cin>>curr->vertex;
            cout<<"Enter Name";
            cin>>curr->name;
            curr->next=NULL;
            temp->next=curr;
            temp=curr;
            cout<<"Do you want to continue adding friend";
            cin>>ch;
            }
            cout<<"\n======================================\n";
      }
}

void graph :: display(){
int i;
gnode * temp;
for(i=0;i<n;i++){
      cout<<"FRIEND LIST\nFRIEND'S OF "<<head[i]->name<<"\n";
      temp=head[i]->next;
      while(temp!=NULL){
            cout<<temp->vertex<<"\t"<<temp->name;
            cout<<"\n";
            temp=temp->next;
      }
      cout<<"\n";
}
}

int main(void){
graph g;
g.create();
g.display();
return 0;
}



/*

Enter Number of users: 5
Name for 0	:1
Name for 1	:2
Name for 2	:3
Name for 3	:4
Name for 4	:5
Do you want to add a friend for 13

======================================
Do you want to add a friend for 22

======================================
Do you want to add a friend for 34

======================================
Do you want to add a friend for 42

======================================
Do you want to add a friend for 52

======================================
FRIEND LIST
FRIEND'S OF 1

FRIEND LIST
FRIEND'S OF 2

FRIEND LIST
FRIEND'S OF 3

FRIEND LIST
FRIEND'S OF 4

FRIEND LIST
FRIEND'S OF 5


*/
