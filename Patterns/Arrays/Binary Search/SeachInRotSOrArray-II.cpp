// search in rotated sorted array II-leetcode 81- duplicates exist
#include<iostream>
#include<vector>

using namespace std;

 bool search(vector<int>& nums, int target) {
         int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                return true;
            }

            // duplicates create ambiguity
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            // left part is sorted
            else if(nums[low]<=nums[mid]){

                // target lies in left part
                if(nums[low]<=target && target<nums[mid]){
                    high=mid-1;       //  go left
                }
                else{
                    low=mid+1;        //  go right
                }
            }

            // right part is sorted
            else{

                // target lies in right part
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;        // go right
                }
                else{
                    high=mid-1;       //  go left
                }
            }
        }

          return false;
    }

    int main(){
        vector<int> arr={2,5,6,0,0,1,2};
        int target=0;
        cout<<search(arr,target);
        return 0;
    }