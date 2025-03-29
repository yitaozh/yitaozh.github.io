---
title: 1235. Maximum Profit in Job Scheduling
categories: Leetcode
date: 2025-03-27 13:12:11
tags:
    - Array
    - Binary Search
    - Dynamic Programming
    - Sorting
---

[1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/)

## Description

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime`, `endTime` and `profit` arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.

**Example 1:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png" style="width: 380px; height: 154px;">**

```bash
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png" style="width: 600px; height: 112px;">**

```bash
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
```

**Example 3:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png" style="width: 400px; height: 112px;">**

```bash
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
```

**Constraints:**

- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
- `1 <= startTime[i] < endTime[i] <= 10^9`
- `1 <= profit[i] <= 10^4`

## Hints/Notes

- 2025/03/20 Q1
- dp + binary search
- [Leetcode solution](https://leetcode.com/problems/maximum-profit-in-job-scheduling/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp.resize(n, -1);
        vector<array<int, 3>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        int res = dfs(0, jobs);
        return res;
    }

    int dfs(int index, vector<array<int, 3>>& jobs) {
        if (index == jobs.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int& res = dp[index];
        // first choice, lets just not pick this item, and continue to the next one
        res = dfs(index + 1, jobs);
        // second option, pick this one, then we need to check the minimum item to start next
        int end = jobs[index][1];
        int left = index, right = jobs.size();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (jobs[mid][0] >= end) {
                right = mid;
            } else {
                left = mid;
            }
        }
        res = max(res, jobs[index][2] + dfs(right, jobs));
        return res;
    }
};
```
