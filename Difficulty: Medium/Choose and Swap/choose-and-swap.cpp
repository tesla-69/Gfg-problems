class Solution {
  public:
    string chooseandswap(string str) {
        // Code Here
        char toBeReplaced = '-', replacedWith='-';
        string s = str, temp = str;
        int n = s.length();
        int i=0, j=0;
        
        vector<int>hasSeen(26,0);
        sort(s.begin(), s.end());

        while( i<n && j<n)
        {
            if(str[i] == s[j])
            {
                hasSeen[s[j]-'a'] = 1;
                i++, j++;
            }
            else if(hasSeen[s[j]-'a'])
            {
                j++;
            }
            else if(hasSeen[str[i]-'a'])
            {
                i++;
            }
            else
            {
                if(str[i] > s[j])
                {
                    
                    toBeReplaced = str[i];
                    replacedWith = s[j];
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        
        if(replacedWith != '-')
        for(int k=0; k<n; k++)
        {
            if(temp[k] == toBeReplaced)
            {
                str[k] = replacedWith; 
            }
            if(temp[k] == replacedWith)
            {
                str[k] = toBeReplaced;
            }
        }
        return str;
    }
};

