---
title: 1944. Number of Visible People in a Queue
categories: Leetcode
date: 2023-12-16 13:40:07
tags:
    - Array
    - Stack
    - Monotonic Stack
---

# [1944\. Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

There are `n` people standing in a queue, and they numbered from `0` to `n - 1` in **left to right** order. You are given an array `heights` of **distinct** integers where `heights[i]` represents the height of the i<sup>th</sup> person.

A person can **see** another person to their right in the queue if everybody in between is **shorter** than both of them. More formally, the i<sup>th</sup> person can see the j<sup>th</sup> person if `i < j` and `min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1])`.

Return _an array_ `answer` _of length_ `n` _where_ `answer[i]` _is the **number of people** the_ i<sup>th</sup> _person can **see** to their right in the queue_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/05/29/queue-plane.jpg)

```bash
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
```

**Example 2:**

```bash
Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]
```

**Constraints:**

* `n == heights.length`
* 1 <= n <= 10<sup>5</sup>
* 1 <= heights[i] <= 10<sup>5</sup>
* All the values of `heights` are **unique**.

## Hints/Notes

* monotonic stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int size = heights.size();
        stack<int> s;
        vector<int> res(size, 0);
        for (int i = size - 1; i >= 0; i--) {
            int removed = 0;
            while (!s.empty() && heights[i] >= s.top()) {
                s.pop();
                removed++;
            }
            res[i] = s.empty() ? removed : removed + 1;
            s.push(heights[i]);
        }
        return res;
    }
};
```
