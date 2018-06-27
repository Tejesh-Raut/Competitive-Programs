/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.


*/

int Solution::divide(int dividend1, int divisor1) {
    bool neg = false;
    long long dividend = (long long)dividend1;
    long long divisor = (long long ) divisor1;
    // if(dividend==-2147483648){
        
    // }
    if (dividend<0){
        neg = !neg;
        dividend = -dividend;
    }
    // cout<<dividend<<endl;
    if(divisor<0){
        divisor = -divisor;
        neg = !neg;
    }
    if(divisor==0){
        return INT_MAX;
    }
    // cout<<"divisor"<<divisor<<"dividend"<<dividend<<endl;
    if(divisor>dividend){
        // cout<<"divisor is bigger"<<endl;
        return 0;
    }
    long long final_ans=1;
    while(divisor<=dividend){
        // cout<<"*"<<endl;
        long long ans = 1;
        long long mult = divisor;
        long long over = 1;
        while((mult<<1)<dividend){
            mult<<=1;
            ans<<=1;
            over++;
            if(over>31){
                break;
            }
            // cout<<mult<<"<"<<dividend<<endl;
        }
        if(over>31){
            return INT_MAX;
        }
        dividend -= mult;
        final_ans +=ans;
        if(dividend==divisor){
            final_ans++;
            break;
        }
        // cout<<ans<<endl;
    }
    if(true){
        final_ans--;
    }
    // cout<<final_ans<<endl;
    if((((int)final_ans)<0)&&(!neg)){
        return INT_MAX;
    }
    if(neg){
        final_ans = -final_ans;
        // final_ans--;
    }
    int final_int = (int ) final_ans;
    return final_int;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
