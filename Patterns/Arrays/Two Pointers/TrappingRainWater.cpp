// two pointer approach - pointers at opposite ends of the array

class Solution {
public:
    int trap(vector<int>& height) {
        //optimal
          int n=height.size();
          int ans=0;
          int l=0,r=n-1;
          int leftmax=0;
          int rightmax=0;

           while(l<r){
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);

            if(leftmax<rightmax){
                ans+=(leftmax-height[l]);
                l++;
            }
            else{
                ans+=(rightmax-height[r]);
                r--;
            }
           }
       return ans;
    }
};



// optimal 2 - precompute leftmax and rightmax arrays
class Solution {
public:
    int trap(vector<int>& height) {
        //optimal 2
          int n=height.size();
          int ans=0;
          
          vector<int> leftmax(n,0);
          vector<int> rightmax(n,0);

          leftmax[0]=height[0];
          for(int i=1;i<n;i++){
              leftmax[i]=max(leftmax[i-1],height[i]);
          }

          rightmax[n-1]=height[n-1];
          for(int i=n-2;i>=0;i--){
              rightmax[i]=max(rightmax[i+1],height[i]);
          }

          for(int i=0;i<n;i++){
            ans+=min(leftmax[i],rightmax[i])-height[i];
          }

           
       return ans;
    }
};



// brute force approach - check for all pairs of lines and calculate the area

class Solution {
public:
    int trap(vector<int>& height) {
        //bruteforce
          int n=height.size();
          int ans=0;
        for(int i=0;i<n;i++){
            int leftmax=0;
            int rightmax=0;

            for(int j=0;j<=i;j++){
                leftmax=max(leftmax,height[j]);
            }

            for(int j=i;j<n;j++){
                rightmax=max(rightmax,height[j]);
            }
             ans+=min(leftmax,rightmax)-height[i];
        }
        return ans;
    }
};