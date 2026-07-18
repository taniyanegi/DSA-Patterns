// optimal
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
             int n=nums.size();
              vector<int> ans;
              int i=0,j=0;
              deque<int> dq;
              while(j<n){
                   while(!dq.empty() && dq.back()<nums[j]){
                       dq.pop_back();
                   }
                   dq.push_back(nums[j]);

                   if(j-i+1<k){
                    j++;
                   }
                   else if(j-i+1==k){
                        ans.push_back(dq.front());
                        if(dq.front()==nums[i]){
                            dq.pop_front();
                        }
                        i++;
                        j++;
                   }
              }
             return ans;           
    }
};


// brute-TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
             int n=nums.size();
              vector<int> ans;
             for(int i=0;i<=n-k;i++){
                int maxi=nums[i];
                for(int j=i;j<i+k;j++){
                         if(nums[j]>maxi){
                            maxi=nums[j];
                         }
                }
                   ans.push_back(maxi);
             } 
             return ans;           
    }
};