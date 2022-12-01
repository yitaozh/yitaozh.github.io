---
title: Bookkeeping - 2022/06
date: 2022-12-01 15:27:11
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7885.96 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 276.05  | Food            | 979.38  |
| Cake & Bread     | 147     | Food            |         |
| Bubble Tea       | 281.74  | Food            |         |
| Groceries        | 274.59  | Food            |         |
| Covid test       | 250     | Health          | 352.78  |
| Pharmacy         | 82.67   | Health          |         |
| Control          | 20.11   | Health          |         |
| Clothing         | 243.68  | Shopping        | 680.5   |
| Home Improvement | 391.29  | Shopping        |         |
| China Ecommerce  | 45.53   | Shopping        |         |
| Electricity      | 53      | Utilities       | 202.03  |
| Gas              | 62.66   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 61      | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 60      | Travel          | 765.11  |
| Ride Share       | 183.28  | Travel          |         |
| Hotel            | 457.83  | Travel          |         |
| Ticket           | 62      | Travel          |         |
| Souvenir         | 2       | Travel          |         |
| Cash & ATM       | 100     | Misc            | 100     |
| Paycheck         | 7885.96 | Income          | 7885.96 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 7885.96   | 5022.31   | 2863.65       |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Covid Test','Pharmacy','Control','Clothing','Home Improvement','China Ecommerce','Electricity','Gas',
        'Phone Bill','Legal','Supply','Television','Mortgage','HOA','Air','Ride Share','Hotel','Ticket','Souvenir','Cash & ATM']
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
                {value:979.38, name:'Food'},
                {value:352.78, name:'Health'},
                {value:680.5, name:'Shopping'},
                {value:202.03, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:765.11, name:'Travel'},
                {value:100, name:'Misc'},
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
                {value:276.05, name:'Restaurants'},
                {value:147, name:'Cake & Bread'},
                {value:281.74, name:'Bubble Tea'},
                {value:274.59, name:'Groceries'},
                {value:250, name:'Covid Test'},
                {value:82.67, name:'Pharmacy'},
                {value:20.11, name:'Control'},
                {value:243.68, name:'Clothing'},
                {value:391.29, name:'Home Improvement'},
                {value:45.53, name:'China Ecommerce'},
                {value:53, name:'Electricity'},
                {value:62.66, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:61, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:60, name:'Air'},
                {value:183.28, name:'Ride Share'},
                {value:457.83, name:'Hotel'},
                {value:62, name:'Ticket'},
                {value:2, name:'Souvenir'},
                {value:100, name:'Cash & ATM'},
            ]
        }
    ]
};
{% endecharts %}