/**
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                p->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                p->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            p = p->next;
        }

        while(list1) {
            p->next = new ListNode(list1->val);
            list1 = list1->next;
            p = p->next;
        }
        while(list2) {
            p->next = new ListNode(list2->val);
            list2 = list2->next;
            p = p->next;
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        
        while(list1 && list2) {
            if(list1->val < list2->val) {
                p->next = list1;        // 链接list1的节点
                list1 = list1->next;
            } else {
                p->next = list2;        // 链接list2的节点
                list2 = list2->next;
            }
            p = p->next;                 // p移动到新链接的节点
        }

        // 链接剩余节点
        if(list1) {
            p->next = list1;
        }
        if(list2) {
            p->next = list2;
        }

        ListNode* result = dummy->next;
        delete dummy;    // 释放dummy节点
        return result;
    }
};
