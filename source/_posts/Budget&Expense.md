---
title: Budget & Expense
date: 2022-11-20 22:54:23
tags: Finance
---

## The accouting process

### When

Use the first and second week to submit reimbursements, do the bookkeeping on the second week's Thursday afternoon, next time: 2023/08/10

### The steps to make monthly record

#### Excel processing

1. Dump the record from Mint to nyuzyt/Personal file/Transactions cvs file
1. Copy the cvs tables content, without the header
1. Insert a line in overall sheet prior to the previous record, then "insert the copied cells"
1. Create a new sheet for this month alone
1. Copy from one previous month's sheet(all the way to comments), paste the column width
1. Copy the records to this month's sheet
1. Remove the Credit Card Payments
1. Remove the Loan accounts
1. Filter the records by account first
1. Check each account, modify the catagory and mark the transactions as verfied
1. Copy the reverse ~ Balance columns from one previous month's table
1. List single item takes more than $10,000

#### Web update

1. Generate the new hexo post with `hexo new post "Bookkeeping - XXXX/XX"`
1. Copy all content from the post for previous month, git add now(so we know what changed)
1. Go to the [Table to Markdown](https://tabletomarkdown.com/convert-spreadsheet-to-markdown/) website to transform excel tables to markdown tables
1. Remove the zeroes from sum column
1. Open the same file to the right window, make it narrow
1. Add new value to and remove old value from the multi layer pie chart for spending and income
1. Ask chatgpt to generate the detailed catagory data

    ```bash
    对
    spending table
    取每一行第一个值和第二个值，生成类似
    {value:251.69, name:'Restaurants'},
    {value:73.15, name:'Cake & Bread'},
    的数据
    ```

1. Add new value to and remove old value from the trend
1. Commit the change with title "Add bookkeeping for YYYY/MM"

### Transaction catagories

| Category              | Section         |
| ----------------      | --------------- |
| Restaurants           | Food            |
| Cake & Bread          | Food            |
| Bubble Tea            | Food            |
| Groceries             | Food            |
| Medical               | Health          |
| Covid Test            | Health          |
| Dental                | Health          |
| Eyecare               | Health          |
| Pharmacy              | Health          |
| Control               | Health          |
| Clothing              | Shopping        |
| Hair & Skin           | Shopping        |
| Home Improvement      | Shopping        |
| China Ecommerce       | Shopping        |
| Electronics           | Shopping        |
| Office                | Shopping        |
| Marriage              | Shopping        |
| Electricity           | Utilities       |
| Gas                   | Utilities       |
| Phone Bill            | Utilities       |
| VPN                   | Utilities       |
| Legal                 | Utilities       |
| Network               | Utilities       |
| Supply                | Utilities       |
| Television            | Utilities       |
| Auto                  | Utilities       |
| Mortgage              | Mortgage & Rent |
| HOA                   | Mortgage & Rent |
| Air                   | Travel          |
| Ride Share/Car rental | Travel          |
| Hotel                 | Travel          |
| Ticket                | Travel          |
| Souvenir              | Travel          |
| IRA                   | Investment      |
| Stock                 | Investment      |
| Cash & ATM            | Misc            |
| Transfer              | Income/Misc     |
| Shipping              | Misc            |
| Annual                | Misc            |
| Visa                  | Misc            |
| Bank Fee              | Misc            |
| Paycheck              | Income          |
| Federal Tax           | Income/Misc     |
| State Tax             | Income/Misc     |
| Deposit               | Income          |
