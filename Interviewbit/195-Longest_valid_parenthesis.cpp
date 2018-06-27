/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


*/

/*
int myFunction(string A, int start){
    int ans = 0;
    int n = A.length();
    stack<bool> S;
    int curr = 0;
    for(int i=start; i<n; i++){
        curr++;
        if(A[i]=='('){
            S.push(true);
        }
        else{
            if(S.empty()){
                return ans;
            }
            S.pop();
            if(S.empty()){
                ans= curr;
            }
        }
    }
    return ans;
}
int Solution::longestValidParentheses(string A) {
    int n = A.length();
    int ans = 0;
    for(int i=0; i<n; i++){
        if(A[i]==')'){
            continue;
        }
        int temp = myFunction(A, i);
        if(temp>ans){
            ans = temp;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
*/

int Solution::longestValidParentheses(string A){
    int n = A.length();
    stack<int> S;
    S.push(-1);
    int result = 0;
    for(int i=0; i<n; i++){
        if(A[i]=='('){
            S.push(i);
        }
        else{
            S.pop();
            if (!S.empty()){
                if((i-S.top())>result){
                    result = i - S.top();
                }
            }
            else{
                S.push(i);
            }
        }
    }
    return result;
}