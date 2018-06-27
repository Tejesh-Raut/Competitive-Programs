/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int len= A.size();
    int a, b;
    a=0;
    b=0;
    long long sum = 0;
    long long sum1 = 0;
    long long sumsq = 0;
    long long sumsq1 = 0;
    for(int i=0; i<len; i++){
        sum += (long long) A[i];
        sum1 += (long long) (i+1);
        sumsq += (long long) A[i] * (long long) A[i];
        sumsq1 += (long long)(i+1) * (long long) (i+1);
    }
    // a-b = sum - sum1
    // a*a - b*b = sumsq - sumsq1
    // a+b = (sumsq - sumsq1)/(sum - sum1)
    a = (int)(((sum - sum1)+abs((sumsq - sumsq1)/(sum - sum1)))/2);
    b = a - (int)(sum - sum1);
    vector<int> ans(2,0);
    ans[0] = a;
    ans[1] = b;
    // cout<<"a+b "<<((sumsq - sumsq1)/(sum - sum1))<<endl;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
