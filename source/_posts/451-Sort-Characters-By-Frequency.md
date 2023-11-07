---
title: 451. Sort Characters By Frequency
categories: Leetcode
date: 2023-11-06 22:40:29
tags:
    - Hash Table
    - String
    - Sorting
    - Heap (Priority Queue)
    - Bucket Sort
    - Counting
---

# [451\. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [String](https://leetcode.com/tag/https://leetcode.com/tag/string//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Bucket Sort](https://leetcode.com/tag/https://leetcode.com/tag/bucket-sort//), [Counting](https://leetcode.com/tag/https://leetcode.com/tag/counting//)

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return _the sorted string_. If there are multiple answers, return _any of them_.

**Example 1:**

```bash
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```bash
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```bash
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

**Constraints:**

* 1 <= s.length <= 5 * 10<sup>5</sup>
* `s` consists of uppercase and lowercase English letters and digits.

## Hints/Notes

* priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    string frequencySort(string s) {
        map<int, int> m;
        for (char c : s) {
            m[c - 'a']++;
        }
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;
        for (auto it : m) {
            int c = it.first;
            int f = it.second;
            pq.push({f, c});
        }
        string res;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            char c = top[1] + 'a';
            int f = top[0];
            for (int i = 0; i < f; i++) {
                res += c;
            }
        }
        return res;
    }
};
```
