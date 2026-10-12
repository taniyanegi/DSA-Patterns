// kth missing positive elemnt
#include<iostream>
#include<vector>
using namespace std;

// O(logn) solution using binary search
int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size();
        
        int l = 0, r = n-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(arr[mid] - (mid+1) < k) { //A[mid]-(mid+1)   --> This gives umber of missing number before m'th index
                l = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        
        return l + k; //see my youtube video above for the explanation of this line
    }

    // O(n) solution
 int findKthPositive(vector<int>& arr, int k) {
      int num=1;
      int n=arr.size();
      int i=0;

      while(i<n && k>0){
           if(arr[i]==num){
            i++;
           }
           else{
            k--;
           }
           num++;
      }

      // when there is no missing no. found and you traversed the whole array
      // eg: {1,2,3}  k=2;
      // ans should be 5 

      while(k--){
         num++;
      }

      return num-1;
    }

int main(){
    vector<int> arr={2,3,4,7,11};
    int k=5;
    cout<<findKthPositive(arr,k);
    return 0;
}