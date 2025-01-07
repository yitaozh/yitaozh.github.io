---
title: 3277. Maximum XOR Score Subarray Queries
categories: Leetcode
date: 2024-10-06 21:55:55
tags:
    - Array
    - Dynamic Programming
---

[3277. Maximum XOR Score Subarray Queries](https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/)

## Description

You are given an array `nums` of `n` integers, and a 2D integer array `queries` of size `q`, where queries[i] = [l<sub>i</sub>, r<sub>i</sub>].

For each query, you must find the **maximum XOR score**  of any subarray of nums[l<sub>i</sub>..r<sub>i</sub>].

The **XOR score**  of an array `a` is found by repeatedly applying the following operations on `a` so that only one element remains, that is the **score** :

- Simultaneously replace `a[i]` with `a[i] XOR a[i + 1]` for all indices `i` except the last one.
- Remove the last element of `a`.

Return an array `answer` of size `q` where `answer[i]` is the answer to query `i`.

**Example 1:**

```bash
Input: nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]

Output: [12,60,60]
```

Explanation:

In the first query, `nums[0..2]` has 6 subarrays `[2]`, `[8]`, `[4]`, `[2, 8]`, `[8, 4]`, and `[2, 8, 4]` each with a respective XOR score of 2, 8, 4, 10, 12, and 6. The answer for the query is 12, the largest of all XOR scores.

In the second query, the subarray of `nums[1..4]` with the largest XOR score is `nums[1..4]` with a score of 60.

In the third query, the subarray of `nums[0..5]` with the largest XOR score is `nums[1..4]` with a score of 60.

**Example 2:**

```bash
Input: nums = [0,7,3,2,8,5,1], queries = [[0,3],[1,5],[2,4],[2,6],[5,6]]

Output: [7,14,11,14,5]
```

Explanation:

<table height="70" width="472"><thead><tr><th>Index</th><th>nums[l<sub>i</sub>..r<sub>i</sub>]</th><th>Maximum XOR Score Subarray</th><th>Maximum Subarray XOR Score</th></tr></thead><tbody><tr><td>0</td><td>[0, 7, 3, 2]</td><td>[7]</td><td>7</td></tr><tr><td>1</td><td>[7, 3, 2, 8, 5]</td><td>[7, 3, 2, 8]</td><td>14</td></tr><tr><td>2</td><td>[3, 2, 8]</td><td>[3, 2, 8]</td><td>11</td></tr><tr><td>3</td><td>[3, 2, 8, 5, 1]</td><td>[2, 8, 5, 1]</td><td>14</td></tr><tr><td>4</td><td>[5, 1]</td><td>[5]</td><td>5</td></tr></tbody></table>

**Constraints:**

- `1 <= n == nums.length <= 2000`
- `0 <= nums[i] <= 2^31 - 1`
- `1 <= q == queries.length <= 10^5`
- `queries[i].length == 2`
- queries[i] = [l<sub>i</sub>, r<sub>i</sub>]
- 0 <= l<sub>i</sub> <= r<sub>i</sub> <= n - 1

## Hints/Notes

- 2024/09/02
- range dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-xor-score-subarray-queries/solution/qu-jian-dp-tao-qu-jian-dppythonjavacgo-b-w4be/)(checked)
- Weekly Contest 413

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]: the maximum xor score of all subarrays between
    // [i, j]
    vector<vector<int>> dp;
    // the meaning of score[i][j]: the value of xor score of subarray [i, i + 1,
    // ..., j] the state transition:
    //  score[i][j] = score[i + 1][j] ^ score[i][j - 1]
    //  to calculate (i, j), we need larger i and smaller j
    vector<vector<int>> score;

    vector<int> maximumSubarrayXor(vector<int>& nums,
                                   vector<vector<int>>& queries) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        score.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            score[i][i] = nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            score[i][i] = nums[i];
            dp[i][i] = score[i][i];
            for (int j = i + 1; j < n; j++) {
                score[i][j] = score[i + 1][j] ^ score[i][j - 1];
                dp[i][j] = max({score[i][j], dp[i + 1][j], dp[i][j - 1]});
            }
        }
        vector<int> res;
        for (auto q : queries) {
            int i = q[0], j = q[1];
            res.push_back(dp[i][j]);
        }
        return res;
    }
};
```
