---
title: Bookkeeping - 2023/01
date: 2023-07-12 12:19:52
tags: Finance
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 5104.74 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| Restaurants      | 656.57  | Food            | 1425.44 |
| Cake & Bread     | 62.89   | Food            |         |
| Bubble Tea       | 330.69  | Food            |         |
| Groceries        | 375.29  | Food            |         |
| Pharmacy         | 61.46   | Health          | 61.46   |
| Clothing         | 262.88  | Shopping        | 451.83  |
| Hair & Skin      | 9.54    | Shopping        |         |
| Home Improvement | 165.43  | Shopping        |         |
| Entertainment    | 13.98   | Shopping        |         |
| Electricity      | 125.74  | Utilities       | 609.5   |
| Gas              | 327.38  | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| Supply           | 127.76  | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Auto             | 10      | Utilities       |         |
| Mortgage         | 1672.53 | Mortgage & Rent | 2096.97 |
| HOA              | 424.44  | Mortgage & Rent |         |
| Ride Share       | 3       | Travel          | 37      |
| Ticket           | 34      | Travel          |         |
| Cash & ATM       | 40      | Misc            | 40      |

### Balance

| Income  | Spending | Balance |
| ------- | -------- | ------- |
| 5104.74 | 4722.2   | 382.54  |

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
        'Bubble Tea','Groceries','Pharmacy','Clothing','Hair & Skin','Home Improvement','Entertainment','Electricity',
        'Gas','Phone Bill','Supply','Television','Auto','Mortgage','HOA','Ride Share','Ticket','Cash & ATM']
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
                {value:1425.44, name:'Food'},
                {value:61.46, name:'Health'},
                {value:451.83, name:'Shopping'},
                {value:609.5, name:'Utilities'},
                {value:2096.97, name:'Mortgage & Rent'},
                {value:37, name:'Travel'},
                {value:40, name:'Misc'},
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
                {value: 656.57, name: 'Restaurants'},
                {value: 62.89, name: 'Cake & Bread'},
                {value: 330.69, name: 'Bubble Tea'},
                {value: 375.29, name: 'Groceries'},
                {value: 61.46, name: 'Pharmacy'},
                {value: 262.88, name: 'Clothing'},
                {value: 9.54, name: 'Hair & Skin'},
                {value: 165.43, name: 'Home Improvement'},
                {value: 13.98, name: 'Entertainment'},
                {value: 125.74, name: 'Electricity'},
                {value: 327.38, name: 'Gas'},
                {value: 3.13, name: 'Phone Bill'},
                {value: 127.76, name: 'Supply'},
                {value: 15.49, name: 'Television'},
                {value: 10, name: 'Auto'},
                {value: 1672.53, name: 'Mortgage'},
                {value: 424.44, name: 'HOA'},
                {value: 3, name: 'Ride Share'},
                {value: 34, name: 'Ticket'},
                {value: 40, name: 'Cash & ATM'}
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
        data: ['2022/2','2022/3','2022/4','2022/5','2022/6','2022/7','2022/8','2022/9','2022/10','2022/11','2022/12','2023/1']
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
            data: [813.19, 1207.9, 1161.14, 1543.5, 979.38, 0, 0, 0, 865, 1131.3, 1327.16, 1425.44]
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
            data: [11.09, 314.53, 5, 51.06, 352.78, 5, 5, 5, 22.31, 102, 36.68, 61.46]
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
            data: [325.59, 4428.25, 447.04, 1470.26, 680.5, 410.64, 177.83, 391.13, 556.55, 2341.89, 543.61, 451.83]
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
            data: [369.22, 444.48, 325.53, 315.63, 202.03, 165.16, 112.3, 102.18, 157.36, 168.02, 313.81, 609.5]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 2074.9, 2074.9, 2074.9, 2074.9, 2096.97, 2096.97, 2096.97]
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
            data: [0, 308.18, 3398.22, 998.23, 765.11, 0, 1706.14, 0, 46.64, 74.52, 61.37, 37]
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
            data: [6000, 0, 0, 50, 0, 0, 0, 0, 0, 0, 6000, 0]
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
            data: [0, 1015, 114.81, 0, 100, 95, 0, 0, 100, 77.36, 0, 40]
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
            data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/10','2022/11','2022/12','2023/01']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 865, 1131.3, 1327.16, 1425.44],
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 556.55, 2341.89, 543.61, 451.83],
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 157.36, 168.02, 313.81, 609.5],
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
        data: ['2022/02','2022/03','2022/04','2022/05','2022/06','2022/07','2022/08','2022/09','2022/10','2022/11','2022/12','2023/01']
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
            data: [3391.79, 6290.52, 6873.05, 4986.17, 7885.96, 7885.94, 8024.04, 4086.16, 2861.14, 5134.02, 8023.04, 5104.74],
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
            data: [-9461.6, -9660.85, -7394.25, -6371.19, -5101.51, -2750.7, -4076.17, -2573.21, -3822.76, -5992.06, -10379.6, -4722.2],
        }
    ]
};
{% endecharts %}

Last 12 months' balance: -1759.53
