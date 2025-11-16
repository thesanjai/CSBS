#include <iostream>
#include<algorithm>
#include<cctype>

using namespace std;

template <class t>

t findmax(t a,t b){
    return max(a,b);
}

template<>
char findmax<char> (char a,char b){
    return max(toupper(a),toupper(b));
}

int main() {
    
    cout<<"Integer(max): "<<findmax(10,20)<<endl;
    cout<<"Float(max): "<<findmax(10.4,10.3)<<endl;
    cout<<"Char(max): "<<findmax('S','i')<<endl;

    return 0;
}
