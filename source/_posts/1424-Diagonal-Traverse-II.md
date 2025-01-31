---
title: 1424. Diagonal Traverse II
categories: Leetcode
date: 2025-01-30 22:57:58
tags:
    - Array
    - Sorting
    - Heap (Priority Queue)
---

[1424. Diagonal Traverse II](https://leetcode.com/problems/diagonal-traverse-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a 2D integer array `nums`, return all elements of `nums` in diagonal order as shown in the below images.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_1_1784.png" style="width: 158px; height: 143px;">

```bash
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_2_1784.png" style="width: 230px; height: 177px;">

```bash
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i].length <= 10^5`
- `1 <= sum(nums[i].length) <= 10^5`
- `1 <= nums[i][j] <= 10^5`

## Hints/Notes

- 2025/01/30
- bfs
- [Leetcode solution](https://leetcode.com/problems/diagonal-traverse-ii/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        int m = nums.size();
        vector<int> res;
        q.push({0, 0});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            res.push_back(nums[x][y]);
            if (y == 0 && x < m - 1) {
                q.emplace(x + 1, 0);
            }
            if (y < nums[x].size() - 1) {
                q.emplace(x, y + 1);
            }
        }
        return res;
    }
};
```
