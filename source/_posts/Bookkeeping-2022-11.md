---
title: Bookkeeping - 2022/11
date: 2022-12-12 13:24:44
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4311.02 |
| State Tax        | 823     |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 534.54  | Food            | 1131.3  |
| Cake & Bread     | 108.93  | Food            |         |
| Bubble Tea       | 232.02  | Food            |         |
| Groceries        | 255.81  | Food            |         |
| Covid Test       | 49.2    | Health          | 151.2   |
| Dental           | 61.1    | Health          |         |
| Pharmacy         | 40.9    | Health          |         |
| Hair & Skin      | 8.49    | Shopping        | 2357.83 |
| Home Improvement | 1209.91 | Shopping        |         |
| China Ecommerce  | 289.44  | Shopping        |         |
| Electronics      | 849.99  | Shopping        |         |
| Electricity      | 33.46   | Utilities       | 168.02  |
| Gas              | 73.98   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Supply           | 29.01   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 74.52   | Travel          | 74.52   |
| Cash & ATM       | 60      | Misc            | 77.36   |
| Shipping         | 17.36   | Misc            |         |
| Paycheck         | 4311.02 | Income          | 5134.02 |
| State Tax        | 823     | Income          |         |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 5134.02   | 6057.2    | -923.18       |

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
        'Groceries','Covid Test','Dental','Pharmacy','Hair & Skin','Home Improvement','China Ecommerce','Electronics','Electricity',
        'Gas','Phone Bill','VPN','Supply','Television','Mortgage','HOA','Ride Share','Cash & ATM','Shipping']
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
                {value:1131.3, name:'Food'},
                {value:151.2, name:'Health'},
                {value:2357.83, name:'Shopping'},
                {value:168.02, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:74.52, name:'Travel'},
                {value:77.36, name:'Misc'},
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
                {value:534.54, name:'Restaurants'},
                {value:108.93, name:'Cake & Bread'},
                {value:232.02, name:'Bubble Tea'},
                {value:255.81, name:'Groceries'},
                {value:49.2, name:'Covid Test'},
                {value:61.1, name:'Dental'},
                {value:40.9, name:'Pharmacy'},
                {value:8.49, name:'Hair & Skin'},
                {value:1209.91, name:'Home Improvement'},
                {value:289.44, name:'China Ecommerce'},
                {value:849.99, name:'Electronics'},
                {value:33.46, name:'Electricity'},
                {value:73.98, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:29.01, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1672.53, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:74.52, name:'Ride Share'},
                {value:60, name:'Cash & ATM'},
                {value:17.36, name:'Shipping'},
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
        data: ['2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/7','2022/8','2022/9','2022/10','2022/11']
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
            data: [1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 0, 0, 0, 865, 1131.3]
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
            data: [90.59, 86.89, 11.09, 314.53, 5, 51.06, 352.78, 5, 5, 5, 22.31, 151.2]
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
            data: [1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 410.64, 177.83, 391.13, 463.61, 2357.83]
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
            data: [232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 165.16, 112.3, 102.18, 157.36, 168.02]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 2074.9, 2074.9, 2074.9, 2074.9, 2096.97]
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
            data: [0, 28.5, 0, 308.18, 3398.22, 998.23, 765.11, 0, 1706.14, 0, 46.64, 74.52]
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
            data: [0, 6000, 6000, 0, 0, 50, 0, 0, 0, 0, 0, 0]
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
            data: [200, 0, 0, 1015, 114.81, 0, 100, 95, 0, 0, 100, 77.36]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/10','2022/11']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 865, 1131.3],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 463.61, 2357.83],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 157.36, 168.02],
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