---
title: 386. Lexicographical Numbers
categories: Leetcode
date: 2025-02-03 00:00:02
tags:
    - Depth-First Search
    - Trie
---

[386. Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

You must write an algorithm that runs in`O(n)`time and uses `O(1)` extra space.

**Example 1:**

```bash
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**Example 2:**

```bash
Input: n = 2
Output: [1,2]
```

**Constraints:**

- `1 <= n <= 5 * 10^4`

## Hints/Notes

- 2025/02/02 Q1
- dfs
- [Leetcode solution](https://leetcode.com/problems/lexicographical-numbers/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> res;
    int n;

    vector<int> lexicalOrder(int n) {
        this->n = n;
        for (int i = 1; i <= min(n, 9); i++) {
            dfs(i);
        }
        return res;
    }

    void dfs(int val) {
        res.push_back(val);
        for (int i = 0; i < 10; i++) {
            if (val * 10 + i > n) {
                break;
            }
            dfs(val * 10 + i);
        }
    }
};
```
