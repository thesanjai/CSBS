#include <iostream>
#include <fstream>

using namespace std;

struct Student {
  string name;
  int rollNo;
  float cgpa;
};

int main() {
  Student s;
  ofstream outFile("students.txt");
  int n;

  cout << "Enter the number of students: ";
  cin >> n;

  for(int i=1; i<=n; i++) {
    cout << "Enter the details of student " << i << ":" << endl;

    cout << "Name: ";
    cin >> s.name;
    outFile << s.name << "\t";

    cout << "Roll Number: ";
    cin >> s.rollNo;
    outFile << s.rollNo << "\t";

    cout << "CGPA: ";
    cin >> s.cgpa;
    outFile << s.cgpa << "\n";
  }

  outFile.close();

  ifstream inFile("students.txt");
  cout << "\nStudent Details:" << endl;
  while(inFile >> s.name >> s.rollNo >> s.cgpa) {
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNo << endl;
    cout << "CGPA: " << s.cgpa << endl;
  }

  inFile.close();

  return 0;
}
