//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution {
  private: 
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse the input lists
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* head = NULL;
        Node* tail = NULL;
        int carry = 0;

        // Process both lists and carry
        while (num1 != NULL || num2 != NULL || carry > 0) {
            int sum = carry;
            if (num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }
            
            int val = sum % 10;
            carry = sum / 10;

            // Create a new node
            Node* newnode = new Node(val);
            // newnode->data = val;
            // newnode->next = NULL;

            if (head == NULL) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        }

        // Reverse the result list
        head = reverse(head);
         while (head != NULL && head->data == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Return the processed list (or NULL if all nodes were zeros)
        return head == NULL ? new Node(0) : head;
        // return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends