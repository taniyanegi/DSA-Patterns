// find minimum in the rotated sorted array
#include<iostream>
#include<vector>
using namespace std;

int findMinInRotatedSorted(vector<int>& arr){
    int n=arr.size();
    int low=0;
    int high=arr.size()-1;
    int res=-1;
    while(low<=high){
          int mid=low+(high-low)/2;

          // check if lelement is in part 1 or part 2
          if(arr[mid]>arr[n-1]){
            //element is in part 2->higher side
            low=mid+1;
          }
          else{
            // element is in part 1->lower side and we want to find first occurance of minimum element
              res=mid;
              high=mid-1;
          }
    }
    return res;
}

int main(){
    vector<int> arr={4,5,6,7,0,1,2};
    cout<<findMinInRotatedSorted(arr);
    return 0;
}