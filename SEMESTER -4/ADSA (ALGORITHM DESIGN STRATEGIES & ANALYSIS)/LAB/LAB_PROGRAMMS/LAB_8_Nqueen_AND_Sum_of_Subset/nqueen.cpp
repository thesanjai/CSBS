#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> board, int row, int col, int N){
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

	for(int i=row,j=col;i>=0 and j<N ;i--,j++){
		if(board[i][j]){
			return false;
		}
	}

	return true;
}

void solveNQ(vector<vector<int>> &board, vector<vector<int>> &solutions, int row, int N ,int &count){ 

	if(row== N){
		
		vector<int> soln;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j]){
					soln.push_back(++j);
				}
			}
		}
		solutions.push_back(soln);
		count++;
		return;
	}

	for(int col=0;col<N;col++){
		if(isSafe(board,row,col,N)){

			board[row][col] = 1;

			solveNQ(board,solutions,row+1,N,count);

			board[row][col] =0; //backTrack
		}
	}
}

int main(int argc, char** argv){
	int N;
	cout<<"Enter the number of Queens (N) : ";
	cin>>N;

	
	vector<vector<int>> board(N,vector<int>(N,0));
	vector<vector<int>> solutions;
	int count =0;

	solveNQ(board,solutions,0,N,count);

	

	for(auto i: solutions){
		cout<<"[";
		for(auto j:i){
			cout<<"\t"<<j;	
		}
		cout<<"]"<<endl;
	}
	cout<<"Total solutions: "<<count<<endl;
	return 0;
}
