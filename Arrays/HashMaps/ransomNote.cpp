#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
           unordered_map<char,int> have;
           unordered_map<char,int> need;

           for(int i=0;i<ransomNote.size();i++){
                  need[ransomNote[i]]++;
           }

            for(int i=0;i<magazine.size();i++){
                  have[magazine[i]]++;
           }

           for(auto it:need){
              char c=it.first;

              int fneed=it.second;
              int fhave=have[c];

              if(fneed>fhave){
                return false;
              }
           }
       
       return true;
        }

        int main(){
            string ransomNote,magazine;
            cin>>ransomNote>>magazine;
            cout<<canConstruct(ransomNote,magazine);
        }