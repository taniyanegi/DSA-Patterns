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

### In-Place Manipulation

Modify the array without using extra space. Usually one pointer tracks the position where the next valid element should be placed, while another pointer scans the array.

Examples:

* Move Zeroes
* Remove Duplicates from Sorted Array
* Remove Duplicates from Sorted Array II
* Sort Colors

Benefits:

* O(1) extra space
* Efficient array modification
* Frequently asked in interviews

## Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---
