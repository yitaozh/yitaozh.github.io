---
title: 3187. Peaks in Array
categories: Leetcode
date: 2024-06-19 00:40:57
tags:
    - Array
    - Binary Indexed Tree
    - Segment Tree
---

[3187. Peaks in Array](https://leetcode.com/problems/peaks-in-array/description/)

## Description

A **peak**  in an array `arr` is an element that is **greater**  than its previous and next element in `arr`.

You are given an integer array `nums` and a 2D integer array `queries`.

You have to process queries of two types:

- queries[i] = [1, l<sub>i</sub>, r<sub>i</sub>], determine the count of **peak**  elements in the subarray nums[l<sub>i</sub>..r<sub>i</sub>].
- queries[i] = [2, index<sub>i</sub>, val<sub>i</sub>], change nums[index<sub>i</sub>] to val<sub>i</sub>.

Return an array `answer` containing the results of the queries of the first type in order.

**Notes:**

- The **first** and the **last** element of an array or a subarray **cannot** be a peak.

**Example 1:**

```bash
Input: nums = [3,1,4,2,5], queries = [[2,3,4],[1,0,4]]

Output: [0]

Explanation:

First query: We change `nums[3]` to 4 and `nums` becomes `[3,1,4,4,5]`.

Second query: The number of peaks in the `[3,1,4,4,5]` is 0.
```

**Example 2:**

```bash
Input: nums = [4,1,4,2,1,5], queries = [[2,2,4],[1,0,2],[1,0,4]]

Output: [0,1]

Explanation:

First query: `nums[2]` should become 4, but it is already set to 4.

Second query: The number of peaks in the `[4,1,4]` is 0.

Third query: The second 4 is a peak in the `[4,1,4,2,1]`.
```

**Constraints:**

- `3 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i][0] == 1` or `queries[i][0] == 2`
- For all `i` that:
  - `queries[i][0] == 1`: `0 <= queries[i][1] <= queries[i][2] <= nums.length - 1`
  - `queries[i][0] == 2`: `0 <= queries[i][1] <= nums.length - 1`, `1 <= queries[i][2] <= 10^5`

## Hints/Notes

- 2024/04/17
- segment tree
- Binary index tree(Fenwick tree)
- [0x3F's solution](https://leetcode.cn/problems/peaks-in-array/solution/shu-zhuang-shu-zu-pythonjavacgo-by-endle-tj0w/)(checked)
- Weekly Contest 402

## Solution

Language: **C++**

Fenwick tree solution:

```C++
class Solution {
public:
    struct Fenwick {
        vector<int> f;

        Fenwick(int n) : f(n) {

        }

        void update(int i, int val) {
            for (; i < f.size(); i += i & -i) {
                f[i] += val;
            }
        }

        int pre(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += f[i];
            }
            return sum;
        }

        int rangeSum(int l, int r) {
            if (l >= r) {
                return 0;
            }
            // because the first and last element of the subarray cannot be a peak as well
            // so the preSum can only reduce l + 1(so l isn't counted) from r(which is the element prior to r)
            return pre(r) - pre(l + 1);
        }
    };

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Fenwick f(n + 1);
        auto update = [&](int i, int val) {
            if (i <= 0 || i >= n - 1) {
                return;
            }
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                f.update(i + 1, val);
            }
        };
        for (int i = 0; i < n; i++) {
            update(i, 1);
        }
        vector<int> res;
        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                int l = q[1], r = q[2];
                res.push_back(f.rangeSum(l, r));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; i++) {
                    update(i, -1);
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; i++) {
                    update(i, 1);
                }
            }
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    vector<int> t;

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        t.resize(2 << (32 - __builtin_clz(n)), 0);
        build(nums, 1, 0, n - 1);
        vector<int> res;
        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                int l = q[1];
                int r = q[2];
                res.push_back(query(nums, 1, l, r, 0, n - 1));
            } else {
                int idx = q[1];
                int val = q[2];
                nums[idx] = val;
                update(nums, 1, 0, n - 1, idx, val);
            }
        }
        return res;
    }

    void update(vector<int>& nums, int o, int l, int r, int i, int val) {
        if (l == r) {
            return;
        }
        int m = (r - l) / 2 + l;
        if (i <= m) {
            update(nums, o * 2, l, m, i, val);
        } else {
            update(nums, o * 2 + 1, m + 1, r, i, val);
        }
        maintain(nums, o, l, r);
    }

    int query(vector<int>& nums, int o, int l, int r, int L, int R) {
        int m = (R - L) / 2 + L;
        if (l == r || l == r - 1) {
            return 0;
        }
        if (l == L && r == R) {
            return t[o];
        }
        if (r <= m) {
            return query(nums, o * 2, l, r, L, m);
        }
        if (l >= m + 1) {
            return query(nums, o * 2 + 1, l, r, m + 1, R);
        }
        return query(nums, o * 2, l, m, L, m) +
               query(nums, o * 2 + 1, m + 1, r, m + 1, R) +
               check(nums, m, l, r) + check(nums, m + 1, l, r);
    }

    void build(vector<int>& nums, int o, int l, int r) {
        if (l == r || l == r - 1) {
            t[o] = 0;
            return;
        }
        int m = (r - l) / 2 + l;
        build(nums, o * 2, l, m);
        build(nums, o * 2 + 1, m + 1, r);
        maintain(nums, o, l, r);
    }

    void maintain(vector<int>& nums, int o, int l, int r) {
        int m = (r - l) / 2 + l;
        t[o] = t[o * 2] + t[o * 2 + 1];
        if (check(nums, m, l, r) || check(nums, m + 1, l, r)) {
            t[o]++;
        }
        return;
    }

    int check(vector<int>& nums, int m, int l, int r) {
        if (m == l || m == r) {
            return false;
        }
        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
            return 1;
        }
        return 0;
    }
};
```
