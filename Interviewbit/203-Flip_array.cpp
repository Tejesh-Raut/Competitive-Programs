/*
Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

 Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum 

*/

pair<int, int> minSumFlip(int sum, int pos, vector<int> &v, int &n){
    // cout<<"* "<<pos<<endl;
    pair<int, int> ans = make_pair(sum, 0);
    pair<int, int> temp;
    for(int i=(pos+1); i<n; i++){
        if((sum-2*v[i])<0){
            break;
        }
        temp = minSumFlip((sum-2*v[i]), i, v, n);
        temp.second++;
        if(temp<ans){
            ans = temp;
        }
    }
    return ans;
}
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    vector<int> v(n,0);
    vector<pair<int, int> > tempM();
    int initial_sum=0;
    for(int i=0; i<n; i++){
        v[i] = A[i];
        initial_sum += A[i];
    }
    sort(v.begin(), v.end());
    int pos = -1;
    pair<int, int> ans = minSumFlip(initial_sum, pos, v, n);
    return ans.second;
}
