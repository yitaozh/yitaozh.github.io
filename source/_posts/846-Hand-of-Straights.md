---
title: 846. Hand of Straights
categories: Leetcode
date: 2025-01-08 01:07:03
tags:
    - Array
    - Hash Table
    - Greedy
    - Sorting
---

[846. Hand of Straights](https://leetcode.com/problems/hand-of-straights/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size `groupSize`, and consists of `groupSize` consecutive cards.

Given an integer array `hand` where `hand[i]` is the value written on the `i^th` card and an integer `groupSize`, return `true` if she can rearrange the cards, or `false` otherwise.

**Example 1:**

```bash
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```

**Example 2:**

```bash
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

```

**Constraints:**

- `1 <= hand.length <= 10^4`
- `0 <= hand[i] <= 10^9`
- `1 <= groupSize <= hand.length`

**Note:**  This question is the same as 1296: <a href="https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/" target="_blank">https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/</a>

## Hints/Notes

- 2025/01/07
- map
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) {
            return false;
        }
        map<int, int> m;
        for (auto num : hand) {
            m[num]++;
        }
        while (!m.empty()) {
            auto [start, _] = *m.begin();
            for (int i = start; i < groupSize + start; i++) {
                if (!m.contains(i) || m[i] == 0) {
                    return false;
                }
                m[i]--;
                if (m[i] == 0) {
                    m.erase(i);
                }
            }
        }
        return true;
    }
};
```
