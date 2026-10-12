// find the number of times a sorted array is rotated

#include<iostream>
#include<vector>
using namespace std;

int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]>arr[n-1]){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }

     int main(){
        vector<int> arr={15,18,2,3,6,12};
        cout<<findKRotation(arr);
        return 0;
        }