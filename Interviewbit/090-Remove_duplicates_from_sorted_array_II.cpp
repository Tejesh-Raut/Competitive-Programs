/*
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].


*/

/*
int Solution::removeDuplicates(vector<int> &A) {
    int i=2;
    // int last = 1;
    // int second_last = 0;
    int n = A.size();
    while(i<n){
        if((A[i]==A[i-1])&&(A[i-1] == A[i-2])){
            A.erase(A.begin()+i);
            n--;
        }
        else{
            i++;
        }
    }
    return n;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
*/
int Solution::removeDuplicates(vector<int> &A){
    int i=2;
    int j=1;
    int n = A.size();
    vector<int> B;
    B.push_back(A[0]);
    if(n>=2){
        B.push_back(A[1]);
        j=2;
    }
    while(i<n){
        if((A[i]==B[j-1])&&(A[i] ==B[j-2])){
            
        }
        else{
            B.push_back(A[i]);
            j++;
        }
        i++;
    }
    A = B;
    return j;
}
