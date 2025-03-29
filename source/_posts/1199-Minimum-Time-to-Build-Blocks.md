---
title: 1199. Minimum Time to Build Blocks
categories: Leetcode
date: 2025-03-27 14:28:54
tags:
    - Array
    - Math
    - Greedy
    - Heap (Priority Queue)
---

[1199. Minimum Time to Build Blocks](https://leetcode.com/problems/minimum-time-to-build-blocks/description/)

## Description

You are given a list of blocks, where `blocks[i] = t` means that the`i`-th block needs`t`units of time to be built. A block can only be built by exactly one worker.

A worker can either split into two workers (number of workers increases by one) or build a block then go home. Both decisions cost some time.

The time cost of spliting one worker into two workers isgiven as an integer `split`. Note that if two workers split at the same time, they split in parallel so the cost would be`split`.

Output the minimum time needed to build all blocks.

Initially, there is only **one**  worker.

**Example 1:**

```bash
Input: blocks = [1], split = 1
Output: 1
Explanation: We use 1 worker to build 1 block in 1 time unit.
```

**Example 2:**

```bash
Input: blocks = [1,2], split = 5
Output: 7
Explanation: We split the worker into 2 workers in 5 time units then assign each of them to a block so the cost is 5 + max(1, 2) = 7.
```

**Example 3:**

```bash
Input: blocks = [1,2,3], split = 1
Output: 4
Explanation: Split 1 worker into 2, then assign the first worker to the last block and split the second worker into 2.
Then, use the two unassigned workers to build the first two blocks.
The cost is 1 + max(3, 1 + max(1, 2)) = 4.
```

**Constraints:**

- `1 <= blocks.length <= 1000`
- `1 <= blocks[i] <= 10^5`
- `1 <= split <= 100`

## Hints/Notes

- 2025/03/22 Q1
- dp
- [Leetcode solution](https://leetcode.com/problems/minimum-time-to-build-blocks/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // dp[i][j]: the minimum time to build blocks [i ~ n - 1] with j workers
    vector<vector<int>> dp;

    int minBuildTime(vector<int>& blocks, int split) {
        int n = blocks.size();
        sort(blocks.begin(), blocks.end(), greater<int>());

        dp.resize(n, vector<int>(n + 1, -1));
        return dfs(blocks, split, 0, 1);
    }

    int dfs(vector<int>& blocks, int split, int idx, int numWorker) {
        if (idx == blocks.size()) {
            return 0;
        }
        if (numWorker == 0) {
            return INT_MAX;
        }
        if (numWorker >= blocks.size() - idx) {
            return blocks[idx];
        }
        if (dp[idx][numWorker] != -1) {
            return dp[idx][numWorker];
        }
        // first choice: have one worker work
        int workHere = max(blocks[idx], dfs(blocks, split, idx + 1, numWorker - 1));
        int splitHere = split + dfs(blocks, split, idx, min(2 * numWorker, (int)blocks.size() - idx));
        dp[idx][numWorker] = min(workHere, splitHere);
        return dp[idx][numWorker];
    }
};
```
