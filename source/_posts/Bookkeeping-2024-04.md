---
title: Bookkeeping - 2024/04
date: 2024-07-21 13:04:42
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4439.64 | Income          | 4439.64 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Restaurants           | 443.16  | Food            | 1324.58 |
| Cake & Bread          | 123.07  | Food            |         |
| Bubble Tea            | 362.46  | Food            |         |
| Groceries             | 395.89  | Food            |         |
| Pharmacy              | 20.74   | Health          | 20.74   |
| Clothing              | 290.97  | Shopping        | 919.23  |
| Hair & Skin           | 67.73   | Shopping        |         |
| Home Improvement      | 560.53  | Shopping        |         |
| Electricity           | 36.57   | Utilities       | 440.6   |
| Gas                   | 212.86  | Utilities       |         |
| Phone Bill            | 0.3     | Utilities       |         |
| VPN                   | 27.67   | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Supply                | 27.66   | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 85.05   | Utilities       |         |
| Mortgage              | 1800.63 | Mortgage & Rent | 1800.63 |
| Souvenir              | 18.43   | Travel          | 18.43   |
| Cash & ATM            | 100     | Misc            | 126.56  |
| Annual                | 26.56   | Misc            |         |

### Balance

| Income  | Spending | Balance  |
| ------- | -------- | -------- |
| 4439.64 | 4650.77  | \-211.13 |

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
        data:['Food','Health','Shopping','Utilities','Mortgage & Rent','Travel','Misc','Restaurants','Cake & Bread','Bubble Tea','Groceries','Pharmacy','Clothing','Hair & Skin','Home Improvement','Electricity','Gas','Phone Bill','VPN','Network','Supply','Television','Auto','Mortgage','Souvenir','Cash & ATM','Annual']
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
                {value:1324.58, name:'Food'},
                {value:20.74, name:'Health'},
                {value:919.23, name:'Shopping'},
                {value:440.6, name:'Utilities'},
                {value:1800.63, name:'Mortgage & Rent'},
                {value:18.43, name:'Travel'},
                {value:126.56, name:'Misc'}
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
                { "value": 443.16, "name": "Restaurants" },
                { "value": 123.07, "name": "Cake & Bread" },
                { "value": 362.46, "name": "Bubble Tea" },
                { "value": 395.89, "name": "Groceries" },
                { "value": 20.74, "name": "Pharmacy" },
                { "value": 290.97, "name": "Clothing" },
                { "value": 67.73, "name": "Hair & Skin" },
                { "value": 560.53, "name": "Home Improvement" },
                { "value": 36.57, "name": "Electricity" },
                { "value": 212.86, "name": "Gas" },
                { "value": 0.3, "name": "Phone Bill" },
                { "value": 27.67, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 27.66, "name": "Supply" },
                { "value": 15.49, "name": "Television" },
                { "value": 85.05, "name": "Auto" },
                { "value": 1800.63, "name": "Mortgage" },
                { "value": 18.43, "name": "Souvenir" },
                { "value": 100, "name": "Cash & ATM" },
                { "value": 26.56, "name": "Annual" }
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
        bottom: 100
    },
    xAxis:  {
        type: 'value'
    },
    yAxis: {
        type: 'category',
        data: ['2023/5','2023/6','2023/7','2023/8','2023/9','2023/10','2023/11','2023/12','2024/1','2024/2','2024/3','2024/4']
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
            data: [0, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 302.13, 0, 751.72, 1324.58]
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
            data: [5, 88.61, 0, 60.43, 0, 14.28, 12.74, 0, 67.96, 0, 7.21, 20.74]
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
            data: [373.71, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 72.09, 2231.5, 226.12, 919.23]
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
            data: [166.7, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 380.43, 1763.79, 324.66, 440.6]
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
            data: [2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 1672.53, 2230.13, 1381.25, 2230.13, 1381.25, 2230.13, 1800.63]
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
            data: [3626.52, 55.31, 457.73, 279.32, 3155.32, 509.47, 30.81, 0, 18.79, 3776.05, 68.65, 18.43]
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
            data: [0, 15, 95, 465.62, 182.98, 60, 0, 0, 0, 0, 234, 126.56]
        }
    ]
}
{% endecharts %}

#### Detailed analysis(only the months fully in U.S.)

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
            data: ['2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/04']
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
            data: [1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 1324.58],
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
            data: [543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 919.23],
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
            data: [313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 440.6],
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
    toolbox: {
        show : true,
        feature : {
            dataView : {show: true, readOnly: false},
            magicType : {show: true, type: ['line', 'bar']},
            restore : {show: true},
            saveAsImage : {show: true}
        }
    },
    xAxis: {
        type : 'category',
        data: ['2023/05','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04']
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
                    position: 'insideTop'
                }
            },
            data: [4896.49, 4655.02, 4413.59, 4812.98, 8202.3, 5736.6, 5927.86, 8512.78, 4559.31, 4455.21, 6636.52, 4439.64],
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
            label: {
                normal: {
                    show: true,
                    position: 'insideBottom'
                }
            },
            data: [-6268.9, -5009.1, -5249.03, -6202.67, -8174.91, -4902.31, -4224.54, -11803.17, -3071.53, -9152.59, -3842.49, -4650.77],
        }
    ]
};
{% endecharts %}

{% echarts %}
{
    tooltip: {
        trigger: 'axis',
    },
    legend: {
        data: ['Balance']
    },
    xAxis: [
        {
            type: 'category',
            data: ['2023/05','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02','2024/03','2024/04']
        }
    ],
    yAxis: [
        {
            type: 'value'
        }
    ],
    grid: {
        bottom: 100
    },
    series: [
        {
            name: 'Balance',
            type: 'bar',
            stack: 'Total',
            areaStyle: {},
            emphasis: {
                focus: 'series'
            },
            label: {
                normal: {
                    show: true,
                    position: 'top'
                }
            },
            data: [-1372.41, -354.08, -835.44, -1389.69, 27.39, 834.29, 1703.32, -3290.39, 1487.78, -4697.38, 2794.03, -211.13]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(December): N/A