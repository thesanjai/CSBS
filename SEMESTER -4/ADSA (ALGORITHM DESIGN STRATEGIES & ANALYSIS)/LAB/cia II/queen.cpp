#include<vector>
2: #include<iostream>
3:
4: #define MAXM 100
5: #define MAXN 50
6:
7: using namespace std;
8:
9: bool isSafe(int board[][MAXN],int n,int row,
int col)
10: {
11: int i, j;
12:
13: /* Check this row on left side */
14: for (i = 0; i < row; i++)
15: if (board[i][col])
16: return false;
17:
18: /* Check upper diagonal on left side */
19: for (i = row, j = col; i >= 0 && j >= 0; i-
-, j--)
20: if (board[i][j])
21: return false;
22:
23: /* Check lower diagonal on left side. But
no need to check.*/
24: /* for (i = row, j = col; j >= 0 && i < n;
i++, j--)
25: if (board[i][j])

26: return false;
27: */
28: /* Check upper diagonal on right side.
But No need to check */
29: for (i = row, j = col; i >= 0 && j < n; i--
, j++)
30: if (board[i][j])
31: return false;
32:
33: /* Check lower diagonal on right side */
34: /* for (i = row, j = col; j < n && i < n; i++,
j++)
35: if (board[i][j])
36: return false;
37: */
38: return true;
39: }
40:
41:
42:
43: /* A recursive utility function to solve N
Queen problem */
44: bool PlaceQueen(int board[MAXM][MAXN], int n,
int r, int Solutions[MAXM][MAXN], int &m)
45: {
46:
47: //Once a solution found - Store it to the
result array
48: if ( r == n)

49: {
50: int k=0;
51: for (int i = 0; i < n; i++)
52: {
53: for (int j = 0; j < n; j++)
54: {
55: if (board[i][j] == 1)
56: Solutions[m][k++]=j + 1;
57: }
58: }
59: m++;
60: return true;
61: }
62:
63:
64: int c;
65: bool res=false;
66:
67: for(c=0;c<n;c++)
68: {
69: if (isSafe(board, n, r, c))
70: {
71: /* Place this queen in board[r][c]
*/
72: board[r][c] = 1;
73:
74: res = PlaceQueen(board, n, r+1,
Solutions, m) || res;
75:

76: // If placing queen in board[r][c]
doesn't lead to a solution,
77: // then remove queen from
board[r][c]
78: board[r][c] = 0; // BACKTRACK
79: }
80: }
81:
82: /* If queen can not be place in any row in
this column col then return false */
83: return res;
84: }
85:
86: bool nQueen(int n, int Solutions[MAXM][MAXN],
int &m)
87: {
88: int board[MAXN][MAXN];
89: int row;
90:
91: for(int i=0;i<n;i++)
92: for(int j=0;j<n;j++)
93: board[i][j] = 0;
94:
95: //Solve by calling the recursive function
to place a queen at row=0
96: row=0;
97: return PlaceQueen(board, n, row, Solutions,

m);
98: }

99:
100: int main()
101: {
102: int n = 4;
103: //For storing results - Array of arrays
104: int Solutions[MAXM][MAXN];
105: int m=0;
106:
107: cout<<"\n\tNumber of Queens: "<<n;
108: if(!nQueen(n, Solutions, m))
109: {
110: cout<<"\n\tCannot be Solved...";
111: return 0;
112: }
113:
114: int i,j;
115:
116: cout<<"\n\tNumber of Solutions Found: "<<m;
117:
118: for (i=0;i<m;i++)
119: {
120: cout<<"\n\t"<<i+1<<". [";
121: for(j=0;j<n;j++)
122: {
123: cout << Solutions[i][j] << " ";
124: }
125: cout << "]";
126: }
127:

128: return
0
;

129:
}
