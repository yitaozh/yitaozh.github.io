---
title: Bookkeeping - 2024/02
date: 2024-07-20 17:34:58
tags: Finance
hidden: true
---

## Overview

### Income

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Paycheck              | 4455.21 | Income          | 4455.21 |

### Spending

| Category              | Sum     | Section         | Sum     |
| --------------------- | ------- | --------------- | ------- |
| Clothing              | 236.51  | Shopping        | 2231.5  |
| Luxury                | 1994.99 | Shopping        |         |
| Electricity           | 60.11   | Utilities       | 1763.79 |
| Gas                   | 242.39  | Utilities       |         |
| Phone Bill            | 0.3     | Utilities       |         |
| VPN                   | 3.5     | Utilities       |         |
| Network               | 35      | Utilities       |         |
| Television            | 15.49   | Utilities       |         |
| Auto                  | 1407    | Utilities       |         |
| Mortgage              | 1381.25 | Mortgage & Rent | 1381.25 |
| Air                   | 1832.23 | Travel          | 3776.05 |
| Ride share/Car rental | 37.19   | Travel          |         |
| Hotel                 | 1055.22 | Travel          |         |
| Travel Misc           | 851.41  | Travel          |         |

### Balance

| Income  | Spending | Balance   |
| ------- | -------- | --------- |
| 4455.21 | 9152.59  | \-4697.38 |

### More than $10,000

| Item | Type | Amount |
| ---- | ---- | ------ |
| N/A  | N/A  | N/A    |

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
        data:['Shopping','Utilities','Mortgage & Rent','Travel','Clothing','Luxury','Electricity','Gas','Phone Bill','VPN','Network','Television','Auto','Mortgage','Air','Ride share/Car rental','Hotel','Travel Misc']
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
                {value:2231.5, name:'Shopping'},
                {value:1763.79, name:'Utilities'},
                {value:1381.25, name:'Mortgage & Rent'},
                {value:3776.05, name:'Travel'}
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
                { "value": 236.51, "name": "Clothing" },
                { "value": 1994.99, "name": "Luxury" },
                { "value": 60.11, "name": "Electricity" },
                { "value": 242.39, "name": "Gas" },
                { "value": 0.3, "name": "Phone Bill" },
                { "value": 3.5, "name": "VPN" },
                { "value": 35, "name": "Network" },
                { "value": 15.49, "name": "Television" },
                { "value": 1407, "name": "Auto" },
                { "value": 1381.25, "name": "Mortgage" },
                { "value": 1832.23, "name": "Air" },
                { "value": 37.19, "name": "Ride share/Car rental" },
                { "value": 1055.22, "name": "Hotel" },
                { "value": 851.41, "name": "Travel Misc" }
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
        data: ['2023/3','2023/4','2023/5','2023/6','2023/7','2023/8','2023/9','2023/10','2023/11','2023/12','2024/1','2024/2']
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
            data: [721.14, 0, 0, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28, 302.13, 0]
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
            data: [142.41, 5, 5, 88.61, 0, 60.43, 0, 14.28, 12.74, 0, 67.96, 0]
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
            data: [194.85, 398.71, 373.71, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76, 72.09, 2231.5]
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
            data: [431.22, 414.16, 166.7, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88, 380.43, 1763.79]
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
            data: [2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 2096.97, 1672.53, 2230.13, 1381.25, 2230.13, 1381.25]
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
            data: [2146.71, 0, 3626.52, 55.31, 457.73, 279.32, 3155.32, 509.47, 30.81, 0, 18.79, 3776.05]
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
            data: [1361, 0, 0, 15, 95, 465.62, 182.98, 60, 0, 0, 0, 0]
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
            data: ['2022/11','2022/12','2023/01','2023/02','2023/03','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12']
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
            data: [1131.3, 1327.16, 1425.44, 971.34, 721.14, 932.43, 1234.85, 1329.06, 1383.72, 1400.12, 908.48, 477.28],
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
            data: [2341.89, 543.61, 451.83, 158.37, 194.85, 1711.43, 1056.3, 85.26, 816.04, 772.85, 729.09, 3055.76],
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
            data: [168.02, 313.81, 609.5, 500.74, 431.22, 109.35, 308.18, 1886.01, 539.88, 473.06, 313.29, 391.88],
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
        data: ['2023/03','2023/04','2023/05','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02']
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
            data: [7332.06, 4841.42, 4896.49, 4655.02, 4413.59, 4812.98, 8202.3, 5736.6, 5927.86, 8512.78, 4559.31, 4455.21],
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
            data: [-7094.3, -2914.84, -6268.9, -5009.1, -5249.03, -6202.67, -8174.91, -4902.31, -4224.54, -11803.17, -3071.53, -9152.59],
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
            data: ['2023/03','2023/04','2023/05','2023/06','2023/07','2023/08','2023/09','2023/10','2023/11','2023/12','2024/01','2024/02']
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
            data: [237.76, 1926.58, -1372.41, -354.08, -835.44, -1389.69, 27.39, 834.29, 1703.32, -3290.39, 1487.78, -4697.38]
        },
    ]
};
{% endecharts %}

Last 12 months' balance(for June and December): N/A
