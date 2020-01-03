/*
 * BYD_drv.h
 *
 *  Created on: 2017-5-3
 */

#ifndef BYD_FPS05_DRV_H_
#define BYD_FPS05_DRV_H_


//#include <stdint.h>


/**************************************************************************
* Global Macro Definition
***************************************************************************/

#define  DIV_VALUE      10
#define  VERVAL         0x80
#define  FGLIMIT_NUM    0x400
#define  ARRAY_LEN      (10)

#define  SPI_WR     1
#define  SPI_RD     0

//--------------return code-------------
#define RT_OK              0x00 //success
#define RT_FAIL            0x01 //fail
#define RT_NO_FG           0x02 //����ָ
#define RT_CHIP_RESET_OK   0x03 //оƬ��λ�ɹ�
#define RT_CHIP_RESET_FAIL 0x04 //оƬ��λʧ��
#define RT_CHIP_FAIL       0x05 //оƬ����ʹ��
#define RT_FG_ERROR        0xFF //оƬ��ָ��������������


//#define FINGER_DOWN    0xaa
//#define FINGER_UP      0x55

//------- FPS15 Register definition --------------
#define CONFIG_FPS05_SENSOR

#ifdef  CONFIG_FPS05_SENSOR

//fps
#define REG_FP_SENSOR_MODE     0x01
#define REG_FP_TX_CLK_SEL      0x02
#define REG_FP_TX_CLK_H_TIME   0x03
#define REG_FP_SEN_RST_TIME    0x04
#define REG_FP_INIT_NUM        0x06


//fps
#define REG_FIR_CMD            0x09
#define REG_FIR_DATA           0x0A
#define REG_DIG_INTE_SEL       0x0B

#define REG_ADC_DP_MODE        0x0E
#define REG_DUMMY_CFG_H        0x0F
#define REG_DUMMY_CFG_L        0x10
#define REG_FPD_DATA           0x11

#define REG_SRAM_EMPTY         0x13

//finger
#define REG_FG_SENSOR_MODE     0x14
#define REG_FG_TX_CLK_SEL      0x15
#define REG_FG_TX_CLK_H_TIME   0x16
#define REG_FG_SEN_RST_TIME    0x17
#define REG_FG_INIT_NUM        0x19

//finger

#define REG_FPD_TH_ON_H        0x1B
#define REG_FPD_TH_ON_L        0x1C
#define REG_FPD_TH_OFF_H       0x1D
#define REG_FPD_TH_OFF_L       0x1E
#define REG_INT_FINGER_CFG     0x1F

#define REG_FINGER_STATE       0x21
#define REG_SUB_VALUE_H        0x22
#define REG_SUB_VALUE_L        0x23

//sys
#define REG_CHIP_MODE          0x30
#define REG_AREA_ROW_START     0x31
#define REG_AREA_ROW_END       0x32

 
//sys
#define REG_FG_REST_TI1		     0x35
#define REG_FG_REST_TI2	       0x36
#define REG_CFG_FLAG	         0x37
#define REG_RST_STATE	         0x38
#define REG_SOFT_RST	         0x39
#define REG_INT_STATE	         0x3A
#define REG_INT_STATE_CLR	     0x3B


#define REG_INT_CFG		         0x3D
#define REG_IO_STATE_SEL	     0x3E
#define REG_PD_ANA_A	         0x3F
#define REG_PD_ANA_B	         0x40

//sys

#define REG_ANA_INIT_TIME	    0x42
#define REG_ADC_I_SEL	        0x43
#define REG_SEN_BUF_I	        0x44
#define REG_IN_PHASE	        0x45
#define REG_SH_I_SEL	        0x46
#define REG_TX_CFG	            0x47
#define REG_RING_SEL	        0x4A

#define REG_DUMMY_SFR_1       0x57
//key
#define REG_SYS_CLK_SEL	      0x58
#define REG_FINGER_CFG	      0x59
#define REG_FG_ERROR_STATE	  0x5A
#define REG_IO_CFG	          0x5B

#define REG_KEY_SCAN_CFG	    0x6E
#define REG_BASE_RST_CFG	    0x6F
#define REG_KEY_THD_H	        0x70
#define REG_KEY_THD_L	        0x71
#define REG_BASE_RST_THD_H	  0x72
#define REG_BASE_RST_THD_L	  0x73
#define REG_KEY_BARREL_THD	  0x74
#define REG_KEY_BASELINE_H	  0x75
#define REG_KEY_BASELINE_L	  0x76
#define REG_KEY_DATA_H	      0x77
#define REG_KEY_DATA_L	      0x78
#define REG_KEY_TEST_MODE	    0x79


