---
title: 3168. Minimum Number of Chairs in a Waiting Room
categories: Leetcode
date: 2024-06-05 01:25:01
tags:
    - String
    - Simulation
---

# [3168. Minimum Number of Chairs in a Waiting Room](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

## Description

You are given a string `s`. Simulate events at each second `i`:

- If `s[i] == 'E'`, a person enters the waiting room and takes one of the chairs in it.
- If `s[i] == 'L'`, a person leaves the waiting room, freeing up a chair.

Return the **minimum** number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially **empty** .

**Example 1:**

```bash
Input: s = "EEEEEEE"

Output: 7

Explanation:

After each second, a person enters the waiting room and no person leaves it. Therefore, a minimum of 7 chairs is needed.
```

**Example 2:**

```bash
Input: s = "ELELEEL"

Output: 2

Explanation:

Let's consider that there are 2 chairs in the waiting room. The table below shows the state of the waiting room at each second.
```

<table><tbody><tr><th>Second</th><th>Event</th><th>People in the Waiting Room</th><th>Available Chairs</th></tr><tr><td>0</td><td>Enter</td><td>1</td><td>1</td></tr><tr><td>1</td><td>Leave</td><td>0</td><td>2</td></tr><tr><td>2</td><td>Enter</td><td>1</td><td>1</td></tr><tr><td>3</td><td>Leave</td><td>0</td><td>2</td></tr><tr><td>4</td><td>Enter</td><td>1</td><td>1</td></tr><tr><td>5</td><td>Enter</td><td>2</td><td>0</td></tr><tr><td>6</td><td>Leave</td><td>1</td><td>1</td></tr></tbody></table>

**Example 3:**

```bash
Input: s = "ELEELEELLL"

Output: 3

Explanation:

Let's consider that there are 3 chairs in the waiting room. The table below shows the state of the waiting room at each second.
```

<table><tbody><tr><th>Second</th><th>Event</th><th>People in the Waiting Room</th><th>Available Chairs</th></tr><tr><td>0</td><td>Enter</td><td>1</td><td>2</td></tr><tr><td>1</td><td>Leave</td><td>0</td><td>3</td></tr><tr><td>2</td><td>Enter</td><td>1</td><td>2</td></tr><tr><td>3</td><td>Enter</td><td>2</td><td>1</td></tr><tr><td>4</td><td>Leave</td><td>1</td><td>2</td></tr><tr><td>5</td><td>Enter</td><td>2</td><td>1</td></tr><tr><td>6</td><td>Enter</td><td>3</td><td>0</td></tr><tr><td>7</td><td>Leave</td><td>2</td><td>1</td></tr><tr><td>8</td><td>Leave</td><td>1</td><td>2</td></tr><tr><td>9</td><td>Leave</td><td>0</td><td>3</td></tr></tbody></table>

**Constraints:**

- `1 <= s.length <= 50`
- `s` consists only of the letters `'E'` and `'L'`.
- `s` represents a valid sequence of entries and exits.

## Hints/Notes

- Weekly Contest 400

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumChairs(string s) {
        int res = 0, cur = 0;
        for (char c : s) {
            if (c == 'E') {
                cur++;
            } else {
                cur--;
            }
            res = max(res, cur);
        }
        return res;
    }
};
```
