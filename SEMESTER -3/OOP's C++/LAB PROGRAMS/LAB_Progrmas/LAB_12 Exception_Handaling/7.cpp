#include <iostream>
#include <fstream>

using namespace std;

class student {
    string name;
    string course;
    string dob;
    double cgpa;
    int rno;

public:
student(){}
    student(int rno, string name, string course, string dob, double cgpa) {
        this->rno = rno;
        this->name = name;
        this->course = course;
        this->dob = dob;
        this->cgpa = cgpa;
    }

    void write() {
        ofstream op("StudentDetails.txt", ios::app);

        try {
            if (!op.is_open()) {
                throw("ERROR\n");
            }

            op << "Roll No: " << rno << endl;
            op << "Name: " << name << endl;
            op << "Course: " << course << endl;
            op << "D.O.B: " << dob << endl;
            op << "CGPA: " << cgpa << endl << endl;
        }
        catch (const string& em) {
            cout << em;
        }
    }

    void read() {
        ifstream ip("StudentDetails.txt");

        try {
            if (!ip.is_open()) {
                throw("Error opening file");
            }

            string txt;
            while (getline(ip, txt)) {
                cout << txt << endl;
            }
        }
        catch (const string& em) {
            cout << em;
        }
    }

  void trunc(){
  ofstream op("StudentDetails.txt", ios::trunc);

        try {
            if (!op.is_open()) {
                throw("ERROR\n");
            }

            op << "Roll No: " << rno << endl;
            op << "Name: " << name << endl;
            op << "Course: " << course << endl;
            op << "D.O.B: " << dob << endl;
            op << "CGPA: " << cgpa << endl << endl;
        }
        catch (const string& em) {
            cout << em;
        }
    
  }
  
    void control() {
        int choice;
        do {
            cout << "1 - Write into the file\n";
            cout << "2 - Read from the file\n";
            cout << "3 - Truncate and write into the file\n";
            cout << "4 - Update the file\n";
            cout << "5 - Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
           
            switch (choice) {
                case 1: {
                    cout << "Enter roll no: ";
                    cin >> rno;
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter dob: ";
                    cin >> dob;
                    cout << "Enter course: ";
                    cin >> course;
                    cout << "Enter cgpa: ";
                    cin >> cgpa;
                    
                    student S1(rno,name,course,dob,cgpa);
                   
                    S1.write(); 
                    break;
                }
                case 2: {
                student S3;
                    S3.read(); 
                }
                case 3: {
                   student S4;
                    S4.trunc();
                    break;
                }
                case 4: {
                    student S5;
                    S5.write();
                    break;
                }
                case 5: {
                    break; 
                }
                default: {
                    cout << "Invalid choice. Try again.\n";
                    break;
                }
            }
        } while (choice != 5);
    }
};

int main() {
    student s1;
    
    s1.control();

    return 0;
    }

