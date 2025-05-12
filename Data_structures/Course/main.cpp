#include <iostream>
#include "course.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Course* csit = new Course();
	student* s;
	char op;
	while (true) {
		cout << "Op: ";
		cin  >> op;
		switch (op) {
			case 'a':
				s = new student;
				cout << "Name: ";
				cin >> s->name;
                cout << "Grade: ";
                cin >> s->grade; 
				csit->addstudent(s);
				break;

			case 'A':
				s= new student;
				cout << "Name: ";
				cin >> s->name;
				cout <<"Grade: ";
				cin >> s->grade;
				cout << "Enter index to insert: ";
				int ind; cin>> ind;

				csit->addAt(ind,s);
				break;
			case 'p':
				csit->print();
				break;

			case 'r':
				s= new student;
				cout << "[Enter student name to remove]: ";
				cin >> s->name;
				cout << endl; 
				cout << "Position: "<< csit->removestudent(s) << endl;
				break;

			case 'R':	
				int t;
				cout<< "Enter index to remove: ";
				cin >> t;
				
				s = csit->removeAt(t);
				cout << "Removed: "<<s->name << " " << s->grade << endl;
				// pede ta mag free sa s ari!
				free(s);
				break;

			case 's':
				csit->sort();
				cout<<"Sorted!" << endl;
				break;


			case 't': 
				cout << "Enter top n students: ";
				int n;
				cin >> n;
				csit->sort();
				csit->topStudents(n);
			break;


			case 'x':
				break;
           
		}
	}
	return 0;
}