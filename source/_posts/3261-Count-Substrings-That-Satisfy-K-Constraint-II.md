---
title: 3261. Count Substrings That Satisfy K-Constraint II
categories: Leetcode
date: 2024-10-04 00:03:10
tags:
    - Array
    - String
    - Binary Search
    - Sliding Window
    - Prefix Sum
---

[3261. Count Substrings That Satisfy K-Constraint II](https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/description/)

## Description

You are given a **binary**  string `s` and an integer `k`.

You are also given a 2D integer array `queries`, where queries[i] = [l<sub>i</sub>, r<sub>i</sub>].

A **binary string**  satisfies the **k-constraint**  if **either**  of the following conditions holds:

- The number of `0`'s in the string is at most `k`.
- The number of `1`'s in the string is at most `k`.

Return an integer array `answer`, where `answer[i]` is the number of substrings of s[l<sub>i</sub>..r<sub>i</sub>] that satisfy the **k-constraint** .

**Example 1:**

```bash
Input: s = "0001111", k = 2, queries = [[0,6]]

Output: [26]
```

Explanation:

For the query `[0, 6]`, all substrings of `s[0..6] = "0001111"` satisfy the k-constraint except for the substrings `s[0..5] = "000111"` and `s[0..6] = "0001111"`.

**Example 2:**

```bash
Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]

Output: [15,9,3]
```

Explanation:

The substrings of `s` with a length greater than 3 do not satisfy the k-constraint.

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.
- `1 <= k <= s.length`
- `1 <= queries.length <= 10^5`
- queries[i] == [l<sub>i</sub>, r<sub>i</sub>]
- 0 <= l<sub>i</sub> <= r<sub>i</sub> < s.length
- All queries are distinct.

## Hints/Notes

- sliding window + preSum + binarySearch
- Weekly Contest 411

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>>& queries) {
        int left = 0;
        vector<int> count(2, 0), leftIdx;
        // first step, for each right index, find their left index
        for (int right = 0; right < s.size(); right++) {
            int val = s[right] - '0';
            count[val % 2]++;
            while (count[0] > k && count[1] > k) {
                val = s[left] - '0';
                count[val % 2]--;
                left++;
            }
            leftIdx.push_back(left);
        }
        // the meaning of preSum[i]: starting from 0, how many valid substrings until index i
        vector<long long> preSum;
        preSum.push_back(0);
        for (int i = 0; i < s.size(); i++) {
            preSum.push_back(preSum.back() + i - leftIdx[i] + 1);
        }
        vector<long long> res;
        for (auto q : queries) {
            // what's the remaining question here:
            //  we need to find the index i between l and r such that leftIdx[i] > l
            //  special case: if leftIdx[r] is <= l, then all substrings are valid
            int l = q[0], r = q[1];
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                if (leftIdx[mid] > q[0]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // now l points to the boundary, on the left side of the boundary,
            // the i has leftIdx[i] < l, so all substrings are valid, on the right side
            // we can use the preSum to calculate
            long first = l - q[0];
            long long tmp =
                (first + 1) * first / 2 + preSum[q[1] + 1] - preSum[l];
            res.push_back(tmp);
        }
        return res;
    }
};
```