//fpd����
#define REG_FPD_TEST_MODE	   0x24//
#define REG_FPD_TEST_CFG	   0x25

//OTP
#define REG_SFR_OTP_CMD			0x63
#define REG_SFR_OTP_DATA		0x64
#define REG_OTP_CMD				0x65
#define REG_OTP_DATA			0x66
#define REG_OTP_SFR_CMD	     	0x63
#define REG_OTP_SFR_DATA	    0x64
//�޵��Ĵ���
#define REG_ADJ_SFR_ADDR	   0x68
#define REG_ADJ_SFR_DATA	   0x6B

//��ָʧ��ֵ�Ĵ���
#define REG_FINGER_OSDATA_H	   0x5B
#define REG_FINGER_OSDATA_L	   0x5C

//��Ʒ��Ϣ�Ĵ���
#define REG_CHIP_INFO_L   0x69
#define REG_CHIP_INFO_H	  0x6A
#define VAL_CHIP_INFO_LA  0x81
#define VAL_CHIP_INFO_LB  0x94
#define VAL_CHIP_INFO_H	  0x5E

//interrupt state  mask & constants
#define BYD_FPS_IRQ_FG_ERROR      0x10
#define BYD_FPS_IRQ_TIMER	        0x08
#define BYD_FPS_IRQ_FINGER	      0x0c
//#define BYD_FPS_IRQ_NOFINGER	    0x04
#define BYD_FPS_IRQ_DATA_ERROR    0x02
#define BYD_FPS_IRQ_DATA_READY	  0x01

#endif


//------- FPS05 normalmode Register value definition --------------

//fps
#define VAL_FP_SENSOR_MODE     0x02
#define VAL_FP_TX_CLK_SEL      0x00
#define VAL_FP_TX_CLK_H_TIME   0x1f
#define VAL_FP_SEN_RST_TIME    0x1c
#define VAL_FP_INIT_NUM        0x03


//
#define VAL_REG_FIR_CMD_WR     0x58
#define VAL_REG_FIR_CMD_RD     0xa3

//#define VAL_DIG_INTE_SEL       0x07//ָ��ɨ����ִ��� 16

//#define VAL_DIG_INTE_SEL       0x03//ָ��ɨ����ִ��� 8

#define VAL_DIG_INTE_SEL       0x02//ָ��ɨ����ִ��� 6



#define VAL_SRAM_EMPTY         0x00

//finger
#define VAL_FG_SENSOR_MODE    0x02
#define VAL_FG_TX_CLK_SEL     0x14
#define VAL_FG_TX_CLK_H_TIME  0x1f
#define VAL_FG_SEN_RST_TIME   0x1c
#define VAL_FG_INIT_NUM       0x03

#define VAL_FPD_TH_ON_H       0xff
#define VAL_FPD_TH_ON_L       0x0f
#define VAL_FPD_TH_OFF_H      0xff
#define VAL_FPD_TH_OFF_L      0x0f

#define VAL_INT_FINGER_CFG    0x01//0x00 //1�������� 0����������
#define VAL_INT_FINGER_NUM    0x00
#define VAL_FINGER_STATE      0x00

//sys
#define VAL_FG_REST_TI1		  0x01//�춨ʱ
#define VAL_FG_REST_TI2	   	  0x13//0x04//0x09//0x13//0x27//0x31//0x63//c7����ʱ
#define VAL_FG_T1_TI2_STEP	5   //��ʱ����ms��оƬ�ڲ��̶�ֵ�������޸�

#define VAL_INT_STATE	      0x00
#define VAL_INT_STATE_CLR	  0x00

/////////////////////////////////////////////////////////////////////////////////////////////
#define BYD_SWITCH_INT_WIDTH_EN  0//�л�INT����ʹ�ܣ��͹�����ָɨ��ʱ����䳤

#define VAL_INT_LEVEL       0x01//1:H;0:L
#define VAL_INT_WIDTH       0x00//(VAL_INT_WIDTH+1)*8ms <= (VAL_FG_REST_TI1+1)*5
#define VAL_INT_CFG		      ((VAL_INT_LEVEL<<4)|VAL_INT_WIDTH)

