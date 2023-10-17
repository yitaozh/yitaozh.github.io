---
title: Bookkeeping - 2023/09
date: 2023-10-17 16:08:44
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 8202.3  |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 427.02  | Food            | 1383.72 |
| Cake & Bread          | 160.41  | Food            |         |
| Bubble Tea            | 353.61  | Food            |         |
| Groceries             | 442.68  | Food            |         |
| Clothing              | 623.23  | Shopping        | 816.04  |
| Hair & Skin           | 77.42   | Shopping        |         |
| Home Improvement      | 51.94   | Shopping        |         |
| Office                | 19.11   | Shopping        |         |
| Entertainment         | 44.34   | Shopping        |         |
| Electricity           | 93.04   | Utilities       | 539.88  |
| Gas                   | 30.18   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| Network               | 15.65   | Utilities       |         |
| Supply                | 60.22   | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 322.17  | Utilities       |         |
| Mortgage              | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Air                   | 1255.44 | Travel          | 3155.32 |
| Ride share/Car rental | 77.47   | Travel          |         |
| Hotel                 | 1061.28 | Travel          |         |
| Ticket                | 581.78  | Travel          |         |
| Souvenir              | 121.06  | Travel          |         |
| Travel Misc           | 58.29   | Travel          |         |
| Cash & ATM            | 67.98   | Misc            | 182.98  |
| Transfer              | 115     | Misc            |         |

### Balance

| Income | Spending | Balance |
| ------ | -------- | ------- |
| 8202.3 | 8174.91  | 27.39   |

### More than $10,000

N/A

## Chart

### Detailed Spending

{% echarts %}
{
    tooltip: {
        trigger: 'item',
        formatter: "{b}: {c} ({d}%)"
    },
    legend: {
        orient: 'vertical',
        x: 'left',
        data:['Food','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Clothing','Hair & Skin','Home Improvement','Office','Entertainment','Electricity',
        'Gas','Phone Bill','Network','Supply','Television','Auto','Mortgage','HOA','Air','Ride share/Car rental',
        'Hotel','Ticket','Souvenir','Travel Misc','Cash & ATM','Transfer']
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
                {value:1383.72, name:'Food'},
                {value:816.04, name:'Shopping'},
                {value:539.88, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:3155.32, name:'Travel'},
                {value:182.98, name:'Misc'}
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
                { "value": 427.02, "name": "Restaurants" },
                { "value": 160.41, "name": "Cake & Bread" },
                { "value": 353.61, "name": "Bubble Tea" },
                { "value": 442.68, "name": "Groceries" },
                { "value": 623.23, "name": "Clothing" },
                { "value": 77.42, "name": "Hair & Skin" },
                { "value": 51.94, "name": "Home Improvement" },
                { "value": 19.11, "name": "Office" },
                { "value": 44.34, "name": "Entertainment" },
                { "value": 93.04, "name": "Electricity" },
                { "value": 30.18, "name": "Gas" },
                { "value": 3.13, "name": "Phone Bill" },
                { "value": 15.65, "name": "Network" },
                { "value": 60.22, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 322.17, "name": "Auto" },
                { "value": 1672.53, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 1255.44, "name": "Air" },
                { "value": 77.47, "name": "Ride share/Car rental" },
                { "value": 1061.28, "name": "Hotel" },
                { "value": 581.78, "name": "Ticket" },
                { "value": 121.06, "name": "Souvenir" },
                { "value": 58.29, "name": "Travel Misc" },
                { "value": 67.98, "name": "Cash & ATM" },
                { "value": 115, "name": "Transfer" }
            ]
        }
    ]
};
{% endecharts %}

### Spending Trend

#### Trend of all categories

{% echarts %}
{
    tooltip : {
        trigger: 'axis',
        axisPointer : {            // 坐标轴指示器，坐标轴触发有效
            type : 'shadow'        // 默认为直线，可选为：'line' | 'shadow'
        }
    },
    legend: {
        data: ['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc']
    },
    grid: {
        left: '3%',
        right: '4%',
        bottom: '3%',
        containLabel: true
    },
    xAxis:  {
        type: 'value'
    },
    yAxis: {
        type: 'category',
        data: ['2022/10','2022/11','2022/12','2023/1','2023/2','2023/3','2023/4','2023/5','2023/6','2023/7','2023/8','2023/9']
    },
    series: [
        {
            name: 'Food',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 0, 0, 932.43, 1234.85, 1329.06, 1383.72]
        },
        {
            name: 'Health',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [22.31, 102, 36.68, 61.46, 644.06, 142.41, 5, 5, 88.61, 0, 60.43, 0]
        },
        {
            name: 'Shopping',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 398.71, 373.71, 1711.43, 1056.3, 85.26, 816.04]
        },
        {
            name: 'Utilities',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 414.16, 166.7, 109.35, 308.18, 1886.01, 539.88]
        },
        {
            name: 'Mortgage & Rent',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [2074.9, 2074.9, 2074.9, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97]
        },
        {
            name: 'Travel',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [46.64, 74.52, 61.37, 37, 113.76, 2146.71, 0, 3626.52, 55.31, 457.73, 279.32, 3155.32]
        },
        {
            name: 'Misc',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: true,
                    position: 'right',
                    formatter: function(params) {
                        let val=0;
                        this.option.series.forEach(s => {
                            val+=s.data[params.dataIndex];
                        } );
                        return parseFloat(val).toFixed(2);
                    }
                }
            },
            data: [100, 77.36, 0, 40, 0, 1361, 0, 0, 15, 95, 465.62, 182.98]
        }
    ]
}
{% endecharts %}

#### Detailed analysis

{% echarts %}
{
    tooltip : {
        trigger: 'axis'
    },
    legend: {
        data:['Food','Shopping','Utilities']
    },
    toolbox: {
        show : true,
        feature : {
            dataView : {show: true, readOnly: false},
            magicType : {show: true, type: ['line', 'bar']},
            restore : {show: true},
            saveAsImage : {show: true}
        }
    },
    calculable : true,
    xAxis : [
        {
            type : 'category',
            data: ['2022/05','2022/06','2022/10','2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08','2023/09']
        }
    ],
    yAxis : [
        {
            type : 'value'
        }
    ],
    series : [
        {
            name:'Food',
            type:'bar',
            data: [1543.5, 979.38, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72],
            markPoint : {
                data : [
                    {type : 'max', name: '最大值'},
                    {type : 'min', name: '最小值'}
                ]
            },
            markLine : {
                data : [
                {
                    type : 'average',
                    name : '平均值',
                    label : {
                        normal: {
                            position: 'left',
                        }
                    }
                }]
            }
        },
        {
            name:'Shopping',
            type:'bar',
            data: [1470.26, 680.5, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04],
            markPoint : {
                data : [
                    {type : 'max', name: '最大值'},
                    {type : 'min', name: '最小值'}
                ]
            },
            markLine : {
                data : [
                    {type : 'average', name : '平均值'}
                ]
            }
        },
        {
            name:'Utilities',
            type:'bar',
            data: [315.63, 202.03, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01, 539.88],
            markPoint : {
                data : [
                    {type : 'max', name: '最大值'},
                    {type : 'min', name: '最小值'}
                ]
            },
            markLine : {
                data : [
                    {type : 'average', name : '平均值'}
                ]
            }
        }
    ]
};
{% endecharts %}
