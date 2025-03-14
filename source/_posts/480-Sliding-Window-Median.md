---
title: 480. Sliding Window Median
categories: Leetcode
date: 2025-03-14 12:11:49
tags:
    - Array
    - Hash Table
    - Sliding Window
    - Heap (Priority Queue)
---

[480. Sliding Window Median](https://leetcode.com/problems/sliding-window-median/description/)

## Description

The **median**  is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

- For examples, if `arr = [2,3,4]`, the median is `3`.
- For examples, if `arr = [1,2,3,4]`, the median is `(2 + 3) / 2 = 2.5`.

You are given an integer array `nums` and an integer `k`. There is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within `10^-5` of the actual value will be accepted.

**Example 1:**

```bash
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[**1  3  -1** ] -3  5  3  6  7        1
 1 [**3  -1  -3** ] 5  3  6  7       -1
 1  3 [**-1  -3  5** ] 3  6  7       -1
 1  3  -1 [**-3  5  3** ] 6  7        3
 1  3  -1  -3 [**5  3  6** ] 7        5
 1  3  -1  -3  5 [**3  6  7** ]       6
```

**Example 2:**

```bash
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## Hints/Notes

- 2025/03/11 Q2
- two sets
- [0x3F's solution](https://leetcode.com/problems/sliding-window-median/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // the ideal size for each set:
        int bigSize = k % 2 ? (k + 1) / 2 : k / 2;
        int smallSize = k - bigSize;
        multiset<int> smaller, bigger;
        vector<double> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            smaller.insert(nums[i]);
            bigger.insert(*smaller.rbegin());
            smaller.erase(prev(smaller.end()));

            if (bigger.size() > bigSize) {
                smaller.insert(*bigger.begin());
                bigger.erase(bigger.begin());
            }

            if (i >= k - 1) {
                if (k % 2) {
                    res.push_back(*bigger.begin());
                } else {
                    double val = (double(*bigger.begin()) + *(prev(smaller.end()))) / 2;
                    res.push_back(val);
                }
                // now remove the last item
                int toBeRemoved = nums[i - k + 1];
                if (toBeRemoved >= *bigger.begin()) {
                    auto it = bigger.find(toBeRemoved);
                    bigger.erase(it);
                } else {
                    auto it = smaller.find(toBeRemoved);
                    smaller.erase(it);
                }
            }
        }
        return res;
    }
};
```
