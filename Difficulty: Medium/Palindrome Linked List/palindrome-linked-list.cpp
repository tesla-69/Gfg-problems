/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    bool palin(string &s){
        int l =0,r= s.length()-1;
        
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(Node *head) {
        Node* temp = head;
        string s;
        
        while(temp != NULL){
            s += temp->data;
            temp = temp->next;
        }
        if(palin(s)){
            return true;
        }
        return false;
        
    }
};