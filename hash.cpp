#include<iostream>
#define max 10
#include<string.h>
using namespace std;

class Student {
	int roll_no;
	char grade;
	string name;

public:
	Student() {
		roll_no = -1;
		name = "NULL";
		grade = '-';
	}
	friend class Hashing;
};

class Hashing {
	Student hashing[max];
public:
	void lp_rep();
	void lp_wrep();
	void display();
};

void Hashing::display() {
	int i;
	for (i = 0; i < max; i++) {
		cout << hashing[i].roll_no << "\t" << hashing[i].name << "\t"
				<< hashing[i].grade;
		cout << "\n";
	}

}

void Hashing::lp_wrep() {
	int roll_no, flag = 0;
	char grade, ch;
	string name;

	do {
		cout << "Enter Student details\n";
		cout << "Enter roll no.";
		cin >> roll_no;
		cout << "Enter Name";
		cin >> name;
		cout << "Enter grade";
		cin >> grade;
		int loc;
		loc = roll_no % max;

		if (hashing[loc].roll_no == -1) {
			hashing[loc].roll_no = roll_no;
			hashing[loc].name = name;
			hashing[loc].grade = grade;
		} else {
			int i;
			i = (loc + 1) % max;
			while (i != loc) {
				if (hashing[i].roll_no == -1) {
					hashing[i].roll_no = roll_no;
					hashing[i].name = name;
					hashing[i].grade = grade;
					flag = 1;
					break;
				}
				i = (i + 1) % max;
			}
			if (flag == 0)
				cout << "Hash-table full";

		}
		cout << "DO you want to continue";
		cin >> ch;
	} while (ch == 'y');

}

void Hashing::lp_rep() {
	int roll_no, flag = 0, newloc;
	char grade, ch;
	string name;
	Student temp;
	do {
		cout << "\nEnter Student's details:-";
		cout << "\nEnter Roll No.:-";
		cin >> roll_no;
		cout << "\nEnter Name:-";
		cin >> name;
		cout << "\nEnter Grade:-";
		cin >> grade;
		int loc;
		loc = roll_no % max;
		if (hashing[loc].roll_no == -1) {
			hashing[loc].roll_no = roll_no;
			hashing[loc].name = name;
			hashing[loc].grade = grade;
		} else {
			newloc = (hashing[loc].roll_no) % max;
			temp.roll_no = roll_no;
			temp.name = name;
			temp.grade = grade;
			if (loc != newloc) {
				temp.roll_no = hashing[loc].roll_no;
				temp.name = hashing[loc].name;
				temp.grade = hashing[loc].grade;
				hashing[loc].roll_no = roll_no;
				hashing[loc].name = name;
				hashing[loc].grade = grade;
			}
			int i;
			i = (loc + 1) % max;
			while (i != loc) {
				if (hashing[i].roll_no == -1) {
					hashing[i].roll_no = temp.roll_no;
					hashing[i].name = temp.name;
					hashing[i].grade = temp.grade;
					flag = 1;
					break;
				}
				i = (i + 1) % max;
			}
			if (flag == 0) {
				cout << "\nHashtable Full";
			}
		}
		cout << "\nDo you want to continue?y or n:-";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

int main() {
	Hashing h, j;
	int c;
	char t;

	do{
		cout <<"\nEnter your choice:-\n1.Linear Probing without repitition\n2.Linear Probing with repitition";
		cin>>c;
		switch (c) {

	case 1:
		h.lp_wrep();
		h.display();
		break;
	case 2:
		j.lp_rep();
		j.display();
		break;
	default:
		cout << "\nEnter correct choice!!!";
	}
	cout<<"\nDo you want to continue?Y or N";
	cin>>t;
	}while(t=='y'||t=='Y');
	return 0;
}

/*
 OUTPUT
 Enter your choice:-
1.Linear Probing without repitition
2.Linear Probing with repitition1
Enter Student details
Enter roll no.1
Enter NameArpit
Enter gradea
DO you want to continuey
Enter Student details
Enter roll no.2
Enter NameDeepesh
Enter gradea
DO you want to continuey
Enter Student details
Enter roll no.22
Enter NameAryan
Enter gradeb
DO you want to continuey
Enter Student details
Enter roll no.3
Enter NameDhruv
Enter gradec
DO you want to continuen
-1	NULL	-
1	Arpit	a
2	Deepesh	a
22	Aryan	b
3	Dhruv	c
-1	NULL	-
-1	NULL	-
-1	NULL	-
-1	NULL	-
-1	NULL	-

Do you want to continue?Y or Ny

Enter your choice:-
1.Linear Probing without repitition
2.Linear Probing with repitition2

Enter Student's details:-
Enter Roll No.:-1

Enter Name:-Arpit

Enter Grade:-a

Do you want to continue?y or n:-y

Enter Student's details:-
Enter Roll No.:-2

Enter Name:-Deepesh

Enter Grade:-c

Do you want to continue?y or n:-y

Enter Student's details:-
Enter Roll No.:-22

Enter Name:-Aryan

Enter Grade:-b

Do you want to continue?y or n:-y

Enter Student's details:-
Enter Roll No.:-3

Enter Name:-Dhruv

Enter Grade:-b

Do you want to continue?y or n:-n
-1	NULL	-
1	Arpit	a
2	Deepesh	c
3	Dhruv	b
22	Aryan	b
-1	NULL	-
-1	NULL	-
-1	NULL	-
-1	NULL	-
-1	NULL	-

Do you want to continue?Y or Nn*/

