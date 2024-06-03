---
title: 666. Path Sum IV
categories: Leetcode
date: 2024-06-03 01:06:58
tags:
---

[666. Path Sum IV](https://leetcode.com/problems/path-sum-iv/description/)

## Description

If the depth of a tree is smaller than `5`, then this tree can be represented by an array of three-digit integers. For each integer in this array:

- The hundreds digit represents the depth `d` of this node where `1 <= d <= 4`.
- The tens digit represents the position `p` of this node in the level it belongs to where `1 <= p <= 8`. The position is the same as that in a full binary tree.
- The units digit represents the value `v` of this node where `0 <= v <= 9`.

Given an array of **ascending**  three-digit integers `nums` representing a binary tree with a depth smaller than `5`, return the sum of all paths from the root towards the leaves.

It is **guaranteed**  that the given array represents a valid connected binary tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/30/pathsum4-1-tree.jpg" style="width: 212px; height: 183px;">

```bash
Input: nums = [113,215,221]
Output: 12
Explanation: The tree that the list represents is shown.
The path sum is (3 + 5) + (3 + 1) = 12.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/30/pathsum4-2-tree.jpg" style="width: 132px; height: 183px;">

```bash
Input: nums = [113,221]
Output: 4
Explanation: The tree that the list represents is shown.
The path sum is (3 + 1) = 4.
```

**Constraints:**

- `1 <= nums.length <= 15`
- `110 <= nums[i] <= 489`
- `nums` represents a valid binary tree with depth less than `5`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int res = 0;
    map<int, int> m;

    int pathSum(vector<int>& nums) {
        int curDepth = 1, index = 0;
        for (auto& num : nums) {
            int key = num / 10;
            int val = num % 10;
            m[key] = val;
        }
        traverse(1, 1, 0);
        return res;
    }

    void traverse(int curDepth, int curIndex, int curVal) {
        int key = curDepth * 10 + curIndex;
        if (!m.contains(key)) {
            return;
        }
        curVal = curVal + m[key];
        int leftKey = (curDepth + 1) * 10 + 2 * curIndex - 1;
        int rightKey = (curDepth + 1) * 10 + 2 * curIndex;
        if (!m.contains(leftKey) && !m.contains(rightKey)) {
            res += curVal;
            return;
        }
        traverse(curDepth + 1, 2 * curIndex - 1, curVal);
        traverse(curDepth + 1, 2 * curIndex, curVal);
    }
};
```
