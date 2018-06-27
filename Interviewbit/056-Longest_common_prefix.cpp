/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.


*/

string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string prefix= "";
    if(n==0){
        return prefix;
    }
    int l = A[0].length();
    int i=0;
    char curr;
    bool done = false;
    while(i<l){
        curr = A[0][i];
        for(int j=1; j<n; j++){
            if(A[j][i]!=curr){
                done = true;
                break;
            }
        }
        if(done){
            break;
        }
        prefix += curr;
        i++;
    }
    return prefix;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
