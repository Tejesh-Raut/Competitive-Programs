/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

int Solution::evalRPN(vector<string> &A) {
    stack<int> S;
    int i=0;
    int n = A.size();
    int a, b, c;
    while(i<n){
        if(A[i].compare("+")==0){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            c = a+b;
            S.push(c);
        }
        else{
            if(A[i].compare("-")==0){
                a = S.top();
                S.pop();
                b = S.top();
                S.pop();
                c = b-a;
                S.push(c);
            }
            else{
                if(A[i].compare("*")==0){
                    a = S.top();
                    S.pop();
                    b = S.top();
                    S.pop();
                    c = a*b;
                    S.push(c);
                }
                else{
                    if(A[i].compare("/")==0){
                        a = S.top();
                        S.pop();
                        b = S.top();
                        S.pop();
                        c = b/a;
                        S.push(c);
                    }
                    else{
                        c = stoi(A[i]);
                        S.push(c);
                    }
                }
            }
        }
        i++;
    }
    return S.top();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
