/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

bool pathExist(string &A, string &B){
    int l = A.length();
    int diff = 0;
    for(int i=0; i<l; i++){
        if(A[i]!=B[i]){
            diff++;
            if(diff>1){
                return false;
            }
        }
    }
    if(diff==1){
        return true;
    }
    else{
        return false;
    }
}
vector<vector<int> > findShortestPath(vector<vector<bool> > &M, int row, int uptil, vector<int> &Map_uptil){
    if(uptil>Map_uptil[row]){
        vector<vector<int> > final_ans;
        return final_ans;
    }
    Map_uptil[row] = uptil;
    int n = M.size() - 2;
    if(M[row][n]){
        // cout<<"direct path from "<<row<<endl;
        vector<int> ans;
        ans.push_back(n);
        ans.push_back(row);
        vector<vector<int> > final_ans;
        final_ans.push_back(ans);
        return final_ans;
    }
    if(row==(n+1)){
        vector<int> ans;
        ans.push_back(n);
        vector<vector<int> > final_ans;
        final_ans.push_back(ans);
        return final_ans;
    }
    int min = -1;
    vector<vector<int> > min_ans;
    vector<vector<int> > t;
    int nt1, nt2;
    for(int i=0; i<n; i++){
        if(M[row][i]){
            // cout<<"**"<<row<<" -> "<<(i+1)<<endl;
            t = findShortestPath(M, (i+1), uptil+1, Map_uptil);
            if(t.size()==0){
                continue;
            }
            nt1 = t.size();
            nt2 = t[0].size();
            if((nt2<min)||(min==-1)){
                min_ans.clear();
                min = nt2;
                for(int j=0; j<nt1; j++){
                    vector<int> ans= t[j];
                    ans.push_back(row);
                    min_ans.push_back(ans);
                }
            }
            else{
                if((nt2==min)){
                    for(int j=0; j<nt1; j++){
                        vector<int> ans= t[j];
                        ans.push_back(row);
                        min_ans.push_back(ans);
                    }
                }
            }
        }
    }
    return min_ans;
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dictV) {
    int l = start.length();
    int n = dictV.size();
    n = n-2;
    // cout<<"n = "<<n<<endl;
    // cout<<"start "<<dictV[n-2]<<" "<<start<<endl;
    // cout<<"end "<<dictV[n-1]<<" "<<end<<endl;
    vector<bool> temp((n+1),false);
    vector<vector<bool> > M((n+2), temp);
    if(start==end){
        vector<string> ans(1,start);
        vector<vector<string> > final_ans(1, ans);
        return final_ans;
    }
    if(pathExist(start, end)){
        vector<string> ans;
        ans.push_back(start);
        ans.push_back(end);
        vector<vector<string> > final_ans(1, ans);
        return final_ans;
    }
    // M[i][j] : path of dictV[i-1] with dictV[j]
    for(int i=0; i<n; i++){
        M[0][i] = pathExist(start, dictV[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i+1][j] = pathExist(dictV[i], dictV[j]);
        }
    }
    for(int i=0; i<n; i++){
        M[i+1][n] = pathExist(end, dictV[i]);
    }
    vector<int> Map_uptil((n+2), (n+2));
    vector<vector<int> > temp_ans = findShortestPath(M, 0, 0, Map_uptil);
    int n1 = temp_ans.size();
    vector<vector<string> > final_ans;
    // cout<<"**************************************************************"<<endl;
    // for(int i=0; i<n1; i++){
    //     int n2 = temp_ans[i].size();
    //     for(int j=(n2-1); j>=0; j--){
    //         cout<<temp_ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"**************************************************************"<<endl;
    for(int i=0; i<n1; i++){
        vector<string> temp;
        temp.push_back(start);
        int n2 = temp_ans[i].size();
        for(int j=(n2-2); j>0; j--){
            temp.push_back(dictV[temp_ans[i][j]-1]);
        }
        temp.push_back(end);
        // if((final_ans.size()==0)||(final_ans[final_ans.size()-1]!=temp))
        if(find(final_ans.begin(), final_ans.end(), temp) == final_ans.end())
        final_ans.push_back(temp);
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
