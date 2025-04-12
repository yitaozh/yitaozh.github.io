---
title: 1386. Cinema Seat Allocation
categories: Leetcode
date: 2025-04-11 23:28:12
tags:
    - Array
    - Hash Table
    - Greedy
    - Bit Manipulation
---

[1386. Cinema Seat Allocation](https://leetcode.com/problems/cinema-seat-allocation/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_1.png" style="width: 400px; height: 149px;">

A cinema has `n`rows of seats, numbered from 1 to `n`and there are tenseats in each row, labelled from 1to 10as shown in the figure above.

Given the array `reservedSeats` containing the numbers of seats already reserved, for example, `reservedSeats[i] = [3,8]`means the seat located in row **3**  and labelled with <b>8</b>is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats **in one single row** . Seats across an aisle (such as [3,3]and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle,which means to have two people on each side.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/14/cinema_seats_3.png" style="width: 400px; height: 96px;">

```bash
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.
```

**Example 2:**

```bash
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2
```

**Example 3:**

```bash
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
```

**Constraints:**

- `1 <= n <= 10^9`
- `1 <=reservedSeats.length <= min(10*n, 10^4)`
- `reservedSeats[i].length == 2`
- `1<=reservedSeats[i][0] <= n`
- `1 <=reservedSeats[i][1] <= 10`
- All `reservedSeats[i]` are distinct.

## Hints/Notes

- 2025/04/09 Q2
- bit manipulation
- [0x3F's solution](https://leetcode.cn/problems/cinema-seat-allocation/solutions/172443/an-pai-dian-ying-yuan-zuo-wei-by-leetcode-solution/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        int m = reservedSeats.size(), res = 2 * n;
        for (int i = 0; i < m; i++) {
            int row = reservedSeats[i][0], seat = reservedSeats[i][1];
            reserved[row] |= (1 << (seat - 1));
        }
        for (auto& [_, r] : reserved) {
            bool first  = r & 0b0111100000;
            bool second = r & 0b0001111000;
            bool third  = r & 0b0000011110;
            if (first && second && third) {
                res -= 2;
            } else if (first || second || third) {
                res -= 1;
            }
        }
        return res;
    }
};
```
