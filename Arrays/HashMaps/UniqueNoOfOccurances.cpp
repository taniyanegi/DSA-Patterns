
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
             unordered_map<int,int> mpp;

             for(int i=0;i<arr.size();i++){
                mpp[arr[i]]++;
             }

             unordered_set<int> st;

             for(auto it:mpp){
                 st.insert(it.second);
             }

              return st.size() == mpp.size();
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<uniqueOccurrences(arr);
    }