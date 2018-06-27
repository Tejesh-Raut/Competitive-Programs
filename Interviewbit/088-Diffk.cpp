/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.


*/

int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int i=0;
    int j=1;
    int diff;
    while((i<n)&&(j<n)){
        diff = A[j]-A[i];
        if((diff==B)&&(j!=i)){
            return 1;
        }
        if(diff<B){
            j++;
        }
        else{
            i++;
        }
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
