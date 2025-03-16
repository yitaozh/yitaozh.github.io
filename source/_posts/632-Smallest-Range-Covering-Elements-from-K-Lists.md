---
title: 632. Smallest Range Covering Elements from K Lists
categories: Leetcode
date: 2025-03-15 20:41:10
tags:
    - Array
    - Hash Table
    - Greedy
    - Sliding Window
    - Sorting
    - Heap (Priority Queue)
---

[632. Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You have `k` lists of sorted integers in **non-decreasingorder** . Find the <b>smallest</b> range that includes at least one number from each of the `k` lists.

We define the range `[a, b]` is smaller than range `[c, d]` if `b - a < d - c` **or**  `a < c` if `b - a == d - c`.

**Example 1:**

```bash
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
```

**Example 2:**

```bash
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
```

**Constraints:**

- `nums.length == k`
- `1 <= k <= 3500`
- `1 <= nums[i].length <= 50`
- `-10^5 <= nums[i][j] <= 10^5`
- `nums[i]`is sorted in **non-decreasing**  order.

## Hints/Notes

- 2025/02/05 Q2
- priority queue
- [0x3F's solution](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/solutions/2982588/liang-chong-fang-fa-dui-pai-xu-hua-dong-luih5/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // ideas:
        // 1. every list is sorted
        // 2. we can put all lists' first value into a data structure,
        //    where we can get both biggest and smallest value
        // 3. for the one with smallest value, move it to the next value
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size(), maxVal = INT_MIN, minRange = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int minVal = v[0], ithList = v[1], idx = v[2];
            if (maxVal - minVal < minRange) {
                res = {minVal, maxVal};
            }
            minRange = min(minRange, maxVal - minVal);
            idx++;
            if (nums[ithList].size() == idx) {
                break;
            } else {
                pq.push({nums[ithList][idx], ithList, idx});
                maxVal = max(maxVal, nums[ithList][idx]);
            }
        }
        return res;
    }
};
```
