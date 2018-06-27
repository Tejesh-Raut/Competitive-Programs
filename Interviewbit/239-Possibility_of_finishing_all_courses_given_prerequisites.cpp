/*
 There are a total of N courses you have to take, labeled from 1 to N. Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2]. 
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses. return 1/0 if it is possible/not possible.
The list of prerequisite pair are given in two integer arrays B and C where B[i] is a prerequisite for C[i].

 Example: If N = 3 and the prerequisite pairs are [1,2] and [2,3], then you can finish courses in the following order: 1, 2 and 3. But if N = 2 and the prerequisite pairs are [1,2] and [2,1], then it is not possible for you to finish all the courses. 

*/

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<int> v(A);
    vector<int> temp;
    vector<vector<int> > p((A+1), temp);
    vector<vector<int> > r((A+1), temp);
    int t=0;
    for(int i=0; i<n; i++){
        if(C[i]==B[i]){
            return 0;
        }
        p[C[i]].push_back(B[i]);
        r[B[i]].push_back(C[i]);
        t = r[C[i]].size();
        for(int j=0; j<t; j++){
            p[r[C[i]][j]].push_back(B[i]);
            r[B[i]].push_back(r[C[i]][j]);
            if(r[C[i]][j] == B[i]){
                return 0;
            }
        }
        t = p[B[i]].size();
        for(int j=0; j<t; j++){
            r[p[B[i]][j]].push_back(C[i]);
            p[C[i]].push_back(p[B[i]][j]);
            if(p[B[i]][j] == C[i]){
                return 0;
            }
        }
    }
    /*
    for(int i=0; i<(A+1); i++){
        cout<<"P["<<i<<"] = ";
        t = p[i].size();
        for(int j=0; j<t; j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
        cout<<"R["<<i<<"] = ";
        t = r[i].size();
        for(int j=0; j<t; j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 1;
}
