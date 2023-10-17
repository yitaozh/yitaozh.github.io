---
title: Bookkeeping - 2023/08
date: 2023-10-17 11:37:43
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 4812.98 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 437.94  | Food            | 1329.06 |
| Cake & Bread          | 121.34  | Food            |         |
| Bubble Tea            | 433.31  | Food            |         |
| Groceries             | 336.47  | Food            |         |
| Pharmacy              | 60.43   | Health          | 60.43   |
| Hair & Skin           | 35      | Shopping        | 85.26   |
| Home Improvement      | 19.1    | Shopping        |         |
| Office                | 31.16   | Shopping        |         |
| Electricity           | 127.55  | Utilities       | 1886.01 |
| Gas                   | 35.18   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| Supply                | 84.5    | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 1620.16 | Utilities       |         |
| Mortgage              | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA                   | 424.44  | Mortgage & Rent |         |
| Ride share/Car rental | 24.31   | Travel          | 279.32  |
| Hotel                 | 255.01  | Travel          |         |
| Cash & ATM            | 100     | Misc            | 465.62  |
| Visa                  | 365.62  | Misc            |         |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 4812.98 | 6202.67  | -1389.69 |

### More than $10,000

| Item              | Type | Amount   |
| ----------------- | ---- | -------- |
| CHAUMET FRANCOIS  | Ring | 4560.73  |
| HARRY WINSTON INC | Ring | 6906.25  |
| Mazda CX-5        | Car  | 32365.88 |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants',
        'Cake & Bread','Bubble Tea','Groceries','Pharmacy','Hair & Skin','Home Improvement','Office',
        'Electricity','Gas','Phone Bill','Supply','Television','Auto','Mortgage','HOA','Ride share/Car rental',
        'Hotel','Cash & ATM','Visa']
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
                {value:1329.06, name:'Food'},
                {value:60.43, name:'Health'},
                {value:85.26, name:'Shopping'},
                {value:1886.01, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:279.32, name:'Travel'},
                {value:465.62, name:'Misc'}
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
                {value: 437.94, name: 'Restaurants'},
                {value: 121.34, name: 'Cake & Bread'},
                {value: 433.31, name: 'Bubble Tea'},
                {value: 336.47, name: 'Groceries'},
                {value: 60.43, name: 'Pharmacy'},
                {value: 35, name: 'Hair & Skin'},
                {value: 19.1, name: 'Home Improvement'},
                {value: 31.16, name: 'Office'},
                {value: 127.55, name: 'Electricity'},
                {value: 35.18, name: 'Gas'},
                {value: 3.13, name: 'Phone Bill'},
                {value: 84.5, name: 'Supply'},
                {value: 15.49, name: 'Television'},
                {value: 1620.16, name: 'Auto'},
                {value: 1672.53, name: 'Mortgage'},
                {value: 424.44, name: 'HOA'},
                {value: 24.31, name: 'Ride share/Car rental'},
                {value: 255.01, name: 'Hotel'},
                {value: 100, name: 'Cash & ATM'},
                {value: 365.62, name: 'Visa'}
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
        data: ['2022/9','2022/10','2022/11','2022/12','2023/1','2023/2','2023/3','2023/4','2023/5','2023/6','2023/7','2023/8']
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
            data: [0, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 0, 0, 932.43, 1234.85, 1329.06]
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
            data: [5, 22.31, 102, 36.68, 61.46, 644.06, 142.41, 5, 5, 88.61, 0, 60.43]
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
            data: [391.13, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 398.71, 373.71, 1711.43, 1056.3, 85.26]
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
            data: [102.18, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 414.16, 166.7, 109.35, 308.18, 1886.01]
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
            data: [0, 46.64, 74.52, 61.37, 37, 113.76, 2146.71, 0, 3626.52, 55.31, 457.73, 279.32]
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
            data: [0, 100, 77.36, 0, 40, 0, 1361, 0, 0, 15, 95, 465.62]
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
            data: ['2022/04','2022/05','2022/06','2022/10','2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08']
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
            data: [1161.14, 1543.5, 979.38, 865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06],
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
            data: [447.04, 1470.26, 680.5, 556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26],
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
            data: [325.53, 315.63, 202.03, 157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01],
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
