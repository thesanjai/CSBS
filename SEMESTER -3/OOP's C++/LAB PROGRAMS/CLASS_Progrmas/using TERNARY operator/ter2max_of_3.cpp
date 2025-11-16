#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cout<<"Enter three numbers: ";
	cin>>a>>b>>c;

	int max=(a>b)?(a>c?a:c):(b>c?b:c);
	cout<<"MAX="<<max;
	return 0;
}
