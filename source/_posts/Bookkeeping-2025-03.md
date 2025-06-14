---
title: Bookkeeping - 2025/03
date: 2025-06-14 17:42:44
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4414.23 | Income          | 4414.23 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 567.86  | Food            | 1674.85 |
| Cake & Bread          | 145.75  | Food            |         |
| Bubble Tea            | 409.33  | Food            |         |
| Groceries             | 551.91  | Food            |         |
| Medical               | 39      | Health          | 76.14   |
| Pharmacy              | 37.14   | Health          |         |
| Clothing              | 312.7   | Shopping        | 569.63  |
| Hair & Skin           | 27.75   | Shopping        |         |
| Home Improvement      | 95.22   | Shopping        |         |
| Office                | 113.86  | Shopping        |         |
| Entertainment         | 20.1    | Shopping        |         |
| Electricity           | 105.05  | Utilities       | 666.84  |
| Gas                   | 403.28  | Utilities       |         |
| Phone Bill            | 0.6     | Utilities       |         |
| VPN                   | 4.52    | Utilities       |         |
| Network               | 38      | Utilities       |         |
| Supply                | 78.82   | Utilities       |         |
| Auto                  | 36.57   | Utilities       |         |
| Mortgage              | 1573.87 | Mortgage & Rent | 1998.31 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Cash & ATM            | 332     | Misc            | 332     |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 4414.23 | 5317.77  | \-903.54 |

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
            "Food", "Health", "Shopping", "Utilities", "Mortgage & Rent", "Misc",
            "Restaurants", "Cake & Bread", "Bubble Tea", "Groceries",
            "Medical", "Pharmacy", "Clothing", "Hair & Skin", "Home Improvement", "Office", "Entertainment",
            "Electricity", "Gas", "Phone Bill", "VPN", "Network", "Supply", "Auto",
            "Mortgage", "HOA", "Cash & ATM"
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
                {value:1674.85, name:'Food'},
                {value:76.14, name:'Health'},
                {value:569.63, name:'Shopping'},
                {value:666.84, name:'Utilities'},
                {value:1998.31, name:'Mortgage & Rent'},
                {value:332, name:'Misc'}
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
                { "value": 567.86, "name": "Restaurants" },
                { "value": 145.75, "name": "Cake & Bread" },
                { "value": 409.33, "name": "Bubble Tea" },
                { "value": 551.91, "name": "Groceries" },
                { "value": 39, "name": "Medical" },
                { "value": 37.14, "name": "Pharmacy" },
                { "value": 312.7, "name": "Clothing" },
                { "value": 27.75, "name": "Hair & Skin" },
                { "value": 95.22, "name": "Home Improvement" },
                { "value": 113.86, "name": "Office" },
                { "value": 20.1, "name": "Entertainment" },
                { "value": 105.05, "name": "Electricity" },
                { "value": 403.28, "name": "Gas" },
                { "value": 0.6, "name": "Phone Bill" },
                { "value": 4.52, "name": "VPN" },
                { "value": 38, "name": "Network" },
                { "value": 78.82, "name": "Supply" },
                { "value": 36.57, "name": "Auto" },
                { "value": 1573.87, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 332, "name": "Cash & ATM" }
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
        data: ['2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03']
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
            data: [1324.58, 1372.49, 1569.95, 1773.14, 1257.02, 993.69, 422.35, 271.3, 1590.69, 1895.38, 1402.14, 1674.85]
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
            data: [20.74, 0, 0, 0, 135.15, 93.79, 0, 0, 63.72, 119.41, 118.17, 76.14]
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
            data: [919.23, 602.33, 969.97, 679.74, 2311.23, 84.26, 213.73, 214.14, 461, 346.92, 620.42, 569.63]
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
            data: [440.6, 954.16, 326.58, 403.04, 1828.68, 149.44, 300.78, 252.05, 253.47, 608.39, 1953.89, 666.84]
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
            data: [1800.63, 1800.63, 3073.95, 2225.07, 2225.07, 2225.07, 2225.07, 1573.87, 1573.87, 2847.19, 1998.31, 1998.31]
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
            data: [18.43, 264.36, 366.38, 4838.74, 1203.15, 472.92, 31.34, 187.73, 297.44, 95.31, 86.15, 0]
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
            data: [126.56, 0, 201.84, 165, 5, 0, 99, 160, 146, 100, 0, 332]
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
            data: ['2023/11','2023/12','2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/12','2025/01','2025/02','2025/03']
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
            data: [908.48, 477.28, 1324.58, 1372.49, 1569.95, 1773.14, 1257.02, 993.69, 1590.69, 1895.38, 1402.14, 1674.85],
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
            data: [729.09, 3055.76, 919.23, 602.33, 969.97, 679.74, 2311.23, 84.26, 461, 346.92, 620.42, 569.63],
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
            data: [313.29, 391.88, 440.6, 954.16, 326.58, 403.04, 1828.68, 149.44, 253.47, 608.39, 1953.89, 666.84],
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
        data: ['2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03']
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
            data: [4439.64, 4992.19, 4632.13, 4801.54, 8359.88, 6763.34, 5104.3, 6894.32, 9230.67, 6728.63, 4443.91, 4414.23],
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
            data: [-4650.77, -4993.97, -6508.67, -11234.73, -8965.3, -4019.17, -3292.27, -8509.09, -4386.19, -6012.6, -6179.08, -5317.77],
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
            data: ['2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12','2025/01','2025/02','2025/03']
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
            data: [-211.13, -1.78, -1876.54, -6433.19, -605.42, 2744.17, 1812.03, -1614.77, 4844.48, 716.03, -1735.17, -903.54]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
