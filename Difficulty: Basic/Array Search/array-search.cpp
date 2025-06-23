class Solution {
  public:
    int search(vector<int>& arr, int x) {
        int target = -1;
        for(int i= 0;i<arr.size();i++){
            if(arr[i]==x){
                target = i;
                break;
            }
        }
        return target;
        
    }
};