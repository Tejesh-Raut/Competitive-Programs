/*
There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

Notes:

Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be upto 109.
For example,

N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13


So, we return [2, 1, 5].


*/

pair<long long, vector<int> > myFunct(vector<int> &A, int len_start, int len_end){
    // vector<int> A;
    // int n = B.size();
    // for(int i=0; i<n; i++){
    //     if((B[i]!=len_start)&&(B[i]!=len_end)){
    //         A.push_back(B[i]);
    //     }
    // }
    int n = A.size();
    if(n==0){
        vector<int> ans2;
        return (make_pair((len_end-len_start), ans2));
    }
    pair<long long, vector<int> > t1, t2;
    long long min_cost = LLONG_MAX;
    vector<int> v1, v2;
    vector<int> ans;
    int flag = true;
    for(int i=0; i<n; i++){
        if((A[i]<=len_start)||(A[i]>=len_end)){
            continue;
        }
        flag = false;
        t1 = myFunct(A, len_start, A[i]);
        t2 = myFunct(A, A[i], len_end);
        if((t1.first + t2.first)<min_cost){
            min_cost = t1.first + t2.first;
            v1 = t1.second;
            v2 = t2.second;
            ans.clear();
            ans.push_back(A[i]);
            ans.insert(ans.end(), v1.begin(), v1.end());
            ans.insert(ans.end(), v2.begin(), v2.end());
        }
    }
    if(flag){
        vector<int> ans2;
        return (make_pair((len_end-len_start), ans2));
    }
    return (make_pair((len_end-len_start+min_cost), ans));
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    pair<int, vector<int> > ans = myFunct(B, 0, A);
    return ans.second;
}
