---
title: 740. Delete and Earn
categories: Leetcode
date: 2025-04-12 00:11:53
tags:
    - Array
    - Hash Table
    - Dynamic Programming
---

[740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an integer array `nums`. You want to maximize the number of points you get by performing the following operation any number of times:

- Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete <b>every</b> element equal to `nums[i] - 1` and **every**  element equal to `nums[i] + 1`.

Return the **maximum number of points**  you can earn by applying the above operation some number of times.

**Example 1:**

```bash
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
```

**Example 2:**

```bash
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= 10^4`

## Hints/Notes

- 2025/04/10 Q1
- dp
- [0x3F's solution](https://leetcode.cn/problems/delete-and-earn/solutions/3061028/zhi-yu-da-jia-jie-she-pythonjavaccgojsru-e5gg/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp;

    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<pair<int, int>> freqs(count.begin(), count.end());
        int n = freqs.size();
        dp.resize(n, -1);
        int res = dfs(0, freqs);
        return res;
    }

    int dfs(int idx, vector<pair<int, int>>& freqs) {
        int n = freqs.size();
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int& res = dp[idx];
        if (idx != n - 1 && freqs[idx].first + 1 == freqs[idx + 1].first) {
            res = max(freqs[idx].first * freqs[idx].second + dfs(idx + 2, freqs), dfs(idx + 1, freqs));
        } else {
            res = freqs[idx].first * freqs[idx].second + dfs(idx + 1, freqs);
        }
        return res;
    }
};
```
