/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 

*/

int Solution::titleToNumber(string A) {
    int n= A.length();
    int num = 0;
    int digit = 0;
    int fac = 1;
    char a;
    int ia;
    for(int i=0; i<n; i++){
        a = A.at(n-1-i);
        ia = (int)a;
        num += (ia - 64)*fac;
        fac = fac*26;
    }
    return num;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
