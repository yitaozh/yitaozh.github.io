---
title: 3219. Minimum Cost for Cutting Cake II
categories: Leetcode
date: 2024-07-23 13:56:49
tags:
    - Array
    - Greedy
    - Sorting
---

[3219. Minimum Cost for Cutting Cake II](https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/description/)

## Description

There is an `m x n` cake that needs to be cut into `1 x 1` pieces.

You are given integers `m`, `n`, and two arrays:

- `horizontalCut` of size `m - 1`, where `horizontalCut[i]` represents the cost to cut along the horizontal line `i`.
- `verticalCut` of size `n - 1`, where `verticalCut[j]` represents the cost to cut along the vertical line `j`.

In one operation, you can choose any piece of cake that is not yet a `1 x 1` square and perform one of the following cuts:

- Cut along a horizontal line `i` at a cost of `horizontalCut[i]`.
- Cut along a vertical line `j` at a cost of `verticalCut[j]`.

After the cut, the piece of cake is divided into two distinct pieces.

The cost of a cut depends only on the initial cost of the line and does not change.

Return the **minimum**  total cost to cut the entire cake into `1 x 1` pieces.

**Example 1:**

```bash
Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]

Output: 13
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/04/ezgifcom-animated-gif-maker-1.gif" style="width: 280px; height: 320px;">

- Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
- Perform a cut on the horizontal line 0 on `3 x 1` subgrid with cost 1.
- Perform a cut on the horizontal line 0 on `3 x 1` subgrid with cost 1.
- Perform a cut on the horizontal line 1 on `2 x 1` subgrid with cost 3.
- Perform a cut on the horizontal line 1 on `2 x 1` subgrid with cost 3.

The total cost is `5 + 1 + 1 + 3 + 3 = 13`.

**Example 2:**

```bash
Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]

Output: 15
```

Explanation:

- Perform a cut on the horizontal line 0 with cost 7.
- Perform a cut on the vertical line 0 on `1 x 2` subgrid with cost 4.
- Perform a cut on the vertical line 0 on `1 x 2` subgrid with cost 4.

The total cost is `7 + 4 + 4 = 15`.

**Constraints:**

- `1 <= m, n <= 10^5`
- `horizontalCut.length == m - 1`
- `verticalCut.length == n - 1`
- `1 <= horizontalCut[i], verticalCut[i] <= 10^3`

## Hints/Notes

- 2024/07/21
- Greedy
- [0x3F's solution](https://leetcode.cn/problems/minimum-cost-for-cutting-cake-ii/solutions/2843063/tan-xin-ji-qi-zheng-ming-jiao-huan-lun-z-ivtn/)(checked)
- Weekly Contest 406

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut,
                          vector<int>& verticalCut) {
        long long res = 0;
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        int hCnt = 1, vCnt = 1, hIdx = horizontalCut.size() - 1,
            vIdx = verticalCut.size() - 1;
        while (hIdx >= 0 || vIdx >= 0) {
            if (hIdx < 0) {
                res += verticalCut[vIdx--] * hCnt;
                vCnt++;
            } else if (vIdx < 0) {
                res += horizontalCut[hIdx--] * vCnt;
                hCnt++;
            } else if (verticalCut[vIdx] > horizontalCut[hIdx]) {
                res += verticalCut[vIdx--] * hCnt;
                vCnt++;
            } else {
                res += horizontalCut[hIdx--] * vCnt;
                hCnt++;
            }
        }
        return res;
    }
};
```
