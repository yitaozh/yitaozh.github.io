---
title: 465. Optimal Account Balancing
categories: Leetcode
date: 2025-04-02 23:21:19
tags:
    - Array
    - Dynamic Programming
    - Backtracking
    - Bit Manipulation
    - Bitmask
---

[465. Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/description/?roomId=HYIsye)

## Description

You are given an array of transactions `transactions` where transactions[i] = [from<sub>i</sub>, to<sub>i</sub>, amount<sub>i</sub>] indicates that the person with ID = from<sub>i</sub> gave amount<sub>i</sub> $ to the person with ID = to<sub>i</sub>.

Return the minimum number of transactions required to settle the debt.

**Example 1:**

```bash
Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
```

**Example 2:**

```bash
Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
```

**Constraints:**

- `1 <= transactions.length <= 8`
- `transactions[i].length == 3`
- 0 <= from<sub>i</sub>, to<sub>i</sub> < 12
- from<sub>i</sub> != to<sub>i</sub>
- 1 <= amount<sub>i</sub> <= 100

## Hints/Notes

- 2025/04/01 Q1
- backtracking
- [Leetcode solution](https://leetcode.com/problems/optimal-account-balancing/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto& t : transactions) {
            int from = t[0], to = t[1], amount = t[2];
            m[from] -= amount;
            m[to] += amount;
        }
        vector<int> nums;
        for (auto [_, v] : m) {
            if (v != 0) {
                nums.push_back(v);
            }
        }
        // now we have 2 arraies, the sum of them is the same, the question is:
        //  how many operations are needed to generate one array from the other one
        int res = dfs(0, nums);
        return res;
    }


    int dfs(int idx, vector<int>& nums) {
        int n = nums.size();
        while (idx < n && nums[idx] == 0) {
            idx++;
        }
        if (idx == nums.size()) {
            return 0;
        }
        int res = INT_MAX;
        int cur = nums[idx];
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[i] * cur < 0) {
                int previous_num = nums[i];
                nums[i] += cur;
                res = min(res, dfs(idx + 1, nums) + 1);
                nums[i] -= cur;
            }
        }
        return res;
    }
};
```
