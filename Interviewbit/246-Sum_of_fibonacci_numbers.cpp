/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

*/

int Solution::fibsum(int A) {
    vector<int> v(2,1);
    int n = 2;
    while((v[n-1]+v[n-2])<=A){
        v.push_back(v[n-1]+v[n-2]);
        n++;
    }
    int sum = A;
    int ans = 0;
    while(sum>0){
        for(int i=n-1; i>=0; i--){
            if(v[i]<=sum){
                sum -= v[i];
                ans++;
                break;
            }
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
