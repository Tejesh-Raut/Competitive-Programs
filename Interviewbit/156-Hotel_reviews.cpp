/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

*/

struct TrieNode{
    struct TrieNode* children[26];
    bool isLeaf;
    // TrieNode(): children(), isLeaf(true) {}
};
struct TrieNode* getNode(){
    struct TrieNode *pnode = new TrieNode();
    pnode->isLeaf = false;
    for(int i=0; i<26; i++){
        pnode->children[i] = NULL;
    }
    return pnode;
}
void insert(struct TrieNode* root, string key){
    int n = key.length();
    struct TrieNode *curr = root;
    for(int i=0; i<n; i++){
        int c = key[i] - 'a';
        if(curr->children[c]==NULL){
            curr->children[c] = getNode();
        }
        curr = curr->children[c];
    }
    curr->isLeaf = true;
}
bool search(struct TrieNode* root, string key){
    int n = key.length();
    struct TrieNode *curr = root;
    for(int i=0; i<n; i++){
        int c = key[i] - 'a';
        if(curr->children[c]==NULL){
            return false;
        }
        curr = curr->children[c];
    }
    if(curr!=NULL){
        if(curr->isLeaf){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool mycompare(pair<int, int> p1, pair<int, int> p2){
    return (p1.first>p2.first);
}
vector<int> Solution::solve(string A, vector<string> &B) {
    int i=0;
    int len = A.length();
    string s="";
    struct TrieNode *root = getNode();
    while(i<len){
        if(A[i]=='_'){
            insert(root, s);
            // cout<<"inserted -"<<s<<"-"<<endl;
            s = "";
        }
        else{
            s = s+A[i];
        }
        i++;
    }
    insert(root, s);
    // cout<<"built tree"<<endl;
    int num_queries = B.size();
    vector<pair<int, int> > score(num_queries, make_pair(0,0));
    for(i=0; i<num_queries; i++){
        score[i].second = i;
    }
    for(i=0; i<num_queries; i++){
        int j=0;
        int len1 = B[i].length();
        string s1="";
        while(j<len1){
            if(B[i][j]=='_'){
                if(search(root, s1)){
                    score[i].first++;
                }
                s1="";
            }
            else{
                s1 = s1+B[i][j];
            }
            j++;
        }
        if(search(root, s1)){
            score[i].first++;
        }
    }
    stable_sort(score.begin(), score.end(), mycompare);
    vector<int> ans(num_queries);
    for(i=0; i<num_queries; i++){
        ans[i] = score[i].second;
    }
    return ans;
}
