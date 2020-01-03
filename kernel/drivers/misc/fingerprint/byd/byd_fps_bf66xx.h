/*
 * File:         byd_fps_bf66xx.h
 *
 * Created:	     2014-11-07
 * Depend on:    byd_fps_bf66xx.c
 * Description:  BYD Fingerprint IC driver for Android
 *               - Spreadtrum SP8932 configuration
 *
 * Copyright (C) 2014 BYD Company Limited
 *
 * Licensed under the GPL-2 or later.
 *
 * History:
 *
 * Contact: qi.ximing@byd.com;
 *
 */
#ifndef __FPS_BF66XX_H__
#define __FPS_BF66XX_H__
//#define PLATFORM_MTK             // MTK kernel 3.18 platform
//#define PLATFORM_MTK_KERNEL3_10  // MTK kernel 3.10 platform
//#define PLATFORM_QUALCOMM        // Qualcomm msm8909 platform
#define USE_ANDROID_M_ARCH
//#define PLATFORM_SPRD              //Spreadtrum SP8932 platform
#define PLATFORM_INGENIC
/*******************************************************************************
* ��һ���֣�ƽ̨������� - ͨѶ����
*     ͨѶ�����Ƕ��ж϶˿ڼ� SPI�ĳ�ʼ�����ã� SPI����ͨ����Kernel����������ļ�
*  dts�У�ͨ���� arch/arm/boot�У������������ض��ĳ�ʼ�������ļ��У�ͨ��Ϊ
*  arch/arm/mach-xxxx/board-xxxx.c����spi_board_info�ṹ�ж��壩���ж�����ͨ����
* ������ƽ̨����byd_fps_platform.c�Ķ˿����ú��� byd_fps_platform_init�С�
*     �� SPI�豸���ص�ƽ̨�� SPI���ߣ���Ҫ��֪ƽ̨���豸������BYD_FPS_DEV_NAME��
* ����SPI���߱�ż����豸 SPIͨѶ���ã�������Ҫ����֪ƽ̨��������豸���жϺ�
* BYD_FPS_IRQ_NUM�������ж϶˿ںš�
*******************************************************************************/

/* 1. �����ж� */

/* �жϴ������ͣ�����IC������һ�£���IRQF_TRIGGER_FALLING, IRQF_TRIGGER_LOW,
IRQF_TRIGGER_RISING, IRQF_TRIGGER_HIGH */
#define EINT_TRIGGER_TYPE  IRQF_TRIGGER_RISING

/* �ж������IRQ������Ϊһ��������ѡ */
//#define BYD_FPS_IRQ_NUM  9

/* �ж϶˿ںţ���ѡ
    �ж϶˿ں����ں���byd_fps_platform_init() �н����ж϶˿����á����⣬����޷�
ֱ�Ӹ����������ж�����ţ���������ж϶˿ں�*/
#ifndef BYD_FPS_IRQ_NUM
#define BYD_FPS_EINT_PORT  //GPIO_PA(21)�Ƶ�/arch/mips/xburst/soc-1000/chip-x1000/ilock/ilock-v20/board.h
#endif

/* 2. ��λ�˿ں� �� POWERʹ�ܶ˿ں�, ��ѡ */
#define BYD_FPS_RESET_PORT	//GPIO_PA(20)	//GPIO_FP_RST_PIN //BYD_FPS_RST_PIN ==GPIO97 //BYD_FPS_IRQ_PIN == GPIO99
#define BYD_FPS_POWER_PORT	//GPIO_PB(22)


/* 3. SPI�˿����� */
#define BYD_FPS_CSS_PORT	GPIO_SPI_CS_PIN
#define BYD_FPS_SCK_PORT	GPIO_SPI_SCK_PIN
#define BYD_FPS_MISO_PORT	GPIO_SPI_MISO_PIN
#define BYD_FPS_MOSI_PORT	GPIO_SPI_MOSI_PIN
#define BYD_FPS_CSS_PORT_MODE	GPIO_SPI_CS_PIN_M_SPI_CSA
#define BYD_FPS_SCK_PORT_MODE	GPIO_SPI_SCK_PIN_M_SPI_CKA
#define BYD_FPS_MISO_PORT_MODE	GPIO_SPI_MISO_PIN_M_SPI_MIA
#define BYD_FPS_MOSI_PORT_MODE	GPIO_SPI_MOSI_PIN_M_SPI_MOA

/* 4. SPI�ٶȣ�ʵ���ض���ƽ̨��ĿǰTINY4412, QUALCOMM�;�����Ч�� */
#define  BYD_FPS_SPI_SPEED  (1 * 1000 * 1000) // 3�� 1.8    (1 * 1000 * 1000)

#define SPI_OS_SPEED  1000 //ɨ��ʧ��ֵ��spi �ٶ����� ����1000k 64�λ���
#define SPI_FP_SPEED  6000 //ɨ��ָ��ͼ��ʱ��ʧ��ֵ���� ��6�λ��֣�6000k ��32�λ��֣�1300k

/* 5. mtkƽ̨����SPIÿ�ζ������������ƣ�ĳЩƽ̨��4BYTE���� */
//#define SPI_TRANS_4BYTE 

/*******************************************************************************
* �ڶ����֣�оƬ����
*******************************************************************************/

