// sort + two pointer at one end and one at the other end

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
           int n=nums.size();
           sort(nums.begin(),nums.end());
           vector<vector<int>> ans;
           for(int i=0;i<n;i++){
                if(i>0 && nums[i]==nums[i-1]){
                    continue;
                }
                int j=i+1;
                int k=n-1;

                while(j<k){
                   long long sum=nums[i]+nums[j]+nums[k];

                   if(sum<0){
                    j++;
                   } 
                   else if(sum>0){
                    k--;
                   }
                   else{
                    vector<int> res={nums[i],nums[j],nums[k]};
                      ans.push_back(res);
                      j++;
                      k--;

                      while(j<k && nums[j]==nums[j-1]){
                        j++;
                      }
                      while(j<k && nums[k]==nums[k+1]){
                        k--;
                      }
                   }
                }
           }
           return ans;
    }
};



// first loop (0-n) second loop(i+1-n)  hashset to find the third element(third=-(nums[i]+nums[j]))

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
 	set<vector<int>> st;
	for(int i=0;i<n;i++)
	{
		set<int> hashset;
		for(int j=i+1;j<n;j++)
		{
			int third=-(nums[i]+nums[j]);
			if(hashset.find(third)!=hashset.end())
			{
				vector<int> temp={nums[i],nums[j],third};
				sort(temp.begin(),temp.end());
				st.insert(temp);
			}
			hashset.insert(nums[j]); 
		}
		 
	}
      	vector<vector<int>> ans(st.begin(),st.end()); 
        return ans; 
    }
};


// brute force approach - three nested loops

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

set<vector<int>>s;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>v(3);
                        v[0]=nums[i];v[1]=nums[j];v[2]=nums[k];
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>v;
        for(auto i:s)
        {
            v.push_back(i);
        }
        return v;
    }

 };