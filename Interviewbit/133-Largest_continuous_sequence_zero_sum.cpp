/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

*/

vector<int> Solution::lszero(vector<int> &A) {
    // unordered_map<int, vector<int> > M;
    int n = A.size();
    int len=0;
    int bestlen=0;
    // vector<int> temp3;
    vector<int> sum((n+1),0);
    int currsum=0;
    for(int i=0; i<n; i++){
        currsum +=A[i];
        sum[i+1] = currsum;
    }
    vector<int> ans;
    int ansi=0;
    int ansj = -1;
    // int sum;
    // M[0] = temp3;
    for(int i=0; i<n; i++){
        // vector<int> temp;
        // sum = 0;
        for(int j=i; j<n; j++){
            // vector<int> temp2;
            // temp.push_back(A[j]);
            // sum += A[j];
            // temp2 = temp;
            if(sum[j+1]==sum[i]){
                // cout<<"*"<<i<<"*"<<j<<endl;
                len = j-i+1;
                if(bestlen<len){
                    bestlen = len;
                    // M[len] = temp2;
                    // ans = temp2;
                    ansi = i;
                    ansj = j;
                }
                // if(M.find(len) == M.end()){
                //     M[len] = temp2;
                // }
            }
        }
    }
    for(int i=ansi; i<=ansj; i++){
        ans.push_back(A[i]);
    }
    return ans;
    // for(int i=n; i>=0; i--){
    //     // cout<<"***"<<i<<endl;
    //     if(M.find(i) == M.end()){
    //     }
    //     else{
    //         return M[i];
    //     }
    // }
}
