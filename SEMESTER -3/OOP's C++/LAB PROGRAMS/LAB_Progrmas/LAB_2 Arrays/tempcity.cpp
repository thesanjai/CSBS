#include<iostream>
using namespace std;

const int city=2;
const int week=7;

int main(){
 
	int temp[city][week];

	for(int i=0;i<city;i++)
	{
	 for(int j=0;j<week;j++){
	  cout<<"City "<<i+1<<" DAY "<<j+1<<" [ENTER]>>";
	  cin>>temp[i][j];
	 }
	  cout<<endl;
	}

 	cout<<"DISPLAYING THE TEMPERATURE: \n";
	
	for(int i=0;i<city;i++){
	 for(int j=0;j<week;j++){
	    cout<<"City "<<i+1<<" DAY "<<j+1<<"temp[i][j]\n";
	 }
	  cout<<endl;
	}

}
