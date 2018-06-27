/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example : 
Given 
s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


*/

bool isPalindrome(string &A, int start, int end){
    int i=start;
    int j = end-1;
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int myFunc(string &A, int start, vector<int> &M){
    // cout<<"** "<<start<<endl;
    if(M[start]!=-2){
        return M[start];
    }
    int n = A.length();
    int min = (n-start-2);
    // cout<<"-* loop started *-"<<endl;
    for(int i=(start+1); i<=n; i++){
        // cout<<":: "<<start<<" "<<i<<endl;
        if(isPalindrome(A, start, i)){
            // cout<<"-- "<<start<<" "<<i<<endl;
            int t = myFunc(A, i, M);
            if(t<min){
                min = t;
            }
        }
    }
    // cout<<"-* loop ended *-"<<endl;
    M[start] = (min+1);
    // cout<<"* "<<start<<" "<<(min+1)<<endl;
    return (min+1);
}
int Solution::minCut(string A) {
    int n = A.length();
    vector<int> M((n+1),-2);
    M[n] = -1;
    M[n-1]=0;
    int ans = myFunc(A, 0, M);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