#define VAL_LOWPOWER_INT_WIDTH  0x05//(VAL_LOWPOWER_INT_WIDTH+1)*8ms <= (VAL_FG_REST_TI2+1)*5
#define VAL_LOWPOWER_INT_CFG		((VAL_INT_LEVEL<<4)|VAL_LOWPOWER_INT_WIDTH)
//////////////////////////////////////////////////////////////////////////////////////////////
#define VAL_SPI_PULLDOWN_EN   0x00
#define VAL_FINGERFLAG_LEVEL  0x00//0:H; 1:L
#define VAL_FINGERFLAG_OUTPUT 0x00//0:ENABLE; 1:CLOSE
#define VAL_IO_STATE_SEL	    ((VAL_SPI_PULLDOWN_EN<<5)|(VAL_FINGERFLAG_LEVEL<<4)|(VAL_FINGERFLAG_OUTPUT<<3)|0x00)

//
#define VAL_ANA_INIT_TIME	    0x02
#define VAL_ADC_I_SEL	        0x02
#define VAL_SEN_BUF_I	        0x01
#define VAL_IN_PHASE	        0x0a
#define VAL_SH_I_SEL	        0x01


#define BYD_SH_METHOD_SEL   0//��ʧ��ֵ���� 
                             //0 ������ʧ����������Ҫ����FLASH; 
                             //2 ����ʽ������������FLASH

														 
#if (BYD_SH_METHOD_SEL ==0) || (BYD_SH_METHOD_SEL == 1)
#define VAL_ADC_DP_MODE       0x00
#elif BYD_SH_METHOD_SEL == 2
#define VAL_ADC_DP_MODE       0x02
#else
#define VAL_ADC_DP_MODE       0x03
#endif

#if BYD_SH_METHOD_SEL==0
#define VAL_RING_SEL	        0xf3
#else
#define VAL_RING_SEL	        0xf8
#endif

#if BYD_SH_METHOD_SEL==0
#define VAL_RING_SEL_EN     0//����Ӧ�ã�1ʹ�� 0�ر�
#else
#define VAL_RING_SEL_EN     1//����ʹ�ܣ������޸�
#endif

#if VAL_RING_SEL_EN==0
#define VAL_PD_ANA_A	      0x00//0x20//
#define VAL_PD_ANA_B	      0x00//0x02//
#define VAL_TX_CFG	        0x31//0x01//
#else
#define VAL_PD_ANA_A	      0x00
#define VAL_PD_ANA_B	      0x00
#if BYD_SH_METHOD_SEL==0
#define VAL_TX_CFG	        0x71//���⼤�����
#else
#define VAL_TX_CFG	        0x70//�ⲿ�������̶������޸�
#endif
#endif

#if (BYD_SH_METHOD_SEL==0) && (VAL_RING_SEL_EN==1)
#define BYD_FINGER_DETECT_TX_SEL  0   //0 ��ָ��ɨ��ͬ����tx����; 1 ��ָ���ʱ�л�Ϊֻ���ⲿ����
#define FINGER_VAL_TX_CFG         0x70//��ָ���ʱ�ر��ڲ�����
#else
#define BYD_FINGER_DETECT_TX_SEL  0 //�̶������޸�
#endif

//key
#define VAL_SYS_CLK_SEL	  		0x00//0x03//

#define TOUCH_KEY_EN      		0x00//����5323����Ҫ�رհ������,����������Ҳ�رռ�⼴����0x00;���ó�0x01��ʾ��������⹦�ܡ�
#define TOUCH_SEN_EN      		0x01
#define KEY_ERROR_NUM     		0x0f//bit[5:2](KEY_ERROR_NUM+1)*16
#define VAL_FINGER_CFG	  		((KEY_ERROR_NUM<<2)|(TOUCH_KEY_EN<<1)|TOUCH_SEN_EN)
     
#define RXD_PULLUP_EN     		0x01//bit6
#define TXD_PULLUP_EN     		0x01//bit5
#define KEY_IO_STATE          0x01//bit4
#define TX_SR_EN              0x00//bit3
#define TX_SR_SEL             0x07//bit[2:0]
#define VAL_IO_CFG	          ((RXD_PULLUP_EN<<6)|(TXD_PULLUP_EN<<5)|(KEY_IO_STATE<<4)|(TX_SR_EN<<3)|TX_SR_SEL)

#define VAL_KEY_SCAN_CFG	    0x01

