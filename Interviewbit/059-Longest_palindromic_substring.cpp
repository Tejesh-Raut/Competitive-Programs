/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/

string Solution::longestPalindrome(string A) {
    int n = A.length();
    vector<bool> temp(n, false);
    
    vector<vector<bool> > isPalin;
    for(int i=0; i<n; i++){
        isPalin.push_back(temp);
    }
    // cout<<"created isPalin "<<endl;
    
    int maxlength = 1;
    for(int i=0; i<n; i++){
        isPalin[i][i] = true;
    }
    // cout<<"done for length 1"<<endl;
    int start = 0;
    for(int i=0; i<(n-1); i++){
        if(A[i]==A[i+1]){
            isPalin[i][i+1] = true;
            start = i;
            maxlength = 2;
        }
    }
    
    for(int k=3; k<=n; k++){
        // cout<<"k "<<k<<endl;
        for(int i=0; i<(n-k+1); i++){
            int j = i+k-1;
            if((isPalin[i+1][j-1])&&(A[i]==A[j])){
                isPalin[i][j] = true;
                if(k>maxlength){
                    start = i;
                    maxlength = k;
                }
            }
        }
    }
    
    string ans="";
    for(int i = start; i<(start+maxlength); i++){
        ans = ans +A[i];
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
