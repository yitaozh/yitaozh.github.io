---
title: Bookkeeping - 2024/06
date: 2024-07-22 00:05:53
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4592.13 | Income          | 4632.13 |
| Deposit               | 40      | Income          |         |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 373.33  | Food            | 1569.95 |
| Cake & Bread          | 217.54  | Food            |         |
| Bubble Tea            | 501.91  | Food            |         |
| Groceries             | 477.17  | Food            |         |
| Clothing              | 486.2   | Shopping        | 969.97  |
| Hair & Skin           | 49.5    | Shopping        |         |
| Home Improvement      | 233.46  | Shopping        |         |
| Electronics           | 200.81  | Shopping        |         |
| Electricity           | 91.35   | Utilities       | 326.58  |
| Gas                   | 61.77   | Utilities       |         |
| Phone Bill            | 0.3     | Utilities       |         |
| VPN                   | 5       | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 34.54   | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 83.13   | Utilities       |         |
| Mortgage              | 1800.63 | Mortgage & Rent | 3073.95 |
| HOA                   | 1273.32 | Mortgage & Rent |         |
| Air                   | 326.38  | Travel          | 366.38  |
| Ticket                | 40      | Travel          |         |
| Annual                | 201.84  | Misc            | 201.84  |

### Balance

| Income  | Spending | Balance   |
| ------- | -------- | --------- |
| 4632.13 | 6508.67  | \-1876.54 |

### More than $10,000

| Item          | Type  | Amount |
| ------------- | ----- | ------ |
| Lighthousecap | Stock | 10000  |

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
        data:['Food','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread','Bubble Tea','Groceries','Clothing','Hair & Skin','Home Improvement','Electronics','Electricity','Gas','Phone Bill','VPN','Network','Supply','Television','Auto','Mortgage','HOA','Air','Ticket','Annual']
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
                {value:1569.95, name:'Food'},
                {value:969.97, name:'Shopping'},
                {value:326.58, name:'Utilities'},
                {value:3073.95, name:'Mortgage & Rent'},
                {value:366.38, name:'Travel'},
                {value:201.84, name:'Misc'}
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
                { "value": 373.33, "name": "Restaurants" },
                { "value": 217.54, "name": "Cake & Bread" },
                { "value": 501.91, "name": "Bubble Tea" },
                { "value": 477.17, "name": "Groceries" },
                { "value": 486.2, "name": "Clothing" },
                { "value": 49.5, "name": "Hair & Skin" },
                { "value": 233.46, "name": "Home Improvement" },
                { "value": 200.81, "name": "Electronics" },
                { "value": 91.35, "name": "Electricity" },
                { "value": 61.77, "name": "Gas" },
                { "value": 0.3, "name": "Phone Bill" },
                { "value": 5, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 34.54, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 83.13, "name": "Auto" },
                { "value": 1800.63, "name": "Mortgage" },
                { "value": 1273.32, "name": "HOA" },
                { "value": 326.38, "name": "Air" },
                { "value": 40, "name": "Ticket" },
                { "value": 201.84, "name": "Annual" }
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
        data: ['2023/7','2023/8','2023/9','2023/10','2023/11','2023/12','2024/1','2024/2','2024/3','2024/4','2024/5','2024/6']
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
            data: [1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 302.13, 0, 751.72, 1324.58, 1372.49, 1569.95]
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
            data: [0, 60.43, 0, 14.28, 12.74, 0, 67.96, 0, 7.21, 20.74, 0, 0]
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
            data: [1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 72.09, 2231.5, 226.12, 919.23, 602.33, 969.97]
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
            data: [308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 380.43, 1763.79, 324.66, 440.6, 954.16, 326.58]
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
            data: [2096.97, 2096.97, 2096.97, 1672.53, 2230.13, 1381.25, 2230.13, 1381.25, 2230.13, 1800.63, 1800.63, 3073.95]
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
            data: [457.73, 279.32, 3155.32, 509.47, 30.81, 0, 18.79, 3776.05, 68.65, 18.43, 264.36, 366.38]
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
            data: [95, 465.62, 182.98, 60, 0, 0, 0, 0, 234, 126.56, 0, 201.84]
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
            data: ['2023/02','2023/03','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/04','2024/05','2024/06']
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
            data: [971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 1324.58, 1372.49, 1569.95],
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
            data: [158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 919.23, 602.33, 969.97],
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
            data: [500.74, 431.22, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 440.6, 954.16, 326.58],
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
        data: ['2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06']
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
            data: [4413.59, 4812.98, 8202.3, 5736.6, 5927.86, 8512.78, 4559.31, 4455.21, 6636.52, 4439.64, 4992.19, 4632.13],
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
            data: [-5249.03, -6202.67, -8174.91, -4902.31, -4224.54, -11803.17, -3071.53, -9152.59, -3842.49, -4650.77, -4993.97, -6508.67],
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
            data: ['2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06']
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
            data: [-835.44, -1389.69, 27.39, 834.29, 1703.32, -3290.39, 1487.78, -4697.38, 2794.03, -211.13, -1.78, -1876.54]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
