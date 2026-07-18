class Solution {
    public:
  bool  isPal(string part){
          int left=0;
          int right=part.size()-1;

          while(left<right){
            if(part[left]!=part[right]){
               return false;
            }
            left++;
            right--;
          }
          return true;
  }

  void getAllParts(string s, vector<string> &partitions,vector<vector<string>> &ans){
              if(s.size()==0){
                ans.push_back(partitions);
                return;
              }

              for(int i=0;i<s.size();i++){
                   string part=s.substr(0,i+1);

                   if(isPal(part)){
                      partitions.push_back(part);
                       getAllParts(s.substr(i+1),partitions,ans);
                       partitions.pop_back();   //backtracking
                   }
              }
}

public:
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;

        getAllParts(s,partitions,ans);

        return ans;
    }
};