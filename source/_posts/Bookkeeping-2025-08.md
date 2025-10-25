---
title: Bookkeeping - 2025/08
date: 2025-10-24 23:42:47
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum      | Section         | Sum     |
| --------------------- | -------- | --------------- | ------- |
| Paycheck              | 25003.22 | Income          | 26590.4 |
| Deposit               | 1587.18  | Income          |         |

### Spending

| Category              | Sum      | Section         | Sum     |
| --------------------- | -------- | --------------- | ------- |
| Restaurants           | 569.5    | Food            | 1502.72 |
| Cake & Bread          | 160.24   | Food            |         |
| Bubble Tea            | 487.87   | Food            |         |
| Groceries             | 285.11   | Food            |         |
| Pharmacy              | 22.1     | Health          | 22.1    |
| Clothing              | 113.8    | Shopping        | 2860.59 |
| Home Improvement      | 2614.6   | Shopping        |         |
| Electronics           | 55.09    | Shopping        |         |
| Office                | 29.33    | Shopping        |         |
| Entertainment         | 47.77    | Shopping        |         |
| Electricity           | 167.67   | Utilities       | 1636.37 |
| Gas                   | 62.71    | Utilities       |         |
| Phone Bill            | 103.17   | Utilities       |         |
| VPN                   | 5        | Utilities       |         |
| Network               | 45.84    | Utilities       |         |
| Supply                | 421.3    | Utilities       |         |
| Auto                  | 748.93   | Utilities       |         |
| Transportation        | 81.75    | Utilities       |         |
| Mortgage              | 1573.87  | Mortgage & Rent | 8960.34 |
| HOA                   | 424.44   | Mortgage & Rent |         |
| Rent                  | 6962.03  | Mortgage & Rent |         |
| Air                   | 932.6    | Travel          | 932.6   |
| Cash & ATM            | 100      | Misc            | 100     |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 26590.4 | 16014.72 | 10575.68 |

### More than $10,000

| Item   | Type     | Amount   |
| ------ | -------- | -------- |
| SignOn | Paycheck | 38102.27 |

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
            "Food", "Health", "Shopping", "Utilities", "Mortgage & Rent", "Travel", "Misc", "Restaurants", "Cake & Bread", "Bubble Tea", "Groceries", "Pharmacy", "Clothing", "Home Improvement", "Electronics", "Office", "Entertainment", "Electricity", "Gas", "Phone Bill", "VPN", "Network", "Supply", "Auto", "Transportation", "Mortgage", "HOA", "Rent", "Air", "Cash & ATM"
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
                {value:1502.72, name:'Food'},
                {value:22.1, name:'Health'},
                {value:2860.59, name:'Shopping'},
                {value:1636.37, name:'Utilities'},
                {value:8960.34, name:'Mortgage & Rent'},
                {value:932.6, name:'Travel'},
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
            data:
            [
                { "value": 569.5, "name": "Restaurants" },
                { "value": 160.24, "name": "Cake & Bread" },
                { "value": 487.87, "name": "Bubble Tea" },
                { "value": 285.11, "name": "Groceries" },
                { "value": 22.1, "name": "Pharmacy" },
                { "value": 113.8, "name": "Clothing" },
                { "value": 2614.6, "name": "Home Improvement" },
                { "value": 55.09, "name": "Electronics" },
                { "value": 29.33, "name": "Office" },
                { "value": 47.77, "name": "Entertainment" },
                { "value": 167.67, "name": "Electricity" },
                { "value": 62.71, "name": "Gas" },
                { "value": 103.17, "name": "Phone Bill" },
                { "value": 5, "name": "VPN" },
                { "value": 45.84, "name": "Network" },
                { "value": 421.3, "name": "Supply" },
                { "value": 748.93, "name": "Auto" },
                { "value": 81.75, "name": "Transportation" },
                { "value": 1573.87, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 6962.03, "name": "Rent" },
                { "value": 932.6, "name": "Air" },
                { "value": 100, "name": "Cash & ATM" }
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
        data: ['2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07','2025/08']
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
            data: [993.69, 422.35, 271.3, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28, 2332.98, 1736.98, 1502.72]
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
            data: [93.79, 0, 0, 63.72, 119.41, 118.17, 76.14, 111.22, 39.47, 676.15, 39.22, 22.1]
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
            data: [84.26, 213.73, 214.14, 461, 346.92, 620.42, 569.63, 520.96, 1070.06, 1641.02, 1750.68, 2860.59]
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
            data: [149.44, 300.78, 252.05, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41, 876.54, 957.27, 1636.37]
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
            data: [2225.07, 2225.07, 1573.87, 1573.87, 2847.19, 1998.31, 1998.31, 1998.31, 1998.31, 1998.31, 1998.31, 8960.34]
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
            data: [472.92, 31.34, 187.73, 297.44, 95.31, 86.15, 0, 75.91, 0, 2948.54, 654.72, 932.6]
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
            data: [0, 99, 160, 146, 100, 0, 332, 2105, 100, 0, 387.92, 100]
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
            data: ['2024/07','2024/08','2024/09','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07','2025/08']
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
            data: [1773.14, 1257.02, 993.69, 1590.69, 1895.38, 1402.14, 1674.85, 1412.3, 1683.28, 2332.98, 1736.98, 1502.72],
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
            data: [679.74, 2311.23, 84.26, 461, 346.92, 620.42, 569.63, 520.96, 1070.06, 1641.02, 1750.68, 2860.59],
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
            data: [403.04, 1828.68, 149.44, 253.47, 608.39, 1953.89, 666.84, 514.82, 612.41, 876.54, 957.27, 1636.37],
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
        data: ['2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07','2025/08']
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
            data: [6763.34, 5104.3, 6894.32, 9230.67, 6728.63, 4443.91, 4414.23, 4439.6, 4714.94, 3186.82, 850, 26590.4],
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
            data: [-4019.17, -3292.27, -8509.09, -4386.19, -6012.6, -6179.08, -5317.77, -6738.52, -5503.53, -10473.54, -7525.1, -16014.72],
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
            data: ['2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03','2025/04','2025/05','2025/06','2025/07','2025/08']
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
            data: [-605.42, 2744.17, 1812.03, -1614.77, 4844.48, 716.03, -1735.17, -903.54, -2298.92, -788.59, -7286.72, -6675.1, 10575.68]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
