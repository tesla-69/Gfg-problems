class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=1;
        }
        int i=1;
        while(1){
        if(m[i]!=1)return i;
        i++;
    }
    return -1;
}
};