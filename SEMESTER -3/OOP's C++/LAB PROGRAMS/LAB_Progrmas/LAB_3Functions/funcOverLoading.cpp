#include <iostream>
using namespace std;

int add(int a, int b) {
return a + b;
}
int add(int a, int b, int c) {
return a + b + c;
}

double add(double a, double b) {
return a + b;
}
int main() {
int sum1 = add(5, 7);
int sum2 = add(3, 9, 2);
double sum3 = add(3.5, 2.7);
cout << "Sum of 5 + 7: " << sum1 << endl;
cout << "Sum of 3 + 9 + 2: " << sum2 << endl;
cout << "Sum of 3.5 + 2.7: " << sum3 << endl;
return 0;
}
