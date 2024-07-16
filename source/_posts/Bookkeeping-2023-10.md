---
title: Bookkeeping - 2023/10
date: 2024-07-16 18:26:45
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 5176.6  |
| Deposit          | 560     |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 422.15  | Food            | 1400.12 |
| Cake & Bread          | 106.03  | Food            |         |
| Bubble Tea            | 482.86  | Food            |         |
| Groceries             | 389.08  | Food            |         |
| Pharmacy              | 14.28   | Health          | 14.28   |
| Clothing              | 99      | Shopping        | 772.85  |
| Hair & Skin           | 87.8    | Shopping        |         |
| Home Improvement      | 36.1    | Shopping        |         |
| Electronics           | 32.9    | Shopping        |         |
| Office                | 99      | Shopping        |         |
| Marriage              | 418.05  | Shopping        |         |
| Electricity           | 84.73   | Utilities       | 473.06  |
| Gas                   | 31.49   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 137.53  | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 165.69  | Utilities       |         |
| Mortgage              | 1672.53 | Mortgage & Rent | 1672.53 |
| Hotel                 | 357.24  | Travel          | 509.47  |
| Ticket                | 70      | Travel          |         |
| Souvenir              | 82.23   | Travel          |         |
| Cash & ATM            | 60      | Misc            | 60      |

### Balance

| Income | Spending | Balance |
| ------ | -------- | ------- |
| 5736.6 | 4902.31  | 834.29  |

### More than $10,000

| Item | Type     | Amount |
| ---- | -------- | ------ |
| Ring | Marriage | 11231  |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Clothing','Hair & Skin','Home Improvement','Electronics','Office','Marriage',
        'Electricity','Gas','Phone Bill','Network','Supply','Television','Auto','Mortgage','Hotel','Ticket','Souvenir',
        'Cash & ATM']
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
                {value:1400.12, name:'Food'},
                {value:14.28, name:'Health'},
                {value:772.85, name:'Shopping'},
                {value:473.06, name:'Utilities'},
                {value:1672.53, name:'Mortgage & Rent'},
                {value:509.47, name:'Travel'},
                {value:60, name:'Misc'}
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
                { "value": 422.15, "name": "Restaurants" },
                { "value": 106.03, "name": "Cake & Bread" },
                { "value": 482.86, "name": "Bubble Tea" },
                { "value": 389.08, "name": "Groceries" },
                { "value": 14.28, "name": "Pharmacy" },
                { "value": 99, "name": "Clothing" },
                { "value": 87.8, "name": "Hair & Skin" },
                { "value": 36.1, "name": "Home Improvement" },
                { "value": 32.9, "name": "Electronics" },
                { "value": 99, "name": "Office" },
                { "value": 418.05, "name": "Marriage" },
                { "value": 84.73, "name": "Electricity" },
                { "value": 31.49, "name": "Gas" },
                { "value": 3.13, "name": "Phone Bill" },
                { "value": 35, "name": "Network" },
                { "value": 137.53, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 165.69, "name": "Auto" },
                { "value": 1672.53, "name": "Mortgage" },
                { "value": 357.24, "name": "Hotel" },
                { "value": 70, "name": "Ticket" },
                { "value": 82.23, "name": "Souvenir" },
                { "value": 60, "name": "Cash & ATM" },
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
        data: ['2022/11','2022/12','2023/1','2023/2','2023/3','2023/4','2023/5','2023/6','2023/7','2023/8','2023/9','2023/10']
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
            data: [1131.3, 1327.16, 1425.44, 971.34, 721.14, 0, 0, 932.43, 1234.85, 1329.06, 1383.72, 1400.12]
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
            data: [102, 36.68, 61.46, 644.06, 142.41, 5, 5, 88.61, 0, 60.43, 0, 14.28]
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
            data: [2341.89, 543.61, 451.83, 158.37, 194.85, 398.71, 373.71, 1711.43, 1056.3, 85.26, 816.04, 772.85]
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
            data: [168.02, 313.81, 609.5, 500.74, 431.22, 414.16, 166.7, 109.35, 308.18, 1886.01, 539.88, 473.06]
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
            data: [2074.9, 2074.9, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 1672.53]
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
            data: [74.52, 61.37, 37, 113.76, 2146.71, 0, 3626.52, 55.31, 457.73, 279.32, 3155.32, 509.47]
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
            data: [77.36, 0, 40, 0, 1361, 0, 0, 15, 95, 465.62, 182.98, 60]
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
            data: ['2022/06','2022/10','2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08','2023/09','2023/10']
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
            data: [979.38, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12],
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
            data: [680.5, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85],
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
            data: [202.03, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01, 539.88, 473.06],
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
