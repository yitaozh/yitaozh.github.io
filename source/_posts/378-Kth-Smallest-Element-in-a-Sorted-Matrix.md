---
title: 378. Kth Smallest Element in a Sorted Matrix
categories: Leetcode
date: 2023-10-17 23:38:07
tags:
    - Array
    - Binary Search
    - Sorting
    - Heap (Priority Queue)
    - Matrix
---

# [378\. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Matrix](https://leetcode.com/tag/https://leetcode.com/tag/matrix//)

Given an `n x n` `matrix` where each of the rows and columns is sorted in ascending order, return _the_ k<sup>th</sup> _smallest element in the matrix_.

Note that it is the k<sup>th</sup> smallest element **in the sorted order**, not the k<sup>th</sup> **distinct** element.

You must find a solution with a memory complexity better than O(n<sup>2</sup>).

**Example 1:**

```bash
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
```

**Example 2:**

```bash
Input: matrix = [[-5]], k = 1
Output: -5
```

**Constraints:**

* `n == matrix.length == matrix[i].length`
* `1 <= n <= 300`
* -10<sup>9</sup> <= `matrix[i][j]` <= 10<sup>9</sup>
* All the rows and columns of `matrix` are **guaranteed** to be sorted in **non-decreasing order**.
* 1 <= k <= n<sup>2</sup>

**Follow up:**

* Could you solve the problem with a constant memory (i.e., `O(1)` memory complexity)?
* Could you solve the problem in `O(n)` time complexity? The solution may be too advanced for an interview but you may find reading [this paper](http://www.cse.yorku.ca/~andy/pubs/X+Y.pdf) fun.

## Hints/Notes

* Priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        while (k > 1) {
            auto p = pq.top();
            pq.pop();
            int i = p[1], j = p[2];
            if (j < n - 1) {
                pq.push({matrix[i][j + 1], i, j + 1});
            }
            k--;
        }
        auto p = pq.top();
        return p[0];
    }
};
```
