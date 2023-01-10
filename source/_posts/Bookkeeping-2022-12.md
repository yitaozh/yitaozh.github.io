---
title: Bookkeeping - 2022/12
date: 2023-01-10 17:54:38
tags:
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7923.04 |
| Deposit          | 100     |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 510.97  | Food            | 1327.16 |
| Cake & Bread     | 71.32   | Food            |         |
| Bubble Tea       | 250.45  | Food            |         |
| Groceries        | 494.42  | Food            |         |
| Pharmacy         | 36.68   | Health          | 36.68   |
| Clothing         | 89.3    | Shopping        | 653.76  |
| Home Improvement | 216.31  | Shopping        |         |
| Electronics      | 307.04  | Shopping        |         |
| Office           | 41.11   | Shopping        |         |
| Electricity      | 96.08   | Utilities       | 313.81  |
| Gas              | 159.24  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 39.87   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 43.81   | Travel          | 61.37   |
| Souvenir         | 17.56   | Travel          |         |
| IRA              | 6000    | Investment      | 6000    |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 8023.04   | 10489.75  | -2466.71      |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Investment','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Pharmacy','Clothing','Home Improvement','Electronics','Office','Electricity',
        'Gas','Phone Bill','VPN','Television','Mortgage','HOA','Ride Share','Souvenir','IRA']
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
                {value:1327.16, name:'Food'},
                {value:36.68, name:'Health'},
                {value:653.76, name:'Shopping'},
                {value:313.81, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:61.37, name:'Travel'},
                {value:6000, name:'Investment'},
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
                {value:510.97, name:'Restaurants'},
                {value:71.32, name:'Cake & Bread'},
                {value:250.45, name:'Bubble Tea'},
                {value:494.421, name:'Groceries'},
                {value:36.68, name:'Pharmacy'},
                {value:89.3, name:'Clothing'},
                {value:216.31, name:'Home Improvement'},
                {value:307.04, name:'Electronics'},
                {value:41.11, name:'Office'},
                {value:96.08, name:'Electricity'},
                {value:159.24, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:39.87, name:'VPN'},
                {value:15.49, name:'Television'},
                {value:1672.53, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:43.81, name:'Ride Share'},
                {value:17.56, name:'Souvenir'},
                {value:6000, name:'IRA'},
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
        data: ['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Investment','Misc']
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
        data: ['2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/7','2022/8','2022/9','2022/10','2022/11','2022/12']
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
            data: [1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 0, 0, 0, 865, 1131.3, 1327.16]
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
            data: [86.89, 11.09, 314.53, 5, 51.06, 352.78, 5, 5, 5, 22.31, 151.2, 36.68]
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
            data: [615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 410.64, 177.83, 391.13, 463.61, 2341.89, 653.76]
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
            data: [337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 165.16, 112.3, 102.18, 157.36, 168.02, 313.81]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 2074.9, 2074.9, 2074.9, 2074.9, 2096.97, 2096.97]
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
            data: [28.5, 0, 308.18, 3398.22, 998.23, 765.11, 0, 1706.14, 0, 46.64, 74.52, 61.37]
        },
        {
            name: 'Investment',
            type: 'bar',
            stack: '总量',
            label: {
                normal: {
                    show: false,
                    position: 'insideRight'
                }
            },
            data: [6000, 6000, 0, 0, 50, 0, 0, 0, 0, 0, 0, 6000]
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
            data: [0, 0, 1015, 114.81, 0, 100, 95, 0, 0, 100, 77.36, 0]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/10','2022/11','2022/12']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 865, 1131.3, 1327.16],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 463.61, 2341.89, 653.76],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 157.36, 168.02, 313.81],
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