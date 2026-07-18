//more optimal
class Solution {
public:
    int divisorSubstrings(int num, int k) {
           int count=0;
             string s=to_string(num);
           for(int i=0;i<=s.size()-k;i++){
                string check=s.substr(i,k);
                if(stoi(check)!=0 && num%stoi(check)==0){
                    count++;
                }
           } 
           return count;
    }
};
//optimal
class Solution {
public:
    int divisorSubstrings(int num, int k) {
           string s=to_string(num);
           int beauty=0;
               int n=s.size();
               int i=0;
               int j=0;

           while(j<n){
              if(j-i+1<k){
                 j++;
              }
              else if(j-i+1==k){
                 string check=s.substr(i,k);
                 int a=stoi(check);
                if(a!=0 && num%a==0){
                        beauty++;
                    }
                    i++;
                    j++;
                   }
                }
        return beauty;
    }
};