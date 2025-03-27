---
title: 826. Most Profit Assigning Work
categories: Leetcode
date: 2025-03-27 13:45:30
tags:
    - Array
    - Two Pointers
    - Binary Search
    - Greedy
    - Sorting
---

[826. Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

You have `n` jobs and `m` workers. You are given three arrays: `difficulty`, `profit`, and `worker` where:

- `difficulty[i]` and `profit[i]` are the difficulty and the profit of the `i^th` job, and
- `worker[j]` is the ability of `j^th` worker (i.e., the `j^th` worker can only complete a job with difficulty at most `worker[j]`).

Every worker can be assigned **at most one job** , but one job can be **completed multiple times** .

- For example, if three workers attempt the same job that pays `$1`, then the total profit will be `$3`. If a worker cannot complete any job, their profit is `$0`.

Return the maximum profit we can achieve after assigning the workers to the jobs.

**Example 1:**

```bash
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
```

**Example 2:**

```bash
Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0
```

**Constraints:**

- `n == difficulty.length`
- `n == profit.length`
- `m == worker.length`
- `1 <= n, m <= 10^4`
- `1 <= difficulty[i], profit[i], worker[i] <= 10^5`

## Hints/Notes

- 2025/03/21
- preMax + sort
- [Leetcode solution](https://leetcode.com/problems/most-profit-assigning-work/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 1; i < n; i++) {
            jobs[i].second = max(jobs[i].second, jobs[i - 1].second);
        }
        int res = 0;
        for (int w : worker) {
            int left = -1, right = n;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (w >= jobs[mid].first) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            if (left == -1) continue;
            res += jobs[left].second;
        }
        return res;
    }
};
```
