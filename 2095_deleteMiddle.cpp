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
        if(head == nullptr) return nullptr;
        ListNode* prev = new ListNode(0);

        prev->next = head;
        ListNode* slow = prev;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return prev->next;
    }
};
