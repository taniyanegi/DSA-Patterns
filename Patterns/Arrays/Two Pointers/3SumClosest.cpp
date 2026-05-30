// two pointer approach - sort + two pointers at opposite ends

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int start = i + 1;
            int end = n - 1;

            while (start < end) {
                int sum = nums[i]+nums[start]+nums[end];

                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum < target)       start++;
                else if (sum > target)  end--;
                else                    return sum;  // exact match, can't get closer
            }
        }
        return closestSum;
    }
};





// two pointer approach - brute force with three nested loops

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 0;
        int minDiff = INT_MAX;
        int n = nums.size();

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){

                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(target - sum);

                    if(diff < minDiff){
                        minDiff = diff;
                        closestSum = sum;
                    }
                }
            }
        }

        return closestSum;
    }
};