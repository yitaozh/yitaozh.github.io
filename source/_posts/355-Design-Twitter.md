---
title: 355. Design Twitter
categories: Leetcode
date: 2023-11-08 00:05:35
tags:
    - Hash Table
    - Linked List
    - Design
    - Heap (Priority Queue)
---

# [355\. Design Twitter](https://leetcode.com/problems/design-twitter/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Linked List](https://leetcode.com/tag/https://leetcode.com/tag/linked-list//), [Design](https://leetcode.com/tag/https://leetcode.com/tag/design//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//)

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the `10` most recent tweets in the user's news feed.

Implement the `Twitter` class:

* `Twitter()` Initializes your twitter object.
* `void postTweet(int userId, int tweetId)` Composes a new tweet with ID `tweetId` by the user `userId`. Each call to this function will be made with a unique `tweetId`.
* `List<Integer> getNewsFeed(int userId)` Retrieves the `10` most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be **ordered from most recent to least recent**.
* `void follow(int followerId, int followeeId)` The user with ID `followerId` started following the user with ID `followeeId`.
* `void unfollow(int followerId, int followeeId)` The user with ID `followerId` started unfollowing the user with ID `followeeId`.

**Example 1:**

```bash
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
```

**Constraints:**

* `1 <= userId, followerId, followeeId <= 500`
* 0 <= tweetId <= 10<sup>4</sup>
* All the tweets have **unique** IDs.
* At most 3 * 10<sup>4</sup> calls will be made to `postTweet`, `getNewsFeed`, `follow`, and `unfollow`.

## Hints/Notes

* priority queue + multiple maps
* the timestamp needs to be recorded separately

## Solution

Language: **C++**

```bash
class Twitter {
public:
    map<int, set<int>> followed;
    map<int, vector<int>> tweets;
    map<int, int> tweetIdToTime;
    int timestamp;

    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        if (!followed.count(userId)) {
            followed[userId] = set<int>{userId};
        }
        if (!tweets.count(userId)) {
            tweets[userId] = vector<int>{tweetId};
        } else {
            tweets[userId].push_back(tweetId);
        }
        tweetIdToTime[tweetId] = timestamp++;
    }

    vector<int> getNewsFeed(int userId) {
        set<int> follows = followed[userId];
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;
        for (int follow : follows) {
            int idx = tweets[follow].size() - 1;
            if (idx >= 0) {
                int tweetId = tweets[follow][idx];
                pq.push({tweetIdToTime[tweetId], tweetId, follow, idx});
            }
        }
        vector<int> res;
        while (pq.size() > 0) {
            if (res.size() == 10) {
                break;
            }
            auto triple = pq.top();
            pq.pop();
            res.push_back(triple[1]);
            int idx = triple[3];
            int user = triple[2];
            if (idx > 0) {
                int tweetId = tweets[user][idx - 1];
                pq.push({tweetIdToTime[tweetId], tweetId, user, idx - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (!followed.count(followerId)) {
            followed[followerId] = set<int>{followerId};
        }
        if (!followed.count(followeeId)) {
            followed[followeeId] = set<int>{followeeId};
        }
        followed[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (!followed.count(followerId)) {
            followed[followerId] = set<int>{followerId};
        }
        if (!followed.count(followeeId)) {
            followed[followeeId] = set<int>{followeeId};
        }
        followed[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```
