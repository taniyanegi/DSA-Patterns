// search in 2D matrix-leetcode 74

#include<iostream>
#include<vector>

using namespace std;

int findUnique(vector<int> &nums) {
        int n=nums.size();
          int start=0;
          int end=n-1;
          int mid;
          if(n==1) return nums[0];
          while(start<=end){
            int mid=start+(end-start)/2;

            //corner cases
           if(mid==0 && nums[0]!=nums[1]) return nums[mid];
           if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[mid];


           //logic  
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            // left and right have even no. of elements
            else if(mid%2==0){
                 if(nums[mid]==nums[mid-1]){
                    //left
                    end=mid-1;
                 }
                 else{
                    //right
                    start=mid+1;
                 }
            }
            //left and right have odd no. of elements
            else{
                 if(nums[mid]==nums[mid-1]){
                    //right
                     start=mid+1;
                 }
                 else{
                    //left
                    end=mid-1;
                 }
            }
          }
          return -1;
    }

int main(){  
    vector<int> arr={1,1,2,3,3,4,4,5,5};
    cout<<findUnique(arr);
    return 0;
}