---
title: 3159. Find Occurrences of an Element in an Array
categories: Leetcode
date: 2024-05-28 23:37:44
tags:
    - Array
    - Hash Table
---

[3159. Find Occurrences of an Element in an Array](https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/)

You are given an integer array `nums`, an integer array `queries`, and an integer `x`.

For each `queries[i]`, you need to find the index of the `queries[i]^th` occurrence of `x` in the `nums` array. If there are fewer than `queries[i]` occurrences of `x`, the answer should be -1 for that query.

Return an integer array `answer` containing the answers to all queries.

**Example 1:**

```bash
Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

Output: [0,-1,2,-1]

Explanation:

- For the 1^st query, the first occurrence of 1 is at index 0.
- For the 2^nd query, there are only two occurrences of 1 in `nums`, so the answer is -1.
- For the 3^rd query, the second occurrence of 1 is at index 2.
- For the 4^th query, there are only two occurrences of 1 in `nums`, so the answer is -1.
```

**Example 2:**

```bash
Input: nums = [1,2,3], queries = [10], x = 5

Output: [-1]

Explanation:

- For the 1^st query, 5 doesn't exist in `nums`, so the answer is -1.
```

**Constraints:**

- `1 <= nums.length, queries.length <= 10^5`
- `1 <= queries[i] <= 10^5`
- `1 <= nums[i], x <= 10^4`

## Hints/Notes

- Biweekly Contest 131

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> occurances;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occurances.push_back(i);
            }
        }
        vector<int> res;
        for (auto query : queries) {
            if (query - 1 >= occurances.size()) {
                res.push_back(-1);
            } else {
                res.push_back(occurances[query - 1]);
            }
        }
        return res;
    }
};
```
