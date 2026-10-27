#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int   BinarySearch(vector<int>& potions,int minPotions){
           int l=0;
           int r=potions.size()-1;
           int index=-1;
           while(l<=r){
                 int mid=l+(r-l)/2;
                 if(potions[mid]>=minPotions){
                     index=mid;
                     r=mid-1;
                 }
                 else{
                    l=mid+1;
                 }  
           }
           return index;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
          int m=spells.size();
          int n=potions.size();
          vector<int> ans;
          sort(potions.begin(),potions.end());
           int maxPotionValue=potions[n-1];

          for(int i=0;i<m;i++){
                    // minPotion*spell>=succes
                    long long minPotions=ceil((1.0)*success/spells[i]);
                    if(maxPotionValue<minPotions){
                        ans.push_back(0);
                        continue;
                    }

            // apply binary search to find value>=minpotions
            // STL to find min potions= lower_bound(begin(potions),end(potions),minPotion)-begin(potions)
            int index=BinarySearch(potions,minPotions);

            int count=n-index;

            ans.push_back(count);
          }
          return ans;
    }

    int main(){
        int m,n;
        cin>>m>>n;
        vector<int> spells(m);
        vector<int> potions(n);
        for(int i=0;i<m;i++){
            cin>>spells[i];
        }
        for(int i=0;i<n;i++){
            cin>>potions[i];
        }
        long long success;
        cin>>success;
        vector<int> ans=successfulPairs(spells,potions,success);
        for(auto it:ans){
            cout<<it<<" ";
        }
    }