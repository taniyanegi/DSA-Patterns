
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int longestPalindrome(string s) {
           int n=s.length();
           unordered_map<char,int> mpp;
           bool odd=false;
           for(int i=0;i<n;i++){
               mpp[s[i]]++;
           }

            int res=0;
           for(auto it:mpp){
            int val=it.second;

            if(val%2==0){
                res+=val;
            }

            else{
                odd=true;
            }

           }
           
           if(odd==false){
            return res;
           }

           for(auto it:mpp){
            int val=it.second;

            if(val%2==1){
                res+=(val-1);
            }

           }

           return res+1;
    }

    int main(){
        string s;
        cin>>s;
        cout<<longestPalindrome(s);
    }