// Source : https://leetcode.com/problems/add-two-numbers/
// Author : daming
// Date   : 2017-01-18

/*************************************************************************************** 
 *
 * You are given two non-empty linked lists representing two non-negative integers. The 
 * digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 
 * itself.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 ***************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int val){
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = NULL;
    return ret;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int val = 0;
    struct ListNode* head = NULL; 
    struct ListNode* p = NULL;
    
    while(l1 != NULL && l2 != NULL){
        val = l1->val + l2->val + carry;
        carry = val/10;
        l1 = l1->next;
        l2 = l2->next;
        if (head == NULL){
            head = newNode(val%10);
            p = head;
        } else {
            p->next = newNode(val%10);
            p = p->next;
        }
    }
    while (l1 != NULL){
        val = l1->val + carry;
        carry=val/10;
        p->next = newNode(val%10);
        p = p->next;
        l1=l1->next;
    }
    while (l2 != NULL){
        val = l2->val + carry;
        carry=val/10;
        p->next = newNode(val%10);
        p = p->next;
        l2=l2->next;
    }
    if (carry > 0) p->next = newNode(carry);
    
    return head;
}
