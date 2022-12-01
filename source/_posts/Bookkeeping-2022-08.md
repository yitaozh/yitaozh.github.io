---
title: Bookkeeping - 2022/08
date: 2022-12-01 16:20:39
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 8024.04 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Pharmacy         | 5       | Health          | 5       |
| China Ecommerce  | 177.83  | Shopping        | 177.83  |
| Electricity      | 28.35   | Utilities       | 112.3   |
| Gas              | 45.63   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1650.46 | Mortgage & Rent | 2074.9  |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 1706.14 | Travel          | 1706.14 |
| Paycheck         | 8024.04 | Income          | 8024.04 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 8024.04   | 4076.17   | 3947.87       |

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
        data:['Health','Shopping','Utilities','Mortgage & Rent','Misc','Pharmacy','China Ecommerce','Electricity','Gas',
        'Phone Bill','Legal','Television','Mortgage','HOA','Annual']
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
                {value:177.83, name:'Shopping'},
                {value:112.3, name:'Utilities'},
                {value:2074.9, name:'Mortgage & Rent'},
                {value:5, name:'Health'},
                {value:1706.14, name:'Travel'},
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
                {value:177.83, name:'China Ecommerce'},
                {value:28.35, name:'Electricity'},
                {value:45.63, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:6.75, name:'Legal'},
                {value:15.49, name:'Television'},
                {value:1650.46, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:5, name:'Pharmacy'},
                {value:1706.14, name:'Air'},
            ]
        }
    ]
};
{% endecharts %}