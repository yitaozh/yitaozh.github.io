---
title: 2061. Number of Spaces Cleaning Robot Cleaned
categories: Leetcode
date: 2024-05-24 16:22:45
tags:
---

[2061. Number of Spaces Cleaning Robot Cleaned](https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/description/?envType=weekly-question&envId=2024-05-15)

## Description

A room is represented by a **0-indexed**  2D binary matrix `room` where a `0` represents an **empty**  space and a `1` represents a space with an **object** . The top left corner of the room will be empty in all test cases.

A cleaning robot starts at the top left corner of the room and is facing right. The robot will continue heading straight until it reaches the edge of the room or it hits an object, after which it will turn 90 degrees **clockwise**  and repeat this process. The starting space and all spaces that the robot visits are **cleaned**  by it.

Return the number of **clean**  spaces in the room if the robot runs indefinetely.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2021/11/01/image-20211101204703-1.png" style="width: 250px; height: 242px;">

```bash
Input: room = [[0,0,0],[1,1,0],[0,0,0]]

Output: 7

Explanation:

- ​​​​​​​The robot cleans the spaces at (0, 0), (0, 1), and (0, 2).
- The robot is at the edge of the room, so it turns 90 degrees clockwise and now faces down.
- The robot cleans the spaces at (1, 2), and (2, 2).
- The robot is at the edge of the room, so it turns 90 degrees clockwise and now faces left.
- The robot cleans the spaces at (2, 1), and (2, 0).
- The robot has cleaned all 7 empty spaces, so return 7.
```

**Example 2:**

<img src="https://assets.leetcode.com/uploads/2021/11/01/image-20211101204736-2.png" style="width: 250px; height: 245px;">

```bash
Input: room = [[0,1,0],[1,0,0],[0,0,0]]

Output: 1

Explanation:

- The robot cleans the space at (0, 0).
- The robot hits an object, so it turns 90 degrees clockwise and now faces down.
- The robot hits an object, so it turns 90 degrees clockwise and now faces left.
- The robot is at the edge of the room, so it turns 90 degrees clockwise and now faces up.
- The robot is at the edge of the room, so it turns 90 degrees clockwise and now faces right.
- The robot is back at its starting position.
- The robot has cleaned 1 space, so return 1.
```

**Example 3:**

```bash
Input: room = [[0,0,0],[0,0,0],[0,0,0]]

Output: 8​​​​​​​
```

**Constraints:**

- `m == room.length`
- `n == room[r].length`
- `1 <= m, n <= 300`
- `room[r][c]` is either `0` or `1`.
- `room[0][0] == 0`

## Hints/Notes

- we need to end if we have visited the same block in the same direction

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> visited;

    int numberOfCleanRooms(vector<vector<int>>& room) {
        int m = room.size(), n = room[0].size();
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        int i = 0, j = 0, direction = 1, cleaned = 0;
        while (!(visited[i][j] & (1 << direction))) {
            if (!visited[i][j]) cleaned++;
            visited[i][j] |= (1 << direction);
            if (direction == 1) {
                if (j == n - 1 || room[i][j + 1] == 1) {
                    direction = 2;
                } else {
                    j++;
                }
            } else if (direction == 2) {
                if (i == m - 1 || room[i + 1][j] == 1) {
                    direction = 3;
                } else {
                    i++;
                }
            } else if (direction == 3) {
                if (j == 0  || room[i][j - 1] == 1) {
                    direction = 4;
                } else {
                    j--;
                }
            } else {
                if (i == 0 || room[i - 1][j] == 1) {
                    direction = 1;
                } else {
                    i--;
                }
            }
        }
        return cleaned;
    }
};
```
