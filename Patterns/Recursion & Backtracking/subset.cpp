class Solution {
    public:
     // TC:O(2^n*n)
    void printSubsets(vector<int>& nums,vector<vector<int>> &result,vector<int> &ans,int i){
          if(i==nums.size()){
                result.push_back(ans);
                return;
          }

         // inclusion
          ans.push_back(nums[i]);
          printSubsets(nums,result,ans,i+1);

           // exclusion
           ans.pop_back();
           printSubsets(nums,result,ans,i+1);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> result;
          vector<int> ans;
          int i=0;

        printSubsets(nums,result,ans,i);  

        return result; 
    }
};