// Ruben Navarro
// 02/14/2020
// Determines if a singly linked list is a palindrome.

#include <iostream>
#include <stack>
#include <cmath>
struct ListNode {
    int val;
    ListNode * next;
    ListNode (int x) : val(x), next(nullptr) {}
};

// displays list
int main() {

        // list construction
        ListNode * head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        head->next->next->next->next = nullptr;


        // returns null is head is null
        if (head == NULL) {
            std::cout << "True" << std::endl;
            return 0;
        }

        // displays list if head is a single node
        if (head != NULL && head->next == NULL) {
            std::cout << "True" << std::endl;
            return 0;
        }

        // pointers for tracking and list traversal
        ListNode * curr = head;
        ListNode *prev = head;
        // counter to keep track of number of nodes
        int counter = 0;
        // stack to hold list values
        std::stack<int> mystack;

        // traverses through list to and adds values to stack
        while (curr != NULL) {
            mystack.push(curr->val);
            curr = curr->next;

            ++counter;
        }

        // resets curr pointer to head of list
        curr = head;
        // formula to get half of list
        float n = float(counter) / 2;
        n = ceil(n);
        int i = 1;

        // if the length of the list if even traverse through the list and pop from stack while comparing both values
        if (counter % 2 == 0) {
            while (curr != NULL) {

                if (curr->val == mystack.top()) {
                    mystack.pop();
                    curr = curr->next;
                }
                else if(curr->val != mystack.top()) {
                    std::cout << "False" << std::endl;
                    return 0;
                }
             }
        }
        // if the length of the list is odd, traverse through the list and compare values. Ensures that middle node is different than adjacent nodes
        else if (counter % 2 != 0) {
            curr = head;
            while (curr != NULL) {

            if (curr->val == mystack.top()) {
                if (n == i && (curr->val == prev->val || curr->val == curr->next->val)) {
                    std::cout << "False" << std::endl;
                    return 0;
                }
                mystack.pop();
                prev = curr;
                curr = curr->next;
            }
            else if (curr->val != mystack.top()) {
                std::cout << "False" << std::endl;
                return 0;
            }
        }
            ++i;
        }

    std::cout << "True" << std::endl;
    return 0;
}
