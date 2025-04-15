---
title: 3480. Maximize Subarrays After Removing One Conflicting Pair
categories: Leetcode
date: 2025-04-15 02:02:19
tags:
    - Array
    - Segment Tree
    - Enumeration
    - Prefix Sum
---

[3480. Maximize Subarrays After Removing One Conflicting Pair](https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

You are given an integer `n` which represents an array `nums` containing the numbers from 1 to `n` in order. Additionally, you are given a 2D array `conflictingPairs`, where `conflictingPairs[i] = [a, b]` indicates that `a` and `b` form a conflicting pair.

Remove **exactly**  one element from `conflictingPairs`. Afterward, count the number of <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:rp:" data-state="closed" class="">non-empty subarrays</button> of `nums` which do not contain both `a` and `b` for any remaining conflicting pair `[a, b]`.

Return the **maximum**  number of subarrays possible after removing **exactly**  one conflicting pair.

**Example 1:**

```bash
Input: n = 4, conflictingPairs = [[2,3],[1,4]]

Output: 9
```

Explanation:

- Remove `[2, 3]` from `conflictingPairs`. Now, `conflictingPairs = [[1, 4]]`.
- There are 9 subarrays in `nums` where `[1, 4]` do not appear together. They are `[1]`, `[2]`, `[3]`, `[4]`, `[1, 2]`, `[2, 3]`, `[3, 4]`, `[1, 2, 3]` and `[2, 3, 4]`.
- The maximum number of subarrays we can achieve after removing one element from `conflictingPairs` is 9.

**Example 2:**

```bash
Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]

Output: 12
```

Explanation:

- Remove `[1, 2]` from `conflictingPairs`. Now, `conflictingPairs = [[2, 5], [3, 5]]`.
- There are 12 subarrays in `nums` where `[2, 5]` and `[3, 5]` do not appear together.
- The maximum number of subarrays we can achieve after removing one element from `conflictingPairs` is 12.

**Constraints:**

- `2 <= n <= 10^5`
- `1 <= conflictingPairs.length <= 2 * n`
- `conflictingPairs[i].length == 2`
- `1 <= conflictingPairs[i][j] <= n`
- `conflictingPairs[i][0] != conflictingPairs[i][1]`

## Hints/Notes

- 2025/04/14 Q1
- greedy
- [0x3F's solution](https://leetcode.cn/problems/maximize-subarrays-after-removing-one-conflicting-pair/solutions/3603047/mei-ju-zuo-duan-dian-wei-hu-zui-xiao-ci-4nvu6/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> groups(n + 1);
        for (auto& p : conflictingPairs) {
            int a = p[0], b = p[1];
            if (a > b) {
                swap(a, b);
            }
            groups[a].push_back(b);
        }
        long long ans = 0;
        vector<long long> extra(n + 2);
        vector<int> b = {n + 1, n + 1}; // the most and second smallest b
        for (int a = n; a > 0; a--) {
            auto& list_b = groups[a];
            b.insert(b.end(), list_b.begin(), list_b.end());
            ranges::sort(b);
            b.resize(2);
            ans += b[0] - a;
            extra[b[0]] += b[1] - b[0];
        }
        return ans + ranges::max(extra);
    }
};
```
