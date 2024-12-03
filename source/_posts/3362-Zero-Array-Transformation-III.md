---
title: 3362. Zero Array Transformation III
categories: Leetcode
date: 2024-12-03 17:43:00
tags:
    - Array
    - Greedy
    - Sorting
    - Heap (Priority Queue)
    - Prefix Sum
---

[3362. Zero Array Transformation III](https://leetcode.com/problems/zero-array-transformation-iii/description/)

## Description

You are given an integer array `nums` of length `n` and a 2D array `queries` where queries[i] = [l<sub>i</sub>, r<sub>i</sub>].

Each `queries[i]` represents the following action on `nums`:

- Decrement the value at each index in the range [l<sub>i</sub>, r<sub>i</sub>] in `nums` by **at most** 1.
- The amount by which the value is decremented can be chosen **independently**  for each index.

A **Zero Array**  is an array with all its elements equal to 0.

Return the **maximum** number of elements that can be removed from `queries`, such that `nums` can still be converted to a **zero array**  using the remaining queries. If it is not possible to convert `nums` to a **zero array** , return -1.

**Example 1:**

```bash
Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1
```

Explanation:

After removing `queries[2]`, `nums` can still be converted to a zero array.

- Using `queries[0]`, decrement `nums[0]` and `nums[2]` by 1 and `nums[1]` by 0.
- Using `queries[1]`, decrement `nums[0]` and `nums[2]` by 1 and `nums[1]` by 0.

**Example 2:**

```bash
Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2
```

Explanation:

We can remove `queries[2]` and `queries[3]`.

**Example 3:**

```bash
Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1
```

Explanation:

`nums` cannot be converted to a zero array even after using all the queries.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- 0 <= l<sub>i</sub> <= r<sub>i</sub> < nums.length

## Hints/Notes

- 2024/12/01
- priority queue
- [0x3F's solution](https://leetcode.cn/problems/zero-array-transformation-iii/solutions/2998650/tan-xin-zui-da-dui-chai-fen-shu-zu-pytho-35o6/)(chekced)
- Biweekly Contest 144

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        ranges::sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int sum = 0, j = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            while (j < queries.size() && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (sum < nums[i] && !pq.empty() && pq.top() >= i) {
                sum++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if (sum < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};
```
