作者姓名：杨子裕

第一测试版

硬件资源：

底盘电机和云台  		用CAN1
拨盘电机           	 	用CAN2

摩擦轮电机         		用PA6,PA7
弹仓舵机            	用PE11 TIM1

裁判系统            	用UART5
视觉                   	用UART4
遥控	        		用UART2
红外 	        		用PD9

电容: 	       			控制充电电流PA4 
						读取电容电压PA0 
						放电PA5 
						充电PA2

调试LED            	    用PC10 PC11 PC13 PC14

//						(APP)
main.c              	系统总体初始化
system.c				不同部分初始化（外设初始化），含斜坡函数
remote.c				遥控通讯的一些定义，以及按键的分配
stm32f4xx_it.c 			中断服务函数相关内容
control.c				系统控制判断及保护以及遥控模式的选择
kalman.c				一阶卡尔曼滤波的一些定义
kalman_filter.c			一阶卡尔曼滤波具体操作（角度和速度）
crc.c					裁判系统官方CRC校验
magazine.c				弹仓舵机的控制，含遥控和键盘两种控制模式
friction.c				摩擦轮电机具体不同工作状态下的射速测试文件（后期速度会分档固定）
super_cap.c				焦耳热，超级电容闭环控制，PID

//						（BSP）
can1.c					底盘和云台电机
can2.c					拨盘电机(fire)
usart.c                 串口2用于读取遥控器接收机数据;
pwm.c					摩擦轮电机
led.c					四个LED灯PC10/PC11/PC13/PC14
laser.c					激光灯
usart4.c				视觉串口通讯		PA0(TX)/PA1(RX)
usart5.c				裁判系统串口通讯	PC12(TX)/PD2(RX)
adda.c					超级电容以及数模转换/电压值获取
iwdg.c					看门狗

//						(task)
Task_Start.c			任务函数及其初始化
Task_Chassis.c			带有pid的底盘程序/其他半自动化程序/键盘操作模式
Task_Revolver.c			射击相关程序（不同发射模式）
Task_Gimbal				云台相关程序（不同射击条件下模式）

//						（AppInfo）
Info_Update.c
Info_Transmitter.c
judge.c
vision.c

//						(TIMER_TASK)
Timer_Send_Task.c

//						(SYSTEM)
usart.c
sys.c
delay.c

//						(MPU6050)
myiic.c
mpu6050.c
inv_mpu.c
inv_mpu_dmp_motion_driver.c
MPU_Temperature

//FreeRTOS_CORE