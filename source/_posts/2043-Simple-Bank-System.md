---
title: 2043. Simple Bank System
categories: Leetcode
date: 2025-05-12 02:17:09
tags:
    - Array
    - Hash Table
    - Design
    - Simulation
---

[2043. Simple Bank System](https://leetcode.com/problems/simple-bank-system/description/?envType=company&envId=coinbase&favoriteSlug=coinbase-all)

## Description

You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has <code>n</code> accounts numbered from <code>1</code> to <code>n</code>. The initial balance of each account is stored in a **0-indexed**  integer array <code>balance</code>, with the <code>(i + 1)^th</code> account having an initial balance of <code>balance[i]</code>.

Execute all the **valid**  transactions. A transaction is **valid**  if:

- The given account number(s) are between <code>1</code> and <code>n</code>, and
- The amount of money withdrawn or transferred from is **less than or equal**  to the balance of the account.

Implement the <code>Bank</code> class:

- <code>Bank(long[] balance)</code> Initializes the object with the **0-indexed**  integer array <code>balance</code>.
- <code>boolean transfer(int account1, int account2, long money)</code> Transfers <code>money</code> dollars from the account numbered <code>account1</code> to the account numbered <code>account2</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.
- <code>boolean deposit(int account, long money)</code> Deposit <code>money</code> dollars into the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.
- <code>boolean withdraw(int account, long money)</code> Withdraw <code>money</code> dollars from the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.

**Example 1:**

```bash
Input

["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
Output

[null, true, true, true, false, false]

Explanation

Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
```

**Constraints:**

- <code>n == balance.length</code>
- <code>1 <= n, account, account1, account2 <= 10^5</code>
- <code>0 <= balance[i], money <= 10^12</code>
- At most <code>10^4</code> calls will be made to **each**  function <code>transfer</code>, <code>deposit</code>, <code>withdraw</code>.

## Hints/Notes

- 2025/05/06 Q1
- simulation
- [Good solution](https://leetcode.com/problems/simple-bank-system/solutions/6590161/beats-98-simple-and-easy-array-manipulation/?envType=company&envId=coinbase&favoriteSlug=coinbase-all)

## Solution

Language: **C++**

```C++
class Bank {
public:
    vector<long long> balance;

    Bank(vector<long long>& balance): balance(balance) {

    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 > balance.size()) {
            return false;
        }
        if (account2 <= 0 || account2 > balance.size()) {
            return false;
        }
        if (balance[account1 - 1] >= money) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (account <= 0 || account > balance.size()) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account <= 0 || account > balance.size() || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
```
