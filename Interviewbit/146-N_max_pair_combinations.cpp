/*
Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int ans_count =0;
    int n = A.size();
    int sum;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int> > > q;
    map<pair<int, int>, bool> M;
    M[make_pair(n-1, n-1)] = true;
    q.push(make_pair((A[n-1]+B[n-1]), make_pair((n-1), (n-1))));
    int L, R;
    while(ans_count<n){
        pair<int, pair<int ,int > > p = q.top();
        L = p.second.first;
        R = p.second.second;
        // cout<<"*"<<p.first<<" "<<L<<" "<<R<<endl;
        ans.push_back(p.first);
        ans_count++;
        if(ans_count>=n){
            break;
        }
        q.pop();
        pair<int ,int> pc = make_pair((L-1), R);
        if(M.find(pc)==M.end()){
            q.push(make_pair((A[L-1]+B[R]), pc));
            M[pc] = true;
        }
        pc = make_pair(L, (R-1));
        if(M.find(pc)==M.end()){
            q.push(make_pair((A[L]+B[R-1]), pc));
            M[pc] = true;
        }
    }
    /*
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = n-1;
    int j = n-1;
    while((i>=0)&&(j>=0)&&(ans_count<n)){
        ans.push_back(A[i]+B[j]);
        ans_count++;
        if(ans_count==n){
            break;
        }
        if((A[i-1]+B[j])>=(A[i]+B[j-1])){
            i--;
        }
        else{
            j--;
        }
    }
    */
    return ans;
}
