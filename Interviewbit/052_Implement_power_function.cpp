/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/

int Solution::pow(int x, int n, int d) {
    long long ans=1;
    if(n==0){
        return (1%d);
    }
    int j = 0;
    ans = 1;//(long long)x;
    ans = ans%((long long)d);
    while(j<n)
    {
        long long ans1 = (long long)x;
        ans1 = ans1%((long long)d);
        int i=0;
        int i1=j;
        for(i=1; i1<=n; i=(2*i)){
            if((i1+i)>n){
                break;
            }
            ans = ans*ans1;
            ans = ans%((long long)d);
            ans1 = ans1*ans1;
            ans1 = ans1%((long long)d);
            i1=i1+i;
        }
        j = i1;
        // cout<<"j="<<j<<endl;
    }
    long long final_ans = ans%((long long)d);
    if(ans<0){
        final_ans = (ans % ((long long )d) + ((long long )d)) % ((long long)d);
    }
    return final_ans;
    // while()
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
