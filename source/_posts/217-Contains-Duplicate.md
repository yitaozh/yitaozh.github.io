---
title: 217. Contains Duplicate
categories: Leetcode
date: 2025-01-03 01:25:42
tags:
    - Array
    - Hash Table
    - Sorting
---

[217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an integer array `nums`, return `true` if any value appears **at least twice**  in the array, and return `false` if every element is distinct.

**Example 1:**

```bash
Input: nums = [1,2,3,1]

Output: true
```

Explanation:

The element 1 occurs at the indices 0 and 3.

**Example 2:**

```bash
Input: nums = [1,2,3,4]

Output: false
```

Explanation:

All elements are distinct.

**Example 3:**

```bash
Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Hints/Notes

- 2025/01/02
- set
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& num : nums) {
            if (s.contains(num)) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};
```
