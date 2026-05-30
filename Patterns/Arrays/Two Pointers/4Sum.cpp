// sort + two pointer at one end and one at the other end

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int n=nums.size();
          vector<vector<int>> ans;
          sort(nums.begin(),nums.end());
          for(int i=0;i<n-3;i++){
                 if(i>0 && nums[i]==nums[i-1]) continue;
                for(int j=i+1;j<n-2;j++){
                    if(j>i+1 && nums[j]==nums[j-1]) continue;
                    int start=j+1;
                    int end=n-1;
                     long long rem = (long long)target - (long long)nums[i] - (long long)nums[j];
                    while(start<end){
                         if(nums[start]+nums[end]<rem){
                            start++;
                         }
                      else if(nums[start]+nums[end]>rem){
                            end--;
                         }
                         else{
                             ans.push_back({{nums[i],nums[j],nums[start],nums[end]}});
                             start++;
                             end--;
                              while(start<end && nums[start]==nums[start-1]){
                                start++;
                              }
                               while(start<end && nums[end]==nums[end+1]){
                                end--;
                              }
                         }
                    }
                }
          }
          return ans;
    }
};


// first loop (0-n) second loop(i+1-n) third loop(j+1-n) hashset to find the fourth element(fourth=-(nums[i]+nums[j]+nums[k]))

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long newtarget=target-(nums[i]+nums[j]);
                int low=j+1;
                int high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]<newtarget){
                        low++;
                    }
                    else if(nums[low]+nums[high]>newtarget){
                        high--;
                    }
                    else{
                        st.insert({nums[i],nums[j],nums[low],nums[high]});
                    }
                }
            }   
        }
        for(auto it:st){
            ans.push_back(it);
        }
       return ans;
    }
};




// brute force approach - four nested loops
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }   
        }
        for(auto it:st){
            ans.push_back(it);
        }
       return ans;
    }
};