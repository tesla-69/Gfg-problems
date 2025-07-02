class Solution {
  public:
    static bool cmp(pair<int, int> p1, pair<int, int> p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        else{
            return p1.second>p2.second;
        }
    }
    vector<int> topKFrequent(vector<int> &arr, int k) {
        map<int, int> mp;
        vector<pair<int, int>> vp;
        vector<int> ans;
        
        for(auto i: arr) mp[i]++;
        for(auto i: mp){
            vp.push_back({i.first, i.second});
        }
        sort(vp.begin(), vp.end(), cmp);
        
        int i=0;
        while(k--){
            ans.push_back(vp[i++].first);
        }
        
        return ans;
    }
};