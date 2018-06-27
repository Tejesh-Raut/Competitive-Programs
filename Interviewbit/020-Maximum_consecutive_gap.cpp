/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

*/

int Solution::maximumGap(const vector<int> &A) {
    int n= A.size();
    if(n<2){
        return 0;
    }
    int max = A[0];
    int min = A[0];
    for(int i=1; i<n; i++){
        if(A[i]>max){
            max = A[i];
        }
        if(A[i]<min){
            min = A[i];
        }
    }
    int bucket_size = (max-min)/(n-1);
    if(bucket_size<1){
        bucket_size = 1;
    }
    int bnum = (max-min)/bucket_size +1;
    vector<bool> bucket_used(bnum, false);
    vector<int> bucket_min(bnum, max);
    vector<int> bucket_max(bnum, min);
    int bucket_no;
    for(int i=0; i<n; i++){
        bucket_no = (A[i]-min)/bucket_size;
        bucket_used[bucket_no] = true;
        if(bucket_min[bucket_no]>A[i]){
            bucket_min[bucket_no] = A[i];
        }
        if(bucket_max[bucket_no]<A[i]){
            bucket_max[bucket_no] = A[i];
        }
    }
    int prev_bucket_max=min;
    int max_gap=0;
    for(int i=0; i<bnum; i++){
        if(bucket_used[i]){
        if(max_gap<(bucket_min[i]-prev_bucket_max)){
            max_gap = bucket_min[i]-prev_bucket_max;
        }
        prev_bucket_max = bucket_max[i];
        }
    }
    return max_gap;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
