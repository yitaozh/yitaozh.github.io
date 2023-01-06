---
title: Bookkeeping - 2022/10
date: 2022-12-01 16:56:45
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 2861.14 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 376.84  | Food            | 865     |
| Cake & Bread     | 96.02   | Food            |         |
| Bubble Tea       | 133.99  | Food            |         |
| Groceries        | 258.15  | Food            |         |
| Pharmacy         | 5       | Health          | 22.31   |
| Control          | 17.31   | Health          |         |
| Hair & Skin      | 25.08   | Shopping        | 463.61  |
| Home Improvement | 184.49  | Shopping        |         |
| China Ecommerce  | 155.04  | Shopping        |         |
| Office           | 99      | Shopping        |         |
| Electricity      | 23.98   | Utilities       | 157.36  |
| Gas              | 43.72   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Network          | 6.38    | Utilities       |         |
| Supply           | 44.96   | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1650.46 | Mortgage & Rent | 2074.9  |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 46.64   | Travel          | 46.64   |
| Cash & ATM       | 100     | Misc            | 100     |
| Paycheck         | 2861.14 | Income          | 2861.14 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 2861.14   | 3729.82   | -868.68       |

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
        'Groceries','Pharmacy','Control','Hair & Skin','Home Improvement','China Ecommerce','Office','Electricity','Gas',
        'Phone Bill','VPN','Legal','Network','Supply','Television','Mortgage','HOA','Ride Share','Cash & ATM']
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
                {value:865, name:'Food'},
                {value:22.31, name:'Health'},
                {value:463.61, name:'Shopping'},
                {value:157.36, name:'Utilities'},
                {value:2074.9, name:'Mortgage & Rent'},
                {value:46.64, name:'Travel'},
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
                {value:376.84, name:'Restaurants'},
                {value:96.02, name:'Cake & Bread'},
                {value:133.99, name:'Bubble Tea'},
                {value:258.15, name:'Groceries'},
                {value:5, name:'Pharmacy'},
                {value:17.31, name:'Control'},
                {value:25.08, name:'Hair & Skin'},
                {value:184.49, name:'Home Improvement'},
                {value:155.04, name:'China Ecommerce'},
                {value:99, name:'Office'},
                {value:23.98, name:'Electricity'},
                {value:43.72, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:6.75, name:'Legal'},
                {value:6.38, name:'Network'},
                {value:44.96, name:'Supply'},
                {value:15.49, name:'Television'},
                {value:1650.46, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:46.64, name:'Ride Share'},
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
        data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/7','2022/8','2022/9','2022/10']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 0, 0, 0, 865]
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
            data: [11.68, 90.59, 86.89, 11.09, 314.53, 5, 51.06, 352.78, 5, 5, 5, 22.31]
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 410.64, 177.83, 391.13, 463.61]
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 165.16, 112.3, 102.18, 157.36]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 2074.9, 2074.9, 2074.9, 2074.9]
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
            data: [49.98, 0, 28.5, 0, 308.18, 3398.22, 998.23, 765.11, 0, 1706.14, 0, 46.64]
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
            data: [0, 0, 6000, 6000, 0, 0, 50, 0, 0, 0, 0, 0]
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
            data: [0, 200, 0, 0, 1015, 114.81, 0, 100, 95, 0, 0, 100]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/10']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 865],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 463.61],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 157.36],
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