/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

*/

bool isPrime(int n){
    if(n==1){
        return false;
    }
    for(int i=2; i<n; i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A) {
    for(int i=1; i<=(A/2); i++){
        if(isPrime(i)&&isPrime(A-i)){
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
}
