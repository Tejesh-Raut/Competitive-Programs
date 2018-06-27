/*
Find largest distance
Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). The nodes will be numbered 0 through N - 1.

The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N). Exactly one of the i’s will have P[i] equal to -1, it will be root node.

 Example:
If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4  
 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3. Note that there are other paths with maximal distance. 

*/

/*
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n<=1){
        return 0;
    }
    vector<int> depth(n, -1);
    int count = 0;
    for(int i=0; i<n; i++){
        if(A[i]==-1){
            depth[i] = 0;
            count++;
            break;
        }
    }
    while(count<n){
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(A[i]==-1){
                continue;
            }
            if(depth[A[i]]!=-1){
                temp.push_back(A[i]);
                depth[i] = depth[A[i]]+1;
                count++;
            }
            if(count>=n){
                break;
            }
        }
        int n1 = temp.size();
        for(int i=0; i<n1; i++){
            depth[temp[i]] = -1;
        }
    }
    for(int i=0; i<n; i++){
        cout<<" "<<i<<" "<<depth[i]<<"    ";
    }
    cout<<endl;
    sort(depth.begin(), depth.end());
    int ans = 0;
    if(depth[n-2] == -1){
        ans = depth[n-1];
    }
    else{
        // cout<<depth[n-1]<<endl;
        // cout<<depth[n-2]<<endl;
        ans = (depth[n-2]+depth[n-1]);
    }
    return ans;
}
*/

void heightFn(int root, vector<int> &diameter, vector<int> &height, vector<vector<int> > &child){
    if(height[root]!=-1){
        return;
    }
    int max_h = 0;
    int num_child = child[root].size();
    for(int i=0; i<num_child; i++){
        heightFn(child[root][i], diameter, height, child);
        if(max_h<height[child[root][i]]){
            max_h = height[child[root][i]];
        }
    }
    height[root] = max_h+1;
    return;
}
void diameterFn(int root, vector<int> &diameter, vector<int> &height, vector<vector<int> > &child){  
    if(diameter[root]!=-1){
        return;
    }
    int num_child = child[root].size();
    int h1 = 0;
    int h2 = 0;
    int max_dia = 0;
    for(int i=0; i<num_child; i++){
        diameterFn(child[root][i], diameter, height, child);
        heightFn(child[root][i], diameter, height, child);
        if(diameter[child[root][i]]>max_dia){
            max_dia = diameter[child[root][i]];
        }
        if(h2<height[child[root][i]]){
            h1 = h2;
            h2= height[child[root][i]];
        }
        else{
            if(h1<height[child[root][i]]){
                h1 = height[child[root][i]];
            }
        }
    }
    // cout<<"* "<<root<<" H1 "<<h1<<" H2 "<<h2<<endl;
    int ans = max((h1 + h2), max_dia);
    diameter[root] = ans;
    return;
}
int Solution::solve(vector<int> &A){
    int n = A.size();
    if(n<=1){
        return 0;
    }
    vector<int> temp;
    vector<vector<int> > child(n, temp);
    int root=-1;
    for(int i=0; i<n; i++){
        if(A[i]==-1){
            root= i;
            continue;
        }
        child[A[i]].push_back(i);
    }
    vector<int> diameter(n, -1);
    vector<int> height(n, -1);
    diameterFn(root, diameter, height, child);
    heightFn(root, diameter, height, child);
    // for(int i=0; i<n; i++){
    //     cout<<i<<" H "<<height[i]<<" D "<<diameter[i]<<endl;
    // }
    return diameter[root];
}
