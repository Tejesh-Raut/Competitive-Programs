/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/

string Solution::convertToTitle(int A) {
    string ans="";
    int remain = 0;
    while(A>0){
        remain = (A-1)%26;
        A = (A-1)/26;
        char c = 'A';
        c += remain;
        ans = c+ans;
        /*
        if(A==0){
            ans = 'A'+ans;
            break;
        }
        */
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
