/*
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

void Solution::reverseWords(string &A) {
    int n = A.length();
    string ans ="";
    string word = "";
    for(int i=0; i<n; i++){
        if(A[i]!=' '){
            word += A[i];
        }
        else{
            if(word.length()!=0){
                if(ans.length()!=0){
                    ans = ' '+ ans;
                }
                ans = word + ans;
                word = "";
            }
        }
    }
    if(word.length()!=0){
        if(ans.length()!=0){
            ans = ' ' +ans;
        }
        ans = word + ans;
    }
    A = ans;
    return;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
