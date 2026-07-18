# Sliding Window Pattern

## What is Sliding Window?

Sliding Window is an optimization technique used to solve problems involving **subarrays** or **substrings**. Instead of checking every possible range using nested loops, we maintain a "window" and adjust its boundaries efficiently.

This technique often reduces the time complexity from **O(n²)** to **O(n)**.

---

# When to Use Sliding Window?

Use this pattern when:

- You are dealing with **subarrays** or **substrings**.
- The problem asks for the **longest** or **shortest** window satisfying a condition.
- A **fixed window size `k`** is given.
- You need to count or maximize/minimize something within a contiguous range.
- You need to process elements in one pass.

---

# Common Variations

## 1. Fixed Size Window

The window size **k** is given.

Algorithm:
- Expand the window until its size becomes **k**.
- Process the current window.
- Remove the leftmost element.
- Slide one step to the right.

Examples:
- Maximum Average Subarray I
- Maximum Number of Vowels in a Substring of Given Length
- Sliding Window Maximum
- Find All Anagrams in a String
- Permutation in String

---

## 2. Variable Size Window

The window size is **not fixed**.

Algorithm:
- Expand the right pointer.
- If the window becomes invalid, shrink the left pointer.
- Continue until the end.

Examples:
- Longest Substring Without Repeating Characters
- Minimum Size Subarray Sum
- Fruit Into Baskets
- Max Consecutive Ones III

---

## 3. At Most K Pattern

Many "Exactly K" problems can be solved using:

```
Exactly(K) = AtMost(K) − AtMost(K−1)
```

Examples:

- Subarrays with K Different Integers
- Count Number of Nice Subarrays

---

## 4. Frequency Map Window

Maintain character frequencies inside the window.

Examples:

- Minimum Window Substring
- Permutation in String
- Find All Anagrams in a String
- Longest Repeating Character Replacement

---

## 5. Monotonic Deque

Maintain the maximum/minimum element of the current window in **O(1)**.

Examples:

- Sliding Window Maximum

---

# Time and Space Complexity

| Variation | Time | Space |
|-----------|------|-------|
| Fixed Window | O(n) | O(1) |
| Variable Window | O(n) | O(1) |
| Frequency Map | O(n) | O(26) / O(128) |
| Monotonic Queue | O(n) | O(k) |

---

# Sliding Window Templates

## 1. Fixed Size Window

**Use When:** Window size `k` is given.

```cpp
int left = 0;
int sum = 0;

for (int right = 0; right < n; right++) {

    // Include current element
    sum += nums[right];

    // Window reaches size k
    if (right - left + 1 == k) {

        // Process current window
        ans = max(ans, sum);

        // Remove left element
        sum -= nums[left];
        left++;
    }
}
```

---

## 2. Variable Size Window

**Use When:** Longest/Largest window satisfying a condition.

```cpp
int left = 0;

for (int right = 0; right < n; right++) {

    // Expand window

    while (window is invalid) {
        // Shrink window
        left++;
    }

    ans = max(ans, right - left + 1);
}
```

---

## 3. Minimum Window Template

**Use When:** Smallest window satisfying a condition.

```cpp
int left = 0;

for (int right = 0; right < n; right++) {

    // Expand window

    while (window is valid) {

        ans = min(ans, right - left + 1);

        // Shrink window
        left++;
    }
}
```

---

## 4. Fixed Window + Frequency Map

**Examples**

- Permutation in String
- Find All Anagrams
- Maximum Number of Vowels

```cpp
unordered_map<char,int> mp;

int left = 0;

for (int right = 0; right < s.size(); right++) {

    mp[s[right]]++;

    if (right - left + 1 == k) {

        // Process window

        mp[s[left]]--;

        if (mp[s[left]] == 0)
            mp.erase(s[left]);

        left++;
    }
}
```

---

## 5. Variable Window + Frequency Map

**Examples**

- Longest Substring Without Repeating Characters
- Fruit Into Baskets
- Longest Repeating Character Replacement

```cpp
unordered_map<char,int> mp;

int left = 0;

for (int right = 0; right < s.size(); right++) {

    mp[s[right]]++;

    while (window is invalid) {

        mp[s[left]]--;

        if (mp[s[left]] == 0)
            mp.erase(s[left]);

        left++;
    }

    ans = max(ans, right - left + 1);
}
```

---

## 6. Exactly K Template

Many problems can be solved using:

```
Exactly(K) = AtMost(K) − AtMost(K-1)
```

Examples

- Subarrays with K Different Integers
- Count Number of Nice Subarrays

```cpp
int solve(vector<int>& nums, int k){

    int left = 0;
    int ans = 0;

    unordered_map<int,int> mp;

    for(int right = 0; right < nums.size(); right++){

        mp[nums[right]]++;

        while(mp.size() > k){

            mp[nums[left]]--;

            if(mp[nums[left]] == 0)
                mp.erase(nums[left]);

            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

answer = solve(nums, K) - solve(nums, K-1);
```

---

## 7. Monotonic Deque Template

**Examples**

- Sliding Window Maximum

```cpp
deque<int> dq;

for(int i = 0; i < nums.size(); i++){

    while(!dq.empty() && dq.front() <= i-k)
        dq.pop_front();

    while(!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

    dq.push_back(i);

    if(i >= k-1)
        ans.push_back(nums[dq.front()]);
}
```

# Practice Problems

## Fixed Window

| Problem | Difficulty | Link |
|----------|------------|------|
| Maximum Average Subarray I | Easy | https://leetcode.com/problems/maximum-average-subarray-i/ |
| Maximum Number of Vowels in a Substring of Given Length | Easy | https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ |
| Sliding Window Maximum | Hard | https://leetcode.com/problems/sliding-window-maximum/ |
| Permutation in String | Medium | https://leetcode.com/problems/permutation-in-string/ |
| Find All Anagrams in a String | Medium | https://leetcode.com/problems/find-all-anagrams-in-a-string/ |
| Maximum Points You Can Obtain from Cards | Medium | https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ |
| Grumpy Bookstore Owner | Medium | https://leetcode.com/problems/grumpy-bookstore-owner/ |
| Sliding Window Median | Hard | https://leetcode.com/problems/sliding-window-median/ |

---

## Variable Window

| Problem | Difficulty | Link |
|----------|------------|------|
| Longest Substring Without Repeating Characters | Medium | https://leetcode.com/problems/longest-substring-without-repeating-characters/ |
| Minimum Size Subarray Sum | Medium | https://leetcode.com/problems/minimum-size-subarray-sum/ |
| Longest Repeating Character Replacement | Medium | https://leetcode.com/problems/longest-repeating-character-replacement/ |
| Max Consecutive Ones III | Medium | https://leetcode.com/problems/max-consecutive-ones-iii/ |
| Fruit Into Baskets | Medium | https://leetcode.com/problems/fruit-into-baskets/ |
| Minimum Window Substring | Hard | https://leetcode.com/problems/minimum-window-substring/ |
| Subarrays with K Different Integers | Hard | https://leetcode.com/problems/subarrays-with-k-different-integers/ |
| Count Number of Nice Subarrays | Medium | https://leetcode.com/problems/count-number-of-nice-subarrays/ |
| Longest Subarray of 1's After Deleting One Element | Medium | https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ |
| Minimum Operations to Reduce X to Zero | Medium | https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/ |
| Subarray Product Less Than K | Medium | https://leetcode.com/problems/subarray-product-less-than-k/ |
| Number of Substrings Containing All Three Characters | Medium | https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ |



