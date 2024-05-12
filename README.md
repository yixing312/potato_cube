# Readme

## Description

可以联动的屏幕小方块集群

以二维形式展开，可以累成屏幕墙（形状自定义,屏幕图案样式自定义）

需要一台主控机_分为两种模式：

1. 在机状态
   1. 自适应接受集群形状
   2. 输入图形样式等参数
   3. 联网发包
2. 离机状态
   1. 考虑额外空间
   2. 读取本地文件
   3. 生成图形
   4. 生成联动包
   5. 保存联动包

自适应如何实现

1. 每个小方块上电时开始随机一个ID，并通过发包向上位机
2. 发包至父节点后，父节点将自己的ID和子节点ID记录下来，并向上迭代
3. 上位机收包之后，对子节点信号进行回复，并向下迭代

需要那些模块

与周围节点通讯
给定一个正方向，第一个接入的节点就是父节点
沿节点方向拓展，同时发送物理地址。

外壳设计
小方块，单面屏幕，四面联动，联动面考虑磁吸接口，选择较小的开发板，预计接口数量为 Vcc+Gnd+SPI x 1+UART x 4

屏幕设计：先购买，如果屏幕不满足需求，考虑单色模糊像素块

## 引脚设计

四个串口占用 5~12 号针脚
剩余针脚可用：2~4，A0~A5 这些针脚
电源布线采用并联方式

```cpp
void testdrawrects(uint16_t color);
void testfillrects(uint16_t color1, uint16_t color2);
void testfillcircles(uint8_t radius, uint16_t color);
void testdrawcircles(uint8_t radius, uint16_t color);
void testtriangles();
void testroundrects();
void tftPrintTest();
void mediabuttons();
```

## 通讯设计

放弃中断设计，考虑在LOOP中加入伪中断

## 工作流程

上电，模块初始化，起床！
完成 Init( ) 函数执行，进入 Loop()

在循环开始位置写一个伪时间戳检查
根据时间戳写一个状态汇报器，状态汇报器向上汇报自己及子树是否存活
之后写一个伪中断函数，检查是否有新的数据包到来
每个数据包具备唯一任务码，检查数据包是否被执行过
如果有新的数据包，检查并处理，

之后开始任务状态机分类，正常任务状态是 playing 状态
此时根节点与子节点存在区别，根节点判断子节点形状，并发布任务序列

如果为连续四、五个，绘制时间
如果为正方形四个，绘制 Icenter 图标
其他情况，根据上位机指令绘制

## 指令集合

`{"cube":"Sunday"}`
