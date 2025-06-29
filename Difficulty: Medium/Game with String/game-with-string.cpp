class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        for(auto &freq:s){
            mp[freq]++;
        }
        // push value into priority queue
        priority_queue<int> pq;
        for(auto &val:mp){
            pq.push(val.second);
        }
        // delete k characters
        while(k>0){
            int temp=pq.top();
            pq.pop();
            temp--;
            pq.push(temp);
            k--;
        }
        // find final ans
        int ans=0;
        while(pq.size()){
            int temp=pq.top();
            pq.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};

