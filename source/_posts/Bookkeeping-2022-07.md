---
title: Bookkeeping - 2022/07
date: 2022-12-01 15:54:19
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7885.94 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Pharmacy         | 5       | Health          | 5       |
| China Ecommerce  | 410.64  | Shopping        | 410.64  |
| Electricity      | 70.37   | Utilities       | 165.16  |
| Gas              | 56.47   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1650.46 | Mortgage & Rent | 2074.9  |
| HOA              | 424.44  | Mortgage & Rent |         |
| Annual           | 95      | Misc            | 95      |
| Paycheck         | 7885.94 | Income          | 7885.94 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 7885.96   | 2750.7    | 5135.24       |

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
                {value:5, name:'Health'},
                {value:410.64, name:'Shopping'},
                {value:165.16, name:'Utilities'},
                {value:2074.9, name:'Mortgage & Rent'},
                {value:95, name:'Misc'},
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
                {value:5, name:'Pharmacy'},
                {value:410.64, name:'China Ecommerce'},
                {value:70.37, name:'Electricity'},
                {value:56.47, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:6.75, name:'Legal'},
                {value:15.49, name:'Television'},
                {value:1650.46, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:95, name:'Annual'},
            ]
        }
    ]
};
{% endecharts %}