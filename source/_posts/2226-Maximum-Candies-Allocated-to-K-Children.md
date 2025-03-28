---
title: 2226. Maximum Candies Allocated to K Children
categories: Leetcode
date: 2025-03-28 02:53:19
tags:
    - Array
    - Binary Search
---

[2226. Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

You are given a **0-indexed**  integer array `candies`. Each element in the array denotes a pile of candies of size `candies[i]`. You can divide each pile into any number of **sub piles** , but you **cannot**  merge two piles together.

You are also given an integer `k`. You should allocate piles of candies to `k` children such that each child gets the **same**  number of candies. Each child can be allocated candies from **only one**  pile of candies and some piles of candies may go unused.

Return the **maximum number of candies**  each child can get.

**Example 1:**

```bash
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
```

**Example 2:**

```bash
Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.
```

**Constraints:**

- `1 <= candies.length <= 10^5`
- `1 <= candies[i] <= 10^7`
- `1 <= k <= 10^12`

## Hints/Notes

- 2025/03/17 Q3
- binary search
- [Leetcode solution](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/editorial/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = -1, right = ranges::max(candies) + 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (canAllocate(mid, k, candies)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool canAllocate(int num, long long k, vector<int>& candies) {
        if (num == 0) {
            return true;
        }
        long long num_allocated = 0;
        for (auto c : candies) {
            num_allocated += c / num;
        }
        return num_allocated >= k;
    }
};
```
