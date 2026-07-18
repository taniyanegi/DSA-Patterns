#include<iostream>
#include <bits/stdc++.h>
using namespace std;
    int partition(vector<int>& nums, int low, int high) {
        // Step 1: choose random pivot index
        int pivotIndex = low + rand() % (high - low + 1);

        // Step 2: move pivot to beginning (your logic uses nums[low])
        swap(nums[low], nums[pivotIndex]);

        int pivot = nums[low];
        int i = low;
        int j = high;

        // Step 3: Hoare partition (your same logic)
        while (i < j) {
            while (i <= high - 1 && nums[i] <= pivot) i++;
            while (j >= low + 1 && nums[j] > pivot) j--;

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[low], nums[j]);
        return j;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int p = partition(nums, low, high);
            quickSort(nums, low, p - 1);
            quickSort(nums, p + 1, high);
        }
    }

    int main() {
        vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
        int n = nums.size();
        srand(time(0)); // seed the random number generator
        quickSort(nums, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        return 0;
    }