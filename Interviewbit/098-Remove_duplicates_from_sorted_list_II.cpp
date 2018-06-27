/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void printList(ListNode* A){
    ListNode* a = A;
    cout<<"*"<<endl;
    while(a!=NULL){
        cout<<a->val<<"->";
        a = a->next;
    }
    cout<<"*";
    return;
}

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* a = new ListNode(0);
    ListNode* ans = a;
    ListNode*b;
    a->next = A;
    while((a !=NULL)){
        // if(a->val == 19){
        //     printList(ans->next);
        // }
        if(a->next == NULL){
            break;
        }
        if(a->next->next == NULL){
            break;
        }
        if((a->next->val)==(a->next->next->val)){
            // cout<<"*"<<a->next->val<<endl;
            b = a->next;
            while((b->val)==(a->next->val)){
                b = b->next;
                if(b == NULL){
                    break;
                }
            }
            a->next = b;
        }
        else{
            a = a->next;
        }
    }
    return ans->next;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
