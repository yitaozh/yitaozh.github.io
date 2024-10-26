---
title: 2107. Number of Unique Flavors After Sharing K Candies
categories: Leetcode
date: 2024-10-25 21:30:15
tags:
    - Array
    - Hash Table
    - Sliding Window
---

[2107. Number of Unique Flavors After Sharing K Candies](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/description/)

## Description

You are given a **0-indexed**  integer array `candies`, where `candies[i]` represents the flavor of the `i^th` candy. Your mom wants you to share these candies with your little sister by giving her `k` **consecutive**  candies, but you want to keep as many flavors of candies as possible.

Return the **maximum**  number of **unique**  flavors of candy you can keep after sharing  with your sister.

**Example 1:**

```bash
Input: candies = [1,2,2,3,4,3], k = 3
Output: 3
Explanation:
Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
You can eat candies with flavors [1,4,3].
There are 3 unique flavors, so return 3.
```

**Example 2:**

```bash
Input: candies = [2,2,2,2,3,3], k = 2
Output: 2
Explanation:
Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
You can eat candies with flavors [2,2,2,3].
There are 2 unique flavors, so return 2.
Note that you can also share the candies with flavors [2,2] and eat the candies with flavors [2,2,3,3].
```

**Example 3:**

```bash
Input: candies = [2,4,5], k = 0
Output: 3
Explanation:
You do not have to give any candies.
You can eat the candies with flavors [2,4,5].
There are 3 unique flavors, so return 3.
```

**Constraints:**

- `1 <= candies.length <= 10^5`
- `1 <= candies[i] <= 10^5`
- `0 <= k <= candies.length`

## Hints/Notes

- sliding window

## Solution

Language: **C++**

```C++
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> m;
        int n = candies.size(), right = k, res = 0;
        if (n == k) {
            return 0;
        }
        while (right < 2 * n - k) {
            int r = candies[right % n];
            m[r]++;
            if (right >= n - 1) {
                res = max(res, (int)m.size());
                int l = candies[(right - n + k + 1) % n];
                m[l]--;
                if (m[l] == 0) {
                    m.erase(l);
                }
            }
            right++;
        }
        return res;
    }
};
```
