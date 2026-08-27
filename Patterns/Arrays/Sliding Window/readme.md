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

