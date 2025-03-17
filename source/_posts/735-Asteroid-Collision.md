---
title: 735. Asteroid Collision
categories: Leetcode
date: 2025-02-22 01:27:26
tags:
    - Array
    - Stack
    - Simulation
---

[735. Asteroid Collision](https://leetcode.com/problems/asteroid-collision/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

We are given an array `asteroids` of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

**Example 1:**

```bash
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

**Example 2:**

```bash
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

**Example 3:**

```bash
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

**Constraints:**

- `2 <= asteroids.length <= 10^4`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

## Hints/Notes

- 2025/02/13 Q1
- stack
- [0x3F's solution](https://leetcode.com/problems/asteroid-collision/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int a : asteroids) {
            if (!stk.empty() && stk.top() > 0 && a < 0) {
                while (!stk.empty() && stk.top() > 0) {
                    int prev = stk.top();
                    if (prev == abs(a)) {
                        // we need to remove the top item
                        break;
                    } else if (prev < abs(a)) {
                        // we need to remove the top item, then continue check
                        stk.pop();
                    } else {
                        // we need to stop here, and not push the cur value
                        break;
                    }
                }
                // the situations we get out
                if (stk.empty() || stk.top() < 0) {
                    stk.push(a);
                } else if (stk.top() > 0 && stk.top() == abs(a)) {
                    stk.pop();
                }
            } else {
                stk.push(a);
            }
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        ranges::reverse(res);
        return res;
    }
};
```
