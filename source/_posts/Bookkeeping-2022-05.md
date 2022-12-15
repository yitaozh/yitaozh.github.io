---
title: Bookkeeping - 2022/05
date: 2022-12-01 14:12:39
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4986.17 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 632.72  | Food            | 1543.5  |
| Cake & Bread     | 183.25  | Food            |         |
| Bubble Tea       | 309.99  | Food            |         |
| Groceries        | 417.54  | Food            |         |
| Pharmacy         | 51.06   | Health          | 51.06   |
| Clothing         | 360.49  | Shopping        | 1470.26 |
| Hair & Skin      | 429.48  | Shopping        |         |
| Home Improvement | 463.68  | Shopping        |         |
| Electronics      | 180.61  | Shopping        |         |
| Marriage         | 36      | Shopping        |         |
| Electricity      | 59.83   | Utilities       | 315.63  |
| Gas              | 153.57  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 76.86   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 475.2   | Travel          | 998.23  |
| Ride Share       | 60.91   | Travel          |         |
| Hotel            | 462.12  | Travel          |         |
| Stock            | 50      | Investment      | 50      |
| Paycheck         | 4986.17 | Income          | 4986.17 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 4986.17   | 6371.19   | -1385.02      |

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
        'Bubble Tea','Groceries','Pharmacy','Clothing','Home Improvement','Electronics','Marriage','Electricity','Gas',
        'Phone Bill','Legal','Supply','Television','Mortgage','HOA','Air','Ride Share','Hotel','Stock']
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
                {value:1543.5, name:'Food'},
                {value:51.06, name:'Health'},
                {value:1470.26, name:'Shopping'},
                {value:315.63, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:998.23, name:'Travel'},
                {value:50, name:'Investment'},
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
                {value:632.72, name:'Restaurants'},
                {value:183.25, name:'Cake & Bread'},
                {value:309.99, name:'Bubble Tea'},
                {value:417.54, name:'Groceries'},
                {value:51.06, name:'Pharmacy'},
                {value:360.49, name:'Clothing'},
                {value:429.48, name:'Hair & Skin'},
                {value:463.68, name:'Home Improvement'},
                {value:180.61, name:'Electronics'},
                {value:36, name:'Marriage'},
                {value:59.83, name:'Electricity'},
                {value:153.57, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:76.86, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:475.2, name:'Air'},
                {value:60.91, name:'Ride Share'},
                {value:462.12, name:'Hotel'},
                {value:50, name:'Stock'},
            ]
        }
    ]
};
{% endecharts %}

### Spending Trend

#### Tread of all categories

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
        data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5]
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
            data: [11.68, 90.59, 86.89, 11.09, 314.53, 5, 51.06]
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26]
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51]
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
            data: [49.98, 0, 28.5, 0, 308.18, 3398.22, 998.23]
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
            data: [0, 0, 6000, 6000, 0, 0, 50]
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
            data: [0, 200, 0, 0, 1015, 114.81, 0]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63],
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