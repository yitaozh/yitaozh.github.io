---
title: Bookkeeping - 2022/11
date: 2022-12-12 13:24:44
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4311.02 |
| State Tax        | 823     |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 534.54  | Food            | 1131.3  |
| Cake & Bread     | 108.93  | Food            |         |
| Bubble Tea       | 232.02  | Food            |         |
| Groceries        | 255.81  | Food            |         |
| Covid Test       | 49.2    | Health          | 151.2   |
| Dental           | 61.1    | Health          |         |
| Pharmacy         | 40.9    | Health          |         |
| Hair & Skin      | 8.49    | Shopping        | 2357.83 |
| Home Improvement | 1209.91 | Shopping        |         |
| China Ecommerce  | 289.44  | Shopping        |         |
| Electronics      | 849.99  | Shopping        |         |
| Electricity      | 33.46   | Utilities       | 168.02  |
| Gas              | 73.98   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Supply           | 29.01   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 74.52   | Travel          | 74.52   |
| Cash & ATM       | 60      | Misc            | 77.36   |
| Shipping         | 17.36   | Misc            |         |
| Paycheck         | 4311.02 | Income          | 5134.02 |
| State Tax        | 823     | Income          |         |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 5134.02   | 6057.2    | -923.18       |

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
        'Groceries','Covid Test','Dental','Pharmacy','Hair & Skin','Home Improvement','China Ecommerce','Electronics','Electricity',
        'Gas','Phone Bill','VPN','Supply','Television','Mortgage','HOA','Ride Share','Cash & ATM','Shipping']
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
                {value:1131.3, name:'Food'},
                {value:151.2, name:'Health'},
                {value:2357.83, name:'Shopping'},
                {value:168.02, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:74.52, name:'Travel'},
                {value:77.36, name:'Misc'},
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
                {value:534.54, name:'Restaurants'},
                {value:108.93, name:'Cake & Bread'},
                {value:232.02, name:'Bubble Tea'},
                {value:255.81, name:'Groceries'},
                {value:49.2, name:'Covid Test'},
                {value:61.1, name:'Dental'},
                {value:40.9, name:'Pharmacy'},
                {value:8.49, name:'Hair & Skin'},
                {value:1209.91, name:'Home Improvement'},
                {value:289.44, name:'China Ecommerce'},
                {value:849.99, name:'Electronics'},
                {value:33.46, name:'Electricity'},
                {value:73.98, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:29.01, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1672.53, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:74.52, name:'Ride Share'},
                {value:60, name:'Cash & ATM'},
                {value:17.36, name:'Shipping'},
            ]
        }
    ]
};
{% endecharts %}