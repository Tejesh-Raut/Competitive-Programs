/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

*/

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if(n<3){
        return A[0];
    }
    int ans = -1;
    int can1, can2;
    int count1, count2;
    count1=0;
    count2=0;
    for(int i=0;i<n;i++){
        if((count1==0)&&(count2==0)){
            can1 = A[i];
            count1++;
        }
        else{
            if(count1==0){
                if(can2==A[i]){
                    count2++;
                }
                else{
                    can1 = A[i];
                    count1++;
                }
            }
            else{
                if(count2==0){
                    if(can1==A[i]){
                        count1++;
                    }
                    else{
                        can2 = A[i];
                        count2++;
                    }
                }
                else{
                    if(can1==A[i]){
                        count1++;
                    }
                    else{
                        if(can2 == A[i]){
                            count2++;
                        }
                        else{
                            if(count1!=0){
                                count1--;
                            }
                            if(count2!=0){
                                count2--;
                            }
                        }
                    }
                }
            }
        }
    }
    
    int newcount1=0;
    int newcount2=0;
    for(int i=0; i<n; i++){
        if(A[i]==can1){
            newcount1++;
        }
        else{
            if(A[i] == can2){
                newcount2++;
            }
        }
    }
    if(newcount1>(n/3)){
        return can1;
    }
    else{
        if(newcount2>(n/3)){
            return can2;
        }
        else{
            return -1;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
