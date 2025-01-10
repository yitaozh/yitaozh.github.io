---
title: 3387. Maximize Amount After Two Days of Conversions
categories: Leetcode
date: 2025-01-09 17:32:48
tags:
    - Array
    - String
    - Depth-First Search
    - Breadth-First Search
    - Graph
---

[3387. Maximize Amount After Two Days of Conversions](https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/description/)

## Description

You are given a string `initialCurrency`, and you start with `1.0` of `initialCurrency`.

You are also given four arrays with currency pairs (strings) and rates (real numbers):

- pairs1[i] = [startCurrency<sub>i</sub>, targetCurrency<sub>i</sub>] denotes that you can convert from startCurrency<sub>i</sub> to targetCurrency<sub>i</sub> at a rate of `rates1[i]` on **day 1** .
- pairs2[i] = [startCurrency<sub>i</sub>, targetCurrency<sub>i</sub>] denotes that you can convert from startCurrency<sub>i</sub> to targetCurrency<sub>i</sub> at a rate of `rates2[i]` on **day 2** .
- Also, each `targetCurrency` can be converted back to its corresponding `startCurrency` at a rate of `1 / rate`.

You can perform **any**  number of conversions, **including zero** , using `rates1` on day 1, **followed**  by any number of additional conversions, **including zero** , using `rates2` on day 2.

Return the **maximum**  amount of `initialCurrency` you can have after performing any number of conversions on both days **in order** .

**Note:** Conversion rates are valid, and there will be no contradictions in the rates for either day. The rates for the days are independent of each other.

**Example 1:**

```bash
Input: initialCurrency = "EUR", pairs1 = [["EUR","USD"],["USD","JPY"]], rates1 = [2.0,3.0], pairs2 = [["JPY","USD"],["USD","CHF"],["CHF","EUR"]], rates2 = [4.0,5.0,6.0]

Output: 720.00000
```

Explanation:

To get the maximum amount of **EUR** , starting with 1.0 **EUR** :

- On Day 1:

- Convert **EUR** to **USD**  to get 2.0 **USD** .
- Convert **USD**  to **JPY**  to get 6.0 **JPY** .

- On Day 2:

- Convert **JPY**  to **USD**  to get 24.0 **USD** .
- Convert **USD**  to **CHF**  to get 120.0 **CHF** .
- Finally, convert **CHF**  to **EUR**  to get 720.0 **EUR** .

**Example 2:**

```bash
Input: initialCurrency = "NGN", pairs1 = [["NGN","EUR"]], rates1 = [9.0], pairs2 = [["NGN","EUR"]], rates2 = [6.0]

Output: 1.50000
```

Explanation:

Converting **NGN**  to **EUR**  on day 1 and **EUR**  to **NGN**  using the inverse rate on day 2 gives the maximum amount.

**Example 3:**

```bash
Input: initialCurrency = "USD", pairs1 = [["USD","EUR"]], rates1 = [1.0], pairs2 = [["EUR","JPY"]], rates2 = [10.0]

Output: 1.00000
```

Explanation:

In this example, there is no need to make any conversions on either day.

**Constraints:**

- `1 <= initialCurrency.length <= 3`
- `initialCurrency` consists only of uppercase English letters.
- `1 <= n == pairs1.length <= 10`
- `1 <= m == pairs2.length <= 10`
- pairs1[i] == [startCurrency<sub>i</sub>, targetCurrency<sub>i</sub>]
- pairs2[i] == [startCurrency<sub>i</sub>, targetCurrency<sub>i</sub>]
- 1 <= startCurrency<sub>i</sub>.length, targetCurrency<sub>i</sub>.length <= 3
- startCurrency<sub>i</sub> and targetCurrency<sub>i</sub> consist only of uppercase English letters.
- `rates1.length == n`
- `rates2.length == m`
- `1.0 <= rates1[i], rates2[i] <= 10.0`
- The input is generated such that there are no contradictions or cycles in the conversion graphs for either day.
- The input is generated such that the output is **at most**  `5 * 10^10`.

## Hints/Notes

- 2025/01/09
- dfs
- [0x3F's solution](https://leetcode.cn/problems/maximize-amount-after-two-days-of-conversions/solutions/3020665/jian-tu-zi-ding-xiang-xia-dfspythonjavac-um05/)(checked)
- Weekly Contest 428

## Solution

Language: **C++**

```C++
class Solution {
public:
    string initialCurrency;
    unordered_map<string, vector<pair<string, double>>> day2;

    unordered_map<string, double> post_day2;
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        this->initialCurrency = initialCurrency;
        auto post_day1 = getCurrency(pairs1, rates1);
        auto post_day2 = getCurrency(pairs2, rates2);
        double res = 0;
        for (auto&[cur, val] : post_day2) {
            if (post_day1.contains(cur)) {
                res = max(res, post_day1[cur] / post_day2[cur]);
            }
        }
        return res;
    }

    unordered_map<string, double> getCurrency(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, double> post_day;
        int n = pairs.size();
        unordered_map<string, vector<pair<string, double>>> day;
        for (int i = 0; i < n; i++) {
            auto& p = pairs[i];
            string from = p[0], to = p[1];
            double rate = rates[i];
            day[from].push_back({to, rate});
            day[to].push_back({from, 1 / rate});
        }
        dfs(initialCurrency, "", 1.0, day, post_day);
        return post_day;
    }

    void dfs(string cur, string from, double curVal, unordered_map<string,
            vector<pair<string, double>>>& day, unordered_map<string, double>& post_day) {
        post_day[cur] = curVal;
        for (auto& p : day[cur]) {
            string next = p.first; double rate = p.second;
            if (next != from) {
                double nextVal = rate * curVal;
                if (!post_day.contains(next) || post_day[next] < nextVal) {
                    dfs(next, cur, nextVal, day, post_day);
                }
            }
        }
    }
};
```
