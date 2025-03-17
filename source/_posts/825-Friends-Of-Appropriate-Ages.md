---
title: 825. Friends Of Appropriate Ages
categories: Leetcode
date: 2025-02-20 23:12:07
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Sorting
---

[825. Friends Of Appropriate Ages](https://leetcode.com/problems/friends-of-appropriate-ages/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

There are `n` persons on a social media website. You are given an integer array `ages` where `ages[i]` is the age of the `i^th` person.

A Person `x` will not send a friend request to a person `y` (`x != y`) if any of the following conditions is true:

- `age[y] <= 0.5 * age[x] + 7`
- `age[y] > age[x]`
- `age[y] > 100 &amp;&amp; age[x] < 100`

Otherwise, `x` will send a friend request to `y`.

Note that if `x` sends a request to `y`, `y` will not necessarily send a request to `x`. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

**Example 1:**

```bash
Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
```

**Example 2:**

```bash
Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
```

**Example 3:**

```bash
Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
```

**Constraints:**

- `n == ages.length`
- `1 <= n <= 2 * 10^4`
- `1 <= ages[i] <= 120`

## Hints/Notes

- 2025/02/10 Q1
- sliding window
- [0x3F's solution](https://leetcode.cn/problems/friends-of-appropriate-ages/solutions/2990994/ji-shu-hua-dong-chuang-kou-pythonjavaccg-jfya/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)
- TODO: use count array to improve the efficiency

## Solution

Language: **C++**

```C++
class Solution {
public:
    // how to interpret:
    //  1. y > 0.5 * x + 7
    //  2. y <= x
    int numFriendRequests(vector<int>& ages) {
        ranges::sort(ages);
        int n = ages.size(), left = 0, right = 0, res = 0;
        for (int i = 0; i < n; i++) {
            while (left < n && ages[left] <= ages[i] * 0.5 + 7) {
                left++;
            }
            while (right < n && ages[right] <= ages[i]) {
                right++;
            }
            res += max(right - left - 1, 0);
        }
        return res;
    }
};
```
