---
title: 3317. Find the Number of Possible Ways for an Event
categories: Leetcode
date: 2024-10-19 16:40:22
tags:
    - Math
    - Dynamic Programming
    - Combinatorics
---

[3317. Find the Number of Possible Ways for an Event](https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/description/)

## Description

You are given three integers `n`, `x`, and `y`.

An event is being held for `n` performers. When a performer arrives, they are **assigned**  to one of the `x` stages. All performers assigned to the **same**  stage will perform together as a band, though some stages might remain **empty** .

After all performances are completed, the jury will **award**  each band a score in the range `[1, y]`.

Return the **total**  number of possible ways the event can take place.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Note**  that two events are considered to have been held **differently**  if **either**  of the following conditions is satisfied:

- **Any**  performer is assigned a different stage.
- **Any**  band is awarded a different score.

**Example 1:**

```bash
Input: n = 1, x = 2, y = 3

Output: 6
```

Explanation:

- There are 2 ways to assign a stage to the performer.
- The jury can award a score of either 1, 2, or 3 to the only band.

**Example 2:**

```bash
Input: n = 5, x = 2, y = 1

Output: 32
```

Explanation:

- Each performer will be assigned either stage 1 or stage 2.
- All bands will be awarded a score of 1.

**Example 3:**

```bash
Input: n = 3, x = 3, y = 4

Output: 684
```

**Constraints:**

- `1 <= n, x, y <= 1000`

## Hints/Notes

- Stirling number of the second kind
- Biweekly Contest 141

## Solution

Language: **C++**

```C++
class Solution {
public:
    // so first, how many stages we are going to use?
    // if n >= x, we can use 1 ~ x stages;
    // if n < x, we can only use a maximum of n stages
    // if we use i stages, then for each stage, the score can vary
    // from 1 ~ y, so i stages can have y ^ i scores
    // also, if we want to use i stage, how to choose that from x stages?
    // this is C(i, n), where 1 <= i <= min(n, x)
    // so assume now we have decided the number of stages i,
    // the next question is how to put the n people on i stages, or the number
    // of permutation to put n people on i stages
    // take example 3: we have 3 people, 3 stages, with max_score = 4
    // now we decided to choose 2 stages, so the factor we have is: C(2, 3) * (4 ^ 2)
    // how to put 3 people on 2 stages?
    // this is Stirling number of the second kind
    int numberOfWays(int n, int x, int y) {
        int max_stages = min(n, x), MOD = 1'000'000'007;
        // C(m, n) = C(m - 1, n - 1) + C(m, n - 1)
        // now we want to calculate C(1, x) ~ C(max_stages, x)
        vector<long long> combinations(max_stages + 1, 0);
        for (int i = 0; i <= x; i++) {
            for (int j = min(i, max_stages); j >= 0; j--) {
                if (j) {
                    combinations[j] = (combinations[j] + combinations[j - 1]) % MOD;
                } else {
                    combinations[j] = 1;
                }
            }
        }
        vector<long long> s(max_stages + 1, 0);
        s[0] = 1;
        // S(n, k) = S(n - 1, k - 1) + k * S(n - 1, k)
        for (int i = 1; i <= n; i++) {
            for (int j = min(i, max_stages); j >= 0; j--) {
                if (j) {
                    s[j] = (j * s[j] + s[j - 1]) % MOD;
                } else {
                    s[j] = 0;
                }
            }
        }
        vector<long long> fac(max_stages + 1, 0);
        fac[0] = 1;
        for (int i = 1; i <= max_stages; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        long long res = 0;
        long long y_base = y;
        for (int i = 1; i <= max_stages; i++) {
            // first, choose i stages from x stages
            long long cur = combinations[i];
            // with i stages, there can be y_base score combinations
            cur = cur * y_base % MOD;
            // finally, to put n people on i stages, and every stage
            // must have at one people, there are s[i] combinations
            // multiplied by fac[i] since stages are different
            cur = (cur * s[i] % MOD) * fac[i] % MOD;
            res = (res + cur) % MOD;
            y_base = y_base * y % MOD;
        }
        return res;
    }
};
```
