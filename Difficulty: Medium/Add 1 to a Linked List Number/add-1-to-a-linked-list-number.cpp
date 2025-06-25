/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        Node* lastNotNine = NULL;
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data!=9){
                lastNotNine = curr;
            }
            curr=curr->next;
        }
        if(lastNotNine==NULL){
            Node* temp = new Node(1);
            temp->next=head;
            head=temp;
            lastNotNine=temp;
        }
        else{
           lastNotNine->data++; 
        }
        
        curr = lastNotNine->next;
        while(curr!=NULL){
            curr->data = 0;
            curr = curr->next;
        }
        
        return head;
        
    }
};