/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011" 
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX.
n is reasonable enough to make sure the answer does not bloat up a lot. 

*/

int factorial(int n){
    if(n<=1){
        return (1);
    }
    else{
        return ((n)*factorial(n-1));
    }
}
string Solution::getPermutation(int n, int k) {
    string ans = "";
    long long fac;
    int r;
    int j;
    // vector<int> num(n,0);
    // for(int i=0; i<n; i++){
    //     num[i] = i+1;
    // }
    vector<bool> flag(n, true);
    for(int i=(n-1); i>=0; i--){
        if(i>12){
            for(int l=0; l<n; l++){
                if(flag[l]){
                    flag[l] = false;
                    ans+= to_string(l+1);
                    break;
                }
            }
            
        }
        else{
            fac = factorial(i);
            // cout<<fac<<endl;
            r = ((k-1)/fac);
            k = k- (r*fac);
            // cout<<"***"<<r<<endl;
            j=0;
            for(int l=0; l<n; l++){
                if(flag[l]){
                    if(j==r){
                        flag[l] = false;
                        ans += to_string(l+1);
                        // cout<<"*"<<(l+1)<<endl;
                        break;
                    }
                    j++;
                }
            }
        }
    }
    // ans += to_string(5);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}



