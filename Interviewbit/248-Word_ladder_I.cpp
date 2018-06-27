/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
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
int findShortestPath(vector<vector<bool> > &M, int row, int uptil, vector<int> &Map_uptil){
    if(uptil>Map_uptil[row]){
        return -1;
    }
    Map_uptil[row] = uptil;
    int n = M.size() - 2;
    if(M[row][n]){
        // cout<<"direct path from "<<row<<endl;
        return 1;
    }
    if(row==(n+1)){
        return 0;
    }
    // int nu = uptil.size();
    // for(int i=0; i<nu; i++){
    //     if(uptil[i]==row){
    //         return -1;
    //     }
    // }
    // uptil.push_back(row);
    // for(int i=0; i<=nu; i++){
    //     cout<<uptil[i]<<"->";
    // }
    // cout<<endl;
    
    int min = -1;
    int t;
    for(int i=0; i<n; i++){
        if(M[row][i]){
            // cout<<"**"<<row<<" -> "<<(i+1)<<endl;
            t = findShortestPath(M, (i+1), uptil+1, Map_uptil);
            if(((t!=-1)&&(t<min))||(min==-1)){
                min = t;
            }
        }
    }
    if(min!=-1){
        min++;
    }
    return min;
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    int l = start.length();
    int n = dictV.size();
    n = n-2;
    // cout<<"n = "<<n<<endl;
    // cout<<"start "<<dictV[n-2]<<" "<<start<<endl;
    // cout<<"end "<<dictV[n-1]<<" "<<end<<endl;
    vector<bool> temp((n+1),false);
    vector<vector<bool> > M((n+2), temp);
    if(start==end){
        return 1;
    }
    if(pathExist(start, end)){
        return 2;
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
    int ans = findShortestPath(M, 0, 0, Map_uptil);
    return (ans+1);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
