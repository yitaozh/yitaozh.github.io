---
title: Bookkeeping - 2021/12
date: 2022-11-29 10:13:11
tags: 财务
hidden: true
---

## Overview

### When

The second week's Sunday night, next time: 2023/01/08

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7559.13 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 735.85  | Food            | 1533.2  |
| Cake & Bread     | 123.43  | Food            |         |
| Bubble Tea       | 244.59  | Food            |         |
| Groceries        | 429.33  | Food            |         |
| Pharmacy         | 75.27   | Health          | 90.59   |
| Control          | 15.32   | Health          |         |
| Clothing         | 33.82   | Shopping        | 1850.21 |
| Hair & Skin      | 96.68   | Shopping        |         |
| Home Improvement | 659.87  | Shopping        |         |
| Electronics      | 1059.84 | Shopping        |         |
| Electricity      | 50.81   | Utilities       | 232.84  |
| Gas              | 85.11   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 43.55   | Utilities       |         |
| Supply           | 36.25   | Utilities       |         |
| Television       | 13.99   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Cash & ATM       | 200     | Misc            | 200     |
| Paycheck         | 7559.13 | Income          | 7559.13 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 7559.13   | 5849.35   | 1709.78       |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Misc','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Clothing','Hair & Skin','Home Improvement','Electronics','Electricity','Gas','Phone Bill','VPN',
        'Supply','Television','Mortgage','HOA','Cash & ATM']
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
                {value:1533.2, name:'Food'},
                {value:90.59, name:'Health'},
                {value:1850.21, name:'Shopping'},
                {value:232.84, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:200, name:'Misc'},
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
                {value:735.85, name:'Restaurants'},
                {value:123.43, name:'Cake & Bread'},
                {value:244.59, name:'Bubble Tea'},
                {value:429.33, name:'Groceries'},
                {value:75.27, name:'Pharmacy'},
                {value:15.32, name:'Control'},
                {value:33.82, name:'Clothing'},
                {value:96.68, name:'Hair & Skin'},
                {value:659.87, name:'Home Improvement'},
                {value:1059.84, name:'Electronics'},
                {value:50.81, name:'Electricity'},
                {value:85.11, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:43.55, name:'VPN'},
                {value:36.25, name:'Supply'},
                {value:13.99, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:200, name:'Cash & ATM'},
            ]
        }
    ]
};
{% endecharts %}