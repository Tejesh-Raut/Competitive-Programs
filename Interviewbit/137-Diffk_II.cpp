/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

*/

int Solution::diffPossible(const vector<int> &A, int B) {
    // sort(A.begin(), A.end());
    int n = A.size();
    unordered_map<int, bool> M;
    for(int i=0; i<n; i++){
        if((M.find(A[i]-B) == M.end())&&(M.find(A[i]+B) == M.end())){
            M[A[i]] = true;
        }
        else{
            return 1;
        }
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
