#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int firstUniqChar(string s) {
         unordered_map<int,int> freq;

         for(char c : s){
            freq[c]++;
         }

         for(int i=0;i<s.length();i++){
            if(freq[s[i]]==1)
            return i;
         }
         return -1;
    }

    int main(){
        string s;
        cin>>s;
        cout<<firstUniqChar(s);
    }
