---
title: 2560. House Robber IV
categories: Leetcode
date: 2025-03-28 10:58:03
tags:
    - Array
    - Binary Search
---

[2560. House Robber IV](https://leetcode.com/problems/house-robber-iv/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Description

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he **refuses to steal from adjacent homes** .

The **capability**  of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array `nums` representing how much money is stashed in each house. More formally, the `i^th` house from the left has `nums[i]` dollars.

You are also given an integer `k`, representing the **minimum**  number of houses the robber will steal from. It is always possible to steal at least `k` houses.

Return the **minimum**  capability of the robber out of all the possible ways to steal at least `k` houses.

**Example 1:**

```bash
Input: nums = [2,3,5,9], k = 2
Output: 5
Explanation:
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.
```

**Example 2:**

```bash
Input: nums = [2,7,9,3,1], k = 2
Output: 2
Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= (nums.length + 1)/2`

## Hints/Notes

- 2025/03/18 Q3
- binary search
- [Leetcode solution](https://leetcode.com/problems/house-robber-iv/editorial/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 0, right = ranges::max(nums);
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (isValid(mid, k, nums)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    bool isValid(int maxVal, int k, vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= maxVal) {
                count++;
                i++;
            }
        }
        return count >= k;
    }
};
```
