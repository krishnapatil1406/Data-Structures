#include <iostream>
using namespace std;

class graph
{
	int cost[10][10];                  //for adjacency list representation
	int tcities;

public:
	graph();                           //default constructor
	void create();			   //member functions
	void display();
	void prims();
};
graph::graph(){
	cout<<"\nEnter no. of cities:";
	cin>>tcities;
	for(int i=0;i<tcities;i++)
	{
		for(int j=0;j<tcities;j++)
		{
			cost[i][j]=999;
		}
	}
}
void graph::create()                                           //function definition for create
{
	char ch;
	for(int i=0;i<tcities;i++)
	{
		for(int j=i+1;j<tcities;j++)
		{
			cout<<"\nIs there a connection between "<<i<<"&"<<j;
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nEnter cost of edge "<<i<<j<<" :";
				cin>>cost[i][j];
				cost[j][i]=cost[i][j];
			}
		}
	}
}
void graph::display()                                          //function definition for display
{
	cout<<"\nThe adjecency matrix is:\n";
	for(int i=0;i<tcities;i++)
		{
			for(int j=0;j<tcities;j++)
			{
				cout<<cost[i][j];
				cout<<"\t";
			}
			cout<<endl;
		}
}
void graph::prims()                                           //function definition for prims
{
	int ST[tcities][2];
	int nearest[tcities];
	int stv,r,min,total=0,j;
	cout<<"\nEnter start vertex";
	cin>>stv;
	nearest[stv]=-1;
	for(int i=0; i<tcities ;i++)
	{
		if(i!=stv)
		{
			nearest[i]=stv;
		}
	}
	r=0;
	for(int i=1; i<tcities ;i++)
	{
		min=999;
		for(int k=0;k<tcities;k++)
		{
			if(nearest[k]!=-1 && cost[k][nearest[k]]<min)
			{
				j=k;
				min= cost[k][nearest[k]];
			}
		}
			ST[r][0]=j;
			ST[r][1]=nearest[j];
			r++;
			total=total+cost[j][nearest[j]];
			nearest[j]=-1;


			for(int k=0;k<tcities;k++)
			{
				if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
				{
					nearest[k]=j;
				}
			}
		}
			cout<<"\n---Spanning tree matrix---\n";
			for(int i=0; i<(tcities-1) ;i++)
			{
				for(int j=0; j<2 ;j++)
				{
					cout<<ST[i][j]<<"\t";
				}
				cout<<"\n";
			}
		cout<<"Minimum cost is:"<<total;
}

int main()                                      //main function
{
	graph g;
	g.create();
	g.display();
	g.prims();
	return 0;
}


/*
 * Enter no. of cities:5

Is there a connection between 0&1y

Enter cost of edge 01 :3

Is there a connection between 0&2y

Enter cost of edge 02 :4

Is there a connection between 0&3n

Is there a connection between 0&4y

Enter cost of edge 04 :7

Is there a connection between 1&2y

Enter cost of edge 12 :8

Is there a connection between 1&3y

Enter cost of edge 13 :1

Is there a connection between 1&4n

Is there a connection between 2&3n

Is there a connection between 2&4y

Enter cost of edge 24 :2

Is there a connection between 3&4y

Enter cost of edge 34 :5

The adjecency matrix is:
999	3	4	999	7
3	999	8	1	999
4	8	999	999	2
999	1	999	999	5
7	999	2	5	999

Enter start vertex0

---Spanning tree matrix---
1	0
3	1
2	0
4	2
Minimum cost is:10*/
 */

