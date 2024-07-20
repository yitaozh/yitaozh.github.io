---
title: Bookkeeping - 2023/11
date: 2024-07-18 00:59:03
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 5927.86 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 324.78  | Food            | 908.48  |
| Cake & Bread          | 22.5    | Food            |         |
| Bubble Tea            | 309.4   | Food            |         |
| Groceries             | 251.8   | Food            |         |
| Pharmacy              | 12.74   | Health          | 12.74   |
| Clothing              | 315.16  | Shopping        | 729.09  |
| Hair & Skin           | 260.53  | Shopping        |         |
| Home Improvement      | 153.4   | Shopping        |         |
| Electricity           | 77.76   | Utilities       | 313.29  |
| Gas                   | 49.44   | Utilities       |         |
| Phone Bill            | 3.13    | Utilities       |         |
| VPN                   | 3.18    | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 58.1    | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 71.19   | Utilities       |         |
| Mortgage              | 1381.25 | Mortgage & Rent | 2230.13 |
| HOA                   | 848.88  | Mortgage & Rent |         |
| Travel Misc           | 30.81   | Travel          | 30.81   |

### Balance

| Income  | Spending | Balance |
| ------- | -------- | ------- |
| 5927.86 | 4224.54  | 1703.32 |

### More than $10,000

N/A

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Restaurants','Cake & Bread','Bubble Tea',
        'Groceries','Pharmacy','Clothing','Hair & Skin','Home Improvement','Electricity','Gas','Phone Bill','VPN','Network',
        'Supply','Television','Auto','Mortgage','HOA','Travel Misc']
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
                {value:908.48, name:'Food'},
                {value:12.74, name:'Health'},
                {value:729.09, name:'Shopping'},
                {value:313.29, name:'Utilities'},
                {value:2230.13, name:'Mortgage & Rent'},
                {value:30.81, name:'Travel'}
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
                { "value": 324.78, "name": "Restaurants" },
                { "value": 22.5, "name": "Cake & Bread" },
                { "value": 309.4, "name": "Bubble Tea" },
                { "value": 251.8, "name": "Groceries" },
                { "value": 12.74, "name": "Pharmacy" },
                { "value": 315.16, "name": "Clothing" },
                { "value": 260.53, "name": "Hair & Skin" },
                { "value": 153.4, "name": "Home Improvement" },
                { "value": 77.76, "name": "Electricity" },
                { "value": 49.44, "name": "Gas" },
                { "value": 3.13, "name": "Phone Bill" },
                { "value": 3.18, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 58.1, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 71.19, "name": "Auto" },
                { "value": 1381.25, "name": "Mortgage" },
                { "value": 848.88, "name": "HOA" },
                { "value": 30.81, "name": "Travel Misc" }
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
        data: ['2022/12','2023/1','2023/2','2023/3','2023/4','2023/5','2023/6','2023/7','2023/8','2023/9','2023/10','2023/11']
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
            data: [1327.16, 1425.44, 971.34, 721.14, 0, 0, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48]
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
            data: [36.68, 61.46, 644.06, 142.41, 5, 5, 88.61, 0, 60.43, 0, 14.28, 12.74]
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
            data: [543.61, 451.83, 158.37, 194.85, 398.71, 373.71, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09]
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
            data: [313.81, 609.5, 500.74, 431.22, 414.16, 166.7, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29]
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
            data: [2074.9, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 1672.53, 2230.13]
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
            data: [61.37, 37, 113.76, 2146.71, 0, 3626.52, 55.31, 457.73, 279.32, 3155.32, 509.47, 30.81]
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
            data: [0, 40, 0, 1361, 0, 0, 15, 95, 465.62, 182.98, 60, 0]
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
            data: ['2022/10','2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11']
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
            data: [865, 1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48],
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
            data: [556.55, 2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09],
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
            data: [157.36, 168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29],
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
    xAxis: {
        type : 'category',
        data: ['2022/12','2023/01','2023/02','2023/03','2023/04','2023/05','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11']
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
                    position: 'top',
                    formatter: function(params) {
                        let val=0;
                        this.option.series.forEach(s => {
                            val+=s.data[params.dataIndex];
                        } );
                        return parseFloat(val).toFixed(2);
                    },
                    fontWeight: "bold",
                    textBorderColor: "black", // 文字本身的描边颜色。
                    textBorderWidth: 0.4, // 文字本身的描边宽度。
                }
            },
            data: [8023.04, 5104.74, 5151.82, 7332.06, 4841.42, 4896.49, 4655.02, 4413.59, 4812.98, 8202.3, 5736.6, 5927.86],
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
            data: [-10379.6, -4722.2, -4485.24, -7094.3, -2914.84, -6268.9, -5009.1, -5249.03, -6202.67, -8174.91, -4902.31, -4224.54],
        }
    ]
};
{% endecharts %}

Last 12 months' balance: -529.72
