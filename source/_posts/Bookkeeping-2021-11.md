---
title: Bookkeeping - 2021/11
date: 2022-11-28 22:43:07
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 5926.72 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 534.72  | Food            | 1133.52 |
| Cake & Bread     | 44.54   | Food            |         |
| Bubble Tea       | 259.67  | Food            |         |
| Groceries        | 294.59  | Food            |         |
| Pharmacy         | 11.68   | Health          | 11.68   |
| Clothing         | 75.8    | Shopping        | 783.8   |
| Hair & Skin      | 43.5    | Shopping        |         |
| Home Improvement | 97.56   | Shopping        |         |
| Electronics      | 566.94  | Shopping        |         |
| Electricity      | 47.14   | Utilities       | 138.74  |
| Gas              | 35.37   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Supply           | 53.1    | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 49.98   | Travel          | 49.98   |
| Paycheck         | 5926.72 | Income          | 5926.72 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 5926.72   | 4060.23   | 1866.49       |

## Chart

{% echarts %}
{
    tooltip: {
        trigger: 'item',
        formatter: "{a} <br/>{b}: {c} ({d}%)"
    },
    legend: {
        orient: 'vertical',
        x: 'left',
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Clothing','Hair & Skin','Home Improvement','Electronics','Electricity','Gas','Phone Bill','Supply',
        'Pharmacy','Mortgage','HOA','Ride Share']
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
                {value:1133.52, name:'Food'},
                {value:11.68, name:'Health'},
                {value:783.8, name:'Shopping'},
                {value:138.75, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:49.98, name:'Travel'},
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
                {value:534.72, name:'Restaurants'},
                {value:44.54, name:'Cake & Bread'},
                {value:259.67, name:'Bubble Tea'},
                {value:294.59, name:'Groceries'},
                {value:11.68, name:'Pharmacy'},
                {value:75.8, name:'Clothing'},
                {value:43.5, name:'Hair & Skin'},
                {value:97.56, name:'Home Improvement'},
                {value:566.94, name:'Electronics'},
                {value:47.14, name:'Electricity'},
                {value:35.37, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:53.1, name:'Supply'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:49.98, name:'Ride Share'},
            ]
        }
    ]
};
{% endecharts %}