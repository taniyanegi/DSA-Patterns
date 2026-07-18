class Solution {
  public:
    int search(string &pat, string &txt) {
        
        unordered_map<char,int> mpp;
        
        // store pattern frequency
        for(int i = 0; i < pat.size(); i++) {
            mpp[pat[i]]++;
        }
        
        int count = mpp.size();
        int k = pat.size();
        int n = txt.size();
        
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < n) {
            
            // calculation
            if(mpp.find(txt[j]) != mpp.end()) {
                mpp[txt[j]]--;
                
                if(mpp[txt[j]] == 0)
                    count--;
            }
            
            // window size < k
            if(j - i + 1 < k) {
                j++;
            }
            
            // window size == k
            else if(j - i + 1 == k) {
                
                if(count == 0)
                    ans++;
                
                // remove ith character
                if(mpp.find(txt[i]) != mpp.end()) {
                    mpp[txt[i]]++;
                    
                    if(mpp[txt[i]] == 1)
                        count++;
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};