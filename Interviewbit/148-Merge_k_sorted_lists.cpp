/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int k = A.size();
    ListNode *ans = NULL;
    priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > q;
    // for(int i=0; i<k; i++){
    //     if(A[i]==NULL){
    //         continue;
    //     }
    //     if(A[i]->next!=NULL){
    //         A[i] = A[i]->next;
    //     }
    // }
    for(int i=0; i<k; i++){
        if(A[i]!=NULL){
            q.push(make_pair(A[i]->val, i));
        }
    }
    ListNode *ansp;
    ans = new ListNode((q.top()).first);
    A[(q.top()).second] = A[(q.top()).second]->next;
    if(A[(q.top()).second]!=NULL){
        q.push(make_pair(A[(q.top()).second]->val, (q.top()).second));
    }
    q.pop();
    ansp = ans;
    while(!q.empty()){
        ansp->next = new ListNode((q.top()).first);
        ansp = ansp->next;
        A[(q.top()).second] = A[(q.top()).second]->next;
        if(A[(q.top()).second]!=NULL){
            q.push(make_pair(A[(q.top()).second]->val, (q.top()).second));
        }
        q.pop();
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
