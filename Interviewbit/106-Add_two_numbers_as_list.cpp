/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(0);
    ListNode* final_ans = ans;
    ListNode* a = A;
    ListNode* b = B;
    int carry = 0;
    int sum = 0;
    while((a!=NULL)||(b!=NULL)||(carry!=0)){
        int ai = 0;
        int bi = 0;
        if(a!=NULL){
            ai = a->val;
            a = a->next;
        }
        if(b!=NULL){
            bi = b->val;
            b = b->next;
        }
        sum = ai+bi+carry;
        carry = 0;
        if(sum>9){
            sum = sum - 10;
            carry = 1;
        }
        ans->val = sum;
        // cout<<"*"<<sum<<endl;
        if((a==NULL)&&(b==NULL)&&(carry==0)){
            break;
        }
        ans->next = new ListNode(0);
        ans = ans->next;
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
