---
title: 2296. Design a Text Editor
categories: Leetcode
date: 2025-03-19 15:55:56
tags:
    - Linked List
    - String
    - Stack
    - Design
    - Simulation
    - Doubly-Linked List
---

[2296. Design a Text Editor](https://leetcode.com/problems/design-a-text-editor/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Design a text editor with a cursor that can do the following:

- **Add**  text to where the cursor is.
- **Delete**  text from where the cursor is (simulating the backspace key).
- **Move**  the cursor either left or right.

When deleting text, only characters to the left of the cursor will be deleted. The cursor will also remain within the actual text and cannot be moved beyond it. More formally, we have that `0 <= cursor.position <= currentText.length` always holds.

Implement the `TextEditor` class:

- `TextEditor()` Initializes the object with empty text.
- `void addText(string text)` Appends `text` to where the cursor is. The cursor ends to the right of `text`.
- `int deleteText(int k)` Deletes `k` characters to the left of the cursor. Returns the number of characters actually deleted.
- `string cursorLeft(int k)` Moves the cursor to the left `k` times. Returns the last `min(10, len)` characters to the left of the cursor, where `len` is the number of characters to the left of the cursor.
- `string cursorRight(int k)` Moves the cursor to the right `k` times. Returns the last `min(10, len)` characters to the left of the cursor, where `len` is the number of characters to the left of the cursor.

**Example 1:**

```bash
Input

["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
Output

[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

Explanation

TextEditor textEditor = new TextEditor(); // The current text is "|". (The '|' character represents the cursor)
textEditor.addText("leetcode"); // The current text is "leetcode|".
textEditor.deleteText(4); // return 4
                          // The current text is "leet|".
                          // 4 characters were deleted.
textEditor.addText("practice"); // The current text is "leetpractice|".
textEditor.cursorRight(3); // return "etpractice"
                           // The current text is "leetpractice|".
                           // The cursor cannot be moved beyond the actual text and thus did not move.
                           // "etpractice" is the last 10 characters to the left of the cursor.
textEditor.cursorLeft(8); // return "leet"
                          // The current text is "leet|practice".
                          // "leet" is the last min(10, 4) = 4 characters to the left of the cursor.
textEditor.deleteText(10); // return 4
                           // The current text is "|practice".
                           // Only 4 characters were deleted.
textEditor.cursorLeft(2); // return ""
                          // The current text is "|practice".
                          // The cursor cannot be moved beyond the actual text and thus did not move.
                          // "" is the last min(10, 0) = 0 characters to the left of the cursor.
textEditor.cursorRight(6); // return "practi"
                           // The current text is "practi|ce".
                           // "practi" is the last min(10, 6) = 6 characters to the left of the cursor.
```

**Constraints:**

- `1 <= text.length, k <= 40`
- `text` consists of lowercase English letters.
- At most `2 * 10^4` calls **in total**  will be made to `addText`, `deleteText`, `cursorLeft` and `cursorRight`.

**Follow-up:**  Could you find a solution with time complexity of `O(k)` per call?

## Hints/Notes

- 2025/02/20 Q3
- Doubly-Linked List
- [Leetcode solution](https://leetcode.cn/problems/design-a-text-editor/solutions/3078930/she-ji-yi-ge-wen-ben-bian-ji-qi-by-leetc-o4by/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class TextEditor {
public:
    struct Node {
        Node(char c): c(c) {}
        char c;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* cursor;

    TextEditor() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        cursor = head;
    }

    void addText(string text) {
        Node* nxt = cursor->next;
        for (char& c : text) {
            Node* node = new Node(c);
            cursor->next = node;
            node->prev = cursor;
            cursor = cursor->next;
        }
        cursor->next = nxt;
        nxt->prev = cursor;
    }

    int deleteText(int k) {
        int deleted = 0;
        Node* nxt = cursor->next;
        while (cursor != head && deleted < k) {
            cursor = cursor->prev;
            delete(cursor->next);
            deleted++;
        }
        cursor->next = nxt;
        nxt->prev = cursor;
        return deleted;
    }

    string cursorLeft(int k) {
        while (cursor != head && k > 0) {
            k--;
            cursor = cursor->prev;
        }
        string res;
        Node* node = cursor;
        while (node != head && res.size() < 10) {
            res = node->c + res;
            node = node->prev;
        }
        return res;
    }

    string cursorRight(int k) {
        while (cursor->next != tail && k > 0) {
            k--;
            cursor = cursor->next;
        }
        string res;
        Node* node = cursor;
        while (node != head && res.size() < 10) {
            res = node->c + res;
            node = node->prev;
        }
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
```
