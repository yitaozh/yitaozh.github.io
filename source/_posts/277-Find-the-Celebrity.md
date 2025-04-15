---
title: 277. Find the Celebrity
categories: Leetcode
date: 2023-08-31 23:27:36
tags:
    - Two Pointers
    - Greedy
    - Graph
    - Interactive
---

[277\. Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/)

## Description

Difficulty: **Medium**

Related Topics: [Two Pointers](https://leetcode.com/tag/https://leetcode.com/tag/two-pointers//), [Greedy](https://leetcode.com/tag/https://leetcode.com/tag/greedy//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Interactive](https://leetcode.com/tag/https://leetcode.com/tag/interactive//)

Suppose you are at a party with `n` people labeled from `0` to `n - 1` and among them, there may exist one celebrity. The definition of a celebrity is that all the other `n - 1` people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function `bool knows(a, b)` that tells you whether `a` knows `b`. Implement a function `int findCelebrity(n)`. There will be exactly one celebrity if they are at the party.

Return _the celebrity's label if there is a celebrity at the party_. If there is no celebrity, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/01/19/g1.jpg)

```bash
Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2\. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/01/19/g2.jpg)

```bash
Input: graph = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.
```

**Constraints:**

* `n == graph.length == graph[i].length`
* `2 <= n <= 100`
* `graph[i][j]` is `0` or `1`.
* `graph[i][i] == 1`

**Follow up:** If the maximum number of allowed calls to the API `knows` is `3 * n`, could you find a solution without exceeding the maximum number of calls?

## Hints/Notes

* 2024/02/15
* knows(i,j) == true then i can't be a celerity since a celeb knows nobody
* knows(i,j) == false then j can't be a celeb since everyone must know the celeb

## Solution

Language: **C++**

```C++
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int can = 0;
        for (int i = 1; i < n; i++) {
            if (knows(can, i)) {
                can = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (can == i) continue;
            if (knows(can, i) || !knows(i, can)) {
                return -1;
            }
        }

        return can;
    }
};
```
