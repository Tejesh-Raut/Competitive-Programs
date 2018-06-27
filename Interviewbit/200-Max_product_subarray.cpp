/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

*/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    int min=1;
    int max=1;
    int ans=1;
    bool none_pos = true;
    max = A[0];
    for(int i=0; i<n; i++){
        if(A[i]>0){
            none_pos = false;
        }
        if(A[i]>max){
            max = A[i];
        }
    }
    if(none_pos){
        bool cons_neg = false;
        for(int i=0; i<(n-1); i++){
            if((A[i]<0)&&(A[i+1]<0)){
                cons_neg = true;
                break;
            }
        }
        if(!cons_neg){
            return max;
        }
    }
    max =1;
    for(int i=0; i<n; i++){
        if(A[i]>0){
            max *= A[i];
            if(min<0){
                min *= A[i];
            }
        }
        else{
            if(A[i]==0){
                max = 1;
                min = 1;
            }
            else{
                int temp = max;
                if(min<0){
                    max = min*A[i];
                }
                min = temp*A[i];
            }
        }
        if(max>ans){
            ans = max;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
