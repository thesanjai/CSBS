#include <iostream>
using namespace std;

int returnByValue(int x) {
int result = x * 2;
return result; 
}

int &returnByReference(int& x) {
x *= 3;
return x; 
}
int main()
{
int a = 5;
cout << "Original value of 'a': " << a << endl;

int b = returnByValue(a); 
cout << "Value returned by value: " << b << endl; 

int c = returnByReference(a); 
cout << "Value returned by reference: " << c <<endl; 

cout << "Original value of 'a': " << a << endl;

int d = returnByValue(a); 
cout << "Value returned by value: " << d << endl; 


return 0;
}
