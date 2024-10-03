---
title: 514. Freedom Trail
categories: Leetcode
date: 2024-10-02 23:14:10
tags:
    - String
    - Dynamic Programming
    - Depth-First Search
    - Breadth-First Search
---

[514. Freedom Trail](https://leetcode.com/problems/freedom-trail/description/)

## Description

In the video game Fallout 4, the quest **"Road to Freedom"** requires players to reach a metal dial called the **"Freedom Trail Ring"** and use the dial to spell a specific keyword to open the door.

Given a string `ring` that represents the code engraved on the outer ring and another string `key` that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the `"12:00"` direction. You should spell all the characters in `key` one by one by rotating `ring` clockwise or anticlockwise to make each character of the string key aligned at the `"12:00"` direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character `key[i]`:

- You can rotate the ring clockwise or anticlockwise by one place, which counts as **one step** . The final purpose of the rotation is to align one of `ring`'s characters at the `"12:00"` direction, where this character must equal `key[i]`.
- If the character `key[i]` has been aligned at the `"12:00"` direction, press the center button to spell, which also counts as **one step** . After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/22/ring.jpg" style="width: 450px; height: 450px;">

```bash
Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1 step to spell this character.
For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
Also, we need 1 more step for spelling.
So the final output is 4.
```

**Example 2:**

```bash
Input: ring = "godding", key = "godding"
Output: 13
```

**Constraints:**

- `1 <= ring.length, key.length <= 100`
- `ring` and `key` consist of only lower case English letters.
- It is guaranteed that `key` could always be spelled by rotating `ring`.

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<set<int>> indexes;
    vector<vector<int>> dp;
    string key_;
    string ring_;

    int findRotateSteps(string ring, string key) {
        indexes.resize(26, set<int>());
        key_ = key;
        ring_ = ring;
        int n = ring.size();
        int k = key.size();
        dp.resize(n, vector<int>(k, -1));
        for (int i = 0; i < n; i++) {
            int idx = ring[i] - 'a';
            indexes[idx].insert(i);
        }

        int res = traverse(0, 0);
        return res;
    }

    int traverse(int ringIdx, int keyIdx) {
        if (keyIdx == key_.size()) {
            return 0;
        }
        int n = ring_.size();
        if (dp[ringIdx][keyIdx] != -1) {
            return dp[ringIdx][keyIdx];
        }
        int idx = key_[keyIdx] - 'a';
        auto nextIt = indexes[idx].lower_bound(ringIdx);
        if (nextIt == indexes[idx].end()) nextIt = indexes[idx].begin();
        std::set<int>::iterator prev;
        if (nextIt == indexes[idx].begin()) {
            prev = std::prev(indexes[idx].end(), 1);
        } else {
            prev = std::prev(nextIt, 1);
        }
        int res = min((*nextIt + n - ringIdx) % n + 1 + traverse(*nextIt, keyIdx + 1),
                    (ringIdx + n - *prev) % n + 1 + traverse(*prev, keyIdx + 1));
        dp[ringIdx][keyIdx] = res;
        return res;
    }
};
```
