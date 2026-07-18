#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int low,int mid,int high){
    vector<int> temp;
      int  l=low;
      int  r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
              temp.push_back(nums[r]);
              r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=0;i<temp.size();i++){
            nums[i+low]=temp[i];
        }
    }
    
   void mergeSort(vector<int>& nums,int low,int high){
      if(low<high){
      int mid=(low+high)/2;
      mergeSort(nums,low,mid);
      mergeSort(nums,mid+1,high);
      merge(nums,low,mid,high);
      }
   }

     
   int main(){
    vector<int> nums={38,27,43,3,9,82,10};
    int n=nums.size();
    mergeSort(nums,0,n-1);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
    }