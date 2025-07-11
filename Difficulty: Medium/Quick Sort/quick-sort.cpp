class Solution {
  public:
   
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int pIndex = partition(arr,low,high);
            quickSort(arr,low,pIndex-1);
            quickSort(arr,pIndex+1,high);
        }
    }

  public:
  
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[low];
        int i = low;
        int j = high;
        
        while(i<j){
            
            while(arr[i] <= pivot &&  i <= high-1){
                i++;
            }
            
            while(arr[j] > pivot &&  j >= low+1 ){
                j--;
            }
            
            if(i<j) {
                swap(arr[i] , arr[j]);
            }
        }
        
        swap(arr[j] , arr[low]);
        return j;
    }
};