---
title: 2611. Mice and Cheese
categories: Leetcode
date: 2025-04-19 12:52:16
tags:
    - Array
    - Greedy
    - Sorting
    - Heap (Priority Queue)
---

[2611. Mice and Cheese](https://leetcode.com/problems/mice-and-cheese/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

There are two mice and `n` different types of cheese, each type of cheese should be eaten by exactly one mouse.

A point of the cheese with index `i` (**0-indexed** ) is:

- `reward1[i]` if the first mouse eats it.
- `reward2[i]` if the second mouse eats it.

You are given a positive integer array `reward1`, a positive integer array `reward2`, and a non-negative integer `k`.

Return **the maximum**  points the mice can achieve if the first mouse eats exactly `k` types of cheese.

**Example 1:**

```bash
Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
Output: 15
Explanation: In this example, the first mouse eats the 2^nd(0-indexed) and the 3^rdtypes of cheese, and the second mouse eats the 0^thand the 1^st types of cheese.
The total points are 4 + 4 + 3 + 4 = 15.
It can be proven that 15 is the maximum total points that the mice can achieve.
```

**Example 2:**

```bash
Input: reward1 = [1,1], reward2 = [1,1], k = 2
Output: 2
Explanation: In this example, the first mouse eats the 0^th(0-indexed) and 1^sttypes of cheese, and the second mouse does not eat any cheese.
The total points are 1 + 1 = 2.
It can be proven that 2 is the maximum total points that the mice can achieve.
```

**Constraints:**

- `1 <= n == reward1.length == reward2.length <= 10^5`
- `1 <= reward1[i],reward2[i] <= 1000`
- `0 <= k <= n`

## Hints/Notes

- 2025/04/16 Q1
- sort
- [0x3F's solution](https://leetcode.cn/problems/mice-and-cheese/solutions/2204108/tan-xin-ji-qi-zheng-ming-by-endlesscheng-u783/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        // so the first mice choose k cheese, second mice choose n - k cheese
        // we can choose all rewards2 first, then pick k maximum diff
        int res = 0;
        vector<int> diff;
        for (int i = 0; i < n; i++) {
            res += reward2[i];
            diff.push_back(reward1[i] - reward2[i]);
        }
        ranges::sort(diff);
        for (int i = n - 1; i >= n - k; i--) {
            res += diff[i];
        }
        return res;
    }
};
```
