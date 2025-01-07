---
title: 763. Partition Labels
categories: Leetcode
date: 2025-01-07 02:16:19
tags:
    - Hash Table
    - Two Pointers
    - String
    - Greedy
---

[763. Partition Labels](https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.

Return a list of integers representing the size of these parts.

**Example 1:**

```bash
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```

**Example 2:**

```bash
Input: s = "eccbbbbdec"
Output: [10]
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/01/03
- jump game
- [0x3F's solution](https://leetcode.cn/problems/partition-labels/solutions/2806706/ben-zhi-shi-he-bing-qu-jian-jian-ji-xie-ygsn8/)

## Solution

Language: **C++**

Solution from 0x3F, it's like merging intervals(56) or jump game(55)

```C++
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]{};
        int n = s.size();
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);
            if (end == i) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
```
