/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    int len = A.size();
    vector<int> B(len, 0);
    bool carry = false;
    if(A[len-1]<9){
        B[len-1] = A[len-1]+1;
    }
    else{
        B[len-1] = 0;
        carry = true;
    }
    for (int i=(len-2); i>=0; i--){
        if(carry){
            if(A[i]<9){
                B[i] = A[i]+1;
                carry = false;
            }
            else{
                B[i] = 0;
            }
        }
        else{
            B[i] = A[i];
        }
    }
    // add 1 as a new MSD if MSD is 9
    if(carry){
        B.insert(B.begin(), 1);
    }
    // remove 0s before most significant digits
    int len1 = B.size();
    for (int i=0; i< len1; i++){
        if(B[0]!=0){
            break;
        }
        else{
            B.erase(B.begin());
        }
    }
    return B;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
