---
title: 3296. Minimum Number of Seconds to Make Mountain Height Zero
categories: Leetcode
date: 2024-10-15 16:36:17
tags:
    - Array
    - Math
    - Binary Search
    - Greedy
    - Heap (Priority Queue)
---

[3296. Minimum Number of Seconds to Make Mountain Height Zero](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/)

## Description

You are given an integer `mountainHeight` denoting the height of a mountain.

You are also given an integer array `workerTimes` representing the work time of workers in **seconds** .

The workers work **simultaneously**  to **reduce**  the height of the mountain. For worker `i`:

- To decrease the mountain's height by `x`, it takes `workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x` seconds. For example:

- To reduce the height of the mountain by 1, it takes `workerTimes[i]` seconds.
- To reduce the height of the mountain by 2, it takes `workerTimes[i] + workerTimes[i] * 2` seconds, and so on.

Return an integer representing the **minimum**  number of seconds required for the workers to make the height of the mountain 0.

**Example 1:**

```bash
Input: mountainHeight = 4, workerTimes = [2,1,1]

Output: 3
```

Explanation:

One way the height of the mountain can be reduced to 0 is:

- Worker 0 reduces the height by 1, taking `workerTimes[0] = 2` seconds.
- Worker 1 reduces the height by 2, taking `workerTimes[1] + workerTimes[1] * 2 = 3` seconds.
- Worker 2 reduces the height by 1, taking `workerTimes[2] = 1` second.

Since they work simultaneously, the minimum time needed is `max(2, 3, 1) = 3` seconds.

**Example 2:**

```bash
Input: mountainHeight = 10, workerTimes = [3,2,2,4]

Output: 12
```

Explanation:

- Worker 0 reduces the height by 2, taking `workerTimes[0] + workerTimes[0] * 2 = 9` seconds.
- Worker 1 reduces the height by 3, taking `workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12` seconds.
- Worker 2 reduces the height by 3, taking `workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12` seconds.
- Worker 3 reduces the height by 2, taking `workerTimes[3] + workerTimes[3] * 2 = 12` seconds.

The number of seconds needed is `max(9, 12, 12, 12) = 12` seconds.

**Example 3:**

```bash
Input: mountainHeight = 5, workerTimes = [1]

Output: 15
```

Explanation:

There is only one worker in this example, so the answer is `workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15`.

**Constraints:**

- `1 <= mountainHeight <= 10^5`
- `1 <= workerTimes.length <= 10^4`
- `1 <= workerTimes[i] <= 10^6`

## Hints/Notes

- priority queue
- Weekly Contest 416

## Solution

Language: **C++**

```C++
class Solution {
public:
    // interpret the problem:
    // n workers, divide the mountainHeight to n sets
    // each set with size h takes t = h * (h + 1) / 2 seconds
    // find the min of max(t * worktime)
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // use priority queue:
        // first, insert all workerTimes into the priority queue,
        // the structure of the priority queue <t, 1, t0)
        // when we pop the item with minmum value out, we then insert a new value updated tri back
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        for (int t : workerTimes) {
            pq.push({t, 1, t});
        }
        long long res = 0;
        while (mountainHeight > 0) {
            auto tri = pq.top();
            pq.pop();
            res = max(res, tri[0]);
            long long n = tri[1] + 1, t = tri[2], t1 = (n + 1) * n / 2 * t;
            pq.push({t1, n, t});
            mountainHeight--;
        }
        return res;
    }
};
```
