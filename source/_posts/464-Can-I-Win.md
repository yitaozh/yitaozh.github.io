---
title: 464. Can I Win
categories: Leetcode
date: 2025-03-17 17:42:39
tags:
    - Math
    - Dynamic Programming
    - Bit Manipulation
    - Memoization
    - Game Theory
    - Bitmask
---

[464. Can I Win](https://leetcode.com/problems/can-i-win/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

In the "100 game" two players take turns adding, to a running total, any integer from `1` to `10`. The player who first causes the running total to **reach or exceed**  100 wins.

What if we change the game so that players **cannot**  re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers `maxChoosableInteger` and `desiredTotal`, return `true` if the first player to move can force a win, otherwise, return `false`. Assume both players play **optimally** .

**Example 1:**

```bash
Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
```

**Example 2:**

```bash
Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true
```

**Example 3:**

```bash
Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true
```

**Constraints:**

- `1 <= maxChoosableInteger <= 20`
- `0 <= desiredTotal <= 300`

## Hints/Notes

- 2025/02/14 Q3
- dfs + memorization
- [Good solution](https://leetcode.cn/problems/can-i-win/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int visited[1 << 21]{};

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }

    bool dfs(int state, int sum, const int maxChoosableInteger, const int desiredTotal) {
        if (visited[state] == 1) {
            return true;
        }
        if (visited[state] == 2) {
            return false;
        }
        for (int x = 1; x <= maxChoosableInteger; x++) {
            if ((1 << x) & state) continue;
            if (sum + x >= desiredTotal) {
                visited[state] = 1;
                return true;
            }
            if (!dfs((1 << x) | state, sum + x, maxChoosableInteger, desiredTotal)) {
                visited[state] = 1;
                return true;
            }
        }
        visited[state] = 2;
        return false;
    }
};
```
