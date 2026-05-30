// two pointer approach - pointers at opposite ends of the array

class Solution {
public:
    int maxArea(vector<int>& height) {
         int n=height.size();
         int ht;
         int wd;
         int area;
         int maxi=0;

         int i=0;
         int j=n-1;

         while(i<j){
              ht=min(height[i],height[j]);
              wd=j-i;
              area=ht*wd;

               maxi=max(maxi,area);
              if(height[i]<height[j]){
                  i++;
              }
              else{
                j--;
              }
         }
         return maxi;
    }
};



// brute force approach - check for all pairs of lines and calculate the area

class Solution {
public:
    int maxArea(vector<int>& height) {
            int n=height.size();
            int ht,width,area;
            int maxi=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                  ht=min(height[i],height[j]);
                  width=j-i;
                  area=ht*width;

                  maxi=max(maxi,area);
                }
            }
            return maxi;
    }
};