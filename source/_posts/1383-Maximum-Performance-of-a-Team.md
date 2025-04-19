---
title: 1383. Maximum Performance of a Team
categories: Leetcode
date: 2025-04-19 15:32:17
tags:
    - Array
    - Greedy
    - Sorting
    - Heap (Priority Queue)
---

[1383. Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

You are given two integers `n` and `k` and two integer arrays `speed` and `efficiency` both of length `n`. There are `n` engineers numbered from `1` to `n`. `speed[i]` and `efficiency[i]` represent the speed and efficiency of the `i^th` engineer respectively.

Choose **at most**  `k` different engineers out of the `n` engineers to form a team with the maximum **performance** .

The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
```

**Example 2:**

```bash
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
**Explanation:
** This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
```

**Example 3:**

```bash
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
```

**Constraints:**

- `1 <= k <= n <= 10^5`
- `speed.length == n`
- `efficiency.length == n`
- `1 <= speed[i] <= 10^5`
- `1 <= efficiency[i] <= 10^8`

## Hints/Notes

- 2025/04/17 Q1
- priority queue
- [Leetcode solution](https://leetcode.com/problems/maximum-performance-of-a-team/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++) {
            pq.push({speed[i], i});
            engineers.push_back({efficiency[i], i});
        }
        vector<int> inTeam(n, false);
        long speedSum = 0, curNum = 0;
        while (!pq.empty() && curNum < k) {
            auto [s, id] = pq.top();
            pq.pop();
            speedSum += s;
            inTeam[id] = true;;
            curNum++;
        }
        vector<bool> removed(n, false);
        ranges::sort(engineers);
        int idx = 0;
        long res = 0;
        while (idx < n) {
            int cur_efficiency = engineers[idx].first;
            res = max(res, (long)cur_efficiency * speedSum);
            while (idx < n && engineers[idx].first == cur_efficiency) {
                int id = engineers[idx].second;
                removed[id] = true;
                if (inTeam[id]) {
                    inTeam[id] = false;
                    speedSum -= speed[id];
                    curNum--;
                }
                idx++;
            }
            while (!pq.empty() && curNum < k) {
                auto [s, id] = pq.top();
                pq.pop();
                if (!removed[id]) {
                    inTeam[id] = true;
                    speedSum += s;
                    curNum++;
                }
            }
        }
        return res % MOD;
    }
};
```
