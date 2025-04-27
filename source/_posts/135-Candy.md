---
title: 135. Candy
categories: Leetcode
date: 2025-04-27 13:49:41
tags:
    - Array
    - Greedy
---

[135. Candy](https://leetcode.com/problems/candy/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.

**Example 1:**

```bash
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

**Example 2:**

```bash
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

**Constraints:**

- `n == ratings.length`
- `1 <= n <= 2 * 10^4`
- `0 <= ratings[i] <= 2 * 10^4`

## Hints/Notes

- 2025/04/22 Q2
- greedy
- [Leetcode solution](https://leetcode.com/problems/candy/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left2right(ratings.size(), 1);
        vector<int> right2left(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < ratings.size(); i++) {
            res += max(left2right[i], right2left[i]);
        }
        return res;
    }
};
```
