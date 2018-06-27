/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.


*/

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length();
    // int len=0;
    int i=0;
    int ans =0;
    unordered_map<char, bool> M;
    // int i=0;
    for(int j=0; j<n; j++){
        // int i=j;
        for(; i<n; i++){
            if(M.find(A[i])!=M.end()){
                if(M[A[i]]){
                    M[A[j]] = false;
                    break;
                }
            }
            M[A[i]] = true;
        }
        // cout<<"i "<<i<<" j "<<j<<endl;
        if((i-j)>ans){
            ans = (i-j);
        }
        if(i==n){
            break;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
