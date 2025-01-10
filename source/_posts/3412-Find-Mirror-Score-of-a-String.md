---
title: 3412. Find Mirror Score of a String
categories: Leetcode
date: 2025-01-10 17:52:56
tags:
    - Hash Table
    - String
    - Stack
    - Simulation
---

[3412. Find Mirror Score of a String](https://leetcode.com/problems/find-mirror-score-of-a-string/description/)

## Description

You are given a string `s`.

We define the **mirror**  of a letter in the English alphabet as its corresponding letter when the alphabet is reversed. For example, the mirror of `'a'` is `'z'`, and the mirror of `'y'` is `'b'`.

Initially, all characters in the string `s` are **unmarked** .

You start with a score of 0, and you perform the following process on the string `s`:

- Iterate through the string from left to right.
- At each index `i`, find the closest **unmarked**  index `j` such that `j < i` and `s[j]` is the mirror of `s[i]`. Then, **mark**  both indices `i` and `j`, and add the value `i - j` to the total score.
- If no such index `j` exists for the index `i`, move on to the next index without making any changes.

Return the total score at the end of the process.

**Example 1:**

```bash
Input: s = "aczzx"

Output: 5
```

Explanation:

- `i = 0`. There is no index `j` that satisfies the conditions, so we skip.
- `i = 1`. There is no index `j` that satisfies the conditions, so we skip.
- `i = 2`. The closest index `j` that satisfies the conditions is `j = 0`, so we mark both indices 0 and 2, and then add `2 - 0 = 2` to the score.
- `i = 3`. There is no index `j` that satisfies the conditions, so we skip.
- `i = 4`. The closest index `j` that satisfies the conditions is `j = 1`, so we mark both indices 1 and 4, and then add `4 - 1 = 3` to the score.

**Example 2:**

```bash
Input: s = "abcdef"

Output: 0
```

Explanation:

For each index `i`, there is no index `j` that satisfies the conditions.

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters.

## Hints/Notes

- 2025/01/13
- stack
- [0x3F's solution](https://leetcode.cn/problems/find-mirror-score-of-a-string/solutions/3039028/26-ge-zhan-pythonjavacgo-by-endlesscheng-ysmk/)(checked)
- Weekly Contest 431

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<int>> nums(26);
        long long res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            int reverseIdx = 25 - idx;
            if (!nums[reverseIdx].empty()) {
                int prev = nums[reverseIdx].top();
                nums[reverseIdx].pop();
                res += i - prev;
            } else {
                nums[idx].push(i);
            }
        }
        return res;
    }
};
```
