// optimal
   #include<iostream>
   #include<bits/stdc++.h>
    using namespace std;

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



// brute-TLE

    // double findMaxAverage(vector<int>& nums, int k) {
    //          int n=nums.size();
    //          double maxi=INT_MIN;
    //          for(int i=0;i<=n-k;i++){
    //             double sum=0;
    //             for(int j=i;j<i+k;j++){
    //                sum+=nums[j];
    //             }
    //             double avg=sum/k;
    //             maxi=max(maxi,avg);
    //          }
    //          return maxi;
    // }

    int main(){
         
        vector<int> nums={1,12,-5,-6,50,3};
        int k=4;

        double maxAvg=findMaxAverage(nums,k);
        cout<<"Maximum average of subarray is "<<maxAvg<<endl;
    }
