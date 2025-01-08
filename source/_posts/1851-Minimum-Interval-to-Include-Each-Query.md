---
title: 1851. Minimum Interval to Include Each Query
categories: Leetcode
date: 2025-01-08 17:27:23
tags:
    - Array
    - Binary Search
    - Line Sweep
    - Sorting
    - Heap (Priority Queue)
---

[1851. Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given a 2D integer array `intervals`, where intervals[i] = [left<sub>i</sub>, right<sub>i</sub>] describes the `i^th` interval starting at left<sub>i</sub> and ending at right<sub>i</sub> **(inclusive)** . The **size**  of an interval is defined as the number of integers it contains, or more formally right<sub>i</sub> - left<sub>i</sub> + 1.

You are also given an integer array `queries`. The answer to the `j^th` query is the **size of the smallest interval**  `i` such that left<sub>i</sub> <= queries[j] <= right<sub>i</sub>. If no such interval exists, the answer is `-1`.

Return an array containing the answers to the queries.

**Example 1:**

```bash
Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
```

**Example 2:**

```bash
Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
```

**Constraints:**

- `1 <= intervals.length <= 10^5`
- `1 <= queries.length <= 10^5`
- `intervals[i].length == 2`
- 1 <= left<sub>i</sub> <= right<sub>i</sub> <= 10^7
- `1 <= queries[j] <= 10^7`

## Hints/Notes

- 2025/01/08
- priority queue
- [Leetcode's solution](https://leetcode.cn/problems/minimum-interval-to-include-each-query/solutions/755628/bao-han-mei-ge-cha-xun-de-zui-xiao-qu-ji-e21j/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> qindex(queries.size());
        iota(qindex.begin(), qindex.end(), 0);
        auto cmp = [&](int i, int j) {
            return queries[i] < queries[j];
        };
        ranges::sort(qindex, cmp);
        ranges::sort(intervals);
        int i = 0, n = intervals.size();
        vector<int> res(queries.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int idx : qindex) {
            while (i < n && intervals[i][0] <= queries[idx]) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, i});
                i++;
            }
            while (!pq.empty() && intervals[pq.top()[1]][1] < queries[idx]) {
                pq.pop();
            }
            res[idx] = pq.empty() ? -1 : pq.top()[0];
        }
        return res;
    }
};
```
