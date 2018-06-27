/*
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example: 
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 

*/

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int i=1;
    int j=1;
    vector<int> B;
    int last = A[0];
    B.push_back(A[0]);
    while(i<n){
        if(A[i]!=last){
            last = A[i];
            j++;
            B.push_back(last);
        }
        i++;
    }
    A= B;
    return j;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
