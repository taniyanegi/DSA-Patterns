    #include <iostream>
   #include <bits/stdc++.h>
   using namespace std;
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

    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> result;
          vector<int> ans;
          int i=0;

        printSubsets(nums,result,ans,i);  

        return result; 
    }

    int main(){
        vector<int> nums={1,2,3};
        vector<vector<int>> ans=subsets(nums);

        for(auto it:ans){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return 0;
    }
