# Two Pointers Pattern

## What is Two Pointers?

Two Pointers is a technique where two indices are used to traverse an array, string, or linked list efficiently. The pointers may move toward each other, move in the same direction, or move at different speeds depending on the problem.

This technique helps optimize brute-force solutions and often reduces time complexity from **O(n²)** to **O(n)**.

---

## When to Use Two Pointers?

Use this pattern when:

* The array is sorted.
* You need to find a pair of elements.
* You need to compare elements from both ends.
* You need to process a subarray or substring efficiently.
* You need to detect cycles in linked lists.

---

## Common Variations

### Opposite Direction Pointers

One pointer starts from the beginning and the other from the end.

Examples:

* Valid Palindrome
* Two Sum II
* Container With Most Water

### Same Direction Pointers

Both pointers move forward.

Examples:

* Move Zeroes
* Remove Duplicates from Sorted Array

### Fast and Slow Pointers

One pointer moves faster than the other.

Examples:

* Linked List Cycle
* Middle of Linked List
* Happy Number

---

## Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---

---

## Key Takeaways

* Avoid unnecessary nested loops.
* Works best on sorted arrays and strings.
* Frequently asked in coding interviews.
* Easy to combine with sorting and sliding window techniques.

---
 ## Practice Problems

| Problem                                                     | Link                                                                                       |
| ----------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| 3Sum                                                        | https://leetcode.com/problems/3sum/                                                        |
| 3Sum Closest                                                | https://leetcode.com/problems/3sum-closest/                                                |
| Longest Mountain in Array                                   | https://leetcode.com/problems/longest-mountain-in-array/                                   |
| Remove Duplicates from Sorted Array II                      | https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/                      |
| 4Sum                                                        | https://leetcode.com/problems/4sum/                                                        |
| Two Sum II - Input Array Is Sorted                          | https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/                            |
| Container With Most Water                                   | https://leetcode.com/problems/container-with-most-water/                                   |
| Longest Word in Dictionary through Deleting                 | https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/                 |
| 3Sum With Multiplicity                                      | https://leetcode.com/problems/3sum-with-multiplicity/                                      |
| Longest Substring Without Repeating Characters              | https://leetcode.com/problems/longest-substring-without-repeating-characters/              |
| Partition Labels                                            | https://leetcode.com/problems/partition-labels/                                            |
| Max Consecutive Ones II                                     | https://leetcode.com/problems/max-consecutive-ones-ii/                                     |
| Max Consecutive Ones III                                    | https://leetcode.com/problems/max-consecutive-ones-iii/                                    |
| Valid Triangle Number                                       | https://leetcode.com/problems/valid-triangle-number/                                       |
| Push Dominoes                                               | https://leetcode.com/problems/push-dominoes/                                               |
| Reverse Vowels of a String                                  | https://leetcode.com/problems/reverse-vowels-of-a-string/                                  |
| Remove Duplicates from Sorted Array                         | https://leetcode.com/problems/remove-duplicates-from-sorted-array/                         |
| Successful Pairs of Spells and Potions                      | https://leetcode.com/problems/successful-pairs-of-spells-and-potions/                      |
| Number of Subsequences That Satisfy the Given Sum Condition | https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/ |
| Minimize Maximum Pair Sum in Array                          | https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/                          |
| Count the Number of Good Partitions                         | https://leetcode.com/problems/count-the-number-of-good-partitions/                         |
| Minimum Length of String After Deleting Similar Ends        | https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/        |
| Count Alternating Subarrays                                 | https://leetcode.com/problems/count-alternating-subarrays/                                 |
| Maximum Width Ramp                                          | https://leetcode.com/problems/maximum-width-ramp/                                          |
| Shortest Subarray to be Removed to Make Array Sorted        | https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/        |
| Minimum Difference Between Highest and Lowest of K Scores   | https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/   |
| Maximum Distance Between a Pair of Values                   | https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/                   |
| Linked List Cycle II                                        | https://leetcode.com/problems/linked-list-cycle-ii/                                        |
| Find the Duplicate Number                                   | https://leetcode.com/problems/find-the-duplicate-number/                                   |
| Remove Nth Node From End of List                            | https://leetcode.com/problems/remove-nth-node-from-end-of-list/                            |
| Backspace String Compare                                    | https://leetcode.com/problems/backspace-string-compare/                                    |
| Max Number of K-Sum Pairs                                   | https://leetcode.com/problems/max-number-of-k-sum-pairs/                                   |
| Boats to Save People                                        | https://leetcode.com/problems/boats-to-save-people/                                        |
| Trapping Rain Water                                         | https://leetcode.com/problems/trapping-rain-water/                                         |
| Minimum Window Substring                                    | https://leetcode.com/problems/minimum-window-substring/                                    |
| Subarray Product Less Than K                                | https://leetcode.com/problems/subarray-product-less-than-k/                                |
| Longest Repeating Character Replacement                     | https://leetcode.com/problems/longest-repeating-character-replacement/                     |
| Palindrome Linked List                                      | https://leetcode.com/problems/palindrome-linked-list/                                      |

