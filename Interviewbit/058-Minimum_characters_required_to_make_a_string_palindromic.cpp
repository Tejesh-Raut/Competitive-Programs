/*
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2


*/

bool isSubstring(string &A, int l, int r){
    while(l<r){
        if(A[l]!=A[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int Solution::solve(string A) {
    int ans =0;
    int n= A.length();
    for(int i=(n-1); i>=0; i--){
        // cout<<i<<endl;
        if(A[i]==A[0]){
            if(isSubstring(A, 0, i)){
                return ans;
            }
            else{
                ans++;
            }
        }
        else{
            ans++;
        }
    }
    return n;
}
