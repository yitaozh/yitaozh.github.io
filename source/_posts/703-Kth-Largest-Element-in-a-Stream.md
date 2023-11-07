---
title: 703. Kth Largest Element in a Stream
categories: Leetcode
date: 2023-11-06 22:48:30
tags:
    - Tree
    - Design
    - Binary Search Tree
    - Heap (Priority Queue)
    - Binary Tree
    - Data Stream
---

# [703\. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Description

Difficulty: **Easy**

Related Topics: [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//), [Data Stream](https://leetcode.com/tag/https://leetcode.com/tag/data-stream//)

Design a class to find the k<sup>th</sup> largest element in a stream. Note that it is the k<sup>th</sup> largest element in the sorted order, not the k<sup>th</sup> distinct element.

Implement `KthLargest` class:

* `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
* `int add(int val)` Appends the integer `val` to the stream and returns the element representing the k<sup>th</sup> largest element in the stream.

**Example 1:**

```bash
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

**Constraints:**

* 1 <= k <= 10<sup>4</sup>
* 0 <= nums.length <= 10<sup>4</sup>
* -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
* -10<sup>4</sup> <= val <= 10<sup>4</sup>
* At most 10<sup>4</sup> calls will be made to `add`.
* It is guaranteed that there will be at least `k` elements in the array when you search for the k<sup>th</sup> element.

## Hints/Notes

* priority queue

## Solution

Language: **C++**

```C++
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int num : nums) {
            addItem(num);
        }
    }

    void addItem(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
    }
    
    int add(int val) {
        addItem(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
