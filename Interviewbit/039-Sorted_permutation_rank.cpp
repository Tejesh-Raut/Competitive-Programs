/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003


*/

long long factorial(int n, vector<long long> &M){
    if(n<=1){
        M[n] = ((long long)1);
        return M[n];
    }
    if(M[n]!=-1){
        return M[n];
    }
    M[n] = (((long long)n)*factorial(n-1, M));
    M[n] %= 1000003;
    return M[n];
}
int Solution::findRank(string A) {
    // return factorial(19);
    int n = A.length();
    char curr;
    int curr_rank;
    long long rank=1;
    vector<long long> M(n, -1);
    for(int i=0; i<n; i++){
        curr = A.at(i);
        curr_rank = 0;
        for(int j=(i+1); j<n; j++){
            if(A.at(j)<curr){
                curr_rank++;
            }
        }
        // cout<<"curr_rank "<<curr_rank<<endl;
        rank = rank + ((long long)curr_rank)*factorial(n-1-i, M);
        rank %= 1000003;
        // cout<<"rank "<<rank<<endl;
    }
    long long ans = (rank%((long long)1000003));
    int final_ans = ans;
    return final_ans;
}
