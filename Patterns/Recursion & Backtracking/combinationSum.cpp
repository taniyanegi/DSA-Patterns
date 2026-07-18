class Solution {
        set<vector<int>> st;
    private:
    void getAllCombinations(vector<int>& candidates,int idx,int target,vector<vector<int>> &ans, vector<int>& combin){
        int n=candidates.size();
               if(idx==n || target<0){
                return;
               }
               if(target==0){
                   if(st.find(combin)==st.end()){
                        st.insert(combin);
                        ans.push_back(combin);
                   }
                return;
               }

               combin.push_back(candidates[idx]);

               // single inclusion
                  getAllCombinations(candidates,idx+1,target-candidates[idx],ans,combin);
               //multiple inclusion
               getAllCombinations(candidates,idx,target-candidates[idx],ans,combin);

               combin.pop_back();   //backtracking 

               //exclusion
               getAllCombinations(candidates,idx+1,target,ans,combin);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> combin;

       getAllCombinations(candidates,0,target,ans,combin);

       return ans;   
    }
};