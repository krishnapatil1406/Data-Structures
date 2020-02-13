#include<iostream>
using namespace std;
#define MAX 10

class student
{
  int marks;
  string name;

  friend class heap;
};

class heap
{
 student heap_array[MAX];
 int n;
 int min_max;

 public:
 void create_heap();
 void display();
 void insert_heap(int index);
 void extract();


 };

 void heap::create_heap()
 {
   student s;
       cout<<"Enter 1 for max and 0 for min heap:";
       cin>>min_max;

       cout<<"Enter the no students:";
       cin>>n;


       for(int i=1;i<=n;i++)
       {

       cout<<"Student Info:\n";
       cout<<"Enter the marks :";
       cin>>s.marks;

       cout<<"Enter the name :";
       cin>>s.name;

       heap_array[i]=s;
       insert_heap(i);
       }
}

void heap::insert_heap(int index)
{
  int i=index;
  student s;
  s=heap_array[index];

  if (min_max==1)
  {
     while(i>1 && s.marks>heap_array[i/2].marks)
     {
         heap_array[i]=heap_array[i/2];
         i=i/2;
     }

     heap_array[i]=s;

  }

  else
  {
     while(i>1 && s.marks<heap_array[i/2].marks)
     {
         heap_array[i]=heap_array[i/2];
         i=i/2;
     }

     heap_array[i]=s;

  }

}

void heap::display()
{
  cout<<"Heap\n";
  for(int i=0;i<=n;i++)
  {
     cout<<heap_array[i].marks<<"  "<<heap_array[i].name<<"  ";

  }
 }

void heap::extract()
{
  if(min_max==1)
  {
  cout<<"Student with maximum marks is:"<<heap_array[1].marks;
  cout<<"  "<<heap_array[1].name;
  }
  else
 {
  cout<<"Student with minimum marks is:"<<heap_array[1].marks;
  cout<<"  "<<heap_array[1].name;
 }
}

int main()
{
  int ch;
  char ch1;

  heap h1;

  do
  {
    cout<<"Enter the choice\n1)create\n2)display\n3)extract\n";
    cin>>ch;

    switch(ch)
    {
       case 1:h1.create_heap();
              break;
       case 2:h1.display();
              break;
       case 3:h1.extract();
              break;
     }
       cout<<"Do you want to continue?(y/n)";
       cin>>ch1;


  }while(ch1=='y');

  return 0;

}


/*
 * Enter the choice
1)create
2)display
3)extract
1
Enter 1 for max and 0 for min heap:1
Enter the no students:7
Student Info:
Enter the marks :12
Enter the name :kp1
Student Info:
Enter the marks :43
Enter the name :kp2
Student Info:
Enter the marks :46
Enter the name :kp3
Student Info:
Enter the marks :51
Enter the name :kp4
Student Info:
Enter the marks :12
Enter the name :kp5
Student Info:
Enter the marks :19
Enter the name :kp6
Student Info:
Enter the marks :11
Enter the name :kp7
Do you want to continue?(y/n)y
Enter the choice
1)create
2)display
3)extract
2
Heap
0    51  kp4  46  kp3  43  kp2  12  kp1  12  kp5  19  kp6  11  kp7
 Do you want to continue?(y/n)y
Enter the choice
1)create
2)display
3)extract
3
Student with maximum marks is:51  kp4
Do you want to continue?(y/n)y
Enter the choice
1)create
2)display
3)extract
1
Enter 1 for max and 0 for min heap:0
Enter the no students:7
Student Info:
Enter the marks :12
Enter the name :kp1
Student Info:
Enter the marks :43
Enter the name :kp2
Student Info:
Enter the marks :46
Enter the name :kp3
Student Info:
Enter the marks :51
Enter the name :kp4
Student Info:
Enter the marks :12
Enter the name :kp5
Student Info:
Enter the marks :19
Enter the name :kp6
Student Info:
Enter the marks :11
Enter the name :kp7
Do you want to continue?(y/n)y
Enter the choice
1)create
2)display
3)extract
2
Heap
0    11  kp7  12  kp5  12  kp1  51  kp4  43  kp2  46  kp3  19  kp6  Do you want to continue?(y/n)y
Enter the choice
1)create
2)display
3)extract
3
Student with minimum marks is:11  kp7
Do you want to continue?(y/n)
 */

