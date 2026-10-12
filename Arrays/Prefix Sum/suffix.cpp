#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void suffixSum(vector<int>& arr, vector<int>& suff){
            for(int i=arr.size()-2;i>=0;i--){
                suff[i]=suff[i+1]+arr[i+1];
            }
}

int main(){
    vector<int> arr={3,4,7,3,2,1};
    int n=arr.size();
    vector<int> suff(n+1,0);   // to store ans-suffixsum
    suffixSum(arr,suff);

    for(int i=0;i<=n;i++){
        cout<<suff[i]<<" ";
    }

    return 0;
}