#define BASE_RST_SEL          0x02//0:1/1; 1:1/2; 2:1/4; 3:1/8
#define BASE_RST_NUM          0x04
#define VAL_BASE_RST_CFG	    ((BASE_RST_SEL<<4)|BASE_RST_NUM)

#define VAL_KEY_THD_H	        0x00
#define VAL_KEY_THD_L	        0x50//0x3c//60
#define VAL_BASE_RST_THD_H	  0x00
#define VAL_BASE_RST_THD_L	  0x28//0x1e//30
#define VAL_KEY_BARREL_THD	  0x0f

#define VAL_KEY_TEST_MODE	    0x00

#define BYD_KEY_RESET_EN	    1//0
#define VAL_KEY_BASELINE_H	  0x00
#define VAL_KEY_BASELINE_L	  0x64

//---------------------------------------------------------------

//------- FPS05 testmode Register value definition -------------- 


//ָ��ɨ�����ݼĴ���
#define TEST_VAL_DIG_INTE_SEL       0x1F//64 ָ��ɨ����ִ���
#define TEST_VAL_TX_CFG	            0x30
#define TEST_VAL_ADC_DP_MODE        0x00

//---------------------------------------------------------------

//------- FPS05 dummy Register and spi comunication mode --------------

#define BYD_FPS_READ_DMA_ENABLE         0//DMA��ָ������ʹ��,ʵ�ֲ��д������ݣ���Լʱ�����֡Ƶ���Ƽ��÷�ʽ

//������SPI���ʸ���ָ��ɨ���ٶ�ʱ��Ҫ����dummy,��ʽ 1 SPIͨ��; 0 ��ʱ;
#if BYD_FPS_READ_DMA_ENABLE

#define BYD_FPS_READ_DUMMY_SELECT       1//�����޸�
#define BYD_FPS_SET_DUMMY_REG_EN        0//���û�ȡͼ��dummy�Ĵ���ʹ��
#define BYD_FPS_SET_TESTDUMMY_REG_EN    0//���û�ȡʧ��dummy�Ĵ���ʹ��

#else //

#define BYD_FPS_READ_DUMMY_SELECT       0//��ͨSPIͨ�ŷ�ʽ�Ƽ���ʱ

#if BYD_FPS_READ_DUMMY_SELECT==0

#define BYD_FPS_SET_DUMMY_REG_EN        0//�����޸�
#define BYD_FPS_SET_TESTDUMMY_REG_EN    0//�����޸�

#define BYD_FPS_DUMMY_DELAYTIME_EN      0//1//��ȡͼ����ʱʹ��
#define BYD_FPS_DUMMY_DELAYTIME         7//��ʱus ��ȡͼ��

#define BYD_FPS_TESTDUMMY_DELAYTIME_EN  0//1//��ȡʧ��ֵ��ʱʹ��
#define BYD_FPS_TEST_DUMMY_DELAYTIME    190//��ʱus ��ȡʧ��ֵ

#else

#define BYD_FPS_SET_DUMMY_REG_EN        0//���û�ȡͼ��dummy�Ĵ���ʹ��
#define BYD_FPS_SET_TESTDUMMY_REG_EN    0//���û�ȡʧ��dummy�Ĵ���ʹ��

#endif
#endif

#if BYD_FPS_SET_DUMMY_REG_EN

#define VAL_DUMMY_CFG_H        0x00
#define VAL_DUMMY_CFG_L        0x09 //0x09(6�λ���) //0x17(8�λ���) //0x32(16�λ���)
//#define VAL_DUMMY_CFG_L        0x07 //0x07(6�λ���) //0x0f(8�λ���) //0x2f(16�λ���)

#else //

#define VAL_DUMMY_CFG_H        0x00
#define VAL_DUMMY_CFG_L        0x00

#endif

#if BYD_FPS_SET_TESTDUMMY_REG_EN

#define TEST_VAL_DUMMY_CFG_H        0x00
#define TEST_VAL_DUMMY_CFG_L        0xfa

#else
#define TEST_VAL_DUMMY_CFG_H        0x00
#define TEST_VAL_DUMMY_CFG_L        0x00

#endif

#define VAL_DUMMY_CFG          ((VAL_DUMMY_CFG_H<<8)|VAL_DUMMY_CFG_L)
#define TEST_VAL_DUMMY_CFG     ((TEST_VAL_DUMMY_CFG_H<<8)|TEST_VAL_DUMMY_CFG_L)
//---------------------------------------------------------------

//�޵��Ĵ���
#define VAL_ADJ_SFR_ADDR_H	   0x69
#define VAL_ADJ_SFR_ADDR_L	   0x6A
#define VAL_ADJ_SFR_DATA_H	   0x00
#define VAL_ADJ_SFR_DATA_L	   0xC0


//����ģʽ����
#define VAL_CHIP_MODE_IDLE              0x00//����
#define VAL_CHIP_MODE_FINGER            0x33//��ָɨ��,�춨ʱ
#define VAL_CHIP_MODE_FINGER_LOWPOWER   0x55//��ָɨ��,����ʱ,�͹�����ָɨ��
#define VAL_CHIP_MODE_FPD               0xAA//ָ��ɨ��
#define VAL_CHIP_MODE_SLEEP             0xCC//����

//�İ�ģʽ����
#define VAL_CHIP_MODE_IDLE_SEC              0x55//����
#define VAL_CHIP_MODE_FINGER_SEC            0x66//��ָɨ��,�춨ʱ
#define VAL_CHIP_MODE_FINGER_LOWPOWER_SEC   0x00//��ָɨ��,����ʱ,�͹�����ָɨ��
#define VAL_CHIP_MODE_FPD_SEC               0xff//ָ��ɨ��
#define VAL_CHIP_MODE_SLEEP_SEC             0x99//����

#define CHIP_NORMALMODE                 0x11//��������ģʽ,��ȡͼ������
#define CHIP_TESTMODE                   0x22//ģ����Թ���ģʽ,��ȡʧ��ֵ

#define VAL_CHIP_IDENTIFY_ONE   0x01//ԭ��
#define VAL_CHIP_IDENTIFY_SEC   0x02//�İ�

#define BYD_OTP_OS_NUM         20
#define OS_STA_MAX_NUM         25
#define COLUMN_DATA_NUM        20//һ��ÿ1/8�����ݸ��� = 160/8

//-------------------- debug definition --------------
//#define DEBUG_MSG

//#define BYD_FPS_IMAGE_WIDTH	      160
//#define BYD_FPS_IMAGE_HEIGHT	    160
//#define BYD_FPS_IMAGE_BUFFER_SIZE 51200//(160 * 160 * 2)
#define BYD_FPS_READ_ROW_BUFMAX   240//((BYD_FPS_IMAGE_WIDTH*3)/2)//��оƬһ�����ݸ����������޸�

#define BYD_FPS_IMAGEDATA_MAXVALUE      4095//����12bit���ֵ��4095

#define BYD_FPS_DEADPOINT_MAX           30//��󻵵����                                     

#define BYD_FPS_WAIT_IRQ_ENABLE         0//�ȴ�ָ���ж�ʹ��
//#define BYD_FPS_DEFAULT_IRQ_TIMEOUT     500//ָ�Ƽ��ȴ��жϵ�ƽʱ��

//#define BYD_FINGER_WAIT_IRQ_ENABLE      0//�ȴ���ָ�ж�ʹ��
//#define BYD_FINGER_DEFAULT_IRQ_TIMEOUT  500//��ָ���ȴ��жϵ�ƽʱ��

																				 
#define BYD_FPS_IMADGEDATA_MEMORY_SELECT  0 //�洢����ͼ�����ݷ�ʽ,��Ϸ�ʽ�����˶�ȡʱ��ʹ��봦��ĸ��Ӷ� 
																					  //0 �洢37.5k(3���ֽ��������12bit��ʽ 160*160*3/2)
																				    //1 �洢50k(�ߵ�8λֱ�Ӵ洢����� 160*160*2)

#define BYD_FPS_DEADPOINT_HANDLE        1//0//���㴦��1 ʹ�� 0�ر�


#define IMAGE_DIFFERDATA_THD            100//�ж���û�д���
																					 //�жϷ�ʽ�Ǽ�����ѡ������ָ���������ֵ����Сֵ֮�С�ڸ�ֵ��Ϊû�д���
#define IMAGE_WHITEDATA_PERCENT_A       9//ͳ��ͼ��İ׵������������ٷֱ�(160*160)*IMAGE_WHITEDATA_PERCENT_A/16��Ϊ��Ч

#define BYD_FPS_CHANGE_8BITS           1//16ת8bit
#define IMAGE_JUDGE_ENABLE             0//ͼ���ж�,Ĭ�Ϲر�
#define IMAGE_SHOW_ENABLE              0//��256*288�ֱ�����ʾͼ��

