# todo

- [x] 首先实现伪时间戳检查
- [x] 实现只有一个节点的情况，此时未找到兄弟们，首先处于Awake状态，渲染开机动画，然后进入ShakeHand状态,寻找兄弟并绘制动画
- [ ] 寻找兄弟的过程中绘制土豆表情序列动画，根据伪时间戳判断是否绘制下一个表情
- [ ] 寻找兄弟的过程中监控硬件串口和所有软件串口，如果找到硬件串口标识，则进入 Sunday 状态，Sunday 状态作为中心机器人，负责协调所有机器人的工作。我将赋予诸位直视太阳的权利
- [ ] 寻找兄弟的过程中如果超过20秒未找到兄弟或者父亲，说明他是孤儿，进入孤儿状态
