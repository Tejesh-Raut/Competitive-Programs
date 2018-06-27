/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation : 
  Day 1 : Buy 
  Day 2 : Sell
  Day 3 : Buy
  Day 4 : Sell

*/

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n<2){
        return 0;
    }
    int minLR = A[0];
    int maxRL = A[n-1];
    vector<int> dpLR(n,0);
    vector<int> dpRL(n,0);
    for(int i=1; i<n; i++){
        if(A[i]<minLR){
            minLR = A[i];
        }
        if(dpLR[i-1]>(A[i]-minLR)){
            dpLR[i] = dpLR[i-1];
        }
        else{
            dpLR[i] = A[i] - minLR;
        }
    }
    for(int i=(n-2); i>=0; i--){
        if(A[i]>maxRL){
            maxRL = A[i];
        }
        if(dpRL[i+1]>(maxRL-A[i])){
            dpRL[i] = dpRL[i+1];
        }
        else{
            dpRL[i] = maxRL - A[i];
        }
    }
    int max = 0;
    for(int i=0; i<n; i++){
        if(max<(dpLR[i]+dpRL[i])){
            max = dpLR[i]+dpRL[i];
        }
    }
    return max;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
