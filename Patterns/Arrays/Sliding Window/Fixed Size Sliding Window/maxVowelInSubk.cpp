   #include<iostream>
   #include<bits/stdc++.h>
    using namespace std;

    bool isVowel(char ch){
              if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                return true;
              }
              return false;
    }

    int maxVowels(string s, int k) {
            int n=s.size();
             int maxi=0;
             int i=0;
             int j=0;
             int windVowel=0;
             while(j<n){
                   if(isVowel(s[j])){
                    windVowel++;
                   }
                   if(j-i+1<k){
                    j++;
                   }
                   else if(j-i+1==k){
                        maxi=max(maxi,windVowel);
                        if(isVowel(s[i])){
                            windVowel--;
                        }
                     i++;
                     j++;
                   }
             }
             return maxi;
    }

    int main(){
        string s="abciiidef";
        int k=3;

        int maxVowel=maxVowels(s,k);
        cout<<"Maximum vowels in substring of size k is "<<maxVowel<<endl;
    }