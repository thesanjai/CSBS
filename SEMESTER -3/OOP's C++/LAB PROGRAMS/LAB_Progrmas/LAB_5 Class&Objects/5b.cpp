#include <iostream>
#include <iomanip>
using namespace std;


class Employee {
private:
    long employeeNumber;
    string name;

public:
    void getData() {
        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Employee Number: ";
        cin >> employeeNumber;
    }

    void putData() {
        cout << setw(20) << setiosflags(ios::left) << "Name: " << name << endl;
        cout << setw(20) << setiosflags(ios::left)  << "Employee Number: " << employeeNumber << endl;
    }
};

int main() {
    int n;
    cout<<"Enter the number of employees: ";
    cin>>n;
    Employee e[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for Employee " << i + 1 << ":" << endl;
        e[i].getData();
    }

   cout << "Employee Information:" << endl;
    for (int i = 0; i < n;i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        e[i].putData();
        cout << endl;
    }

    return 0;
}


