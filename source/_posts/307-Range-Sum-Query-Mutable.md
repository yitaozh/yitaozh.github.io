---
title: 307. Range Sum Query - Mutable
categories: Leetcode
date: 2024-11-25 08:37:45
tags:
    - Array
    - Design
    - Binary Indexed Tree
    - Segment Tree
---

[307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/)

## Description

Given an integer array `nums`, handle multiple queries of the following types:

- **Update**  the value of an element in `nums`.
- Calculate the **sum**  of the elements of `nums` between indices `left` and `right` **inclusive**  where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `void update(int index, int val)` **Updates**  the value of `nums[index]` to be `val`.
- `int sumRange(int left, int right)` Returns the **sum**  of the elements of `nums` between indices `left` and `right` **inclusive**  (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

**Example 1:**

```bash
Input

["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output

[null, 9, null, 8]

Explanation

NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `0 <= index < nums.length`
- `-100 <= val <= 100`
- `0 <= left <= right < nums.length`
- At most `3 * 10^4` calls will be made to `update` and `sumRange`.

## Hints/Notes

- 2024/11/12
- Binary index tree(Fenwick tree)
- [0x3F's solution](https://leetcode.cn/problems/range-sum-query-mutable/solutions/2524481/dai-ni-fa-ming-shu-zhuang-shu-zu-fu-shu-lyfll/)(checked)

## Solution

Language: **C++**

```C++
class NumArray {
private:
    vector<int> nums;
    vector<int> tree;

    int preSum(int t) {
        int sum = 0;
        for (; t > 0; t -= (t & -t)) {
            sum += tree[t];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) :nums(nums.size()), tree(nums.size() + 1) {
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += (i & -i)) {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right) {
        return preSum(right + 1) - preSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```
