/*
Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.

For example,

N=2
If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
{(1-2), (3-4)} and {(1-4), (2-3)}

So, we return 2.
Notes:

1 ≤ N ≤ 1000
Return answer modulo 109+7.

*/

int Solution::chordCnt(int A){
    vector<long> v(A+1, 0);
    v[0] = 1;
    v[1] = 1;
    for(int i=2; i<=A; i++){
        v[i] = 0;
        for(int j=0; j<i; j++){
            v[i] += v[j]*v[i-j-1];
            v[i] %= 1000000007;
        }
    }
    return v[A];
}
