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

You are given two **positive**  integers `n` and `k`.

An integer `x` is called **k-palindromic**  if:

- `x` is a palindrome.
- `x` is divisible by `k`.

Return the **largest**  integer having `n` digits (as a string) that is **k-palindromic** .

**Note**  that the integer must **not**  have leading zeros.

**Example 1:**

```bash
Input: n = 3, k = 5

Output: "595"
```

Explanation:

595 is the largest k-palindromic integer with 3 digits.

**Example 2:**

```bash
Input: n = 1, k = 4

Output: "8"
```

Explanation:

4 and 8 are the only k-palindromic integers with 1 digit.

**Example 3:**

```bash
Input: n = 5, k = 6

Output: "89898"
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= k <= 9`

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
        vector<long long> preSum;
        preSum.push_back(0);
        for (int i = 0; i < s.size(); i++) {
            cout << leftIdx[i] << endl;
            preSum.push_back(preSum.back() + i - leftIdx[i] + 1);
        }
        vector<long long> res;
        for (auto q : queries) {
            // what's the remaining question here:
            //  we need to find the index i between l and r such that left[i] >
            //  l
            int l = q[0], r = q[1];
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                if (leftIdx[mid] > q[0]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // now l points to the boundary
            long first = l - q[0];
            long long tmp =
                (first + 1) * first / 2 + preSum[q[1] + 1] - preSum[l];
            res.push_back(tmp);
        }
        return res;
    }
};
```
