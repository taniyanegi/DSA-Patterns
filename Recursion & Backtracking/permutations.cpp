   #include <iostream>
   #include <bits/stdc++.h>
   using namespace std;

      void getPermutations(vector<int>& nums,int idx,vector<vector<int>> &ans){
            if(idx==nums.size()){
                ans.push_back(nums);
            }

            for(int i=idx;i<nums.size();i++){
                swap(nums[idx],nums[i]);    // idx place=>ith element choice
                getPermutations(nums,idx+1,ans);
                swap(nums[idx],nums[i]);
            }
      }


    vector<vector<int>> permute(vector<int>& nums) {
           vector<vector<int>> ans;
           getPermutations(nums,0,ans);
           return ans;
    }

    int main(){
        vector<int> nums={1,2,3};
        vector<vector<int>> ans=permute(nums);

        for(auto it:ans){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return 0;
    }