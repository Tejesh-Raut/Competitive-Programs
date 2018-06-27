/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *mycloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &M) {  
    if(M.find(node)!=M.end()){
        return M[node];
    }
    // cout<<"Cloning "<<node->label<<endl;
    UndirectedGraphNode * ans = new UndirectedGraphNode(node->label);
    M[node] = ans;
    vector<UndirectedGraphNode *> temp;
    int n = (node->neighbors).size();
    // bool self_loop = false;
    for(int i=0; i<n; i++){
        // if((node->neighbors)[i] == node){
        //     self_loop = true;
        //     continue;
        // }
        UndirectedGraphNode *t = mycloneGraph((node->neighbors)[i], M);
        temp.push_back(t);
    }
    
    ans->neighbors = temp;
    // if(self_loop){
    //     (ans->neighbors).push_back(ans);
    // }
    
    // cout<<"Cloned "<<ans->label<<endl;
    return ans;
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> M;
    UndirectedGraphNode *ans = mycloneGraph(node, M);
    return ans;
}
