---
title: 1079. Letter Tile Possibilities
categories: Leetcode
date: 2025-04-04 14:57:23
tags:
    - Hash Table
    - String
    - Backtracking
    - Counting
---

[1079. Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

You have `n``tiles`, where each tile has one letter `tiles[i]` printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those `tiles`.

**Example 1:**

```bash
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

**Example 2:**

```bash
Input: tiles = "AAABBC"
Output: 188
```

**Example 3:**

```bash
Input: tiles = "V"
Output: 1
```

**Constraints:**

- `1 <= tiles.length <= 7`
- `tiles` consists of uppercase English letters.

## Hints/Notes

- 2025/03/30 Q2
- backtracking, check approach 3
- [Leetcode solution](https://leetcode.com/problems/letter-tile-possibilities/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n;

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<int> count(26, 0);
        for (char& c : tiles) {
            count[c - 'A']++;
        }
        int res = dfs(count);
        return res;
    }

    int dfs(vector<int>& count) {
        int res = 0;

        for (int i = 0; i < 26; i++) {
            if (!count[i]) {
                continue;
            }
            res++;
            count[i]--;
            res += dfs(count);
            count[i]++;
        }
        return res;
    }
};
```
