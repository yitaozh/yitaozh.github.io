---
title: Bookkeeping - 2025/07
date: 2025-10-24 23:28:25
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 25      | Income          | 850     |
| Deposit               | 825     | Income          |         |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 948.01  | Food            | 1736.98 |
| Cake & Bread          | 249.9   | Food            |         |
| Bubble Tea            | 481.23  | Food            |         |
| Groceries             | 57.84   | Food            |         |
| Pharmacy              | 39.22   | Health          | 39.22   |
| Clothing              | 120.09  | Shopping        | 1750.68 |
| Hair & Skin           | 35      | Shopping        |         |
| Home Improvement      | 1368.47 | Shopping        |         |
| Electronics           | 110.14  | Shopping        |         |
| Office                | 24      | Shopping        |         |
| Entertainment         | 92.98   | Shopping        |         |
| Electricity           | 89.99   | Utilities       | 957.27  |
| Gas                   | 69.13   | Utilities       |         |
| Phone Bill            | 108.42  | Utilities       |         |
| VPN                   | 4.84    | Utilities       |         |
| Network               | 38      | Utilities       |         |
| Supply                | 300.33  | Utilities       |         |
| Auto                  | 120.69  | Utilities       |         |
| Transportation        | 225.87  | Utilities       |         |
| Mortgage              | 1573.87 | Mortgage & Rent | 1998.31 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Ride Share/Car Rental | 268.48  | Travel          | 654.72  |
| Hotel                 | 179.35  | Travel          |         |
| Ticket                | 169.34  | Travel          |         |
| Souvenir              | 37.55   | Travel          |         |
| Transfer              | 292.92  | Misc            | 387.92  |
| Annual                | 95      | Misc            |         |

### Balance

| Income | Spending | Balance  |
| ------ | -------- | -------- |
| 850    | 7525.1   | \-6675.1 |

### More than $10,000

| Item          | Type      | Amount |
| ------------- | --------- | ------ |
|China          | Deposit   | 9,990  |

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
        data: [
            "Food", "Health", "Shopping", "Utilities", "Mortgage & Rent", "Travel", "Misc", "Restaurants", "Cake & Bread", "Bubble Tea", "Groceries", "Pharmacy", "Clothing", "Hair & Skin", "Home Improvement", "Electronics", "Office", "Entertainment", "Electricity", "Gas", "Phone Bill", "VPN", "Network", "Supply", "Auto", "Transportation", "Mortgage", "HOA", "Air", "Ride Share/Car Rental", "Hotel", "Ticket", "Souvenir", "Transfer", "Annual"
        ]
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
                {value:1736.98, name:'Food'},
                {value:39.22, name:'Health'},
                {value:1750.68, name:'Shopping'},
                {value:957.27, name:'Utilities'},
                {value:1998.31, name:'Mortgage & Rent'},
                {value:654.72, name:'Travel'},
                {value:387.92, name:'Misc'}
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
            data:
            [
                { "value": 948.01, "name": "Restaurants" },
                { "value": 249.9, "name": "Cake & Bread" },
                { "value": 481.23, "name": "Bubble Tea" },
                { "value": 57.84, "name": "Groceries" },
                { "value": 39.22, "name": "Pharmacy" },
                { "value": 120.09, "name": "Clothing" },
                { "value": 35, "name": "Hair & Skin" },
                { "value": 1368.47, "name": "Home Improvement" },
                { "value": 110.14, "name": "Electronics" },
                { "value": 24, "name": "Office" },
                { "value": 92.98, "name": "Entertainment" },
                { "value": 89.99, "name": "Electricity" },
                { "value": 69.13, "name": "Gas" },
                { "value": 108.42, "name": "Phone Bill" },
                { "value": 4.84, "name": "VPN" },
                { "value": 38, "name": "Network" },
                { "value": 300.33, "name": "Supply" },
                { "value": 120.69, "name": "Auto" },
                { "value": 225.87, "name": "Transportation" },
                { "value": 1573.87, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 268.48, "name": "Ride Share/Car Rental" },
                { "value": 179.35, "name": "Hotel" },
                { "value": 169.34, "name": "Ticket" },
                { "value": 37.55, "name": "Souvenir" },
                { "value": 292.92, "name": "Transfer" },
                { "value": 95, "name": "Annual" }
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
        bottom: 100
    },
    xAxis:  {
        type: 'value'
    },
    yAxis: {
        type: 'category',
        data: ['2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07']
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
            data: [1257.02, 993.69, 422.35, 271.3, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28, 2332.98, 1736.98]
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
            data: [135.15, 93.79, 0, 0, 63.72, 119.41, 118.17, 76.14, 111.22, 39.47, 676.15, 39.22]
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
            data: [2311.23, 84.26, 213.73, 214.14, 461, 346.92, 620.42, 569.63, 520.96, 1070.06, 1641.02, 1750.68]
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
            data: [1828.68, 149.44, 300.78, 252.05, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41, 876.54, 957.27]
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
            data: [2225.07, 2225.07, 2225.07, 1573.87, 1573.87, 2847.19, 1998.31, 1998.31, 1998.31, 1998.31, 1998.31, 1998.31]
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
            data: [1203.15, 472.92, 31.34, 187.73, 297.44, 95.31, 86.15, 0, 75.91, 0, 2948.54, 654.72]
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
            data: [5, 0, 99, 160, 146, 100, 0, 332, 2105, 100, 0, 387.92]
        }
    ]
}
{% endecharts %}

