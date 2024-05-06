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
