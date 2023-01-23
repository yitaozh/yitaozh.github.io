---
title: 370. Range Addition
categories: Leetcode
date: 2023-01-23 11:21:37
tags:
    - Array
    - Prefix Sum
---

# [370\. Range Addition](https://leetcode.com/problems/range-addition/)

## Description

Difficulty: **Medium**

undefined

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