#### Detailed analysis(only the months fully in U.S.)

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
            data: ['2024/06','2024/07','2024/08','2024/09','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07']
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
            data: [1569.95, 1773.14, 1257.02, 993.69, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28, 2332.98, 1736.98],
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
                }]
            }
        },
        {
            name:'Shopping',
            type:'bar',
            data: [969.97, 679.74, 2311.23, 84.26, 461, 346.92, 620.42, 569.63, 520.96, 1070.06, 1641.02, 1750.68],
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
                    }
                ]
            }
        },
        {
            name:'Utilities',
            type:'bar',
            data: [326.58, 403.04, 1828.68, 149.44, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41, 876.54, 957.27],
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

#### Balance

{% echarts %}
{
    tooltip: {
        trigger: 'axis'
    },
    legend: {
        data: ['Income', 'Spending'],
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
    xAxis: {
        type : 'category',
        data: ['2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07']
    },
    yAxis: {
        type : 'value'
    },
    grid: {
        bottom: 100
    },
    series: [
        {
            name: 'Income',
            type: 'bar',
            stack: 'one',
            emphasis: {
                itemStyle: {
                    shadowBlur: 10,
                    shadowColor: 'rgba(0,0,0,0.3)'
                }
            },
            label: {
                normal: {
                    show: true,
                    position: 'top'
                }
            },
            data: [8359.88, 6763.34, 5104.3, 6894.32, 9230.67, 6728.63, 4443.91, 4414.23, 4439.6, 4714.94, 3186.82, 850],
        },
        {
            name: 'Spending',
            type: 'bar',
            stack: 'one',
            emphasis: {
                itemStyle: {
                    shadowBlur: 10,
                    shadowColor: 'rgba(0,0,0,0.3)'
                }
            },
            label: {
                normal: {
                    show: true,
                    position: 'insideBottom'
                }
            },
            data: [-8965.3, -4019.17, -3292.27, -8509.09, -4386.19, -6012.6, -6179.08, -5317.77, -6738.52, -5503.53, -10473.54, -7525.1],
        }
    ]
};
{% endecharts %}

{% echarts %}
{
    tooltip: {
        trigger: 'axis',
    },
    legend: {
        data: ['Balance']
    },
    xAxis: [
        {
            type: 'category',
            data: ['2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07']
        }
    ],
    yAxis: [
        {
            type: 'value'
        }
    ],
    grid: {
        bottom: 100
    },
    series: [
        {
            name: 'Balance',
            type: 'bar',
            stack: 'Total',
            areaStyle: {},
            emphasis: {
                focus: 'series'
            },
            label: {
                normal: {
                    show: true,
                    position: 'top'
                }
            },
            data: [-605.42, 2744.17, 1812.03, -1614.77, 4844.48, 716.03, -1735.17, -903.54, -2298.92, -788.59, -7286.72, -6675.1]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
