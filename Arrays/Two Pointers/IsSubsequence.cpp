// two pointer approach - one pointer for each string

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i,j;
      i=0;
      j=0;
          while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
          }
          if(i==s.size())
          return true;

          return false;
    }
};