// find the first and last occurance of element in a sorted array- duplicates are there

#include<iostream>
#include<vector>

using namespace std;

int firstOccurance(vector<int>& arr,int target){
      int low=0;
      int high=arr.size()-1;
      
      int res=-1;

      while(low<=high){
          int mid=low+(high-low)/2;

          if(arr[mid]<target){
              low=mid+1;
          }

          else if(arr[mid]>target){
            high=mid-1;
          }

          else{
            res=mid;
            high=mid-1;
          }
      }
      return res;
}

int LastOccurance(vector<int>& arr,int target){
      int low=0;
      int high=arr.size()-1;
      
      int res=-1;

      while(low<=high){
          int mid=low+(high-low)/2;

          if(arr[mid]<target){
              low=mid+1;
          }

          else if(arr[mid]>target){
            high=mid-1;
          }
          
          else{
            res=mid;
            low=mid+1;
          }
      }
      return res;
}

int main(){
      vector<int> arr={5,10,30,30,30,40,50};
       int target=5;

      int first=firstOccurance(arr,target);
      int last=LastOccurance(arr,target);

        cout<<"first occurnace = "<<first<<endl;
        cout<<"last occurnace = "<<last<<endl;
}