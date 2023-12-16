---
title: 1475. Final Prices With a Special Discount in a Shop
categories: Leetcode
date: 2023-12-16 13:49:48
tags:
    - Array
    - Stack
    - Monotonic Stack
---

# [1475\. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)

## Description

Difficulty: **Easy**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Stack](https://leetcode.com/tag/https://leetcode.com/tag/stack//), [Monotonic Stack](https://leetcode.com/tag/https://leetcode.com/tag/monotonic-stack//)

You are given an integer array `prices` where `prices[i]` is the price of the i<sup>th</sup> item in a shop.

There is a special discount for items in the shop. If you buy the i<sup>th</sup> item, then you will receive a discount equivalent to `prices[j]` where `j` is the minimum index such that `j > i` and `prices[j] <= prices[i]`. Otherwise, you will not receive any discount at all.

Return an integer array `answer` where `answer[i]` is the final price you will pay for the i<sup>th</sup> item of the shop, considering the special discount.

**Example 1:**

```bash
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
```

**Example 2:**

```bash
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
```

**Example 3:**

```bash
Input: prices = [10,1,1,6]
Output: [9,0,1,6]
```

**Constraints:**

* `1 <= prices.length <= 500`
* `1 <= prices[i] <= 1000`

## Hints/Notes

* monotonic stack

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        vector<int> res(size, 0);
        stack<int> s;
        for (int i = size - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            res[i] = s.empty() ? prices[i] : prices[i] - s.top();
            s.push(prices[i]);
        }
        return res;
    }
};
```
