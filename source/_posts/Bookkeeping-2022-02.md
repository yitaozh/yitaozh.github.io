---
title: Bookkeeping - 2022/02
date: 2022-11-30 18:02:32
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 3391.79 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 218.52  | Food            | 813.19  |
| Cake & Bread     | 143.7   | Food            |         |
| Bubble Tea       | 186.46  | Food            |         |
| Groceries        | 264.51  | Food            |         |
| Pharmacy         | 11.09   | Health          | 11.09   |
| Hair & Skin      | 2.01    | Shopping        | 325.59  |
| Home Improvement | 318.95  | Shopping        |         |
| Office           | 4.63    | Shopping        |         |
| Electricity      | 69.02   | Utilities       | 369.22  |
| Gas              | 273.31  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 3.02    | Utilities       |         |
| Television       | 13.99   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Stock            | 6000    | Investment      | 6000    |
| Paycheck         | 3391.79 | Income          | 3391.79 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 3391.79   | 9461.6    | -6069.81      |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Investment','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Pharmacy','Hair & Skin','Home Improvement','Office','Electricity','Gas','Phone Bill','Legal',
        'Supply','Television','Mortgage','HOA','Stock']
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
                {value:813.19, name:'Food'},
                {value:11.09, name:'Health'},
                {value:325.59, name:'Shopping'},
                {value:369.22, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
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
                {value:218.52, name:'Restaurants'},
                {value:143.7, name:'Cake & Bread'},
                {value:186.46, name:'Bubble Tea'},
                {value:264.51, name:'Groceries'},
                {value:11.09, name:'Pharmacy'},
                {value:2.01, name:'Hair & Skin'},
                {value:318.95, name:'Home Improvement'},
                {value:4.63, name:'Office'},
                {value:69.02, name:'Electricity'},
                {value:273.31, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:3.02, name:'Supply'},
                {value:13.99, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:6000, name:'Stock'},
            ]
        }
    ]
};
{% endecharts %}