/*
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.


*/
int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> S;
    stack<int> Si;
    int n = A.size();
    if(n==0){
        return 0;
    }
    vector<int> left(n,-1);
    S.push(A[0]);
    Si.push(0);
    for(int i=1; i<n; i++){
        while((!S.empty())&&(S.top()>=A[i])){
            S.pop();
            Si.pop();
        }
        if(S.empty()){
            left[i] = -1;
        }
        else{
            left[i] = Si.top();
        }
        S.push(A[i]);
        Si.push(i);
    }
    vector<int> right(n,n);
    stack<int> S1;
    stack<int> S1i;
    S1.push(A[n-1]);
    S1i.push(n-1);
    for(int i=(n-1); i>=0; i--){
        while((!S1.empty())&&(S1.top()>=A[i])){
            S1.pop();
            S1i.pop();
        }
        if(S1.empty()){
            right[i] = n;
        }
        else{
            right[i] = S1i.top();
        }
        S1.push(A[i]);
        S1i.push(i);
    }
    int max_area = A[0];
    int curr;
    for(int i=0; i<n; i++){
        curr = A[i]*(right[i]-left[i]-1);
        if(curr>max_area){
            max_area = curr;
        }
    }
    return max_area;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
