class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
             
        int i=0;
        int j=0;
        vector<int> mergeArr;
        while(i<m && j<n )
        {
          
            if(nums1[i]<=nums2[j])
            {
                mergeArr.push_back(nums1[i]);
                i++;
            }
     else
     {
         
                mergeArr.push_back(nums2[j]);
                j++;
         
     }            
            }
        
        while(i<m)
        {
         mergeArr.push_back(nums1[i]);
         i++;
        
        }
        while(j<n)
        {
                mergeArr.push_back(nums2[j]);
                j++;
                
        }
        for(int i=0;i<mergeArr.size();i++)
        {
            nums1[i]=mergeArr[i];
        }
        
    }
};