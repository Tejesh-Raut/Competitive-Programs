/*
Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Example:

Grid:
	1 2 3 4
	2 3 4 5
so we will choose
3 and 5 so sum will be 3 + 5 = 8


Note that you can choose more than 2 numbers


*/

int myFunc(vector<vector<int> > &A, int pos, unordered_map<int, int> &M, int &n){
    if(pos>=n){
        return 0;
    }
    if(M.find(pos)!=M.end()){
        return M[pos];
    }
    int ans1, ans2;
    ans1 = myFunc(A, (pos+1), M, n); // dont pick
    ans2 = myFunc(A, (pos+2), M, n); // pick
    if(A[0][pos]>A[1][pos]){
        ans2 += A[0][pos];
    }
    else{
        ans2 += A[1][pos];
    }
    if(ans2>ans1){
        M[pos] = ans2;
        return ans2;
    }
    else{
        M[pos] = ans1;
        return ans1;
    }
}
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int ans =0;
    unordered_map<int, int> M;
    ans = myFunc(A, 0, M, n);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
