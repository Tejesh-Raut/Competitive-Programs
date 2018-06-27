/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.


*/

int Solution::lengthOfLastWord(const string &A) {
    int count =0;
    int last_count =0;
    int i=0;
    while(A[i]!='\0'){
        // cout<<i<<","<<A[i]<<","<<endl;
        // cout<<last_count<<endl;
        
        if(A[i]==' '){
            if(count!=0){
                last_count = count;
            }
            count=0;
        }
        else{
            count++;
        }
        i++;
    }
    if(count!=0){
        last_count = count;
    }
    return last_count;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
