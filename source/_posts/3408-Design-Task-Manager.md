---
title: 3408. Design Task Manager
categories: Leetcode
date: 2025-01-10 17:12:20
tags:
    - Hash Table
    - Design
    - Heap (Priority Queue)
    - Ordered Set
---

[3408. Design Task Manager](https://leetcode.com/problems/design-task-manager/description/)

## Description

There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the `TaskManager` class:

- `TaskManager(vector<vector<int>>&; tasks)` initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form `[userId, taskId, priority]`, which adds a task to the specified user with the given priority.

- `void add(int userId, int taskId, int priority)` adds a task with the specified `taskId` and `priority` to the user with `userId`. It is **guaranteed**  that `taskId` does not exist in the system.

- `void edit(int taskId, int newPriority)` updates the priority of the existing `taskId` to `newPriority`. It is **guaranteed**  that `taskId` exists in the system.

- `void rmv(int taskId)` removes the task identified by `taskId` from the system. It is **guaranteed**  that `taskId` exists in the system.

- `int execTop()` executes the task with the **highest**  priority across all users. If there are multiple tasks with the same **highest**  priority, execute the one with the highest `taskId`. After executing, the `taskId` is **removed**  from the system. Return the `userId` associated with the executed task. If no tasks are available, return -1.

**Note**  that a user may be assigned multiple tasks.

**Example 1:**

```bash
Input:
["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]<br>
[[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]

Output:
[null, null, null, 3, null, null, 5]

Explanation

TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
taskManager.edit(102, 8); // Updates priority of task 102 to 8.
taskManager.execTop(); // return 3. Executes task 103 for User 3.
taskManager.rmv(101); // Removes task 101 from the system.
taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
taskManager.execTop(); // return 5. Executes task 105 for User 5.
```

**Constraints:**

- `1 <= tasks.length <= 10^5`
- `0 <= userId <= 10^5`
- `0 <= taskId <= 10^5`
- `0 <= priority <= 10^9`
- `0 <= newPriority <= 10^9`
- At most `2 * 10^5` calls will be made in **total**  to `add`, `edit`, `rmv`, and `execTop` methods.
- The input is generated such that `taskId` will be valid.

## Hints/Notes

- 2025/01/12
- lazy priority queue
- [0x3F's solution](https://leetcode.cn/problems/design-task-manager/solutions/3039132/lan-shan-chu-dui-pythonjavacgo-by-endles-q5vb/)(checked)
- Biweekly Contest 147

## Solution

Language: **C++**

```C++
class TaskManager {
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> taskIdToPriority;
    unordered_map<int, int> taskIdToUserId;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskIdToPriority[taskId] = priority;
            taskIdToUserId[taskId] = userId;
            pq.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskIdToPriority[taskId] = priority;
        taskIdToUserId[taskId] = userId;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskIdToPriority[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskIdToPriority[taskId] = -1;
        taskIdToUserId[taskId] = -1;
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (taskIdToPriority.contains(taskId) && priority == taskIdToPriority[taskId]) {
                // matches, return the id
                taskIdToPriority.erase(taskId);
                return taskIdToUserId[taskId];
            } else {
                continue;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
```
