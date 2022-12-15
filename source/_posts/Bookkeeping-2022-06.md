---
title: Bookkeeping - 2022/06
date: 2022-12-01 15:27:11
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7885.96 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 276.05  | Food            | 979.38  |
| Cake & Bread     | 147     | Food            |         |
| Bubble Tea       | 281.74  | Food            |         |
| Groceries        | 274.59  | Food            |         |
| Covid test       | 250     | Health          | 352.78  |
| Pharmacy         | 82.67   | Health          |         |
| Control          | 20.11   | Health          |         |
| Clothing         | 243.68  | Shopping        | 680.5   |
| Home Improvement | 391.29  | Shopping        |         |
| China Ecommerce  | 45.53   | Shopping        |         |
| Electricity      | 53      | Utilities       | 202.03  |
| Gas              | 62.66   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 61      | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 60      | Travel          | 765.11  |
| Ride Share       | 183.28  | Travel          |         |
| Hotel            | 457.83  | Travel          |         |
| Ticket           | 62      | Travel          |         |
| Souvenir         | 2       | Travel          |         |
| Cash & ATM       | 100     | Misc            | 100     |
| Paycheck         | 7885.96 | Income          | 7885.96 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 7885.96   | 5022.31   | 2863.65       |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Covid Test','Pharmacy','Control','Clothing','Home Improvement','China Ecommerce','Electricity','Gas',
        'Phone Bill','Legal','Supply','Television','Mortgage','HOA','Air','Ride Share','Hotel','Ticket','Souvenir','Cash & ATM']
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
                {value:979.38, name:'Food'},
                {value:352.78, name:'Health'},
                {value:680.5, name:'Shopping'},
                {value:202.03, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:765.11, name:'Travel'},
                {value:100, name:'Misc'},
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
                {value:276.05, name:'Restaurants'},
                {value:147, name:'Cake & Bread'},
                {value:281.74, name:'Bubble Tea'},
                {value:274.59, name:'Groceries'},
                {value:250, name:'Covid Test'},
                {value:82.67, name:'Pharmacy'},
                {value:20.11, name:'Control'},
                {value:243.68, name:'Clothing'},
                {value:391.29, name:'Home Improvement'},
                {value:45.53, name:'China Ecommerce'},
                {value:53, name:'Electricity'},
                {value:62.66, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:61, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:60, name:'Air'},
                {value:183.28, name:'Ride Share'},
                {value:457.83, name:'Hotel'},
                {value:62, name:'Ticket'},
                {value:2, name:'Souvenir'},
                {value:100, name:'Cash & ATM'},
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
        data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38]
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
            data: [11.68, 90.59, 86.89, 11.09, 314.53, 5, 51.06, 352.78]
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5]
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51]
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
            data: [49.98, 0, 28.5, 0, 308.18, 3398.22, 998.23, 765.11]
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
            data: [0, 0, 6000, 6000, 0, 0, 50, 0]
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
            data: [0, 200, 0, 0, 1015, 114.81, 0, 100]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38],
            markPoint : {
                data : [
                    {type : 'max', name: '最大值'},
                    {type : 'min', name: '最小值'}
                ]
            },
            markLine : {
                data : [
                    {type : 'average', name: '平均值'}
                ]
            }
        },
        {
            name:'Shopping',
            type:'bar',
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03],
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