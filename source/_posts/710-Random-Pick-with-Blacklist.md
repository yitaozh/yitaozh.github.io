---
title: 710. Random Pick with Blacklist
categories: Leetcode
date: 2023-02-01 12:27:16
tags:
---

# [710\. Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist/)

## Description

Difficulty: **Hard**

Related Topics: [Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/), [Randomized](https://leetcode.com/tag/randomized/)

You are given an integer `n` and an array of **unique** integers `blacklist`. Design an algorithm to pick a random integer in the range `[0, n - 1]` that is **not** in `blacklist`. Any integer that is in the mentioned range and not in `blacklist` should be **equally likely** to be returned.

Optimize your algorithm such that it minimizes the number of calls to the **built-in** random function of your language.

Implement the `Solution` class:

* `Solution(int n, int[] blacklist)` Initializes the object with the integer `n` and the blacklisted integers `blacklist`.
* `int pick()` Returns a random integer in the range `[0, n - 1]` and not in `blacklist`.

**Example 1:**

```text
Input
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
Output
[null, 0, 4, 1, 6, 1, 0, 4]

Explanation
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4
```

**Constraints:**

* 1 <= n <= 10<sup>9</sup>
* 0 <= blacklist.length <= min(10<sup>5</sup>, n - 1)
* `0 <= blacklist[i] < n`
* All the values of `blacklist` are **unique**.
* At most 2 * 10<sup>4</sup> calls will be made to `pick`.

## Solution

Language: **C++**

```C++
class Solution {
public:
    int size = 0;
    unordered_map<int, int> nums;

    Solution(int n, vector<int>& blacklist) {
        size = n - blacklist.size();
        for (int blackNum : blacklist) {
            nums[blackNum] = blackNum;
        }

        int last = n - 1;
        for (int blackNum : blacklist) {
            if (blackNum >= size) {
                continue;
            }
            while (nums.count(last)) {
                last--;
            }
            nums[blackNum] = last--;
        }
    }
    
    int pick() {
        int num = rand() % size;
        if (nums.count(num)) {
            return nums[num];
        } else {
            return num;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
```
