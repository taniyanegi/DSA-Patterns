// single element in a sorted array
#include<iostream>
#include<vector>

using namespace std;

int singleElement(vector<int>& arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int res=-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                low=mid+2;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        else{
            if(arr[mid]==arr[mid-1]){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr={1,1,2,3,3,4,4,5,5};
    cout<<arr[singleElement(arr)];
    return 0;
}