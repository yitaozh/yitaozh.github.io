---
title: Bookkeeping - 2024/07
date: 2025-06-13 11:32:45
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4801.54 | Income          | 4801.54 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 699.32  | Food            | 1773.14 |
| Cake & Bread          | 171.5   | Food            |         |
| Bubble Tea            | 376.92  | Food            |         |
| Groceries             | 525.4   | Food            |         |
| Clothing              | 428.24  | Shopping        | 679.74  |
| Hair & Skin           | 77.65   | Shopping        |         |
| Home Improvement      | 173.85  | Shopping        |         |
| Electricity           | 119.99  | Utilities       | 403.04  |
| Gas                   | 36.78   | Utilities       |         |
| Phone Bill            | 0.32    | Utilities       |         |
| VPN                   | 4.84    | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 135.15  | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 55.47   | Utilities       |         |
| Mortgage              | 1800.63 | Mortgage & Rent | 2225.07 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Air                   | 3809.8  | Travel          | 4838.74 |
| Ride share/Car rental | 274.77  | Travel          |         |
| Hotel                 | 575.32  | Travel          |         |
| Ticket                | 100     | Travel          |         |
| Souvenir              | 78.85   | Travel          |         |
| IRA                   | 1150    | Investment      | 1150    |
| Cash & ATM            | 60      | Misc            | 165     |
| Annual                | 95      | Misc            |         |
| Bank Fee              | 10      | Misc            |         |

### Balance

| Income  | Spending | Balance   |
| ------- | -------- | --------- |
| 4801.54 | 11234.73 | \-6433.19 |

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
        data:['Food','Shopping','Utilities','Mortgage & Rent','Travel','Investment','Misc','Restaurants','Cake & Bread','Bubble Tea','Groceries','Clothing','Hair & Skin','Home Improvement','Electricity','Gas','Phone Bill','VPN','Network','Supply','Television','Auto','Mortgage','HOA','Air','Ride share/Car rental','Hotel','Ticket','Souvenir','IRA','Cash & ATM','Annual','Bank Fee']
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
                {value:1773.14, name:'Food'},
                {value:679.74, name:'Shopping'},
                {value:403.04, name:'Utilities'},
                {value:2225.07, name:'Mortgage & Rent'},
                {value:4838.74, name:'Travel'},
                {value:1150, name:'Investment'},
                {value:165, name:'Misc'}
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
                { "value": 699.32, "name": "Restaurants" },
                { "value": 171.5, "name": "Cake & Bread" },
                { "value": 376.92, "name": "Bubble Tea" },
                { "value": 525.4, "name": "Groceries" },
                { "value": 428.24, "name": "Clothing" },
                { "value": 77.65, "name": "Hair & Skin" },
                { "value": 173.85, "name": "Home Improvement" },
                { "value": 119.99, "name": "Electricity" },
                { "value": 36.78, "name": "Gas" },
                { "value": 0.32, "name": "Phone Bill" },
                { "value": 4.84, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 135.15, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 55.47, "name": "Auto" },
                { "value": 1800.63, "name": "Mortgage" },
                { "value": 424.44, "name": "HOA" },
                { "value": 3809.8, "name": "Air" },
                { "value": 274.77, "name": "Ride share/Car rental" },
                { "value": 575.32, "name": "Hotel" },
                { "value": 100, "name": "Ticket" },
                { "value": 78.85, "name": "Souvenir" },
                { "value": 1150, "name": "IRA" },
                { "value": 60, "name": "Cash & ATM" },
                { "value": 95, "name": "Annual" },
                { "value": 10, "name": "Bank Fee" }
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
        data: ['2023/8','2023/9','2023/10','2023/11','2023/12','2024/1','2024/2','2024/3','2024/4','2024/5','2024/6','2024/7']
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
            data: [1329.06, 1383.72, 1400.12, 908.48, 477.28, 302.13, 0, 751.72, 1324.58, 1372.49, 1569.95, 1773.14]
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
            data: [60.43, 0, 14.28, 12.74, 0, 67.96, 0, 7.21, 20.74, 0, 0, 0]
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
            data: [85.26, 816.04, 772.85, 729.09, 3055.76, 72.09, 2231.5, 226.12, 919.23, 602.33, 969.97, 679.74]
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
            data: [1886.01, 539.88, 473.06, 313.29, 391.88, 380.43, 1763.79, 324.66, 440.6, 954.16, 326.58, 403.04]
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
            data: [2096.97, 2096.97, 1672.53, 2230.13, 1381.25, 2230.13, 1381.25, 2230.13, 1800.63, 1800.63, 3073.95, 2225.07]
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
            data: [279.32, 3155.32, 509.47, 30.81, 0, 18.79, 3776.05, 68.65, 18.43, 264.36, 366.38, 4838.74]
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
            data: [465.62, 182.98, 60, 0, 0, 0, 0, 234, 126.56, 0, 201.84, 165]
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
            data: ['2023/03','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/04','2024/05','2024/06','2024/07']
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
            data: [721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 1324.58, 1372.49, 1569.95, 1773.14],
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
            data: [194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 919.23, 602.33, 969.97, 679.74],
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
            data: [431.22, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 440.6, 954.16, 326.58, 403.04],
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
        data: ['2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07']
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
            data: [4812.98, 8202.3, 5736.6, 5927.86, 8512.78, 4559.31, 4455.21, 6636.52, 4439.64, 4992.19, 4632.13, 4801.54],
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
            data: [-6202.67, -8174.91, -4902.31, -4224.54, -11803.17, -3071.53, -9152.59, -3842.49, -4650.77, -4993.97, -6508.67, -11234.73],
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
            data: ['2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04','2024/05','2024/06','2024/07']
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
            data: [-1389.69, 27.39, 834.29, 1703.32, -3290.39, 1487.78, -4697.38, 2794.03, -211.13, -1.78, -1876.54, -6433.19]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A
