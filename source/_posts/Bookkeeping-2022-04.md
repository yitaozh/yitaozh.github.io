---
title: Bookkeeping - 2022/04
date: 2022-12-01 13:02:49
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 6873.05 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 762.87  | Food            | 1161.14 |
| Cake & Bread     | 58.53   | Food            |         |
| Bubble Tea       | 237.06  | Food            |         |
| Groceries        | 102.68  | Food            |         |
| Pharmacy         | 5       | Health          | 5       |
| Clothing         | 216.71  | Shopping        | 447.04  |
| Hair & Skin      | 12.63   | Shopping        |         |
| Home Improvement | 70.62   | Shopping        |         |
| Marriage         | 147.08  | Shopping        |         |
| Electricity      | 69.95   | Utilities       | 325.53  |
| Gas              | 197.18  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Supply           | 33.03   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1518.07 | Mortgage & Rent | 1942.51 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Air              | 2450.06 | Travel          | 3398.22 |
| Ride Share       | 313.52  | Travel          |         |
| Hotel            | 634.64  | Travel          |         |
| Cash & ATM       | 111.31  | Misc            | 114.81  |
| Visa             | 3.5     | Misc            |         |
| Paycheck         | 6873.05 | Income          | 6873.05 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 6873.05   | 7394.25   | -521.2        |

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
        'Groceries','Pharmacy','Clothing','Hair & Skin','Home Improvement','Marriage','Electricity','Gas','Phone Bill','Legal',
        'Supply','Television','Mortgage','HOA','Air','Ride Share','Hotel','Cash & ATM','Visa']
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
                {value:1161.14, name:'Food'},
                {value:5, name:'Health'},
                {value:447.04, name:'Shopping'},
                {value:325.53, name:'Utilities'},
                {value:1942.51, name:'Mortgage & Rent'},
                {value:3398.22, name:'Travel'},
                {value:114.81, name:'Misc'},
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
                {value:762.87, name:'Restaurants'},
                {value:58.53, name:'Cake & Bread'},
                {value:237.06, name:'Bubble Tea'},
                {value:102.68, name:'Groceries'},
                {value:5, name:'Pharmacy'},
                {value:216.71, name:'Clothing'},
                {value:12.63, name:'Hair & Skin'},
                {value:70.62, name:'Home Improvement'},
                {value:147.089, name:'Marriage'},
                {value:69.95, name:'Electricity'},
                {value:197.18, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:6.75, name:'Legal'},
                {value:33.03, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1518.07, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:2450.06, name:'Air'},
                {value:313.52, name:'Ride Share'},
                {value:634.64, name:'Hotel'},
                {value:111.31, name:'Cash & ATM'},
                {value:3.5, name:'Visa'},
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
        data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14]
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
            data: [11.68, 90.59, 86.89, 11.09, 314.53, 5]
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04]
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51]
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
            data: [49.98, 0, 28.5, 0, 308.18, 3398.22]
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
            data: [0, 0, 6000, 6000, 0, 0]
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
            data: [0, 200, 0, 0, 1015, 114.81]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53],
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