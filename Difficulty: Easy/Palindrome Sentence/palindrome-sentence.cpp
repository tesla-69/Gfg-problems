class Solution {
  public:
  
    bool check(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
            || (ch >= '0' && ch <= '9')) return true;
            
        return false;
    }
  
    bool isPalinSent(string &s) {
        // code here
        int i = 0; 
        int j = s.size() - 1;
        
        while(i < j) {
            if(check(s[i]) && check(s[j])) {
                s[i] = tolower(s[i]);
                s[j] = tolower(s[j]);
                if(s[i] != s[j]) return false;
                i++;
                j--;
            } 
            else if(check(s[i])) j--;
            else if(check(s[j])) i++;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};