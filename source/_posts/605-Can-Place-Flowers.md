---
title: 605. Can Place Flowers
categories: Leetcode
date: 2025-02-22 16:43:08
tags:
    - Array
    - Greedy
---

[605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent**  plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return `true`if `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule and `false` otherwise.

**Example 1:**

```bash
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

**Example 2:**

```bash
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

**Constraints:**

- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

## Hints/Notes

- 2025/02/16
- array
- [0x3F's solution](https://leetcode.cn/problems/can-place-flowers/solutions/2463018/ben-ti-zui-jian-dan-xie-fa-pythonjavacgo-6a6k/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == m - 1 || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};
```
