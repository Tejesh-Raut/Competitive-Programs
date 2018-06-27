/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

*/

void Solution::sortColors(vector<int> &A) {
    int i,j;
    i=0;j=0;
    int l=0;
    int n=A.size();
    while(l<n){
        if(A[l]==0){
            i++;
            j++;
        }
        else{
            if(A[l]==1){
                j++;
            }
        }
        l++;
    }
    for(l=0;l<i;l++){
        A[l] = 0;
    }
    for(l=i; l<j;l++){
        A[l] = 1;
    }
    for(l=j; l<n; l++){
        A[l] = 2;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
