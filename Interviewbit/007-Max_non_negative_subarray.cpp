/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index


*/

vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long int max_sum=0;
    long int curr_sum=0;
    int max_start_index =0;
    int start_index=0;
    int max_len = 0;
    for(int i=0; i<n; i++){
        // cout<<A[i]<<endl;
        if(A[i]>=0 ){
            // cout<<"p";
            curr_sum +=A[i];
        }
        else{
            // cout<<"n";
            // cout<<curr_sum<<endl;
            if(max_sum<curr_sum){
                // cout<<curr_sum<<endl;
                max_sum = curr_sum;
                max_start_index = start_index;
                max_len = i - start_index;
                // return
            }
            else{
                if(max_sum==curr_sum){
                    if(max_len<(i-start_index)){
                        max_start_index = start_index;
                        max_len = i-start_index;
                        // return
                    }
                    else{
                        if(max_len == (i-start_index)){
                            // obviously max_start_index < start_index so return it
                        }
                    }
                }
            }
            curr_sum=0;
            start_index = i+1;
        }
    }
    //end case
    if(max_sum<curr_sum){
        max_sum = curr_sum;
        max_start_index = start_index;
        max_len = n- start_index;
    }
    else{
        if(max_sum==curr_sum){
            if(max_len<(n-start_index)){
                max_start_index = start_index;
                max_len = n-start_index;
            }
        }
    }
    
    vector<int>::const_iterator first = A.begin() + max_start_index;
    vector<int>::const_iterator second = A.begin() + max_start_index + max_len;
    vector<int> newVec(first, second);
    // cout<<curr_sum<<endl;
    // cout<<start_index<<endl;
    // cout<<max_start_index<<endl;
    // cout<<max_len<<endl;
    return newVec;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
