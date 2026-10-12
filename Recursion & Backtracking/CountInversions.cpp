#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums,int low,int mid,int high){
    vector<int> temp;
    int inversionCount=0;
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
              inversionCount+=mid-l+1;
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
    return inversionCount;
    }
    
   int mergeSort(vector<int>& nums,int low,int high){
      if(low<high){
      int mid=(low+high)/2;
    int leftInversionCount=mergeSort(nums,low,mid);
    int rightInversionCount=mergeSort(nums,mid+1,high);
    int InversionCount=merge(nums,low,mid,high);

    return leftInversionCount+rightInversionCount+InversionCount;
      }
   }

   int main(){
    vector<int> nums={38,27,43,3,9,82,10};
    int n=nums.size();
    int inversionCount=mergeSort(nums,0,n-1);
    cout<<"Inversion Count: "<<inversionCount<<endl;
    return 0;
    }

     
  