/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/
int Solution::isPalindrome(string A) {
    int n = A.length();
    int l = 0;
    int r = n-1;
    while(l<r){
        char cl, cr;
        cl = A[l];
        cr = A[r];
        // cout<<"l "<<l<<" r "<<r<<endl;
        if(((cl>='A')&&(cl<='Z'))||((cl>='0')&&(cl<='9'))||((cl>='a')&&(cl<='z'))){
            if(((cr>='A')&&(cr<='Z'))||((cr>='0')&&(cr<='9'))||((cr>='a')&&(cr<='z'))){
                if(cl>='a'){
                    cl = cl - 32;
                }
                if(cr>='a'){
                    cr = cr -32;
                }
                if(cl!=cr){
                    // cout<<"cl "<<cl<<" cr "<<cr<<endl;
                    return 0;
                }
                else{
                    l++;
                    r--;
                }
            }
            else{
                r--;
            }
        }
        else{
            l++;
        }
    }
    return 1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
