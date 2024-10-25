---
title: 3320. Count The Number of Winning Sequences
categories: Leetcode
date: 2024-10-21 15:25:18
tags:
    - String
    - Dynamic Programming
---

[3320. Count The Number of Winning Sequences](https://leetcode.com/problems/count-the-number-of-winning-sequences/description/)

## Description

Alice and Bob are playing a fantasy battle game consisting of `n` rounds where they summon one of three magical creatures each round: a Fire Dragon, a Water Serpent, or an Earth Golem. In each round, players **simultaneously**  summon their creature and are awarded points as follows:

- If one player summons a Fire Dragon and the other summons an Earth Golem, the player who summoned the **Fire Dragon**  is awarded a point.
- If one player summons a Water Serpent and the other summons a Fire Dragon, the player who summoned the **Water Serpent**  is awarded a point.
- If one player summons an Earth Golem and the other summons a Water Serpent, the player who summoned the **Earth Golem**  is awarded a point.
- If both players summon the same creature, no player is awarded a point.

You are given a string `s` consisting of `n` characters `'F'`, `'W'`, and `'E'`, representing the sequence of creatures Alice will summon in each round:

- If `s[i] == 'F'`, Alice summons a Fire Dragon.
- If `s[i] == 'W'`, Alice summons a Water Serpent.
- If `s[i] == 'E'`, Alice summons an Earth Golem.

Bob’s sequence of moves is unknown, but it is guaranteed that Bob will never summon the same creature in two consecutive rounds. Bob beats Alice if the total number of points awarded to Bob after `n` rounds is **strictly greater**  than the points awarded to Alice.

Return the number of distinct sequences Bob can use to beat Alice.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: s = "FFF"

Output: 3
```

Explanation:

Bob can beat Alice by making one of the following sequences of moves: `"WFW"`, `"FWF"`, or `"WEW"`. Note that other winning sequences like `"WWE"` or `"EWW"` are invalid since Bob cannot make the same move twice in a row.

**Example 2:**

```bash
Input: s = "FWEFW"

Output: 18
```

Explanation:

Bob can beat Alice by making one of the following sequences of moves: `"FWFWF"`, `"FWFWE"`, `"FWEFE"`, `"FWEWE"`, `"FEFWF"`, `"FEFWE"`, `"FEFEW"`, `"FEWFE"`, `"WFEFE"`, `"WFEWE"`, `"WEFWF"`, `"WEFWE"`, `"WEFEF"`, `"WEFEW"`, `"WEWFW"`, `"WEWFE"`, `"EWFWE"`, or `"EWEWE"`.

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` is one of `'F'`, `'W'`, or `'E'`.

## Hints/Notes

- dp
- the array<int, n> stl must be initialized explicitly
- Weekly Contest 419

## Solution

Language: **C++**

```C++
class Solution {
public:
    // F vs. E: F win
    // W vs. F: w win
    // E vs. W: E win
    int n_, MOD;
    string s_;
    vector<vector<array<int, 3>>> dp;
    int countWinningSequences(string s) {
        s_ = s;
        n_ = s.size();
        MOD = 1e9 + 7;
        dp.resize(n_,
                  vector<array<int, 3>>(
                      n_ + 1000, array<int, 3>({INT_MIN, INT_MIN, INT_MIN})));
        int res = dfs(0, 1000, -1);
        return res;
    }

    int dfs(int index, int curScore, int prev) {
        if (index == n_) {
            return curScore > 1000;
        }
        if (prev != -1 && dp[index][curScore][prev] != INT_MIN) {
            return dp[index][curScore][prev];
        }
        int cur;
        if (s_[index] == 'F') {
            cur = 0;
        } else if (s_[index] == 'W') {
            cur = 1;
        } else {
            cur = 2;
        }
        long res = 0;
        for (int i = 0; i < 3; i++) {
            if (i != prev) {
                if (i == cur) {
                    res = (res + dfs(index + 1, curScore, i)) % MOD;
                } else if ((i == 0 && cur == 2) || (i == 1 && cur == 0) ||
                           (i == 2 && cur == 1)) {
                    res = (res + dfs(index + 1, curScore + 1, i)) % MOD;
                } else {
                    res = (res + dfs(index + 1, curScore - 1, i)) % MOD;
                }
            }
        }
        if (prev != -1) {
            dp[index][curScore][prev] = res;
        }
        return res;
    }
};
```
