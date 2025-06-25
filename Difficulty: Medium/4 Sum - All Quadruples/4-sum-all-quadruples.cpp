// User function template for C++

class Solution {
  public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        set<vector<int>>s;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                unordered_map<int,int>m;
                
                for(int k=j+1;k<n;k++){
                    
                    int sum=arr[i]+arr[j]+arr[k];
                    int fourth=target-sum;
                    
                    if(m.find(fourth)!=m.end()){
                        vector<int>temp={arr[i],arr[j],arr[k],fourth};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                   m[arr[k]]=k;
                }
                
            }
        }
        vector<vector<int>>result;
        result.insert(result.begin(),s.begin(),s.end());
        return result;
        
    }
};