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
    /**
     * Reverses a singly linked list.
     * 
     * Approach:
     * - Iterate through the list.
     * - Reverse the `next` pointer for each node to point to its previous node.
     * - Update pointers as we progress.
     *
     * Example:
     * Initial List:      1 -> 2 -> 3 -> 4 -> 5 -> nullptr
     * Reversed List: nullptr <- 1 <- 2 <- 3 <- 4 <- 5
     *
     * Diagram of the Process:
     * 
     * Initial State:
     *      head -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
     * 
     * Iteration 1:
     *      prev    cur   next
     *       ↓       ↓      ↓
     *     nullptr <- 1    2 -> 3 -> 4 -> 5 -> nullptr
     * 
     * Iteration 2:
     *             prev    cur   next
     *              ↓       ↓      ↓
     *     nullptr <- 1 <- 2    3 -> 4 -> 5 -> nullptr
     * 
     * Iteration 3:
     *                     prev   cur   next
     *                      ↓      ↓      ↓
     *     nullptr <- 1 <- 2 <- 3    4 -> 5 -> nullptr
     * 
     * Iteration 4:
     *                           prev  cur   next
     *                            ↓     ↓      ↓
     *     nullptr <- 1 <- 2 <- 3 <- 4    5 -> nullptr
     * 
     * Iteration 5:
     *                                  prev cur   next
     *                                   ↓    ↓      ↓
     *     nullptr <- 1 <- 2 <- 3 <- 4 <- 5   nullptr
     * 
     * Final State:
     *     head -> 5 -> 4 -> 3 -> 2 -> 1 -> nullptr
     * 
     * @param head Pointer to the head of the linked list.
     * @return Pointer to the head of the reversed linked list.
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // Initialize previous node as nullptr (new tail of the list)
        ListNode* next = nullptr;   // To store the next node temporarily
        ListNode* cur = head;       // Start with the head node

        while(cur != nullptr){
            next = cur->next;       // Step 1: Save the next node
            cur->next = prev;       // Step 2: Reverse the current node's pointer to the previous node
            prev = cur;             // Step 3: Move previous up to the current node
            cur = next;             // Step 4: Move current to the next node
        }

        // By the end of the loop, prev is the new head of the reversed list
        return prev;
    }
};
