/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.


*/

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int n = heights.size();
    vector<pair<int, int> > A(n);
    for(int i=0; i<n; i++){
        A[i] = make_pair(heights[i], infronts[i]);
    }
    sort(A.begin(), A.end());
    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        int k=A[i].second;
        int l=0;
        int j=0;
        for(j=0; j<n; j++){
            if(ans[j]==0){
                l++;
            }
            if(l>k){
                break;
            }
        }
        ans[j] = A[i].first;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
