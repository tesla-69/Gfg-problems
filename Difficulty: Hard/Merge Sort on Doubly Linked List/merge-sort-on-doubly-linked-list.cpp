/* Structure of the node of the list is as
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
      DLLNode *merge(DLLNode *a,DLLNode *b){
        DLLNode *head = new DLLNode(-1);
        DLLNode *ans = head;
        while(a && b){
            if(a->data<b->data){
               head->next = a;
               a->prev=head;
               a=a->next;
               head=head->next;
            }
            else{
               head->next = b;
               b->prev=head;
               b=b->next;
               head=head->next;
            }
        }
        while(a){
           head->next = a;
           a->prev=head;
           a=a->next;
           head=head->next;
        }
        while(b){
           head->next = b;
           b->prev=head;
           b=b->next;
           head=head->next;
        }
        head = ans->next;
        head->prev=NULL;
        return  head;
    }
    DLLNode *sortDoubly(DLLNode *head) {
        if (!head || !head->next) return head;
        DLLNode* slow = head;
        DLLNode* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        DLLNode* mid = slow;
        if (mid->prev) mid->prev->next = nullptr;
        mid->prev = nullptr;
        DLLNode* a = sortDoubly(head);
        DLLNode* b = sortDoubly(mid);
        return merge(a,b);
    }
};