#if BYD_SH_METHOD_SEL==0
#define READ_OFFSETVAL_FROM_FLASH_EN    1//��flash�ж�ȡʧ��ֵʹ��
#define OFFSETVAL_FLASH_ADDRESS         ((uint32_t)0x08020000U) //���ʧ��ֵ��flash��ַ
#define OFFSETVAL_FLASH_WRITE_SELECT    0 //flash�洢ʧ��ֵ��ʽѡ��,��Ϸ�ʽ�����˶�ȡʱ��ʹ��봦��ĸ��Ӷ� 
																				  //0 �洢37.5k(3���ֽ��������12bit��ʽ 160*160*3/2)
																				  //1 �洢50k(�ߵ�8λֱ�Ӵ洢����� 160*160*2)
#if OFFSETVAL_FLASH_WRITE_SELECT
#define BYD_FPS_ERASE_PAGE_NUM          26
//#define MODULEID_FLASH_ADDRESS          ((uint32_t)0x0802c800U)//(OFFSETVAL_FLASH_ADDRESS+50*1024)�洢ģ��ID��flash��ַ
//#define FINGERTHD_FLASH_ADDRESS         ((uint32_t)0x0802c80AU)//�洢��ָ��ֵ��flash��ַ

#else
#define BYD_FPS_ERASE_PAGE_NUM          19
//#define MODULEID_FLASH_ADDRESS          ((uint32_t)0x08029600U) //(OFFSETVAL_FLASH_ADDRESS+37.5*1024)�洢ģ��ID��flash��ַ
//#define FINGERTHD_FLASH_ADDRESS         ((uint32_t)0x0802960AU) //�洢��ָ��ֵ��flash��ַ

#endif


#define BYD_FPS_MODULEID_CHECK_EN      1//ģ��ID�жϣ�1 ʹ�� 0 �ر�,��Ʒ���Խ׶ιر�,��ʱ��Ʒ�ﻹδ��¼ģ��ID��IDֵ����0xff

#define BYD_FPS_SUBVALUE_JUDGE_EN      1//0//�ж���ָʧ��ֵ�Ƿ�׼ȷ��1 ʹ�� 0�ر�
#define BYD_FPS_AVESUBVALUE_THD        70//��ָ������ƽ��ֵ�ж���ֵ��С�ڸ�ֵ��Ϊ��ȷ
#endif

#if BYD_SH_METHOD_SEL==0
#define BYD_FPS_SUBVALUE_DIFF          1850//��ָ������ֵ��ȥ��ֵ�õ���ָ��ֵ
#define BYD_FPS_SUBVALUE_DIFF_DOWN          1800//1800
#define BYD_FPS_SUBVALUE_DIFF_UP           	100//1000
#else
#define BYD_FPS_SUBVALUE_DIFF_DOWN          1800//1800
#define BYD_FPS_SUBVALUE_DIFF_UP           	100//1000
#endif


/**************************************************************************
* Global Variable Declaration
***************************************************************************/
#pragma pack(1)
typedef struct 
{
	 uint8_t chipidentify;   //��־
	 uint8_t idlemode;			//����ģʽ
   uint8_t fingermode;		//������ָ���ģʽ
   uint8_t lowpfingermode;//�͹�����ָ���ģʽ
   uint8_t fpdmode;				//ָ��ɨ��ģʽ
   uint8_t sleepmode;			//����ģʽ
	 uint8_t fgresetti2;		//����ʱ�Ĵ�������ֵ
	 uint8_t intcfg;		    //�춨ʱINT����������ָ���ʱ
	 uint8_t lowintcfg;	    //����ʱINT�����͹�����ָ���ʱ
	 uint8_t iostate;       //�˿�����
	
}STRUCTCHIPMODIFYINFOR;
#pragma pack()



#define OTP_MODULE_ID             		0x80
#define OTP_MODULE_ID_END             	0x87
#define OTP_MODULE_BYTE           		8

#define OTP_BAD_POINT_CHIP_START		0x88
#define OTP_BAD_POINT_CHIP				0x89
#define OTP_BAD_POINT_CHIP_END			0xC4
#define OTP_BAD_POINT_CHIP_LEN			60

#define OTP_BAD_POINT_POTTING_START		0xC5
#define OTP_BAD_POINT_POTTING			0xC6
#define OTP_BAD_POINT_POTTING_END		0x101
#define OTP_BAD_POINT_POTTING_LEN		60



#define OTP_MARK						0x17F


#endif
