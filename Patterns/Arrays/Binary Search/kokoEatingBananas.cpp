#include<iostream>
#include<vector>

using namespace std;

int timetaken(vector<int>& arr, int n,int speed){
           int time=0;
           
           for(int i=0;i<n;i++){
                 time+=arr[i]/speed;
                 
                 if(arr[i]%speed!=0){
                     time++;
                 }
           }
           return time;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int maxi=arr[0];
            for(int i=1;i<n;i++){
                maxi=max(maxi,arr[i]);
            }
        int low=1;
        int high=maxi;
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int hour=timetaken(arr,n,mid);
            
            if(hour>k){
                //goto right-increase speed
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }

    int main(){
        vector<int> arr={3,6,7,11};
        int k=8;
        cout<<kokoEat(arr,k);
    }