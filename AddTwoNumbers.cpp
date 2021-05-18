/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode (0);
        ListNode* curr = head;
        int remainder = 0;
        while(l1 || l2){
            int x = l1? l1->val : 0;
            int y = l2? l2->val : 0;
            int sum = x+y+remainder;
            remainder = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(remainder > 0) {
            curr->next = new ListNode(remainder);
        }
        return head->next;
        
        
    }
};
