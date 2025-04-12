---
title: 274. H-Index
categories: Leetcode
date: 2025-04-12 01:09:21
tags:
    - Array
    - Sorting
    - Counting Sort
---

[274. H-Index](https://leetcode.com/problems/h-index/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their `i^th` paper, return the researcher's h-index.

According to the <a href="https://en.wikipedia.org/wiki/H-index" target="_blank">definition of h-index on Wikipedia</a>: The h-index is defined as the maximum value of `h` such that the given researcher has published at least `h` papers that have each been cited at least `h` times.

**Example 1:**

```bash
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
```

**Example 2:**

```bash
Input: citations = [1,3,1]
Output: 1
```

**Constraints:**

- `n == citations.length`
- `1 <= n <= 5000`
- `0 <= citations[i] <= 1000`

## Hints/Notes

- 2025/04/10 Q3
- [Leetcode solution](https://leetcode.cn/problems/h-index/solutions/869042/h-zhi-shu-by-leetcode-solution-fnhl/?source=submission-noac)(check the binary search solution!)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1);
        for (int c : citations) {
            count[min(c, n)]++;
        }
        int s = 0;
        for (int i = n; i >= 0; i--) {
            s += count[i];
            if (s >= i) {
                return i;
            }
        }
        return 0;
    }
};
```
