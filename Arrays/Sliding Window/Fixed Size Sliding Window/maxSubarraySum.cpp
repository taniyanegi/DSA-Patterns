   #include<iostream>
   #include<bits/stdc++.h>
   using namespace std;

    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
          int n=arr.size();
            int sum=0;
            int maxi=INT_MIN;
            int i=0;
            int j=0;
            
            while(j<n){
                sum+=arr[j];
                if(j-i+1<k){
                    j++;
                }
                else if(j-i+1==k){
                    maxi=max(maxi,sum);
                    
                    sum-=arr[i];
                    i++;
                    j++;
                }
            }
            return maxi;
    }

    int main(){
             vector<int> nums={1,12,-5,-6,50,3};
        int k=4;

        int maxSum=maxSubarraySum(nums,k);
        cout<<"Maximum sum of subarray is "<<maxSum<<endl;
    }