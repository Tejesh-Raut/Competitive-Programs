/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points. 

*/

void reverse(vector<int> &A, int start){
    int n=A.size();
    int mid = (start+n)/2;
    int temp =0;
    for(int i=start; i<mid; i++){
        temp = A[i];
        A[i] = A[n-1-i+start];
        A[n-1-i+start] = temp;
    }
}
void Solution::nextPermutation(vector<int> &A) {
    // reverse(A,0);
    // return;
    int n= A.size();
    int pivot=-1;
    for(int i=(n-1); i>=0; i--){
        if(A[i-1]<A[i]){
            pivot = i-1;
            break;
        }
    }
    if(pivot==-1){
        reverse(A, 0);
        return;
    }
    int swap_with=-1;
    for(int i=(n-1); i>pivot; i--){
        if(A[i]>A[pivot]){
            swap_with = i;
            break;
        }
    }
    int temp = A[pivot];
    A[pivot] = A[swap_with];
    A[swap_with] = temp;
    reverse(A, (pivot+1));
    return;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
