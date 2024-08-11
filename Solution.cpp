class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeSort(long long arr[], int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
  
        long long left[n1], right[n2];
        
        for (int i = 0; i < n1; i++)
            left[i] = arr[i + l];
            
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];
      
        long long count = 0, i = 0, j = 0, k = l;
        
        while (i < n1 && j < n2) {
          
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            }
          
            else {
                arr[k++] = right[j++];
                count = count + (n1 - i);
            }
        }
      
        while (i < n1)
            arr[k++] = left[i++];
        while (j < n2)
            arr[k++] = right[j++];
      
        return count;
    }
    
    long long int merge(long long arr[], int l, int r) {
        long long ans = 0;
        if (l < r) {
            int m = (r + l) / 2;
      
            ans += merge(arr, l, m);
            ans += merge(arr, m + 1, r);
      
            ans += mergeSort(arr, l, m, r);
        }
        return ans;
    }
    
    long long int inversionCount(long long arr[], int n) {
        return merge(arr, 0, n - 1);
    }
};
