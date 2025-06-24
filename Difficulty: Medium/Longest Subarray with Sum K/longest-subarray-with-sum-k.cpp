class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        int n = arr.size();
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == k) maxlen = i + 1;
            else if(mp.find(sum-k) != mp.end()) {
                maxlen = max(maxlen, i - mp[sum-k]);
            }
            
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return maxlen;
    }
};