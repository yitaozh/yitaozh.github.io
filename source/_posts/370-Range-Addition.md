---
title: 370. Range Addition
categories: Leetcode
date: 2023-01-23 11:21:37
tags:
    - Array
    - Prefix Sum
---

[370. Range Addition](https://leetcode.com/problems/range-addition/)

You are given an integer `length` and an array `updates` where `updates[i] = [startIdx<sub>i</sub>, endIdx<sub>i</sub>, inc<sub>i</sub>]`.

You have an array `arr` of length `length` with all zeros, and you have some operation to apply on `arr`. In the `i^th` operation, you should increment all the elements `arr[startIdx<sub>i</sub>], arr[startIdx<sub>i</sub> + 1], ..., arr[endIdx<sub>i</sub>]` by `inc<sub>i</sub>`.

Return `arr` after applying all the `updates`.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/rangeadd-grid.jpg" style="width: 413px; height: 573px;">

```bash
Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
```

**Example 2:**

```bash
Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]
```

**Constraints:**

- `1 <= length <= 10^5`
- `0 <= updates.length <= 10^4`
- `0 <= startIdx<sub>i</sub> <= endIdx<sub>i</sub> < length`
- `-1000 <= inc<sub>i</sub> <= 1000`

## Hints/Notes

- Use the diff array

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diffs(length, 0);
        for (vector<int> update : updates) {
            int start = update[0], end = update[1], val = update[2];
            diffs[start] += val;
            if (end + 1 < length) {
                diffs[end + 1] -= val;
            }
        }
        vector<int> res;
        res.push_back(diffs[0]);
        for (int i = 1; i < length; i++) {
            res.push_back(diffs[i - 1] + diffs[i]);
        }
        return res;
    }
};
```
