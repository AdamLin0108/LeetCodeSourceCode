/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     // Constructors
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has only one node, return it as is
        if(head == nullptr) return nullptr;

        // Initialize pointers for odd and even nodes
        ListNode* odd = head;             // Starts at the first node (odd position)
        ListNode* even = head->next;      // Starts at the second node (even position)
        ListNode* evenHead = even;        // Save the head of the even list to attach later

        /* Initial State:
         *
         * [1] -> [2] -> [3] -> [4] -> [5] -> NULL
         *  ^      ^
         * odd    even
         *
         * evenHead points to [2]
         */

        // Loop until there are no more even nodes
        while(odd->next != nullptr && even->next != nullptr){
            // Link current odd node to the next odd node
            odd->next = even->next;
            odd = odd->next;              // Move odd pointer to the next odd node

            /* After updating odd pointers:
             *
             * [1] -> [3] -> [4] -> [5] -> NULL
             *         ^
             *        odd
             *
             * [2] -> [3] (still, but will be updated next)
             * evenHead points to [2]
             */

            // Link current even node to the next even node
            even->next = odd->next;
            even = even->next;            // Move even pointer to the next even node

            /* After updating even pointers:
             *
             * [1] -> [3] -> [4] -> [5] -> NULL
             *         ^
             *        odd
             *
             * [2] -> [4] -> [5] -> NULL
             *                ^
             *               even
             *
             * evenHead points to [2]
             */
        }

        // Attach the even list to the end of the odd list
        odd->next = evenHead;

        /* Final State:
         *
         * [1] -> [3] -> [5] -> [2] -> [4] -> NULL
         *  ^                       ^
         * head                    evenHead
         */

        // Return the head of the rearranged list
        return head;
    }
};
