---
title: Bookkeeping - 2022/08
date: 2022-12-01 16:20:39
tags: 财务
hidden: true
---

## Overview

### Income

| Category         | Sum     |
| ---------------- | ------- |
| Paycheck         | 8024.04 |

### Spending

| Category         | Sum     | Section         | Sum     |
| ---------------- | ------- | --------------- | ------- |
| China Ecommerce  | 177.83  | Shopping        | 177.83  |
| Electricity      | 28.35   | Utilities       | 112.3   |
| Gas              | 45.63   | Utilities       |         |
| Phone Bill       | 3.13    | Utilities       |         |
| VPN              | 12.95   | Utilities       |         |
| Legal            | 6.75    | Utilities       |         |
| Television       | 15.49   | Utilities       |         |
| Mortgage         | 1650.46 | Mortgage & Rent | 2074.9  |
| HOA              | 424.44  | Mortgage & Rent |         |
| Pharmacy         | 5       | Health          | 5       |
| Air              | 1706.14 | Travel          | 1706.14 |
| Paycheck         | 8024.04 | Income          | 8024.04 |

### Balance

| Income    | Spending  | Cash flow     |
| --------- | --------- | ------------- |
| 8024.04   | 4076.17   | 3947.87       |

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
        data:['Health','Shopping','Utilities','Mortgage & Rent','Misc','Pharmacy','China Ecommerce','Electricity','Gas',
        'Phone Bill','Legal','Television','Mortgage','HOA','Annual']
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
                {value:177.83, name:'Shopping'},
                {value:112.3, name:'Utilities'},
                {value:2074.9, name:'Mortgage & Rent'},
                {value:5, name:'Health'},
                {value:1706.14, name:'Travel'},
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
                {value:177.83, name:'China Ecommerce'},
                {value:28.35, name:'Electricity'},
                {value:45.63, name:'Gas'},
                {value:3.13, name:'Phone Bill'},
                {value:12.95, name:'VPN'},
                {value:6.75, name:'Legal'},
                {value:15.49, name:'Television'},
                {value:1650.46, name:'Mortgage'},
                {value:424.44, name:'HOA'},
                {value:5, name:'Pharmacy'},
                {value:1706.14, name:'Air'},
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
        data: ['2021/11','2021/12','2022/1','2022/2','2022/3','2022/4','2022/5','2022/6','2022/7','2022/8']
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
            data: [1133.52, 1533.2, 1802.25, 813.19, 1207.9, 1161.14, 1543.5, 979.38, 0, 0]
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
            data: [11.68, 90.59, 86.89, 11.09, 314.53, 5, 51.06, 352.78, 5, 5]
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
            data: [783.8, 1850.21, 615.83, 325.59, 4428.25, 447.04, 1470.26, 680.5, 410.64, 177.83]
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
            data: [138.74, 232.84, 337.69, 369.22, 444.48, 325.53, 315.63, 202.03, 165.16, 112.3]
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
            data: [1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 1942.51, 2074.9, 2074.9]
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
            data: [49.98, 0, 28.5, 0, 308.18, 3398.22, 998.23, 765.11, 0, 1706.14]
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
            data: [0, 0, 6000, 6000, 0, 0, 50, 0, 0, 0]
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
            data: [0, 200, 0, 0, 1015, 114.81, 0, 100, 95, 0]
        }
    ]
}
{% endecharts %}

#### Detailed analysis

Not in U.S. this month, skip this part.