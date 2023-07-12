---
title: Bookkeeping - 2023/03
date: 2023-07-12 18:05:12
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 7332.06 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 92.78   | Food            | 721.14  |
| Cake & Bread          | 46.26   | Food            |         |
| Bubble Tea            | 391.94  | Food            |         |
| Groceries             | 190.16  | Food            |         |
| Pharmacy              | 142.41  | Health          | 142.41  |
| Hair & Skin           | 35      | Shopping        | 194.85  |
| Home Improvement      | 0.61    | Shopping        |         |
| China Ecommerce       | 107.19  | Shopping        |         |
| Office                | 52.05   | Shopping        |         |
| Electricity           | 112.9   | Utilities       | 431.22  |
| Gas                   | 289.7   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| Supply                | 10      | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Mortgage              | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Air                   | 1993.4  | Travel          | 2146.71 |
| Ride share/Car rental | 65.84   | Travel          |         |
| Souvenir              | 87.47   | Travel          |         |
| Cash & ATM            | 60      | Misc            | 1361    |
| Annual                | 234     | Misc            |         |
| Federal Tax           | 651     | Misc            |         |
| State Tax             | 416     | Misc            |         |

### Balance

| Income  | Spending | Balance |
| ------- | -------- | ------- |
| 7332.06 | 7094.3   | 237.76  |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread',
        'Bubble Tea','Groceries','Pharmacy','Hair & Skin','Home Improvement','China Ecommerce','Office','Electricity',
        'Gas','Phone Bill','Supply','Television','Mortgage','HOA','Air','Ride share/Car rental','Souvenir','Cash & ATM',
        'Annual','Federal Tax','State Tax']
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
                {value:721.14, name:'Food'},
                {value:142.41, name:'Health'},
                {value:194.85, name:'Shopping'},
                {value:431.22, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:2146.7, name:'Travel'},
                {value:1361, name:'Misc'}
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
                {value: 92.78, name: 'Restaurants'},
                {value: 46.26, name: 'Cake & Bread'},
                {value: 391.94, name: 'Bubble Tea'},
                {value: 190.16, name: 'Groceries'},
                {value: 142.41, name: 'Pharmacy'},
                {value: 35, name: 'Hair & Skin'},
                {value: 0.61, name: 'Home Improvement'},
                {value: 107.19, name: 'China Ecommerce'},
                {value: 52.05, name: 'Office'},
                {value: 112.9, name: 'Electricity'},
                {value: 289.7, name: 'Gas'},
                {value: 3.13, name: 'Phone Bill'},
                {value: 10, name: 'Supply'},
                {value: 15.49, name: 'Television'},
                {value: 1672.53, name: 'Mortgage'},
                {value: 424.44, name: 'HOA'},
                {value: 1993.4, name: 'Air'},
                {value: 65.84, name: 'Ride share/Car rental'},
                {value: 87.47, name: 'Souvenir'},
                {value: 60, name: 'Cash & ATM'},
                {value: 234, name: 'Annual'},
                {value: 651, name: 'Federal Tax'},
                {value: 416, name: 'State Tax'}
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
        data: ['2022/4','2022/5','2022/6','2022/7','2022/8','2022/9','2022/10','2022/11','2022/12','2023/1','2023/2','2023/3']
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
            data: [1161.14, 1543.5, 979.38, 0, 0, 0, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14]
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
            data: [5, 51.06, 352.78, 5, 5, 5, 22.31, 102, 36.68, 61.46, 644.06, 142.41]
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
            data: [447.04, 1470.26, 680.5, 410.64, 177.83, 391.13, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85]
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
            data: [325.53, 315.63, 202.03, 165.16, 112.3, 102.18, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22]
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
            data: [1942.51, 1942.51, 1942.51, 2074.9, 2074.9, 2074.9, 2074.9, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97]
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
            data: [3398.22, 998.23, 765.11, 0, 1706.14, 0, 46.64, 74.52, 61.37, 37, 113.76, 2146.71]
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
            data: [0, 50, 0, 0, 0, 0, 0, 0, 6000, 0, 0, 0]
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
            data: [114.81, 0, 100, 95, 0, 0, 100, 77.36, 0, 40, 0, 1361]
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
            data: ['2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/10','2022/11','2022/12','2023/01','2023/02','2023/03']
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
            data: [1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14],
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
            data: [615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85],
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
            data: [337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22],
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
