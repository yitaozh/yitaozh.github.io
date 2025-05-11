---
title: 2604. Minimum Time to Eat All Grains
categories: Leetcode
date: 2025-05-11 01:00:20
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sorting
---

[2604. Minimum Time to Eat All Grains](https://leetcode.com/problems/minimum-time-to-eat-all-grains/description/?envType=company&envId=confluent&favoriteSlug=confluent-all)

## Description

There are <code>n</code> hens and <code>m</code> grains on a line. You are given the initial positions of the hens and the grains in two integer arrays <code>hens</code> and <code>grains</code> of size <code>n</code> and <code>m</code> respectively.

Any hen can eat a grain if they are on the same position. The time taken for this is negligible. One hen can also eat multiple grains.

In <code>1</code> second, a hen can move right or left by <code>1</code> unit. The hens can move simultaneously and independently of each other.

Return the **minimum**  time to eat all grains if the hens act optimally.

**Example 1:**

```bash
Input: hens = [3,6,7], grains = [2,4,7,9]
Output: 2
Explanation:
One of the ways hens eat all grains in 2 seconds is described below:
- The first hen eats the grain at position 2 in 1 second.
- The second hen eats the grain at position 4 in 2 seconds.
- The third hen eats the grains at positions 7 and 9 in 2 seconds.
So, the maximum time needed is 2.
It can be proven that the hens cannot eat all grains before 2 seconds.
```

**Example 2:**

```bash
Input: hens = [4,6,109,111,213,215], grains = [5,110,214]
Output: 1
Explanation:
One of the ways hens eat all grains in 1 second is described below:
- The first hen eats the grain at position 5 in 1 second.
- The fourth hen eats the grain at position 110 in 1 second.
- The sixth hen eats the grain at position 214 in 1 second.
- The other hens do not move.
So, the maximum time needed is 1.
```

**Constraints:**

- <code>1 <= hens.length, grains.length <= 2*10^4</code>
- <code>0 <= hens[i], grains[j] <= 10^9</code>

## Hints/Notes

- 2025/05/03 Q1
- binary search + greedy
- [Good solution](https://leetcode.com/problems/minimum-time-to-eat-all-grains/solutions/3357686/c-python-binary-search-greedy-two-pointers-simple-math-with-explanation/?envType=company&envId=confluent&favoriteSlug=confluent-all)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        ranges::sort(hens);
        ranges::sort(grains);
        unordered_set<int> henset(hens.begin(), hens.end());
        int left = -1, right = 2e9 + 1;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if (check(mid, hens, grains)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    bool check(long time, vector<int>& hens, vector<int>& grains) {
        int n = grains.size(), r = 0;
        for (int hen : hens) {
            long budget = time;
            if (hen > grains[r]) {
                if (hen - grains[r] > time) return false;
                long diff = hen - grains[r];
                budget = max(budget - 2 * diff, (budget - diff) / 2);
            }
            while (r < n && grains[r] - hen <= budget) {
                r++;
            }
            if (r == n) {
                return true;
            }
        }
        return false;
    }
};
```
