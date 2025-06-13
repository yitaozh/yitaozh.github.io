---
title: Bookkeeping - 2024/08
date: 2025-06-13 17:57:43
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 8261.59 | Income          | 8359.88 |
| Deposit               | 98.29   | Income          |         |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 360.98  | Food            | 1257.02 |
| Cake & Bread          | 54.95   | Food            |         |
| Bubble Tea            | 296.01  | Food            |         |
| Groceries             | 545.08  | Food            |         |
| Pharmacy              | 135.15  | Health          | 135.15  |
| Clothing              | 52.06   | Shopping        | 2311.23 |
| Hair & Skin           | 40      | Shopping        |         |
| Home Improvement      | 111.71  | Shopping        |         |
| Office                | 2070    | Shopping        |         |
| Entertainment         | 37.46   | Shopping        |         |
| Electricity           | 174.77  | Utilities       | 1828.68 |
| Gas                   | 41.54   | Utilities       |         |
| Phone Bill            | 0.32    | Utilities       |         |
| VPN                   | 5       | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 64.96   | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 1491.6  | Utilities       |         |
| Mortgage              | 1800.63 | Mortgage & Rent | 2225.07 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Air                   | 763.8   | Travel          | 1203.15 |
| Hotel                 | 419.35  | Travel          |         |
| Ticket                | 20      | Travel          |         |
| Annual                | 5       | Misc            | 5       |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 8359.88 | 8965.3   | \-605.42 |

### More than $10,000

| Item          | Type  | Amount |
| ------------- | ----- | ------ |
| N/A           | N/A   | N/A    |

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
            'Food', 'Health', 'Shopping', 'Utilities', 'Mortgage & Rent', 'Travel', 'Misc', 'Restaurants', 'Cake & Bread', 'Bubble Tea', 'Groceries', 'Pharmacy', 'Clothing', 'Hair & Skin', 'Home Improvement', 'Office', 'Entertainment', 'Electricity', 'Gas', 'Phone Bill', 'VPN', 'Network', 'Supply', 'Television', 'Auto', 'Mortgage', 'HOA', 'Air', 'Hotel', 'Ticket', 'Annual'
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
                {value:1257.02, name:'Food'},
                {value:135.15, name:'Health'},
                {value:2311.23, name:'Shopping'},
                {value:1828.68, name:'Utilities'},
                {value:2225.07, name:'Mortgage & Rent'},
                {value:1203.15, name:'Travel'},
                {value:5, name:'Misc'}
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
                { "value": 360.98, "name": "Restaurants" },
                { "value": 54.95, "name": "Cake & Bread" },
                { "value": 296.01, "name": "Bubble Tea" },
                { "value": 545.08, "name": "Groceries" },
                { "value": 135.15, "name": "Pharmacy" },
                { "value": 52.06, "name": "Clothing" },
                { "value": 40, "name": "Hair & Skin" },
                { "value": 111.71, "name": "Home Improvement" },
                { "value": 2070, "name": "Office" },
                { "value": 37.46, "name": "Entertainment" },
                { "value": 174.77, "name": "Electricity" },
                { "value": 41.54, "name": "Gas" },
                { "value": 0.32, "name": "Phone Bill" },
                { "value": 5, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 64.96, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 1491.6, "name": "Auto" },
                { "value": 1800.63, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 763.8, "name": "Air" },
                { "value": 419.35, "name": "Hotel" },
                { "value": 20, "name": "Ticket" },
                { "value": 5, "name": "Annual" }
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
        data: ['2023/9','2023/10','2023/11','2023/12','2024/1','2024/2','2024/3','2024/4','2024/5','2024/6','2024/7','2024/8']
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
            data: [1383.72, 1400.12, 908.48, 477.28, 302.13, 0, 751.72, 1324.58, 1372.49, 1569.95, 1773.14, 1257.02]
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
            data: [0, 14.28, 12.74, 0, 67.96, 0, 7.21, 20.74, 0, 0, 0, 135.15]
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
            data: [816.04, 772.85, 729.09, 3055.76, 72.09, 2231.5, 226.12, 919.23, 602.33, 969.97, 679.74, 2311.23]
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
            data: [539.88, 473.06, 313.29, 391.88, 380.43, 1763.79, 324.66, 440.6, 954.16, 326.58, 403.04, 1828.68]
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
            data: [2096.97, 1672.53, 2230.13, 1381.25, 2230.13, 1381.25, 2230.13, 1800.63, 1800.63, 3073.95, 2225.07, 2225.07]
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
            data: [3155.32, 509.47, 30.81, 0, 18.79, 3776.05, 68.65, 18.43, 264.36, 366.38, 4838.74, 1203.15]
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
            data: [182.98, 60, 0, 0, 0, 0, 234, 126.56, 0, 201.84, 165, 5]
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
            data: ['2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/04','2024/05','2024/06','2024/07','2024/08']
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
            data: [932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 1324.58, 1372.49, 1569.95, 1773.14, 1257.02],
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
            data: [1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 919.23, 602.33, 969.97, 679.74, 2311.23],
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
            data: [109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 440.6, 954.16, 326.58, 403.04, 1828.68],
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
        data: ['2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07','2024/08']
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
            data: [8202.3, 5736.6, 5927.86, 8512.78, 4559.31, 4455.21, 6636.52, 4439.64, 4992.19, 4632.13, 4801.54, 8359.88],
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
            data: [-8174.91, -4902.31, -4224.54, -11803.17, -3071.53, -9152.59, -3842.49, -4650.77, -4993.97, -6508.67, -11234.73, -8965.3],
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
            data: ['2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07','2024/08']
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
            data: [27.39, 834.29, 1703.32, -3290.39, 1487.78, -4697.38, 2794.03, -211.13, -1.78, -1876.54, -6433.19, -605.42]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
