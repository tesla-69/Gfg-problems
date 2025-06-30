class Solution {
  public:
  
    // int isValid(vector<int> arr, int k, int mid, int w) {
    //     int n = arr.size();
    //     for(int i = 0; i < n; i++) {
    //         int temp = mid - arr[i];
    //         if(temp > k) return false;
    //         k -= temp;
    //         arr[i] += temp;
    //         for(int j = i+1; j < n && j < i + w; j++) arr[j] += temp;
    //     }
    //     return true;
    // }
  
    // int maxMinHeight(vector<int> &arr, int k, int w) {
    //     // code here
    //     long long low = *min_element(arr.begin(), arr.end());
    //     long long high = *max_element(arr.begin(), arr.end());
    //     high += k;
        
    //     int ans;
    //     while(low <= high) {
    //         int mid = low + (high - low) / 2;
            
    //         if(isValid(arr, k, mid, w)) {
    //             ans = mid;
    //             low = mid + 1;
    //         }
    //         else high = mid - 1; 
    //     }
    //     return ans;
    // }
    
    bool possible(int n,vector<int> a,int k,int w,int mid){
        for(int i=0;i<n;i++){
            if(a[i]<mid){
                int temp = mid-a[i];
                if(temp>k)return false;
                k-=temp;
                a[i]=mid;
                for(int j=i+1;j<n and j<i+w;j++){
                    a[j]+=temp;
                }
            }
        }
        return true;
    }
    int maxMinHeight(vector<int> &a, int k, int w) 
    {
        // code here
        int n = a.size();
        int mn=INT_MAX,mx;
        for(int i=0;i<n;i++)mn=min(mn,a[i]);
        mx=mn+k;
        long long int ans;
        while(mn<=mx){
            int mid = (mn+mx)/2;
            if(possible(n,a,k,w,mid)){
                ans=mid;
                mn=mid+1;
            }
            else mx=mid-1;
        }
        return ans;
    }
};