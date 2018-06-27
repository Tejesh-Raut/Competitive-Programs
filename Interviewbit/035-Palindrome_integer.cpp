/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

*/

bool isPalUtil(int num, int* dupNum)
{
    if (num >= 0 && num < 10)
        return (num == (*dupNum) % 10);
     if (!isPalUtil(num/10, dupNum))
        return false;
     *dupNum /= 10;
     return (num % 10 == (*dupNum) % 10);
}
bool Solution::isPalindrome(int A) {
    int *dupNum = new int(A);
    return isPalUtil(A, dupNum);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
