---
title: 134. Gas Station
categories: Leetcode
date: 2024-12-29 17:04:22
tags:
    - Array
    - Greedy
---

[134. Gas Station](https://leetcode.com/problems/gas-station/description/?envType=problem-list-v2&envId=plakya4j)

## Description

There are `n` gas stations along a circular route, where the amount of gas at the `i^th` station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `i^th` station to its next `(i + 1)^th` station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is **guaranteed**  to be **unique** .

**Example 1:**

```bash
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

**Example 2:**

```bash
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

**Constraints:**

- `n == gas.length == cost.length`
- `1 <= n <= 10^5`
- `0 <= gas[i], cost[i] <= 10^4`

## Hints/Notes

- 2024/12/29
- greedy
- [0x3F's solution](https://leetcode.cn/problems/gas-station/solutions/2933132/yong-zhe-xian-tu-zhi-guan-li-jie-pythonj-qccr/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff;
        for (int i = 0; i < n; i++) {
            diff.push_back(gas[i] - cost[i]);
        }
        int sum = reduce(diff.begin(), diff.end(), 0);
        if (sum < 0) {
            return -1;
        }
        int left = 0; sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            while (sum < 0) {
                sum -= diff[left];
                left++;
            }
        }
        return left;
    }
};
```