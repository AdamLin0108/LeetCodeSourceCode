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
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        while(slow != nullptr){
            res = max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return res;
    }
};