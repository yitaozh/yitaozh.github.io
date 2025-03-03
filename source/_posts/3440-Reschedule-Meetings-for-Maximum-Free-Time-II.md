---
title: 3440. Reschedule Meetings for Maximum Free Time II
categories: Leetcode
date: 2025-02-26 18:15:04
tags:
    - Array
    - Greedy
    - Enumeration
---

[3440. Reschedule Meetings for Maximum Free Time II](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/)

## Description

You are given an integer `eventTime` denoting the duration of an event. You are also given two integer arrays `startTime` and `endTime`, each of length `n`.

These represent the start and end times of `n` **non-overlapping**  meetings that occur during the event between time `t = 0` and time `t = eventTime`, where the `i^th` meeting occurs during the time `[startTime[i], endTime[i]].`

You can reschedule **at most** one meeting by moving its start time while maintaining the **same duration** , such that the meetings remain non-overlapping, to **maximize**  the **longest**  continuous period of free time during the event.

Return the **maximum**  amount of free time possible after rearranging the meetings.

**Note**  that the meetings can **not**  be rescheduled to a time outside the event and they should remain non-overlapping.

**Note:**  In this version, it is **valid**  for the relative ordering of the meetings to change after rescheduling one meeting.

**Example 1:**

```bash
Input: eventTime = 5, startTime = [1,3], endTime = [2,5]

Output: 2
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/22/example0_rescheduled.png" style="width: 375px; height: 123px;">

Reschedule the meeting at `[1, 2]` to `[2, 3]`, leaving no meetings during the time `[0, 2]`.

**Example 2:**

```bash
Input: eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]

Output: 7
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/22/rescheduled_example0.png" style="width: 375px; height: 125px;">

Reschedule the meeting at `[0, 1]` to `[8, 9]`, leaving no meetings during the time `[0, 7]`.

**Example 3:**

```bash
Input: eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]

Output: 6
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2025/01/28/image3.png" style="width: 375px; height: 125px;">**

Reschedule the meeting at `[3, 4]` to `[8, 9]`, leaving no meetings during the time `[1, 7]`.

**Example 4:**

```bash
Input: eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

Output: 0
```

Explanation:

There is no time during the event not occupied by meetings.

**Constraints:**

- `1 <= eventTime <= 10^9`
- `n == startTime.length == endTime.length`
- `2 <= n <= 10^5`
- `0 <= startTime[i] < endTime[i] <= eventTime`
- `endTime[i] <= startTime[i + 1]` where `i` lies in the range `[0, n - 2]`.

## Hints/Notes

- 2025/02/22
- [0x3F's solution](https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/solutions/3061629/wei-hu-qian-san-da-de-kong-wei-mei-ju-fe-xm2f/)
- Biweekly Contest 149

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> intervals;
        int n = startTime.size();
        intervals.push_back(startTime[0]);
        for (int i = 0; i < n - 1; i++) {
            int internval = startTime[i + 1] - endTime[i];
            intervals.push_back(internval);
        }
        intervals.push_back(eventTime - endTime[n - 1]);
        multiset<int> s(intervals.begin(), intervals.end());
        s.erase(s.find(intervals[0]));
        int res = 0, cur = 0;
        for (int i = 0; i < intervals.size(); i++) {
            cur += intervals[i];
            if (i) {
                auto it = s.find(intervals[i]);
                s.erase(it);
                // if we can find a later slot
                if (s.lower_bound(endTime[i - 1] - startTime[i - 1]) != s.end()) {
                    res = max(res, cur + endTime[i - 1] - startTime[i - 1]);
                } else {
                    res = max(res, cur);
                }
                cur -= intervals[i - 1];
            }
        }
        // now reverse the intervals and do the same work again
        cout << res << endl;
        ranges::reverse(intervals);
        ranges::reverse(startTime);
        ranges::reverse(endTime);
        cur = 0;
        s.insert(intervals.begin(), intervals.end());
        s.erase(s.find(intervals[0]));
        for (int i = 0; i < intervals.size(); i++) {
            cur += intervals[i];
            if (i) {
                auto it = s.find(intervals[i]);
                s.erase(it);
                // if we can find a later slot
                if (s.lower_bound(endTime[i - 1] - startTime[i - 1]) != s.end()) {
                    res = max(res, cur + endTime[i - 1] - startTime[i - 1]);
                } else {
                    res = max(res, cur);
                }
                cur -= intervals[i - 1];
            }
        }
        return res;
    }
};
```
