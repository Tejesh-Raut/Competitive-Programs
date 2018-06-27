/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])


*/

struct mypair{
    int first;
    int second;
};
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    unordered_map<int, vector<mypair> > M;
    int n = A.size();
    int nin;
    for(int i=0; i<n; i++){
        for(int j=(i+1); j<n; j++){
            if(M.find(B-A[i]-A[j])!=M.end()){
                vector<int> temp(4,0);
                vector<mypair> temp2 = M[B-A[i]-A[j]];
                nin = temp2.size();
                for(int k=0; k<nin; k++){
                    mypair temp1;
                    temp1 = temp2[k];
                    temp[0] = temp1.first;
                    temp[1] = temp1.second;
                    temp[2] = A[i];
                    temp[3] = A[j];
                    if(find(ans.begin(), ans.end(), temp) == ans.end()){
                        ans.push_back(temp);
                    }
                }
                // ans.push_back(temp);
            }
        }
        for(int k=0; k<i; k++){
            mypair temp1;
            temp1.first = A[k];
            temp1.second = A[i];
            // if(A[k] == -9){
            //     cout<<"*"<<A[k]<<" "<<A[i]<<endl;
            // }
            if(M.find(B-A[i]-A[k])!= M.end()){
                vector<mypair> temp2 = M[A[i]+A[k]];
                nin = temp2.size();
                if(nin!=0){
                    if((temp2[nin-1].first!=temp1.first)&&(temp2[nin-1].second!=temp1.second)){
                        M[A[i]+A[k]].push_back(temp1);
                    }
                    else{
                        vector<mypair> temp2;
                        temp2.push_back(temp1);
                        M[A[i]+A[k]] = temp2;
                    }
                }
            }
            else{
                vector<mypair> temp2;
                temp2.push_back(temp1);
                M[A[i]+A[k]] = temp2;
            }
            // M[A[i]+A[k]] = temp1;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
