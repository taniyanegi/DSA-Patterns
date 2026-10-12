// binary search - time complexirty= O(log(n))
#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& nums, int start, int end, int target) {
        if(start<=end){
        int mid=start+(end-start)/2;
        if (nums[mid]<target){
        return binarySearch(nums,mid + 1,end,target);
        }

        else if(nums[mid]>target){
        return binarySearch(nums,start,mid - 1,target);
        }
        else{
            return mid;
        }
    }
    return -1;
    }

    int main(){
          vector<int> arr={2,5,9,11,14,19,20};
          int ans=binarySearch(arr,0,arr.size()-1,19);

          cout<<ans;

    }
