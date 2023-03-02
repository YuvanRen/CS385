/***************************************************************************
 * Name    : student.cpp
 * Author  : Yuvan Rengifo
 * Version : 1.0
 * Date    : February 16, 2023
 * Description : Program to enter and access the GPAs of students.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ***************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Student{

private:
	string first_;
	string last_;
	int id_;
	float gpa_;


public:
	Student(string first, string last, const float gpa, const int id) {
		first_ = first;
		last_ = last;
		gpa_ = gpa;
		id_ = id;
	}


string fullname() const{
    return first_ + " " + last_;
}

int id() const{
    return id_;
}

float gpa() const{
    return gpa_;
}

void print_info() const{
    cout << endl << fullname() << ", GPA: " << fixed << setprecision(2) << gpa() << ", ID: " << id();
}
};

vector<Student> find_failing_students(const vector<Student> &students){
    vector<Student> failing_students;

    for(auto it = students.cbegin(); it != students.cend(); ++it){
        if(it-> gpa() < 1.0)
            failing_students.push_back(*it);
    }
    return failing_students;
}
void print_students(const vector<Student> &student){
    for(long unsigned int i = 0; i < student.size(); i++){
        student[i].print_info();
    }
}

int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;

    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    cout << endl << "All students:" ;
       print_students(students);
       cout << endl;

       cout << endl << "Failing students:";
    if(find_failing_students(students).size() == 0){
           cout << " None" << endl;
       }
       else{
            print_students(find_failing_students(students));
       }
       return 0;

   }
