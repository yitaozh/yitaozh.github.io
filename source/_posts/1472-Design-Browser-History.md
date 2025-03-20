---
title: 1472. Design Browser History
categories: Leetcode
date: 2025-03-19 22:16:54
tags:
    - Array
    - Linked List
    - Stack
    - Design
    - Doubly-Linked List
    - Data Stream
---

[1472. Design Browser History](https://leetcode.com/problems/design-browser-history/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You have a **browser**  of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

- `BrowserHistory(string homepage)` Initializes the object with the `homepage`of the browser.
- `void visit(string url)`Visits`url` from the current page. It clears up all the forward history.
- `string back(int steps)`Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you willreturn only `x` steps. Return the current `url`after moving back in history **at most**  `steps`.
- `string forward(int steps)`Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you willforward only`x` steps. Return the current `url`after forwarding in history **at most**  `steps`.

**Example:**

```bash
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
<b>Output:</b>
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```

**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of '.' or lower case English letters.
- At most `5000`calls will be made to `visit`, `back`, and `forward`.

## Hints/Notes

- 2025/02/23 Q2
- doubly linked list
- [Leetcode solution](https://leetcode.com/problems/design-browser-history/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class BrowserHistory {
public:
    struct Node {
        Node(string url) : url(url), prev(nullptr), next(nullptr) {}
        string url;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* current;

    BrowserHistory(string homepage) {
        head = new Node(homepage);
        current = head;
    }

    void visit(string url) {
        Node* nxt = current->next;
        while (nxt) {
            Node* prev = nxt;
            nxt = nxt->next;
            delete(prev);
        }
        Node* node = new Node(url);
        current->next = node;
        node->prev = current;
        current = current->next;
    }

    string back(int steps) {
        while (steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
```
