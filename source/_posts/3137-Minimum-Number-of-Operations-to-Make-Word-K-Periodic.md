---
title: 3137. Minimum Number of Operations to Make Word K-Periodic
categories: Leetcode
date: 2024-05-17 11:51:28
tags:
    - Hash Table
    - String
    - Counting
---

[3137. Minimum Number of Operations to Make Word K-Periodic](https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/)

You are given a string `word` of size `n`, and an integer `k` such that `k` divides `n`.

In one operation, you can pick any two indices `i` and `j`, that are divisible by `k`, then replace the substring of length `k` starting at `i` with the substring of length `k` starting at `j`. That is, replace the substring `word[i..i + k - 1]` with the substring `word[j..j + k - 1]`.

Return the **minimum**  number of operations required to make `word` **k-periodic** .

We say that `word` is **k-periodic**  if there is some string `s` of length `k` such that `word` can be obtained by concatenating `s` an arbitrary number of times. For example, if `word == “ababab”`, then `word` is 2-periodic for `s = "ab"`.

**Example 1:**

```bash
Input: word = "leetcodeleet", k = 4

Output: 1

Explanation:

We can obtain a 4-periodic string by picking i = 4 and j = 0. After this operation, word becomes equal to "leetleetleet".
```

**Example 2:**

```bash
Input: word = "leetcoleet", k = 2

Output: 3

Explanation:

We can obtain a 2-periodic string by applying the operations in the table below.
```

**Constraints:**

- `1 <= n == word.length <= 10^5`
- `1 <= k <= word.length`
- `k` divides `word.length`.
- `word` consists only of lowercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int maxCount = 0;
        map<string, int> m;
        for (int i = 0; i < word.size(); i = i + k) {
            string cur = word.substr(i, k);
            m[cur]++;
            maxCount = max(maxCount, m[cur]);
        }
        return word.size() / k - maxCount;
    }
};
```
