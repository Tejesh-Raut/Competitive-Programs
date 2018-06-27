/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.


*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A==NULL){
        return NULL;
    }
    RandomListNode* ans = new RandomListNode(A->label);
    RandomListNode* Ap = A;
    RandomListNode* ansp = ans;
    unordered_map<RandomListNode* , RandomListNode*> M;
    M[Ap] = ansp;
    // M[NULL] = NULL;
    while((Ap->next)!=NULL){
        ansp = new RandomListNode(Ap->next->label);
        Ap = Ap->next;
        M[Ap] = ansp;
    }
    Ap = A;
    ansp = ans;
    while((Ap->next)!=NULL){
        ansp->next = M[Ap->next];
        if((Ap->random)!=NULL){
            ansp->random = M[Ap->random];
        }
        ansp = ansp->next;
        Ap = Ap->next;
    }
    if((Ap->random)!=NULL){
        ansp->random = M[Ap->random];
    }
    return ans;
}
