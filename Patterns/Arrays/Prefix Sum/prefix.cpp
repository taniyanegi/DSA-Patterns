#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prefixSum(vector<int>& arr, vector<int>& pref){
            for(int i=1;i<=arr.size();i++){
                pref[i]=pref[i-1]+arr[i-1];
            }

}

int main(){
    vector<int> arr={3,4,7,3,2,1};
    int n=arr.size();
    vector<int> pref(n+1,0);   // to store ans-prefixsum
    prefixSum(arr,pref);

    for(int i=0;i<=n;i++){
        cout<<pref[i]<<" ";
    }

    return 0;
}