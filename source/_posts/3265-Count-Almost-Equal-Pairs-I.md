---
title: 3265. Count Almost Equal Pairs I
categories: Leetcode
date: 2024-10-06 15:44:51
tags:
    - Array
    - Hash Table
    - Sorting
    - Counting
    - Enumeration
---

[3265. Count Almost Equal Pairs I](https://leetcode.com/problems/count-almost-equal-pairs-i/description/)

## Description

You are given an array `nums` consisting of positive integers.

We call two integers `x` and `y` in this problem **almost equal**  if both integers can become equal after performing the following operation **at most once** :

- Choose **either**  `x` or `y` and swap any two digits within the chosen number.

Return the number of indices `i` and `j` in `nums` where `i < j` such that `nums[i]` and `nums[j]` are **almost equal** .

**Note**  that it is allowed for an integer to have leading zeros after performing an operation.

**Example 1:**

```bash
Input: nums = [3,12,30,17,21]

Output: 2
```

Explanation:

The almost equal pairs of elements are:

- 3 and 30. By swapping 3 and 0 in 30, you get 3.
- 12 and 21. By swapping 1 and 2 in 12, you get 21.

**Example 2:**

```bash
Input: nums = [1,1,1,1,1]

Output: 10
```

Explanation:

Every two elements in the array are almost equal.

**Example 3:**

```bash
Input: nums = [123,231]

Output: 0
```

Explanation:

We cannot swap any two digits of 123 or 231 to reach the other.

**Constraints:**

- `2 <= nums.length <= 100`
- `1 <= nums[i] <= 10^6`

## Hints/Notes

- N/A

## Solution

Language: **C++**

My solutino:

```C++
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (almostEqual(nums[i], nums[j])) {
                    res++;
                }
            }
        }
        return res;
    }

    bool almostEqual(int x, int y) {
        int diff1 = -1, diff2 = -1;
        while (x != 0 || y != 0) {
            int a = x % 10;
            int b = y % 10;
            if (a != b) {
                if (diff1 == -1) {
                    diff1 = a;
                    diff2 = b;
                } else {
                    if (!(diff1 == b && diff2 == a)) {
                        return false;
                    }
                    diff1 = -2;
                }
            }
            x /= 10;
            y /= 10;
        }
        return diff1 < 0;
    }
};
```

Apply the solution for t4:

```C++
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int num : nums) {
            string numStr = to_string(num);
            int n = numStr.size();
            unordered_set<int> s;
            s.insert(num);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    char tmp = numStr[i];
                    numStr[i] = numStr[j];
                    numStr[j] = tmp;
                    s.insert(stoi(numStr));
                    numStr[j] = numStr[i];
                    numStr[i] = tmp;
                }
            }
            for (int val : s) {
                res += m[val];
            }
            m[num]++;
        }
        return res;
    }
};
```
