---
title: 384. Shuffle an Array
categories: Leetcode
date: 2025-03-17 00:46:53
tags:
    - Array
    - Math
    - Design
    - Randomized
---

[384. Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given an integer array `nums`, design an algorithm to randomly shuffle the array. All permutations of the array should be **equally likely**  as a result of the shuffling.

Implement the `Solution` class:

- `Solution(int[] nums)` Initializes the object with the integer array `nums`.
- `int[] reset()` Resets the array to its original configuration and returns it.
- `int[] shuffle()` Returns a random shuffling of the array.

**Example 1:**

```bash
Input

["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output

[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation

Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

```

**Constraints:**

- `1 <= nums.length <= 50`
- `-10^6 <= nums[i] <= 10^6`
- All the elements of `nums` are **unique** .
- At most `10^4` calls **in total**  will be made to `reset` and `shuffle`.

## Hints/Notes

- 2025/02/12 Q2
- design
- [Good solution](https://leetcode.cn/problems/shuffle-an-array/solutions/1114958/gong-shui-san-xie-xi-pai-suan-fa-yun-yon-0qmy/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) : nums(nums) {

    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int> copy(nums);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + rand() % (n - i);
            swap(copy[i], copy[j]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```
