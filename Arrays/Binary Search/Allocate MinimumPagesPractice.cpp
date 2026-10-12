#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<int> &arr,int n, int k,int maxAllowedPages){
          int stu=1;
          int pages=0;
          for(int i=0;i<n;i++){
               if(arr[i]>maxAllowedPages) return false;
          if(pages+arr[i]<=maxAllowedPages){
              pages+=arr[i];
          }
          else{
              stu++;
              pages=arr[i];
          }
          }
          if(stu>k) return false;
          else return true;
    }
 
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int mid;
        int start=0;
        int end=sum;
        int ans=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(isValid(arr,n,k,mid)){  //goto left to search 
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1; //goto right to search
            }
        }
        return ans;
    }

    int main(){
        vector<int> arr={10,20,30,40};
        int k=2;
        cout<<findPages(arr,k);
    }