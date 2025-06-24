class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        map<char,int> mp;
        for(auto it: s) mp[it]++;
        int cnt = -1;
        map<int,int> mp2;
        for(auto it: mp) {
            mp2[it.second]++;
        }
        if(mp2.size() > 2) return false;
        
        int maxfreq = 0, freq = 0;
        for(auto it: mp2) {
            if(it.second > freq) {
                freq = it.second;
                maxfreq = it.first;
            }
        }
        // cout<<maxfreq<<" "<<freq<<endl;
        bool f = true;
        for(auto &it: mp)  {
            // cout<<it.second<<" ";
            if(it.second != maxfreq) {
                if(f) {
                    if(it.second - 1 == maxfreq || it.second == 1) {
                        f = false;
                        it.second--;
                    }
                }
            }
            // cout<<it.second<<"   ";
        }
        
        for(auto it: mp) {
            if(it.second != maxfreq && it.second != 0) return false;
        }
        return true;
    }
    
};







