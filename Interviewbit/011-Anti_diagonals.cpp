/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    int row, col;
    vector<vector<int> > ans;
    for(int i=0; i<(n-1); i++){
        row=0;
        col=i;
        vector<int> temp;
        while(col>=0){
            temp.push_back(A[row][col]);
            col--;
            row++;
        }
        ans.push_back(temp);
    }
    for(int i=0; i<n; i++){
        row=i;
        col=n-1;
        vector<int> temp;
        while(row<n){
            temp.push_back(A[row][col]);
            col--;
            row++;
        }
        ans.push_back(temp);
    }
    return ans;
}
