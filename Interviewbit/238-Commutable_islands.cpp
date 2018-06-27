/*
There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Example :
Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10
In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration. In each row first two numbers represent the islands number which are connected by this bridge and the third integer is the cost associated with this bridge.

In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with cost 3), 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible cost(1+3+2 = 6). 
In any other case, cost incurred will be more.


*/

void joinSets(vector<int> &v, int s1, int s2){
    int a, b;
    if(v[s1-1]>v[s2-1]){
        a = v[s2-1];
        b = v[s1-1];
    }
    else{
        a = v[s1-1];
        b = v[s2-1];
    }
    int n = v.size();
    for(int i=0; i<n; i++){
        if(v[i]==b){
            v[i] = a;
            // cout<<"vertex "<<(i+1)<<" put in set "<<v[s1-1]<<endl;
        }
    }
    return;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pair<int, pair<int, int> > > E;
    int n = B.size();
    for(int i=0; i<n; i++){
        E.push_back(make_pair(B[i][2], make_pair(B[i][0], B[i][1])));
    }
    sort(E.begin(), E.end());
    vector<int> v(A); // to store set number in which vertex is stored
    for(int i=0; i<A; i++){
        v[i] = (i+1);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(v[E[i].second.first - 1]!=v[E[i].second.second - 1]){
            // cout<<"Joined "<<E[i].second.first<<" and "<<E[i].second.second<<endl;
            joinSets(v, E[i].second.first, E[i].second.second);
            ans += E[i].first;
        }
    }
    return ans;
}
