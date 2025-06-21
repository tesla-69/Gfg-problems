class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        vector<int>ans(2,-1);
        int i;
        for(i=0 ;i<arr.size() ;i++)
        {
            if(arr[i]==x && ans[0]==-1)
            {
                ans[0]=i;
            }
            
            if(ans[0]!=-1 && arr[i]>x)
            {
                ans[1]=i-1;
                break;
            }
        }
        
        if(i==arr.size() && ans[0]!=-1)
        {
            ans[1]=i-1;
        }
        
        return ans;
    }
};