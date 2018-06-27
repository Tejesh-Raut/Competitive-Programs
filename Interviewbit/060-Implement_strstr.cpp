/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

*/

int Solution::strStr(const string &haystack, const string &needle) {
    int n= haystack.length();
    int m= needle.length();
    if(m==0){
        return -1;
    }
    // int ans = -1;
    bool flag = false;
    for(int i=0; i<(n-m+1); i++){
        flag = false;
        for(int j=i; j<(i+m); j++){
            if(haystack[j]!=needle[j-i]){
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        else{
            return i;
        }
    }
    return -1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
