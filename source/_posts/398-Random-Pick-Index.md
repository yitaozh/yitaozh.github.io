---
title: 398. Random Pick Index
categories: Leetcode
date: 2025-01-23 00:18:19
tags:
    - Hash Table
    - Math
    - Reservoir Sampling
    - Randomized
---

[398. Random Pick Index](https://leetcode.com/problems/random-pick-index/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an integer array `nums` with possible **duplicates** , randomly output the index of a given `target` number. You can assume that the given target number must exist in the array.

Implement the `Solution` class:

- `Solution(int[] nums)` Initializes the object with the array `nums`.
- `int pick(int target)` Picks a random index `i` from `nums` where `nums[i] == target`. If there are multiple valid i's, then each index should have an equal probability of returning.

**Example 1:**

```bash
Input

["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output

[null, 4, 0, 2]

Explanation

Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `target` is an integer from `nums`.
- At most `10^4` calls will be made to `pick`.

## Hints/Notes

- 2025/01/22
- map
- [Leetcode solution](https://leetcode.com/problems/random-pick-index/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    unordered_map<int, vector<int>> m;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int size = m[target].size();
        return m[target][rand() % size];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```
