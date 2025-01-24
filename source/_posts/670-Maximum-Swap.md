---
title: 670. Maximum Swap
categories: Leetcode
date: 2025-01-24 15:35:27
tags:
    - Math
    - Greedy
---

[670. Maximum Swap](https://leetcode.com/problems/maximum-swap/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an integer `num`. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

**Example 1:**

```bash
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
```

**Example 2:**

```bash
Input: num = 9973
Output: 9973
Explanation: No swap.
```

**Constraints:**

- `0 <= num <= 10^8`

## Hints/Notes

- 2025/01/24
- greedy
- [Leetcode solution](https://leetcode.com/problems/maximum-swap/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> nextLarger(n, n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (numStr[i] > numStr[nextLarger[i + 1]]) {
                nextLarger[i] = i;
            } else {
                nextLarger[i] = nextLarger[i + 1];
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (numStr[i] < numStr[nextLarger[i]]) {
                swap(numStr[i], numStr[nextLarger[i]]);
                break;
            }
        }
        return stoi(numStr);
    }
};
```
