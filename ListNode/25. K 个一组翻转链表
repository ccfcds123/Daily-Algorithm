给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]

提示：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？

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

// 1. 迭代法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head, *pre = dummy;
        int length = 0;
        while(cur) {
            length++;
            cur = cur->next;
        }
        cur = head;
        for(int i = 0; i < length / k; i++) {
            for(int j = 1; j < k; j++) { // eg.[1,2,3,4,5] k = 2
                ListNode *next = cur->next; // pre = dummy, cur = 1, next = 2
                cur->next = next->next;     // 1->3
                next->next = pre->next;     // 2->1
                pre->next = next;           // dummy->2
            }                               // dummy->2->1->3
            pre = cur;                      // pre = 1
            cur = cur->next;                // cur = 3
        }

        return dummy->next;
    }
};
