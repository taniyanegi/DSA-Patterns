# Sliding Window Pattern
 
# What is Sliding Window?

Sliding Window is an optimization technique used to solve problems involving **subarrays** or **substrings** by maintaining a contiguous window instead of generating all possible ranges.

It reduces the complexity from **O(n²)** to **O(n)** in most interview problems.

---

# When to Use Sliding Window?

Use Sliding Window when:

- Window/Subarray/Substrings are involved.
- The range must be contiguous.
- Window size is fixed.
- Longest/Shortest valid window is asked.
- Count subarrays/substrings satisfying a condition.
- Maximum/Minimum value over contiguous elements.

---

# Pattern Classification

## 1. Fixed Size Window

### General Template

```cpp
i = 0;
j = 0;

while(j < n){

    // Include current element

    if(j - i + 1 < k){

        j++;

    }

    else if(j - i + 1 == k){

        // Process answer

        // Remove nums[i]

        i++;
        j++;
    }
}
```

### Common Fixed Window Subpatterns

### 1. Sum / Average Window

Examples

- Maximum Average Subarray I

---

### 2. Frequency / Count Window

Examples

- Maximum Number of Vowels
- Find All Anagrams
- Permutation in String

Usually solved using

- Array Frequency
- HashMap

---

### 3. Monotonic Queue / Deque

Examples

- Sliding Window Maximum
- Sliding Window Median

Maintains

- Maximum
- Minimum

inside current window.

---

### 4. Circular Window

Examples

- Maximum Points You Can Obtain from Cards

Uses modulo (%) or converts circular array into linear logic.

---

# Variable Size Window

Window size is **not fixed**.

Expand the window first.

Shrink only when the condition becomes invalid.

---

## Template (Longest Valid Window)

```cpp
i = 0;
j = 0;

while(j < n){

    // Include nums[j]

    while(window is invalid){

        // Remove nums[i]
        i++;
    }

    ans = max(ans, j - i + 1);

    j++;
}
```

Used in

- Longest Substring Without Repeating Characters
- Fruit Into Baskets
- Max Consecutive Ones III

---

## Template (Shortest Valid Window)

```cpp
i = 0;
j = 0;

while(j < n){

    // Include nums[j]

    while(window is valid){

        ans = min(ans, j - i + 1);

        // Remove nums[i]
        i++;
    }

    j++;
}
```

Used in

- Minimum Window Substring
- Minimum Size Subarray Sum

---

# Exact Comparison Template

When the problem asks

- Exactly K Distinct
- Exactly K Odds
- Exactly K Characters

Never solve Exactly directly.

Use

```
Exactly(K) = AtMost(K) − AtMost(K−1)
```

Problems

- Subarrays with K Different Integers
- Count Number of Nice Subarrays
- Count of Vowel Substrings

---

# Non-Exact Comparison Template

When the question asks

- At Most K
- Longest
- Largest
- Maximum

```cpp
i = 0;
j = 0;

while(j < n){

    // Expand window

    while(condition invalid){

        // Shrink
        i++;
    }

    ans = max(ans, j - i + 1);

    j++;
}
```

---

# Important Observations

## Fixed Window

- Window size is always constant.
- Expand and remove together.
- No inner while loop.

---

## Variable Window

- Window size changes dynamically.
- Expand first.
- Shrink only if condition becomes invalid.

---

## Exactly K Trick

```
Exactly(K)
=
AtMost(K)
-
AtMost(K-1)
```

One of the most important Sliding Window observations.

---

# Complexity

| Pattern | Time | Space |
|---------|------|-------|
| Fixed Window | O(n) | O(1) |
| Variable Window | O(n) | O(1) |
| Frequency Map | O(n) | O(26) / O(128) |
| Monotonic Queue | O(n) | O(k) |

---

---

# 🔗 Solve Problems

## Fixed Size Sliding Window

| # | Problem | Difficulty | Solve |
|---|---------|------------|-------|
| 1 | Maximum sum Subarray | Easy | https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1 |
| 2 |count occ of anagrams | Medium|https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/|
| 2 | Maximum Average Subarray I | Easy | https://leetcode.com/problems/maximum-average-subarray-i/ |
| 3 | Maximum Number of Vowels in a Substring of Given Length | Easy | https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ |
| 3 | Sliding Window Maximum | Hard | https://leetcode.com/problems/sliding-window-maximum/ |
| 4 | Permutation in String | Medium | https://leetcode.com/problems/permutation-in-string/ |
| 5 | Find All Anagrams in a String | Medium | https://leetcode.com/problems/find-all-anagrams-in-a-string/ |
| 6 | Maximum Points You Can Obtain from Cards | Medium | https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ |
| 7 | Grumpy Bookstore Owner | Medium | https://leetcode.com/problems/grumpy-bookstore-owner/ |
| 8 | Sliding Window Median | Hard | https://leetcode.com/problems/sliding-window-median/ |

---

## Variable Size Sliding Window

| # | Problem | Difficulty | Solve |
|---|---------|------------|-------|
| 9 | Longest Substring Without Repeating Characters | Medium | https://leetcode.com/problems/longest-substring-without-repeating-characters/ |
| 10 | Minimum Size Subarray Sum | Medium | https://leetcode.com/problems/minimum-size-subarray-sum/ |
| 11 | Longest Repeating Character Replacement | Medium | https://leetcode.com/problems/longest-repeating-character-replacement/ |
| 12 | Max Consecutive Ones III | Medium | https://leetcode.com/problems/max-consecutive-ones-iii/ |
| 13 | Fruit Into Baskets | Medium | https://leetcode.com/problems/fruit-into-baskets/ |
| 14 | Minimum Window Substring ⭐ | Hard | https://leetcode.com/problems/minimum-window-substring/ |
| 15 | Subarrays with K Different Integers | Hard | https://leetcode.com/problems/subarrays-with-k-different-integers/ |
| 16 | Count Number of Nice Subarrays | Medium | https://leetcode.com/problems/count-number-of-nice-subarrays/ |
| 17 | Longest Subarray of 1's After Deleting One Element | Medium | https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ |
| 18 | Minimum Operations to Reduce X to Zero | Medium | https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/ |
| 19 | Subarray Product Less Than K | Medium | https://leetcode.com/problems/subarray-product-less-than-k/ |
| 20 | Number of Substrings Containing All Three Characters | Medium | https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ |

---
