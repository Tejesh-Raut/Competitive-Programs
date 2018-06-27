/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.


*/

struct mypair{
    int first;
    int second;
};
vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    unordered_map<int, mypair> M;
    vector<vector<int> > ans;
    for(int a=0; a<n; a++){
        for(int b=a+1; b<n; b++){
            int sum1 = A[a]+A[b];
            if(M.find(sum1)==M.end()){
                mypair p;
                p.first = a;
                p.second = b;
                M[sum1] = p;
            }
        }
        for(int c = a+1; c<n; c++){
            for(int d = c+1; d<n; d++){
                int sum2 = A[c]+A[d];
                if(M.find(sum2)!=M.end()){
                    mypair p1 = M[sum2];
                    vector<int> temp;
                    temp.push_back(p1.first);
                    temp.push_back(p1.second);
                    temp.push_back(c);
                    temp.push_back(d);
                    if((p1.second!=c)&&(p1.second!=d)){
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    if(ans.size()==0){
        vector<int> temp;
        return temp;
    }
    sort(ans.begin(), ans.end());
    return ans[0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
