/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 

*/

struct TrieNode{
    struct TrieNode* children[26];
    int num_children;
    bool isLeaf;
};
struct TrieNode* getNode(){
    struct TrieNode *pnode = new TrieNode();
    pnode->isLeaf = false;
    for(int i=0; i<26; i++){
        pnode->children[i] = NULL;
    }
    pnode->num_children = 0;
    return pnode;
}
void insert(struct TrieNode* root, string key){
    int n = key.length();
    struct TrieNode *curr = root;
    for(int i=0; i<n; i++){
        int c = key[i] - 'a';
        if(curr->children[c]==NULL){
            curr->children[c] = getNode();
            curr->num_children++;
        }
        curr = curr->children[c];
    }
    curr->isLeaf = true;
}
void myFunction(vector<string> &ans, TrieNode *root, string s, string curr, bool found){
    if(root->num_children==0){
        if(!found){
            s = curr;
        }
        found = true;
        // cout<<"*"<<curr<<endl;
        // cout<<"**"<<s<<endl;
        if(ans.size()==0){
            ans.push_back(s);
            return;
        }
        if(ans[ans.size()-1].compare(s)!=0){
            ans.push_back(s);
        }
        return;
    }
    if(root->num_children==1){
        if(!found){
            s = curr;
        }
        found = true;
    }
    else{
        found = false;
    }
    for(int i=0; i<26; i++){
        if(root->children[i]==NULL){
            continue;
        }
        string temp = curr + (char)('a'+i);
        myFunction(ans, root->children[i], s, temp, found);
    }
    return;
}
vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    struct TrieNode *root = getNode();
    for(int i=0; i<n; i++){
        insert(root, A[i]);
    }
    vector<string> ans;
    string s="";
    myFunction(ans, root, s, s, false);
    // return ans;
    vector<int> indices(n,0);
    vector<bool> alloted(n, false);
    for(int i=0; i<n; i++){
        int len = ans[i].size();
        for(int j=0; j<n; j++){
            int len2 = A[j].size();
            if((!alloted[j])&&(len2>=len)){
                int k=0;
                for(k=0; k<len; k++){
                    if(ans[i][k]!=A[j][k]){
                        break;
                    }
                }
                if(k==len){
                    alloted[j]=true;
                    indices[j]=i;
                }
            }
        }
    }
    vector<string> final_ans(n);
    for(int i=0; i<n; i++){
        final_ans[i]= ans[indices[i]];
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
