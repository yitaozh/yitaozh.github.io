---
title: 3433. Count Mentions Per User
categories: Leetcode
date: 2025-02-23 13:52:12
tags:
    - Array
    - Math
    - Sorting
    - Simulation
---

[3433. Count Mentions Per User](https://leetcode.com/problems/count-mentions-per-user/description/)

## Description

You are given an integer `numberOfUsers` representing the total number of users and an array `events` of size `n x 3`.

Each `events[i]` can be either of the following two types:

1. **Message Event:**  ["MESSAGE", "timestamp<sub>i</sub>", "mentions_string<sub>i</sub>"]

    - This event indicates that a set of users was mentioned in a message at timestamp<sub>i</sub>.
    - The mentions_string<sub>i</sub> string can contain one of the following tokens:

        - `id<number>`: where `<number>` is an integer in range `[0,numberOfUsers - 1]`. There can be **multiple**  ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
        - `ALL`: mentions **all**  users.
        - `HERE`: mentions all **online**  users.

2. **Offline Event:**  ["OFFLINE", "timestamp<sub>i</sub>", "id<sub>i</sub>"]

    - This event indicates that the user id<sub>i</sub> had become offline at timestamp<sub>i</sub> for **60 time units** . The user will automatically be online again at time timestamp<sub>i</sub> + 60.

Return an array `mentions` where `mentions[i]` represents the number of mentions the user with id `i` has across all `MESSAGE` events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

**Note** that a user can be mentioned **multiple**  times in a **single**  message event, and each mention should be counted **separately**.

**Example 1:**

```bash
Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

Output: [2,2]
```

Explanation:

Initially, all users are online.

At timestamp 10, `id1` and `id0` are mentioned. `mentions = [1,1]`

At timestamp 11, `id0` goes **offline.**

At timestamp 71, `id0` comes back **online**  and `"HERE"` is mentioned. `mentions = [2,2]`

**Example 2:**

```bash
Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

Output: [2,2]
```

Explanation:

Initially, all users are online.

At timestamp 10, `id1` and `id0` are mentioned. `mentions = [1,1]`

At timestamp 11, `id0` goes **offline.**

At timestamp 12, `"ALL"` is mentioned. This includes offline users, so both `id0` and `id1` are mentioned. `mentions = [2,2]`

**Example 3:**

```bash
Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

Output: [0,1]
```

Explanation:

Initially, all users are online.

At timestamp 10, `id0` goes **offline.**

At timestamp 12, `"HERE"` is mentioned. Because `id0` is still offline, they will not be mentioned. `mentions = [0,1]`

**Constraints:**

- `1 <= numberOfUsers <= 100`
- `1 <= events.length <= 100`
- `events[i].length == 3`
- `events[i][0]` will be one of `MESSAGE` or `OFFLINE`.
- `1 <= int(events[i][1]) <= 10^5`
- The number of `id<number>` mentions in any `"MESSAGE"` event is between `1` and `100`.
- `0 <= <number> <= numberOfUsers - 1`
- It is **guaranteed**  that the user id referenced in the `OFFLINE` event is **online**  at the time the event occurs.

## Hints/Notes

- 2025/02/19 Q1
- sort
- [0x3F's solution](https://leetcode.cn/problems/count-mentions-per-user/solutions/3057699/an-zhao-shi-jian-chuo-fen-zu-mo-ni-by-en-w77b/)
- Weekly Contest 434 t2

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> res(numberOfUsers, 0);
        vector<bool> status(numberOfUsers, true);
        vector<int> hereEvent;
        vector<vector<int>> statusEvents;
        for (auto& event : events) {
            auto& type = event[0];
            int time = stoi(event[1]);
            if (type == "MESSAGE") {
                string mentions = event[2];
                if (mentions == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        res[i]++;
                    }
                } else if (mentions == "HERE") {
                    hereEvent.push_back(time);
                } else {
                    istringstream iss(mentions);
                    do {
                        string user;
                        iss >> user;
                        if (user == "") {
                            break;
                        }
                        user = user.substr(2);
                        int userId = stoi(user);
                        res[userId]++;
                    } while (iss);
                }
            } else {
                int userId = stoi(event[2]);
                statusEvents.push_back({time, userId, 1});
                statusEvents.push_back({time + 60, userId, 0});
            }
        }
        ranges::sort(hereEvent);
        ranges::sort(statusEvents);
        int j = 0;
        for (int i = 0; i < hereEvent.size(); i++) {
            int time = hereEvent[i];
            while (j < statusEvents.size() && statusEvents[j][0] <= time) {
                int userId = statusEvents[j][1];
                status[userId] = 1 - statusEvents[j][2];
                j++;
            }
            for (int k = 0; k < numberOfUsers; k++) {
                res[k] += status[k];

            }
        }
        return res;
    }
};
```
