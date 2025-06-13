class Solution {
  public:
    bool checkForHoursLessThanK(vector<int>& arr, int k, int checkK){
        int var = 0;
        for(int i = 0; i < arr.size(); i++) {
            var += (arr[i]%checkK == 0) ? arr[i] / checkK : arr[i]/checkK + 1;
        }
        return var <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int maxele = 0;
        for(int i = 0; i < n; i++) maxele = max(maxele, arr[i]);
        int s = 1; 
        int e = maxele;
        int ans = maxele;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(checkForHoursLessThanK(arr, k, m)){
                ans = min(ans, m);
                e = m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};