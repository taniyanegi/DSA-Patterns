// code to search an element in a rotated sorted array
#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
        // Code Here
        int n=nums.size();
                int low=0;
                int high=n-1;

                while(low<=high){
                    int mid=low+((high-low)/2);
                      if(nums[mid]==target){
                        return mid;
                    }
                    // mid falls in part 1
                       if(nums[mid]>nums[n-1]){
                    // if target is greater tham nums[mid]
                     if(nums[mid]<target){
                        // goto right for greater element
                        low=mid+1;
                     }
                     else{
                          // when target is less than nums[mid]-> here two condition arises target can be left or right side 
                          // to check if it could be left side or right side
                          if(nums[0]>target){
                             // can not be left side search right sie
                             low=mid+1;
                          }
                          else{
                            // it is in left side
                            high=mid-1;
                          }
                     }
                       }
                       else{
                        // mid fallse in part 2
                       if(nums[mid]>target){
                            // goto left
                            high=mid-1;
                        }
                        else {
                            if(nums[n-1]<target){
                                // goto left
                                high=mid-1;
                            }
                            else{
                                low=mid+1;
                            }
                        }
                       }
                }
                return -1;
            }

    int main(){
        vector<int> arr={4,5,6,7,0,1,2};
        int target=0;
        cout<<search(arr,target);
        return 0;
    }