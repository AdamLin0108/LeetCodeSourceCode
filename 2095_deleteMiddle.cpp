#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    //constructor
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    private:
        Node* head;

    public:
        //constructor
        LinkedList() : head(nullptr) {}

        //destructor
        ~LinkedList(){
            Node* current = head;
            while(current != nullptr){
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

        void append(int val){
            Node* newNode = new Node(val);

            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }

        void printLinkedList() const {
            Node* current = head;
            while(current != nullptr){
                cout << current->data << "->";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
};

int main(){
    LinkedList list;

    list.append(10);
    list.append(20);

    list.printLinkedList();
}

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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty, return nullptr
        if (head == nullptr) return nullptr;

        // If the list has only one node, delete it and return nullptr
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Create a dummy node pointing to the head
        ListNode* prev = new ListNode(0);
        prev->next = head;

        // Initialize two pointers: slow and fast
        ListNode* slow = prev; // Will end up at the node before the middle
        ListNode* fast = head; // Moves twice as fast as slow

        /* Initial Diagram:
        
        prev -> [0] -> [1] -> [2] -> [3] -> [4] -> [5] -> nullptr
                   |
                  slow
                   |
                  head
                   |
                  fast

        */

        // Traverse the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // Move slow by one node
            fast = fast->next->next;     // Move fast by two nodes

            /* Diagram after each iteration:

            Iteration 1:
            slow moves to head (node 1)
            fast moves to node 3

            prev -> [0] -> [1] -> [2] -> [3] -> [4] -> [5] -> nullptr
                          |
                         slow
                                    |
                                   fast

            Iteration 2:
            slow moves to node 2
            fast moves to node 5

            prev -> [0] -> [1] -> [2] -> [3] -> [4] -> [5] -> nullptr
                                 |
                                slow
                                               |
                                              fast

            Iteration 3:
            slow moves to node 3
            fast moves to nullptr (end of list)

            prev -> [0] -> [1] -> [2] -> [3] -> [4] -> [5] -> nullptr
                                          |
                                         slow
                                                       |
                                                      fast (nullptr)

            */
        }

        // Now, slow->next is the middle node
        // Delete the middle node
        ListNode* temp = slow->next;      // Store the middle node
        slow->next = slow->next->next;    // Bypass the middle node

        /* Diagram after deletion:

        Middle node (node 3) is deleted

        prev -> [0] -> [1] -> [2] -------> [4] -> [5] -> nullptr
                                          /
                                  [3] (deleted)
        
        Updated positions:

        slow remains at node 3 (which is now connected to node 4)

        */

        delete temp;                      // Free memory of the middle node

        // Get the new head of the list
        ListNode* newHead = prev->next;

        // Delete the dummy node
        delete prev;

        // Return the modified list
        return newHead;
    }
};

