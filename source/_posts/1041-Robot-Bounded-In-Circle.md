---
title: 1041. Robot Bounded In Circle
categories: Leetcode
date: 2025-03-29 12:53:03
tags:
    - Math
    - String
    - Simulation
---

[1041. Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

On an infinite plane, a robot initially stands at `(0, 0)` and faces north. Note that:

- The **north direction**  is the positive direction of the y-axis.
- The **south direction**  is the negative direction of the y-axis.
- The **east direction**  is the positive direction of the x-axis.
- The **west direction**  is the negative direction of the x-axis.

The robot can receive one of three instructions:

- `"G"`: go straight 1 unit.
- `"L"`: turn 90 degrees to the left (i.e., anti-clockwise direction).
- `"R"`: turn 90 degrees to the right (i.e., clockwise direction).

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

**Example 1:**

```bash
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.
```

**Example 2:**

```bash
Input: instructions = "GG"
Output: false
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
Based on that, we return false.
```

**Example 3:**

```bash
Input: instructions = "GL"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
"G": move one step. Position: (-1, 1). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
"G": move one step. Position: (-1, 0). Direction: South.
"L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
"G": move one step. Position: (0, 0). Direction: East.
"L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
Based on that, we return true.
```

**Constraints:**

- `1 <= instructions.length <= 100`
- `instructions[i]` is `'G'`, `'L'` or, `'R'`.

## Hints/Notes

- 2025/03/22 Q2
- simulation
- [Leetcode solution](https://leetcode.com/problems/robot-bounded-in-circle/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, curDir = 0;
        for (char& c : instructions) {
            switch(c) {
                case 'G': x += dirs[curDir][0], y += dirs[curDir][1]; break;
                case 'L': curDir = (curDir - 1 + 4) % 4; break;
                case 'R': curDir = (curDir + 1) % 4; break;
            }
        }
        return (x == 0 && y == 0) || (curDir != 0);
    }
};
```
