/*
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors.

Example:

Input : 
Prime numbers : [2,3,5] 
k : 5

If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be: 

Output: 
{2,3,4,5,6}

Explanation : 
4 = p1 * p1 ( 2 * 2 )
6 = p1 * p2 ( 2 * 3 )

Note: The sequence should be sorted in ascending order


*/

vector<int> Solution::solve(int A, int B, int C, int D) {
    queue<long long> Q;
    Q.push(A);
    Q.push(B);
    Q.push(C);
    vector<long long> v;
    v.push_back(A);
    int add = 1;
    if(find(v.begin(), v.end(),(B))==v.end()){
        v.push_back(B);
        Q.push(B);
        add++;
    }
    if(find(v.begin(), v.end(),(C))==v.end()){
        v.push_back(C);
        Q.push(C);
        add++;
    }
    int vs = add;
    while(!Q.empty()){
        long long t = Q.front();
        add = 0;
        Q.pop();
        if(find(v.begin(), v.end(),(long long)(t*A))==v.end()){
            v.push_back((long long)(t*A));
            Q.push((long long)(t*A));
            add++;
        }
        if(find(v.begin(), v.end(),(long long)(t*B))==v.end()){
            v.push_back((long long)(t*B));
            Q.push((long long)(t*B));
            add++;
        }
        if(find(v.begin(), v.end(),(long long)(t*C))==v.end()){
            v.push_back((long long)(t*C));
            Q.push((long long)(t*C));
            add++;
        }
        vs += add;
        if(vs>(3*D)){
            break;
        }
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i=0; i<D; i++){
        ans.push_back(v[i]);
    }
    return ans;
}
