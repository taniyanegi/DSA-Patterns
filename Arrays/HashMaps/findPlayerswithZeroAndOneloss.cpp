#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
           vector<vector<int>> ans;
           unordered_map<int,int> lostmap;

           for(int i=0;i<matches.size();i++){
              int loser=matches[i][1];
              lostmap[loser]++;
           }

           vector<int> lostOne;
           vector<int> neverLost;

           for(int i=0;i<matches.size();i++){
                  int winner=matches[i][0];
                  int loser=matches[i][1];

                  if(lostmap.find(winner)==lostmap.end()){
                       neverLost.push_back(winner);
                       //to avoid duplicate insertion in ans
                       lostmap[winner]=2;
                  }

                 if(lostmap[loser]==1){
                 lostOne.push_back(loser);
             }
           }
           sort(neverLost.begin(),neverLost.end());
           sort(lostOne.begin(),lostOne.end());
           return {neverLost,lostOne};
    }

    int main(){
        vector<vector<int>> matches={{1,2},{2,3},{4,2},{5,6}};
        vector<vector<int>> ans=findWinners(matches);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }