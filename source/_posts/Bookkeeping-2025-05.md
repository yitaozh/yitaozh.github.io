---
title: Bookkeeping - 2025/05
date: 2025-10-24 22:28:22
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4714.94 | Income          | 5503.53 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 811.94  | Food            | 1683.28 |
| Cake & Bread          | 122.98  | Food            |         |
| Bubble Tea            | 402.63  | Food            |         |
| Groceries             | 345.73  | Food            |         |
| Pharmacy              | 39.47   | Health          | 39.47   |
| Clothing              | 288.99  | Shopping        | 1070.06 |
| Hair & Skin           | 45.67   | Shopping        |         |
| Home Improvement      | 40.48   | Shopping        |         |
| China Ecommerce       | 431.69  | Shopping        |         |
| Office                | 245.24  | Shopping        |         |
| Entertainment         | 17.99   | Shopping        |         |
| Electricity           | 56.41   | Utilities       | 612.41  |
| Gas                   | 209.71  | Utilities       |         |
| Phone Bill            | 50.3    | Utilities       |         |
| VPN                   | 4.84    | Utilities       |         |
| Network               | 38      | Utilities       |         |
| Supply                | 65.22   | Utilities       |         |
| Auto                  | 59.98   | Utilities       |         |
| Transportation        | 127.95  | Utilities       |         |
| Mortgage              | 1573.87 | Mortgage & Rent | 1998.31 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Cash & ATM            | 100     | Misc            | 100     |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 4714.94 | 5503.53  | \-788.59 |

### More than $10,000

| Item          | Type      | Amount |
| ------------- | --------- | ------ |
| N/A           | N/A       | N/A    |

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
            "Food", "Health", "Shopping", "Utilities", "Mortgage & Rent", "Misc", "Restaurants", "Cake & Bread", "Bubble Tea", "Groceries", "Pharmacy", "Clothing", "Hair & Skin", "Home Improvement", "China Ecommerce", "Office", "Entertainment", "Electricity", "Gas", "Phone Bill", "VPN", "Network", "Supply", "Auto", "Transportation", "Mortgage", "HOA", "Cash & ATM"
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
                {value:1683.28, name:'Food'},
                {value:39.47, name:'Health'},
                {value:1070.06, name:'Shopping'},
                {value:612.41, name:'Utilities'},
                {value:1998.31, name:'Mortgage & Rent'},
                {value:100, name:'Misc'}
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
                { "value": 811.94, "name": "Restaurants" },
                { "value": 122.98, "name": "Cake & Bread" },
                { "value": 402.63, "name": "Bubble Tea" },
                { "value": 345.73, "name": "Groceries" },
                { "value": 39.47, "name": "Pharmacy" },
                { "value": 288.99, "name": "Clothing" },
                { "value": 45.67, "name": "Hair & Skin" },
                { "value": 40.48, "name": "Home Improvement" },
                { "value": 431.69, "name": "China Ecommerce" },
                { "value": 245.24, "name": "Office" },
                { "value": 17.99, "name": "Entertainment" },
                { "value": 56.41, "name": "Electricity" },
                { "value": 209.71, "name": "Gas" },
                { "value": 50.3, "name": "Phone Bill" },
                { "value": 4.84, "name": "VPN" },
                { "value": 38, "name": "Network" },
                { "value": 65.22, "name": "Supply" },
                { "value": 59.98, "name": "Auto" },
                { "value": 127.95, "name": "Transportation" },
                { "value": 1573.87, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 100, "name": "Cash & ATM" },
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
        data: ['2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05']
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
            data: [1569.95, 1773.14, 1257.02, 993.69, 422.35, 271.3, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28]
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
            data: [0, 0, 135.15, 93.79, 0, 0, 63.72, 119.41, 118.17, 76.14, 111.22, 39.47]
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
            data: [969.97, 679.74, 2311.23, 84.26, 213.73, 214.14, 461, 346.92, 620.42, 569.63, 520.96, 1070.06]
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
            data: [326.58, 403.04, 1828.68, 149.44, 300.78, 252.05, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41]
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
            data: [3073.95, 2225.07, 2225.07, 2225.07, 2225.07, 1573.87, 1573.87, 2847.19, 1998.31, 1998.31, 1998.31, 1998.31]
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
            data: [366.38, 4838.74, 1203.15, 472.92, 31.34, 187.73, 297.44, 95.31, 86.15, 0, 75.91, 0]
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
            data: [201.84, 165, 5, 0, 99, 160, 146, 100, 0, 332, 2105, 100]
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
            data: ['2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05']
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
            data: [1324.58, 1372.49, 1569.95, 1773.14, 1257.02, 993.69, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28],
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
            data: [919.23, 602.33, 969.97, 679.74, 2311.23, 84.26, 461, 346.92, 620.42, 569.63, 520.96, 1070.06],
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
            data: [440.6, 954.16, 326.58, 403.04, 1828.68, 149.44, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41],
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
        data: ['2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05']
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
                    position: 'insideTop'
                }
            },
            data: [4632.13, 4801.54, 8359.88, 6763.34, 5104.3, 6894.32, 9230.67, 6728.63, 4443.91, 4414.23, 4439.6, 4714.94],
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
            data: [-6508.67, -11234.73, -8965.3, -4019.17, -3292.27, -8509.09, -4386.19, -6012.6, -6179.08, -5317.77, -6738.52, -5503.53],
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
            data: ['2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05']
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
            data: [-1876.54, -6433.19, -605.42, 2744.17, 1812.03, -1614.77, 4844.48, 716.03, -1735.17, -903.54, -2298.92, -788.59]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
