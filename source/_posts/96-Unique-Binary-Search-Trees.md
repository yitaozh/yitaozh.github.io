---
title: 96. Unique Binary Search Trees
categories: Leetcode
date: 2023-08-27 23:16:09
tags:
    - Math
    - Dynamic Programming
    - Tree
    - Binary Search Tree
    - Binary Tree
---

[96\. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

## Description

Difficulty: **Medium**

Related Topics: [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Tree](https://leetcode.com/tag/https://leetcode.com/tag/tree//), [Binary Search Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-search-tree//), [Binary Tree](https://leetcode.com/tag/https://leetcode.com/tag/binary-tree//)

Given an integer `n`, return _the number of structurally unique **BST'**s (binary search trees) which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```bash
Input: n = 3
Output: 5
```

**Example 2:**

```bash
Input: n = 1
Output: 1
```

**Constraints:**

* `1 <= n <= 19`

## Hints/Notes

* Draw the tree
* Dynamic programming

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> memo;

    int numTrees(int n) {
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return count(1, n);
    }

    int count(int low, int high) {
        if (low >= high) {
            return 1;
        }

        if (memo[low][high] != 0) {
            return memo[low][high];
        }

        int sum = 0;
        for (int i = low; i <= high; i++) {
            int left = count(low, i - 1);
            int right = count(i + 1, high);
            sum += left * right;
        }
        memo[low][high] = sum;
        return sum;
    }
};
```
