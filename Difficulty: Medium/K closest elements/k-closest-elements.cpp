class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n = arr.size();
        int i;
        for(i = 0; i < n; i++) {
            if(arr[i] >= x) break;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        for(int j = i; j < n; j++) {
            if(arr[j] == x) continue;
            int diff = abs(x - arr[j]);
            pq.push({diff, arr[j]});
        }
        for(int j = i-1; j>=0; j--) {
            int diff = abs(arr[j]-x);
            pq.push({diff, arr[j]});
        }
        vector<int> ans;
        while(k--){
            auto ele = pq.top();
            pq.pop();
            if(!pq.empty() && pq.top().first == ele.first && pq.top().second 
            > ele.second) {
                auto temp = pq.top();
                pq.pop();
                pq.push(ele);
                ele = temp;
            }
            ans.push_back(ele.second);
        }
        return ans;
    }
};