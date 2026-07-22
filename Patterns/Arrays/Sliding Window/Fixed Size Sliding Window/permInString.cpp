   #include<iostream>
   #include<bits/stdc++.h>
    using namespace std;

    bool checkInclusion(string s1, string s2) {
         unordered_map<char,int> mpp;
        // Frequency of s1
        for(char ch : s1){
            mpp[ch]++;
        }
        int n=s2.length();
        int count=mpp.size();   // no. of unique chars
        int k=s1.length();

        int i=0;
        int j=0;

        while(j<n){
            // calculations-
            if(mpp.find(s2[j])!=mpp.end()){
                   mpp[s2[j]]--;

                   if(mpp[s2[j]]==0){
                    count--;
                   }
            }

        // incread j till correct window size not reached
            if(j-i+1<k){
                j++;
            }

         else if(j-i+1==k){
                  if(count==0){
                    return true;
                  }

                  // remove ith element or slide the window
                  if(mpp.find(s2[i])!=mpp.end()){
                         if(mpp[s2[i]] == 0){
                           count++;
                            }
                         mpp[s2[i]]++;      
                  }
                  i++;
                  j++;
            }
        }
        return false;
    }

    int main(){
        string s1="ab";
        string s2="eidbaooo";

        bool isPermutationPresent=checkInclusion(s1,s2);
        if(isPermutationPresent){
            cout<<"Permutation of s1 is present in s2"<<endl;
        }
        else{
            cout<<"Permutation of s1 is not present in s2"<<endl;
        }
    }