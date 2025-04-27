---
title: 3389. Minimum Operations to Make Character Frequencies Equal
categories: Leetcode
date: 2025-04-27 13:39:56
tags:
    - Hash Table
    - String
    - Dynamic Programming
    - Counting
    - Enumeration
---

[3389. Minimum Operations to Make Character Frequencies Equal](https://leetcode.com/problems/minimum-operations-to-make-character-frequencies-equal/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given a string `s`.

A string `t` is called **good**  if all characters of `t` occur the same number of times.

You can perform the following operations **any number of times** :

- Delete a character from `s`.
- Insert a character in `s`.
- Change a character in `s` to its next letter in the alphabet.

**Note**  that you cannot change `'z'` to `'a'` using the third operation.

Return the **minimum**  number of operations required to make `s` **good** .

**Example 1:**

```bash
Input: s = "acab"

Output: 1
```

Explanation:

We can make `s` good by deleting one occurrence of character `'a'`.

**Example 2:**

```bash
Input: s = "wddw"

Output: 0
```

Explanation:

We do not need to perform any operations since `s` is initially good.

**Example 3:**

```bash
Input: s = "aaabc"

Output: 2
```

Explanation:

We can make `s` good by applying these operations:

- Change one occurrence of `'a'` to `'b'`
- Insert one occurrence of `'c'` into `s`

**Constraints:**

- `3 <= s.length <= 2* 10^4`
- `s` contains only lowercase English letters.

## Hints/Notes

- 2025/04/22 Q1
- dp
- [Leetcode solution](https://leetcode.cn/problems/minimum-operations-to-make-character-frequencies-equal/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int makeStringGood(string s) {
        int count[26]{};
        for (char& c : s) {
            count[c - 'a']++;
        }
        int mx = ranges::max(count);
        int f[27]{};
        int ans = s.size();
        for (int target = 1; target <= mx; target++) {
            f[25] = min(count[25], abs(count[25] - target));
            for (int i = 24; i >= 0; i--) {
                int x = count[i], y = count[i + 1];
                // only modify x
                f[i] = f[i + 1] + min(x, abs(x - target));
                // x become target or 0, y become target
                if (y < target) {
                    // if x > target, then x -> target, y -> target
                    // if x <= target, then x -> 0, y -> target
                    int t = x > target ? target : 0;
                    f[i] = min(f[i], f[i + 2] + max(x - t, target - y));
                }
            }
            ans = min(ans, f[0]);
        }
        return ans;
    }
};
```
