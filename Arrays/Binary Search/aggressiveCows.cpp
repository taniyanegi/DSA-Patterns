#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int n,int k,int minAllowedDist){
         int cows=1;
         int lastStallPos=stalls[0];
         
         for(int i=1;i<n;i++){
         if(stalls[i]-lastStallPos>=minAllowedDist){
         cows++;
         lastStallPos=stalls[i];
         }
          if(cows==k) return true;
         }
         return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int maxi=stalls[n-1];
        int mini=stalls[0];
        int st=1;
        int end=maxi-mini;
        int mid;
        int ans=-1;
        while(st<=end){
            mid=st+(end-st)/2;
            
            if(isPossible(stalls,n,k,mid)){
                //right
                ans=mid;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
       return ans; 
    }

    int main(){
        vector<int> stalls={1,2,4,8,9};
        int k=3;
        cout<<aggressiveCows(stalls,k);
    }