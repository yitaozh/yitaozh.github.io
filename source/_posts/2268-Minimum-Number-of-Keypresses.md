---
title: 2268. Minimum Number of Keypresses
categories: Leetcode
date: 2025-03-16 15:18:00
tags:
    - Hash Table
    - String
    - Greedy
    - Sorting
    - Counting
---

[2268. Minimum Number of Keypresses](https://leetcode.com/problems/minimum-number-of-keypresses/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You have a keypad with `9` buttons, numbered from `1` to `9`, each mapped to lowercase English letters. You can choose which characters each button is matched to as long as:

- All 26 lowercase English letters are mapped to.
- Each character is mapped to by **exactly**  `1` button.
- Each button maps to **at most**  `3` characters.

To type the first character matched to a button, you press the button once. To type the second character, you press the button twice, and so on.

Given a string `s`, return the **minimum**  number of keypresses needed to type `s` using your keypad.

**Note**  that the characters mapped to by each button, and the order they are mapped in cannot be changed.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505184346-1.png" style="width: 300px; height: 293px;">

```bash
Input: s = "apple"
Output: 5
Explanation: One optimal way to setup your keypad is shown above.
Type 'a' by pressing button 1 once.
Type 'p' by pressing button 6 once.
Type 'p' by pressing button 6 once.
Type 'l' by pressing button 5 once.
Type 'e' by pressing button 3 once.
A total of 5 button presses are needed, so return 5.
```

**Example 2:**

<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505203823-1.png" style="width: 300px; height: 288px;">

```bash
Input: s = "abcdefghijkl"
Output: 15
Explanation: One optimal way to setup your keypad is shown above.
The letters 'a' to 'i' can each be typed by pressing a button once.
Type 'j' by pressing button 1 twice.
Type 'k' by pressing button 2 twice.
Type 'l' by pressing button 3 twice.
A total of 15 button presses are needed, so return 15.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/02/08 Q2
- sorting
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumKeypresses(string s) {
        int count[26]{};
        for (char& c : s) {
            count[c - 'a']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push(count[i]);
            }
        }
        int sum = 0, k = 0;
        while (!pq.empty()) {
            int freq = pq.top();
            pq.pop();
            sum += freq * (k / 9 + 1);
            k++;
        }
        return sum;
    }
};
```
