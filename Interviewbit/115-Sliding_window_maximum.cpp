/*
A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. You have to find the maximum for each window. The following example will give you more clarity.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max of the array. 

*/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    if(B>n){
        int max = A[0];
        for(int i=1; i<n; i++){
            if(A[i]>max){
                max = A[i];
            }
        }
        vector<int> ans;
        ans.push_back(max);
        return ans;
    }
    vector<int> ans(n-B+1);
    deque<int>  Q(B);
    int i;
    for(i=0; i<B; i++){
        while((!Q.empty())&&(A[i]>A[Q.back()])){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for(;i<n;i++){
        ans[i-B] = A[Q.front()];
        while((!Q.empty())&&(Q.front()<=(i-B))){
            Q.pop_front();
        }
        while((!Q.empty())&&(A[i]>=A[Q.back()])){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    ans[n-B] = A[Q.front()];
    /*
    vector<int> temp(B,0);
    for(int i=0; i<B; i++){
        temp[i] = A[i];
    }
    sort(temp.begin(), temp.end());
    int max = temp[B-1];
    stack<int> S;
    for(int i=0; i<B; i++){
        S.push(temp[i]);
    }
    vector<int> ans(n-B+1);
    
    ans[0] = max;
    for(int i=1; i<=(n-B); i++){
        if(S.top()==A[i-1]){
            S.pop();
        }
        if(S.empty()){
            S.push(A[i+B-1]);
        }
        else{
            if(A[i+B-1]>S.top()){
                S.push(A[i+B-1]);
            }
        }
        ans[i] = S.top();
    }
    */
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
