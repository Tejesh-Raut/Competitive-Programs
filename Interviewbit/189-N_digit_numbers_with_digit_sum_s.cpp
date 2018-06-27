/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4 
Valid numbers are {22, 31, 13, 40} 
Hence output 4.


*/

// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator () (const std::pair<T1,T2> &p) const {
//         auto h1 = std::hash<T1>{}(p.first);
//         auto h2 = std::hash<T2>{}(p.second);

//         // Mainly for demonstration purposes, i.e. works but is overly simple
//         // In the real world, use sth. like boost.hash_combine
//         return h1 ^ h2;  
//     }
// };

int mySolve(int A, int B, vector<vector<int> > &M){
    // cout<<"*"<<A<<" "<<B<<endl;
    if(A==0){
        if(B==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(B==0){
        return 1;
    }
    long long count = 0;
    int i=0;
    while(((B-i)>=0)&&(i<=9)){
        if(M[A-1][B-i]==-1){
            count += (long long)mySolve((A-1), (B-i), M);
            count %= 1000000007;
        }
        else{
            // cout<<"**"<<(A-1)<<" "<<(B-i)<<endl;
            count += M[A-1][B-i];
            count %= 1000000007;
        }
        i++;
    }
    count %= 1000000007;
    M[A][B] = (int) count;
    return count;
}
int Solution::solve(int A, int B) {
    if(A==0){
        return 0;
    }
    if(B==0){
        if(A==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    long long count =0;
    int i=1;
    vector<int> temp(B, -1);
    vector<vector<int> > M (A, temp);
    while(((B-i)>=0)&&(i<=9)){
        count += (long long)mySolve((A-1), (B-i), M);
        count %= 1000000007;
        i++;
    }
    count %= 1000000007;
    return count;
}
