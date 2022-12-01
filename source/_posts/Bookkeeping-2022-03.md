---
title: Bookkeeping - 2022/03
date: 2022-12-01 12:09:49
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 3354.52 |
| Federal Tax      | 2535    |
| State Tax        | 401     |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 513.79  | Food            | 1207.9  |
| Cake & Bread     | 168.67  | Food            | 0       |
| Bubble Tea       | 279.94  | Food            | 0       |
| Groceries        | 245.5   | Food            | 0       |
| Medical          | 287.21  | Health          | 314.53  |
| Eyecare          | 10      | Health          | 0       |
| Pharmacy         | 17.32   | Health          | 0       |
| Clothing         | 994.52  | Shopping        | 4351.15 |
| Hair & Skin      | 56.34   | Shopping        | 0       |
| Home Improvement | 87.54   | Shopping        | 0       |
| Electronics      | 112.41  | Shopping        | 0       |
| Office           | 52.05   | Shopping        | 0       |
| Marriage         | 3048.29 | Shopping        | 0       |
| Electricity      | 89.78   | Utilities       | 444.48  |
| Gas              | 280.38  | Utilities       | 0       |
| Phone Bill       | 3.13    | Utilities       | 0       |
| Legal            | 6.75    | Utilities       | 0       |
| Supply           | 50.45   | Utilities       | 0       |
| Television       | 13.99   | Utilities       | 0       |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent | 0       |
| Air              | 257.2   | Travel          | 308.18  |
| Ride Share       | 50.98   | Travel          | 0       |
| Cash & ATM       | 800     | Misc            | 1015    |
| Transfer         | 1       | Misc            | 0       |
| Annual           | 214     | Misc            | 0       |
| Paycheck         | 3354.52 | Income          | 6290.52 |
| Federal Tax      | 2535    | Income          | 0       |
| State Tax        | 401     | Income          | 0       |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 6290.52   | 9461.6    | -3293.23      |

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
        'Groceries','Medical','Eyecare','Pharmacy','Clothing','Hair & Skin','Home Improvement','Office','Marriage','Electricity',
        'Gas','Phone Bill','Legal','Supply','Television','Mortgage','HOA','Air','Ride Share','Cash & ATM','Transfer','Annual']
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
                {value:1207.9, name:'Food'},
                {value:314.53, name:'Health'},
                {value:4351.15, name:'Shopping'},
                {value:444.48, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:308.18, name:'Travel'},
                {value:1015, name:'Misc'},
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
                {value:513.79, name:'Restaurants'},
                {value:168.67, name:'Cake & Bread'},
                {value:279.94, name:'Bubble Tea'},
                {value:245.5, name:'Groceries'},
                {value:287.21, name:'Medical'},
                {value:10, name:'Eyecare'},
                {value:17.32, name:'Pharmacy'},
                {value:994.52, name:'Clothing'},
                {value:56.34, name:'Hair & Skin'},
                {value:87.54, name:'Home Improvement'},
                {value:112.41, name:'Electronics'},
                {value:52.05, name:'Office'},
                {value:3048.29, name:'Marriage'},
                {value:89.78, name:'Electricity'},
                {value:280.38, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:50.45, name:'Supply'},
                {value:13.99, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:257.2, name:'Air'},
                {value:50.98, name:'Ride Share'},
                {value:800, name:'Cash & ATM'},
                {value:1, name:'Transfer'},
                {value:214, name:'Annual'},
            ]
        }
    ]
};
{% endecharts %}