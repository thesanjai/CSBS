#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> board,int row, int col,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j>=0 ;i--,j--){
         if(board[i][j]){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 and j<n ;i--,j++){
         if(board[i][j]){
            return false;
        }
    }
    return true;
}
void solveQ(vector<vector<int>> &board, int row, int n,vector<vector<int>> &result , int &count){

    if(row==n){
        vector<int> soln;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    soln.push_back(j+1);
                }
            }
        }
        result.push_back(soln);
        count++;
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]=1;
            solveQ(board,row+1,n,result,count);
            board[row][col]=0;
        }
    }
}
int main(int argc, char** argv) {

    int n;
    cout<<"Enter the number of QUEENS: ";
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> result;

    int count=0;
    solveQ(board,0,n,result,count); 

    for(auto i:result){
        for(auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }   
    cout<<"\n TOTAL SOLUTIONS :"<<count;
    return 0;
}