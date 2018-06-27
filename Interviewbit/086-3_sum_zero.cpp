/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > ans;
    int n = A.size();
    sort(A.begin(), A.end());
    int j, k, sum;
    for(int i=0; i<(n-2); i++){
        j = i+1;
        k = n-1;
        while(k>j){
            sum = A[i]+A[j]+A[k];
            if(sum==0){
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                temp.push_back(A[k]);
                if(find(ans.begin(), ans.end(), temp) == ans.end()){
                    ans.push_back(temp);
                }
                // ans.push_back(temp);
            }
            if(sum>0){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
