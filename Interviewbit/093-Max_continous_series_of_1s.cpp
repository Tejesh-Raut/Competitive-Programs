/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.


*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int wL=0;
    int wR=0;
    int nZero =0;
    int best = -1;
    int bestwL=0;
    int bestwR=-1;
    int n = A.size();
    while(wR<n){
        if(nZero<=B){
            if(A[wR]==0){
                nZero++;
            }
            wR++;
        }
        if(nZero>B){
            if(A[wL]==0){
                nZero--;
            }
            wL++;
        }
        if((wR-wL)>best){
            best = wR-wL;
            bestwL = wL;
            bestwR = wR;
            // cout<<"*"<<wL<<" "<<wR<<endl;
        }
    }
    vector<int> ans;
    for(int i=bestwL; i<bestwR; i++){
        ans.push_back(i);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
