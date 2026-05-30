// two pointer approach - Floyd's Tortoise and Hare (Cycle Detection)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
               int slow=nums[0];
               int fast=nums[0];

               do{
                slow=nums[slow];
                fast=nums[nums[fast]];
               } while(slow!=fast);

               slow=nums[0];
               while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
               }
               return slow;
    }
};


// sorting approach - sort the array and check for adjacent elements

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
               sort(nums.begin(),nums.end());

               for(int i=0;i<n-1;i++){
                   if(nums[i]==nums[i+1]){
                      return nums[i];
                   }
               } 
               return -1;  
    }
};

// brute force approach - check for all pairs of elements and find the duplicate

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
               for(int i=0;i<n;i++){
                   for(int j=i+1;j<n;j++){
                       if(nums[i]==nums[j]){
                          return nums[i];
                       }
                   }
               } 
               return -1;  
    }
};  