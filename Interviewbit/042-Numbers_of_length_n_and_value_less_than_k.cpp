/*
Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

 NOTE: All numbers can only have digits from the given set. 
Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)
Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

*/

int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    int ans = 0;
    int curr;
    // no need to check if C has more digits
    int C_digits = 0;
    int power_10=1;
    while((C/power_10)>0){
        C_digits++;
        power_10 *=10;
    }
    if(C_digits>B){
        int len=n;
        ans = 1;
        for(int i=0; i<B; i++){
            ans = ans*len;
            // len--;
        }
        bool zero_present = false;
        for(int i=0; i<n; i++){
            if(A[i]==0){
                zero_present = true;
            }
        }
        if((zero_present)&&(B!=1)){
            int temp = 1;
            for(int i=0; i<(B-1); i++){
                temp = temp*len;
            }
            ans = ans - temp;
        }
        return ans;
    }
    if(C_digits<B){
        return 0;
    }
    int len = n-1;
    power_10 = power_10/10;
    for(int i=0; i<B; i++){
        curr= (C/power_10)%10;
        // cout<<"curr "<<curr<<endl;
        power_10 = power_10/10;
        int ans1 =0;
        bool equal_present = false;
        for(int j=0; j<n; j++){
            if(A[j]<curr){
                ans1++;
                if((i==0)&&(B!=1)&&(A[j]==0)){
                    ans1--;
                }
            }
            if(A[j]==curr){
                equal_present = true;
            }
        }
        // cout<<"ans1 "<<ans1<<endl;
        int ans2= n;
        int ans3 = 1;
        for(int j=0; j<(B-1-i); j++){
            ans3 *= ans2;
            // ans2 = ans2-1;
        }
        
        ans += ans1*ans3;
        // cout<<"*"<<ans<<endl;
        if(!equal_present){
            break;
        }
        len--;
    }
    return ans;
}
