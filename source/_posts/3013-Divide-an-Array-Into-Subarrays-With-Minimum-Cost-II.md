---
title: 3013. Divide an Array Into Subarrays With Minimum Cost II
categories: Leetcode
date: 2024-10-21 15:27:45
tags:
    - Array
    - Hash Table
    - Sliding Window
    - Heap (Priority Queue)
---

[3013. Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/)

## Description

You are given a **0-indexed**  array of integers `nums` of length `n`, and two **positive**  integers `k` and `dist`.

The **cost**  of an array is the value of its **first**  element. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into `k` **disjoint contiguous** subarrays, such that the difference between the starting index of the **second**  subarray and the starting index of the `kth` subarray should be **less than or equal to**  `dist`. In other words, if you divide `nums` into the subarrays nums[0..(i<sub>1</sub> - 1)], nums[i<sub>1</sub>..(i<sub>2</sub> - 1)], ..., nums[i<sub>k-1</sub>..(n - 1)], then i<sub>k-1</sub> - i<sub>1</sub> <= dist.

Return the **minimum**  possible sum of the cost of these subarrays.

**Example 1:**

```bash
Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
```

Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because i<sub>k-1</sub> - i<sub>1</sub> is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.

**Example 2:**

```bash
Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
```

Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because i<sub>k-1</sub> - i<sub>1</sub> is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
The division [10], [1], [2,2,2], and [1] is not valid, because the difference between i<sub>k-1</sub> and i<sub>1</sub> is 5 - 1 = 4, which is greater than dist.
It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.

**Example 3:**

```bash
Input: nums = [10,8,18,9], k = 3, dist = 1
Output: 36
```

Explanation: The best possible way to divide nums into 4 subarrays is: [10], [8], and [18,9]. This choice is valid because i<sub>k-1</sub> - i<sub>1</sub> is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
The division [10], [8,18], and [9] is not valid, because the difference between i<sub>k-1</sub> and i<sub>1</sub> is 3 - 1 = 2, which is greater than dist.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.

**Constraints:**

- `3 <= n <= 10^5`
- `1 <= nums[i] <= 10^9`
- `3 <= k <= n`
- `k - 2 <= dist <= n - 2`

## Hints/Notes

- use 2 sets

## Solution

Language: **C++**

```C++
class Solution {
public:
    // so, we need to pick nums[0], with another k - 1 numbers
    // the best choice is pick the minimum k - 1 numbers
    // but we have the contraint that ik-1 - i1 <= dist
    // i1 = len(subArray1), so ik-1 <= dist + len(subArray1)
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long cur = nums[0], res = LLONG_MAX;
        int n = nums.size();
        // starting from i, we need to pick k - 1 numbers,
        // so the last number we can iterate  is n - k + 1
        multiset<int> mx, mi;
        int right = 1;
        for (int i = 1; i <= n - k + 1; i++) {
            // feeding numbers until i + dist
            // now we need to get the minimum k - 1 numbers
            // use 2
            while (right <= min(i + dist, n - 1)) {
                mi.insert(nums[right]);
                cur += nums[right];
                if (mi.size() > k - 1) {
                    auto it = prev(mi.end());
                    int tmp = *it;
                    cur -= tmp;
                    mi.erase(it);
                    mx.insert(tmp);
                    1
                }
                right++;
            }
            res = min(res, cur);
            // now we need to erase nums[i] from the sliding window
            if (mi.contains(nums[i])) {
                auto it = mi.lower_bound(nums[i]);
                cur -= *it;
                mi.erase(it);
                if (!mx.empty()) {
                    it = mx.begin();
                    mi.insert(*it);
                    cur += *it;
                    mx.erase(it);
                }
            } else {
                auto it = mx.lower_bound(nums[i]);
                mx.erase(it);
            }
        }
        return res;
    }
};
```
