/*
Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0


*/
int Solution::braces(string A) {
    int i=0;
    stack<char> S;
    while(A[i]!='\0'){
        if((A[i]=='(')||(A[i]=='+')||(A[i]=='*')||(A[i]=='-')||(A[i]=='/')){
            S.push(A[i]);
        }
        else{
            if(A[i]==')'){
                if(S.top()=='('){
                    return 1;
                }
                else{
                    while(S.top()!='('){
                        S.pop();
                    }
                    S.pop();
                }
            }
        }
        i++;
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
