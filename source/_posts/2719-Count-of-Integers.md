---
title: 2719. Count of Integers
categories: Leetcode
date: 2024-11-30 15:15:49
tags:
    - Math
    - String
    - Dynamic Programming
---

[2719. Count of Integers](https://leetcode.com/problems/count-of-integers/description/)

## Description

You are given two numeric strings `num1` and `num2` and two integers `max_sum` and `min_sum`. We denote an integer `x` to be good if:

- `num1 <= x <= num2`
- `min_sum <= digit_sum(x) <= max_sum`.

Return the number of good integers. Since the answer may be large, return it modulo `10^9 + 7`.

Note that `digit_sum(x)` denotes the sum of the digits of `x`.

**Example 1:**

```bash
Input: num1 = "1", num2 = "12", `min_sum` = 1, max_sum = 8
Output: 11
Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.
```

**Example 2:**

```bash
Input: num1 = "1", num2 = "5", `min_sum` = 1, max_sum = 5
Output: 5
Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.
```

**Constraints:**

- `1 <= num1 <= num2 <= 10^22`
- `1 <= min_sum <= max_sum <= 400`

## Hints/Notes

- 2024/11/22
- digit dp with limit_low
- [0x3F's solution](https://leetcode.cn/problems/count-of-integers/solutions/2296043/shu-wei-dp-tong-yong-mo-ban-pythonjavacg-9tuc/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;
    string low, high;
    int min_sum, max_sum;
    int MOD = 1'000'000'007;

    int count(string num1, string num2, int min_sum, int max_sum) {
        this->min_sum = min_sum;
        this->max_sum = max_sum;
        low = num1;
        high = num2;
        int n = high.size();
        low = string(n - low.size(), '0') + low;
        dp.resize(n, vector<int>(max_sum + 1, -1));
        int res = dfs(0, 0, true, true) % MOD;
        return res;
    }

    int dfs(int index, int sum, bool limit_low, bool limit_high) {
        if (index == high.size()) {
            return sum >= min_sum;
        }
        if (!limit_low && !limit_high && dp[index][sum] != -1) {
            return dp[index][sum];
        }
        long long res = 0;
        int lo = limit_low ? low[index] - '0' : 0;
        int hi = limit_high ? high[index] - '0' : 9;
        for (int i = lo; i <= min(hi, max_sum - sum); i++) {
            res = (res + dfs(index + 1, sum + i, limit_low && i == lo,
                             limit_high && i == hi)) %
                  MOD;
        }
        if (!limit_low && !limit_high) {
            dp[index][sum] = res;
        }
        return res;
    }
};
```
