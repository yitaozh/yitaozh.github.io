---
title: Bookkeeping - 2022/05
date: 2022-12-01 14:12:39
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4986.17 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 632.72  | Food            | 1543.5  |
| Cake & Bread     | 183.25  | Food            |         |
| Bubble Tea       | 309.99  | Food            |         |
| Groceries        | 417.54  | Food            |         |
| Pharmacy         | 51.06   | Health          | 51.06   |
| Clothing         | 360.49  | Shopping        | 1040.78 |
| Home Improvement | 463.68  | Shopping        |         |
| Electronics      | 180.61  | Shopping        |         |
| Marriage         | 36      | Shopping        |         |
| Electricity      | 59.83   | Utilities       | 315.63  |
| Gas              | 153.57  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 76.86   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 475.2   | Travel          | 998.23  |
| Ride Share       | 60.91   | Travel          |         |
| Hotel            | 462.12  | Travel          |         |
| Stock            | 50      | Investment      | 50      |
| Paycheck         | 4986.17 | Income          | 4986.17 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 4986.17   | 5941.71   | -955.54       |

## Chart

{% echarts %}
{
    tooltip: {
        trigger: 'item',
        formatter: "{b}: {c} ({d}%)"
    },
    legend: {
        orient: 'vertical',
        x: 'left',
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Investment','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Pharmacy','Clothing','Home Improvement','Electronics','Marriage','Electricity','Gas',
        'Phone Bill','Legal','Supply','Television','Mortgage','HOA','Air','Ride Share','Hotel','Stock']
    },
    series: [
        {
            name:'Section',
            type:'pie',
            selectedMode: 'single',
            radius: [0, '50%'],
            threshold: 100,
            avoidLabelOverlap: true,
            label: {
                normal: {
                    position: 'inner'
                },
            },
            labelLine: {
                normal: {
                    show: false
                }
            },
            data:[
                {value:1543.5, name:'Food'},
                {value:51.06, name:'Health'},
                {value:1040.78, name:'Shopping'},
                {value:315.63, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:998.23, name:'Travel'},
                {value:50, name:'Investment'},
            ]
        },
        {
            name:'Detail',
            type:'pie',
            radius: ['60%', '75%'],
            threshold: 100,
            // avoidLabelOverlap: true,
            label: {
                normal: {
                    // formatter: '{a|{a}}{abg|}\n{hr|}\n  {b|{b}：}{c}  {per|{d}%}  ',
                    formatter: '{b|{b}：}{c}  {per|{d}%}  ',
                    backgroundColor: '#eee',
                    borderColor: '#aaa',
                    borderWidth: 1,
                    borderRadius: 4,
                    // shadowBlur:3,
                    // shadowOffsetX: 2,
                    // shadowOffsetY: 2,
                    // shadowColor: '#999',
                    // padding: [0, 7],
                    rich: {
                        // a: {
                        //    color: '#999',
                        //    lineHeight: 22,
                        //    align: 'center'
                        // },
                        // abg: {
                        //     backgroundColor: '#333',
                        //     width: '100%',
                        //     align: 'right',
                        //     height: 22,
                        //     borderRadius: [4, 4, 0, 0]
                        // },
                        // hr: {
                        //    borderColor: '#aaa',
                        //    width: '100%',
                        //    borderWidth: 0.5,
                        //    height: 0
                        // },
                        b: {
                            fontSize: 16,
                            lineHeight: 33
                        },
                        per: {
                            color: '#eee',
                            backgroundColor: '#334455',
                            padding: [2, 4],
                            borderRadius: 2
                        }
                    }
                },
            },
            data:[
                {value:632.72, name:'Restaurants'},
                {value:183.25, name:'Cake & Bread'},
                {value:309.99, name:'Bubble Tea'},
                {value:417.54, name:'Groceries'},
                {value:51.06, name:'Pharmacy'},
                {value:360.49, name:'Clothing'},
                {value:463.68, name:'Home Improvement'},
                {value:180.61, name:'Electronics'},
                {value:36, name:'Marriage'},
                {value:59.83, name:'Electricity'},
                {value:153.57, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:76.86, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:475.2, name:'Air'},
                {value:60.91, name:'Ride Share'},
                {value:462.12, name:'Hotel'},
                {value:50, name:'Stock'},
            ]
        }
    ]
};
{% endecharts %}