/* 1. оƬ�ͺ�ѡ��ֻ�ܵ�ѡ������ͬʱ��ѡ�� */
//#define CONFIG_FPS12  0x5040 
//#define CONFIG_FPS11  0x4840 
//#define CONFIG_FPS22    0x7040
#define  CONFIG_FPS05   0x5880
/* 2. �汾��Ϣ�����¸�ʽ��
      IC����-IC��װ��-�����汾��-�ͻ�����-��Ŀ����-�����汾���� */
#if defined(CONFIG_FPS12)
	#define BYD_FPS_DRIVER_DESCRIPTION  "FPS12B-BF663x-DRV4.11-CLIENT0000-PROJ00-PARA1.0"
#elif defined(CONFIG_FPS11)
	#define BYD_FPS_DRIVER_DESCRIPTION  "FPS11A-BF663x-DRV4.11-CLIENT0000-PROJ00-PARA1.0"
#elif defined(CONFIG_FPS22)
	#define BYD_FPS_DRIVER_DESCRIPTION  "FPS22A-BF663x-DRV4.11-CLIENT0000-PROJ00-PARA1.0"
#elif defined(CONFIG_FPS05)	
	#define BYD_FPS_DRIVER_DESCRIPTION  "FPS05A-BF663x-DRV4.11-CLIENT0000-PROJ00-PARA1.0"
#endif

#define BYD_FPS_FAE_FINGER_DOWN_DIFF	300 // 2000 // ����̧���ֵ

/*******************************************************************************
* �������֣��㷨��������
*******************************************************************************/

#if (defined BYD_FPS_ALG_IN_KERNEL) || (defined BYD_FPS_ALG_IN_TZ)
#ifdef USE_ANDROID_M_ARCH
#define CONFIG_TEMPLATE_FILE_PATH  "/media/"//"/data/system/fingerprint/"
#else
#define CONFIG_TEMPLATE_FILE_PATH  "/data/data/com.fingerprints.fps/files/template/"
#endif
#define CONFIG_ALG_NUM_PARA		//�����Ҫ�����㷨ģ�������������򿪸ú�
#define CONFIG_ALG_AREA_PARA	//�����Ҫ�����㷨��Ч����������򿪸ú�


// config maximum number of fingers and the number of templates per finger
#ifdef  CONFIG_ALG_NUM_PARA
#define CONFIG_ALG_MAX_NUM_FINGERS			  	    CONFIG_BYD_FINGERPRINT_MAX_NUM
#define CONFIG_ALG_NUM_TEMPLATES_PER_FENGER	  		3//8
#define CONFIG_ALG_MAX_NUM_TEMPLATES          		15//99//20		//һ����ָ���ģ������
#define CONFIG_ALG_SAME_FJUDGE                		1	//�Ƿ�����ͳһ��ָ¼��ͬһID��0������1��������
#endif

// config sensor area
#ifdef  CONFIG_ALG_AREA_PARA
#define CONFIG_ALG_SENSOR_VALID_ENROLL_AREA			50
#define CONFIG_ALG_SENSOR_INVALID_ENROLL_BLOCK		50
#define CONFIG_ALG_SENSOR_VALID_MATCH_AREA			60
#define CONFIG_ALG_SENSOR_INVALID_MATCH_BLOCK		60
#define CONFIG_ALG_SENSOR_INVALID_VARIANCE			6
#define CONFIG_ALG_SENSOR_MOVEXY					20
#endif

#endif // BYD_FPS_ALG_IN_KERNEL or BYD_FPS_ALG_IN_TZ


/*******************************************************************************
* ���Ĳ��֣��������� - �з��ڲ�ʹ��
*******************************************************************************/

/* �豸ID����������������ƽ̨���豸�����ļ��������SPI�豸����һ�� */
#define BYD_FPS_NAME "byd_fps"
#define BYD_FPS_FASYNC

/* �˿����÷�ʽ��
    ����˿�������ƽ̨�ˣ��豸�����ļ���˿����ú������У���򿪸ö��壬�����ʾ
���������Ķ˿����ú��� */
//#define BYD_FPS_PLATFORM_INIT

/* ��EARLYSUSPEND��FB��PM_SLEEP��LINUX SUSPEND/RESUMEΪ����˳����undef��������
   �߷�ʽ֮ǰ�����ж���*/
//#undef CONFIG_HAS_EARLYSUSPEND
#undef CONFIG_HAS_EARLYSUSPEND
#undef CONFIG_FB
#undef CONFIG_PM_SLEEP

/* SPI��probe�г�ʼ��ʧ�����⣬���ڸ���ͻ�ƽ̨���� */
#ifdef PLATFORM_MTK_KERNEL3_10
#define MTK_SPI_INIT_BUG_FIX
#endif

#define FPS_THREAD_MODE_IDLE             0
#define FPS_THREAD_MODE_ALG_PROC         1
#define FPS_THREAD_MODE_EXIT             6

#include <linux/semaphore.h>

/**
 * struct byd_fps_thread_task - thread task data
 * @mode:	current thread mode
 * @should_stop:	thread is supposed to be stopped
 * @sem_idle:
 * @wait_job:
 * @thread:
 *
 */
struct byd_fps_thread_task {
	int mode;
	int should_stop;
	struct semaphore sem_idle;
	wait_queue_head_t wait_job;
	struct task_struct *thread;
};


#endif
