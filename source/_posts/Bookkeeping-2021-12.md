---
title: Bookkeeping - 2021/12
date: 2022-11-29 10:13:11
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7559.13 |

### Spending

| Category         | Sum     | Section         | Sum        |
| ---------------- | ------- | --------------- | ---------- |
| Bubble Tea       | 244.59  | Food            | 1533.2     |
| Restaurants      | 735.85  | Food            |            |
| Groceries        | 429.33  | Food            |            |
| Cake & Bread     | 123.43  | Food            |            |
| Electronics      | 1059.84 | Shopping        | 1753.53    |
| Home Improvement | 659.87  | Shopping        |            |
| Clothing         | 33.82   | Shopping        |            |
| Electricity      | 50.81   | Utility         | 248.16     |
| Phone Bill       | 3.13    | Utility         |            |
| VPN              | 43.55   | Utility         |            |
| Control          | 15.32   | Utility         |            |
| Television       | 13.99   | Utility         |            |
| Gas              | 85.11   | Utility         |            |
| Supply           | 36.25   | Utility         |            |
| Pharmacy         | 75.27   | Health          | 171.95     |
| Hair & Skin      | 96.68   | Health          |            |
| HOA              | 424.44  | Mortgage & Rent | 1942.51    |
| Mortgage         | 1518.07 | Mortgage & Rent |            |
| Cash & ATM       | 200     | Misc            | 200        |

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
        data:['Food','Shopping','Utility','Health','Mortgage & Rent','Misc','Bubble Tea','Restaurants','Groceries',
        'Cake & Bread','Clothing','Home Improvement','Hair & Skin','Electronics','Supply','Phone Bill','Electricity',
        'VPN','Control','Television','Gas','Pharmacy','Hair & Skin','HOA','Mortgage','Cash & ATM']
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
                {value:1753.53, name:'Shopping'},
                {value:248.16, name:'Utility'},
                {value:171.95, name:'Health'},
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
                {value:244.59, name:'Bubble Tea'},
                {value:735.85, name:'Restaurants'},
                {value:429.33, name:'Groceries'},
                {value:123.43, name:'Cake & Bread'},
                {value:1059.84, name:'Electronics'},
                {value:659.87, name:'Home Improvement'},
                {value:33.82, name:'Clothing'},
                {value:50.81, name:'Electricity'},                {value:3.13, name:'Phone Bill'},
                {value:43.55, name:'VPN'},
                {value:15.32, name:'Control'},
                {value:13.99, name:'Television'},
                {value:85.11, name:'Gas'},
                {value:36.25, name:'Supply'},
                {value:75.27, name:'Pharmacy'},
                {value:96.68, name:'Hair & Skin'},
                {value:424.44, name:'HOA'},
                {value:1518.07, name:'Mortgage'},
                {value:200, name:'Cash & ATM'},
            ]
        }
    ]
};
{% endecharts %}