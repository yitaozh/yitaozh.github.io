---
title: Bookkeeping - 2023/07
date: 2023-08-31 01:09:22
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4413.59 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 253.51  | Food            | 1234.85 |
| Cake & Bread          | 83.75   | Food            |         |
| Bubble Tea            | 476.67  | Food            |         |
| Groceries             | 420.92  | Food            |         |
| Clothing              | 639.26  | Shopping        | 1056.3  |
| Hair & Skin           | 3.59    | Shopping        |         |
| Home Improvement      | 413.45  | Shopping        |         |
| Electricity           | 51.2    | Utilities       | 308.18  |
| Gas                   | 33.36   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| Supply                | 162.58  | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 42.42   | Utilities       |         |
| Mortgage              | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Ride share/Car rental | 85.71   | Travel          | 457.73  |
| Hotel                 | 372.02  | Travel          |         |
| Annual                | 95      | Misc            | 95      |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 4413.59 | 5249.03  | -835.44  |

### More than $10,000

| Category | Type | Amount |
| -------- | ---- | ------ |
| N/A      | N/A  | N/A    |

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
        data:['Food','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Clothing','Hair & Skin','Home Improvement','Electricity','Gas','Phone Bill',
        'Supply','Television','Auto','Mortgage','HOA','Ride share/Car rental','Hotel','Annual']
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
                {value:1234.85, name:'Food'},
                {value:0, name:'Health'},
                {value:1056.3, name:'Shopping'},
                {value:308.18, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:457.73, name:'Travel'},
                {value:95, name:'Misc'}
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
                {value: 253.51, name: 'Restaurants'},
                {value: 83.75, name: 'Cake & Bread'},
                {value: 476.67, name: 'Bubble Tea'},
                {value: 420.92, name: 'Groceries'},
                {value: 639.26, name: 'Clothing'},
                {value: 3.59, name: 'Hair & Skin'},
                {value: 413.45, name: 'Home Improvement'},
                {value: 51.2, name: 'Electricity'},
                {value: 33.36, name: 'Gas'},
                {value: 3.13, name: 'Phone Bill'},
                {value: 162.58, name: 'Supply'},
                {value: 15.49, name: 'Television'},
                {value: 42.42, name: 'Auto'},
                {value: 1672.53, name: 'Mortgage'},
                {value: 424.44, name: 'HOA'},
                {value: 85.71, name: 'Ride share/Car rental'},
                {value: 372.02, name: 'Hotel'},
                {value: 95, name: 'Annual'}
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
        data: ['2022/8','2022/9','2022/10','2022/11','2022/12','2023/1','2023/2','2023/3','2023/4','2023/5','2023/6','2023/7']
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
            data: [0, 0, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 0, 0, 932.43, 1234.85]
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
            data: [5, 5, 22.31, 102, 36.68, 61.46, 644.06, 142.41, 5, 5, 88.61, 0]
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
            data: [177.83, 391.13, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 398.71, 373.71, 1711.43, 1056.3]
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
            data: [112.3, 102.18, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 414.16, 166.7, 109.35, 308.18]
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
            data: [2074.9, 2074.9, 2074.9, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97]
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
            data: [1706.14, 0, 46.64, 74.52, 61.37, 37, 113.76, 2146.71, 0, 3626.52, 55.31, 457.73]
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
            data: [0, 0, 0, 0, 6000, 0, 0, 0, 0, 0, 0, 0]
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
            data: [0, 0, 100, 77.36, 0, 40, 0, 1361, 0, 0, 15, 95]
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
            data: ['2022/03','2022/04','2022/05','2022/06','2022/10','2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07']
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
            data: [1207.9, 1161.14, 1543.5, 979.38, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85],
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
            data: [4428.25, 447.04, 1470.26, 680.5, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3],
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
            data: [444.48, 325.53, 315.63, 202.03, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18],
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
