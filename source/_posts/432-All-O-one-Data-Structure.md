---
title: 432. All O one Data Structure
categories: Leetcode
date: 2025-03-18 02:29:41
tags:
    - Hash Table
    - Linked List
    - Design
    - Doubly-Linked List
---

[432. All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the `AllOne` class:

- `AllOne()` Initializes the object of the data structure.
- `inc(String key)` Increments the count of the string `key` by `1`. If `key` does not exist in the data structure, insert it with count `1`.
- `dec(String key)` Decrements the count of the string `key` by `1`. If the count of `key` is `0` after the decrement, remove it from the data structure. It is guaranteed that `key` exists in the data structure before the decrement.
- `getMaxKey()` Returns one of the keys with the maximal count. If no element exists, return an empty string `""`.
- `getMinKey()` Returns one of the keys with the minimum count. If no element exists, return an empty string `""`.

**Note**  that each function must run in `O(1)` average time complexity.

**Example 1:**

```bash
Input

["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output

[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation

AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
```

**Constraints:**

- `1 <= key.length <= 10`
- `key` consists of lowercase English letters.
- It is guaranteed that for each call to `dec`, `key` is existing in the data structure.
- At most `5 * 10^4`calls will be made to `inc`, `dec`, `getMaxKey`, and `getMinKey`.

## Hints/Notes

- 2025/02/17 Q3
- double linked list
- [Leetcode solution](https://leetcode.com/problems/all-oone-data-structure/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class AllOne {
public:
    struct Node {
        Node(int val) : freq(val) {
            prev = nullptr;
            next = nullptr;
        }
        int freq;
        unordered_set<string> str;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    unordered_map<string, Node*> keyToNode;

    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->next = head;
    }

    void inc(string key) {
        if (keyToNode.contains(key)) {
            Node* curNode = keyToNode[key];
            int freq = curNode->freq;
            if (curNode->next == tail || curNode->next->freq != freq + 1) {
                Node* newNode = new Node(freq + 1);
                newNode->str.insert(key);
                curNode->str.erase(key);
                keyToNode[key] = newNode;
                Node* next = curNode->next;
                curNode->next = newNode;
                newNode->prev = curNode;
                newNode->next = next;
                next->prev = newNode;
            } else {
                Node* next = curNode->next;
                curNode->str.erase(key);
                next->str.insert(key);
                keyToNode[key] = next;
            }
            if (curNode->str.empty()) {
                removeNode(curNode);
            }
        } else {
            if (head->next == tail || head->next->freq != 1) {
                Node* newNode = new Node(1);
                newNode->str.insert(key);
                Node* next = head->next;
                newNode->prev = head;
                head->next = newNode;
                next->prev = newNode;
                newNode->next = next;
                keyToNode[key] = newNode;
            } else {
                head->next->str.insert(key);
                keyToNode[key] = head->next;
            }
        }
    }

    void dec(string key) {
        Node* curNode = keyToNode[key];
        int freq = curNode->freq;
        // we need to transfer this key to another node
        if (freq > 1) {
            if (curNode->prev == head || curNode->prev->freq != freq - 1) {
                Node* newNode = new Node(freq - 1);
                newNode->str.insert(key);
                curNode->str.erase(key);
                keyToNode[key] = newNode;
                Node* prev = curNode->prev;
                prev->next = newNode;
                newNode->prev = prev;
                newNode->next = curNode;
                curNode->prev = newNode;
            } else {
                Node* prev = curNode->prev;
                prev->str.insert(key);
                curNode->str.erase(key);
                keyToNode[key] = prev;
            }
        } else {
            curNode->str.erase(key);
            keyToNode.erase(key);
        }
        if (curNode->str.empty()) {
            removeNode(curNode);
        }
    }

    string getMaxKey() {
        if (head->next == tail) {
            return "";
        } else {
            string s = *tail->prev->str.begin();
            return s;
        }

    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        } else {
            string s = *head->next->str.begin();
            return s;
        }
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
        delete(node);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```
