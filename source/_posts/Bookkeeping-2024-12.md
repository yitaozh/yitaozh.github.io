---
title: Bookkeeping - 2024/12
date: 2025-06-14 17:02:19
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 9127.17 | Income          | 9230.67 |
| Deposit               | 103.5   | Income          |         |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 587.11  | Food            | 1590.69 |
| Cake & Bread          | 189.57  | Food            |         |
| Bubble Tea            | 288.79  | Food            |         |
| Groceries             | 525.22  | Food            |         |
| Dental                | 57.01   | Health          | 63.72   |
| Pharmacy              | 6.71    | Health          |         |
| Hair & Skin           | 206.48  | Shopping        | 461     |
| Home Improvement      | 219.04  | Shopping        |         |
| China Ecommerce       | 17.88   | Shopping        |         |
| Entertainment         | 17.6    | Shopping        |         |
| Electricity           | 52.95   | Utilities       | 253.47  |
| Gas                   | 107.19  | Utilities       |         |
| Phone Bill            | 0.6     | Utilities       |         |
| VPN                   | 4.84    | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 20      | Utilities       |         |
| Auto                  | 32.89   | Utilities       |         |
| Mortgage              | 1573.87 | Mortgage & Rent | 1573.87 |
| Hotel                 | 297.44  | Travel          | 297.44  |
| Cash & ATM            | 60      | Misc            | 146     |
| Transfer              | 56      | Misc            |         |
| Bank Fee              | 30      | Misc            |         |

### Balance

| Income  | Spending | Balance |
| ------- | -------- | ------- |
| 9230.67 | 4386.19  | 4844.48 |

### More than $10,000

| Item          | Type      | Amount |
| ------------- | --------- | ------ |
| Wire          | Income    | 49,990 |

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
            "Food", "Health", "Shopping", "Utilities", "Mortgage & Rent", "Travel", "Misc",
            "Restaurants", "Cake & Bread", "Bubble Tea", "Groceries", "Dental", "Pharmacy",
            "Hair & Skin", "Home Improvement", "China Ecommerce", "Entertainment",
            "Electricity", "Gas", "Phone Bill", "VPN", "Network", "Supply", "Auto",
            "Mortgage", "Hotel", "Cash & ATM", "Transfer", "Bank Fee"
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
                {value:1590.69, name:'Food'},
                {value:63.72, name:'Health'},
                {value:461, name:'Shopping'},
                {value:253.47, name:'Utilities'},
                {value:1573.87, name:'Mortgage & Rent'},
                {value:297.44, name:'Travel'},
                {value:146, name:'Misc'}
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
                { "value": 587.11, "name": "Restaurants" },
                { "value": 189.57, "name": "Cake & Bread" },
                { "value": 288.79, "name": "Bubble Tea" },
                { "value": 525.22, "name": "Groceries" },
                { "value": 57.01, "name": "Dental" },
                { "value": 6.71, "name": "Pharmacy" },
                { "value": 206.48, "name": "Hair & Skin" },
                { "value": 219.04, "name": "Home Improvement" },
                { "value": 17.88, "name": "China Ecommerce" },
                { "value": 17.6, "name": "Entertainment" },
                { "value": 52.95, "name": "Electricity" },
                { "value": 107.19, "name": "Gas" },
                { "value": 0.6, "name": "Phone Bill" },
                { "value": 4.84, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 20, "name": "Supply" },
                { "value": 32.89, "name": "Auto" },
                { "value": 1573.87, "name": "Mortgage" },
                { "value": 297.44, "name": "Hotel" },
                { "value": 60, "name": "Cash & ATM" },
                { "value": 56, "name": "Transfer" },
                { "value": 30, "name": "Bank Fee" }
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
        data: ['2024/1','2024/2','2024/3','2024/4','2024/5','2024/6','2024/7','2024/8','2024/9','2024/10','2024/11','2024/12']
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
            data: [302.13, 0, 751.72, 1324.58, 1372.49, 1569.95, 1773.14, 1257.02, 993.69, 422.35, 271.3, 1590.69]
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
            data: [67.96, 0, 7.21, 20.74, 0, 0, 0, 135.15, 93.79, 0, 0, 63.72]
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
            data: [72.09, 2231.5, 226.12, 919.23, 602.33, 969.97, 679.74, 2311.23, 84.26, 213.73, 214.14, 461]
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
            data: [380.43, 1763.79, 324.66, 440.6, 954.16, 326.58, 403.04, 1828.68, 149.44, 300.78, 252.05, 253.47]
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
            data: [2230.13, 1381.25, 2230.13, 1800.63, 1800.63, 3073.95, 2225.07, 2225.07, 2225.07, 2225.07, 1573.87, 1573.87]
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
            data: [18.79, 3776.05, 68.65, 18.43, 264.36, 366.38, 4838.74, 1203.15, 472.92, 31.34, 187.73, 297.44]
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
            data: [0, 0, 234, 126.56, 0, 201.84, 165, 5, 0, 99, 160, 146]
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
            data: ['2023/08','2023/09','2023/10','2023/11','2023/12','2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/12']
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
            data: [1329.06, 1383.72, 1400.12, 908.48, 477.28, 1324.58, 1372.49, 1569.95, 1773.14, 1257.02, 993.69, 1590.69],
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
            data: [85.26, 816.04, 772.85, 729.09, 3055.76, 919.23, 602.33, 969.97, 679.74, 2311.23, 84.26, 461],
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
            data: [1886.01, 539.88, 473.06, 313.29, 391.88, 440.6, 954.16, 326.58, 403.04, 1828.68, 149.44, 253.47],
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
        data: ['2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12']
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
            data: [4559.31, 4455.21, 6636.52, 4439.64, 4992.19, 4632.13, 4801.54, 8359.88, 6763.34, 5104.3, 6894.32, 9230.67],
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
            data: [-3071.53, -9152.59, -3842.49, -4650.77, -4993.97, -6508.67, -11234.73, -8965.3, -4019.17, -3292.27, -8509.09, -4386.19],
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
            data: ['2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07','2024/08','2024/09','2024/10','2024/11','2024/12']
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
            data: [1487.78, -4697.38, 2794.03, -211.13, -1.78, -1876.54, -6433.19, -605.42, 2744.17, 1812.03, -1614.77, 4844.48]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): 70869.05 - 72626.77 = -1757.72
