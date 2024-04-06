---
title: 528. Random Pick with Weight
categories: Leetcode
date: 2023-01-25 13:42:48
tags:
    - Array
    - Math
    - Binary Search
    - Prefix Sum
    - Randomized
---

[912\. Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/), [Randomized](https://leetcode.com/tag/randomized/)

You are given a **0-indexed** array of positive integers `w` where `w[i]` describes the **weight** of the i<sup>th</sup> index.

You need to implement the function `pickIndex()`, which **randomly** picks an index in the range `[0, w.length - 1]` (**inclusive**) and returns it. The **probability** of picking an index `i` is `w[i] / sum(w)`.

* For example, if `w = [1, 3]`, the probability of picking index `0` is `1 / (1 + 3) = 0.25` (i.e., `25%`), and the probability of picking index `1` is `3 / (1 + 3) = 0.75` (i.e., `75%`).

**Example 1:**

```text
Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0\. The only option is to return 0 since there is only one element in w.
```

**Example 2:**

```text
Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1\. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0\. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.
```

**Constraints:**

* 1 <= w.length <= 10<sup>4</sup>
* 1 <= w[i] <= 10<sup>5</sup>
* `pickIndex` will be called at most 10<sup>4</sup> times.

## Hints/Notes

* preSum
* binary search to find the left boundry
* if the number doesn't exist, we can iterpret the return as
  * where it ought to be in the array
  * the index of value > target

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> preSum;

    Solution(vector<int>& w) {
        preSum.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            preSum.push_back(preSum[i - 1] + w[i]);
        }
    }

    int pickIndex() {
        int r = rand() % preSum.back() + 1;
        int left = 0, right = preSum.size() - 1;
        // 1, 2, 3, 5, 8
        // r = 4
        //
        // 1. left = 2, right = 2
        // preSum[mid] < 4, left = mid + 1 = 3, right = 2
        // 2. left = 3, right = 3
        // preSum[mid] > 4, left = 3, right = 2
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] == r) {
                return mid - 1;
            } else if (preSum[mid] < r) {
                left = mid + 1;
            } else if (preSum[mid] > r) {
                right = mid - 1;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```
