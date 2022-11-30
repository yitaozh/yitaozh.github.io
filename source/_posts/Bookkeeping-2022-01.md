---
title: Bookkeeping - 2022/01
date: 2022-11-30 14:51:37
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4741.41 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 559.76  | Food            | 1802.25 |
| Cake & Bread     | 157.19  | Food            |         |
| Bubble Tea       | 225.15  | Food            |         |
| Groceries        | 860.15  | Food            |         |
| Pharmacy         | 86.89   | Health          | 86.89   |
| Clothing         | 1.04    | Shopping        | 615.83  |
| Home Improvement | 220.25  | Shopping        |         |
| Electronics      | 394.54  | Shopping        |         |
| Electricity      | 71.46   | Utilities       | 337.69  |
| Gas              | 236     | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Supply           | 13.11   | Utilities       |         |
| Television       | 13.99   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 28.5    | Travel          | 28.5    |
| IRA              | 6000    | Investment      | 6000    |
| Paycheck         | 4741.41 | Income          | 4741.41 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 4741.41   | 10813.67  | -6072.26      |

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
        'Bubble Tea','Groceries','Clothing','Home Improvement','Electronics','Electricity','Gas','Phone Bill','Supply',
        'Television','Pharmacy','Mortgage','HOA','Ride Share','IRA']
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
                {value:1802.25, name:'Food'},
                {value:86.89, name:'Health'},
                {value:615.83, name:'Shopping'},
                {value:337.69, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:28.5, name:'Travel'},
                {value:6000, name:'Investment'},
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
                {value:559.76, name:'Restaurants'},
                {value:157.19, name:'Cake & Bread'},
                {value:225.15, name:'Bubble Tea'},
                {value:860.15, name:'Groceries'},
                {value:86.89, name:'Pharmacy'},
                {value:1.04, name:'Clothing'},
                {value:220.25, name:'Home Improvement'},
                {value:394.54, name:'Electronics'},
                {value:71.46, name:'Electricity'},   
                {value:236, name:'Gas'},             
                {value:3.13, name:'Phone Bill'},
                {value:13.11, name:'Supply'},
                {value:13.99, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:28.5, name:'Ride Share'},
                {value:6000, name:'IRA'},
            ]
        }
    ]
};
{% endecharts %}