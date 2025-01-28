---
title: 691. Stickers to Spell Word
categories: Leetcode
date: 2025-01-28 16:51:13
tags:
---

[691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

We are given `n` different types of `stickers`. Each sticker has a lowercase English word on it.

You would like to spell out the given string `target` by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return the minimum number of stickers that you need to spell out `target`. If the task is impossible, return `-1`.

**Note:**  In all test cases, all words were chosen randomly from the `1000` most common US English words, and `target` was chosen as a concatenation of two random words.

**Example 1:**

```bash
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
```

**Example 2:**

```bash
Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.
```

**Constraints:**

- `n == stickers.length`
- `1 <= n <= 50`
- `1 <= stickers[i].length <= 10`
- `1 <= target.length <= 15`
- `stickers[i]` and `target` consist of lowercase English letters.

## Hints/Notes

- 2025/01/28
- dp
- [Good solution](https://leetcode.com/problems/stickers-to-spell-word/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n;
    vector<int> dp;
    string t;

    int minStickers(vector<string>& stickers, string target) {
        t = target;
        n = target.size();
        dp.resize(1 << n, -1);
        dfs(0, stickers);
        return dp[0] == INT_MAX ? -1 : dp[0];
    }

    int dfs(int mask, vector<string>& stickers) {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        long res = INT_MAX;
        for (auto& s : stickers) {
            int new_mask = mask;
            for (char& c : s) {
                for (int i = 0; i < n; i++) {
                    if (!((new_mask >> i) & 1) && c == t[i]) {
                        new_mask |= (1 << i);
                        break;
                    }
                }
            }
            if (new_mask != mask) {
                res = min(res, (long)dfs(new_mask, stickers) + 1);
            }
        }
        dp[mask] = res;
        return res;
    }
};
```
