class Solution {
  public:
    vector<int> topKSumPairs(vector<int> &A, vector<int> &B, int K) {
        vector<int>ans;
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        int N = A.size();
        priority_queue<vector<int>>pq;
        set<pair<int,int>>st;
        
        pq.push({(A[0] + B[0]),0,0});
        st.insert({0,0});
        
        while(K-- && !pq.empty()){
            auto top = pq.top();pq.pop();
            int sum = top[0];
            int i = top[1];
            int j = top[2];
            
            if(i + 1 <N && st.count({(i+1),j}) == 0){
                pq.push({(A[i+1] + B[j]), i+1 , j});
                st.insert({(i+1) , j});
            }
            
            if(j + 1 <N && st.count({i,(j+1)}) == 0){
                pq.push({(A[i] + B[j+1]), i , j+1});
                st.insert({i , (j+1)});
            }
            
            ans.push_back(sum);
        }
        return ans;
    }
};