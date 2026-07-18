// optimal
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
            int n=nums.size();
             double sum=0;
             double avg=0;
             int i=0;
             int j=0;
             double maxi=INT_MIN;

             while(j<n){
                sum+=nums[j];
                if(j-i+1<k){
                    j++;
                }
                else if(j-i+1==k){
                    avg=sum/k;
                    maxi=max(maxi,avg);
                    sum-=nums[i];
                    i++;
                    j++;
                }
             }
             return maxi;
    }
};



// brute-TLE
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
             int n=nums.size();
             double maxi=INT_MIN;
             for(int i=0;i<=n-k;i++){
                double sum=0;
                for(int j=i;j<i+k;j++){
                   sum+=nums[j];
                }
                double avg=sum/k;
                maxi=max(maxi,avg);
             }
             return maxi;
    }
};