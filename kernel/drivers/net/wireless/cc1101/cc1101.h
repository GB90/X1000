/* 
 * File:   cc110x.h
 * Author: elinux
 *
 * Created on 2015��4��7��, ����10:32
 */

#ifndef _LINUX_CC1101_H
#define _LINUX_CC1101_H

#define CC1101_DRV_NAME     "cc1101"
#define CC1101_CHN_SET		0xE001
#define CC1101_CHN_GET		0xE002

// ���üĴ�������
#define CCxxx0_IOCFG2       0x00 // GDO2���������. GDO2 output pin configuration  
#define CCxxx0_IOCFG1       0x01 // GDO1���������. GDO1 output pin configuration  
#define CCxxx0_IOCFG0       0x02 // GDO0���������. GDO0 output pin configuration  
#define CCxxx0_FIFOTHR      0x03 // RX FIFO��TX FIFO��ֵ. RX FIFO and TX FIFO thresholds  
#define CCxxx0_SYNC1        0x04 // ͬ����,��8λ. Sync word, high u8  
#define CCxxx0_SYNC0        0x05 // ͬ����,��8λ. Sync word, low u8  
#define CCxxx0_PKTLEN       0x06 // ���ݰ�����. Packet length  
#define CCxxx0_PKTCTRL1     0x07 // ���ݰ��Զ�����1. Packet automation control  
#define CCxxx0_PKTCTRL0     0x08 // ���ݰ��Զ�����0. Packet automation control  
#define CCxxx0_ADDR         0x09 // �豸��ַ. Device address  
#define CCxxx0_CHANNR       0x0A // �ŵ���. Channel number  
#define CCxxx0_FSCTRL1      0x0B // Ƶ�ʺϳ�������1. Frequency synthesizer control  
#define CCxxx0_FSCTRL0      0x0C // Ƶ�ʺϳ�������0. Frequency synthesizer control  
#define CCxxx0_FREQ2        0x0D // Ƶ�ʿ����֣���8λ. Frequency control word, high u8  
#define CCxxx0_FREQ1        0x0E // Ƶ�ʿ����֣���8λ. Frequency control word, middle u8  
#define CCxxx0_FREQ0        0x0F // Ƶ�ʿ����֣���8λ. Frequency control word, low u8  
#define CCxxx0_MDMCFG4      0x10 // ���ƽ��������4. Modem configuration  
#define CCxxx0_MDMCFG3      0x11 // ���ƽ��������3. Modem configuration  
#define CCxxx0_MDMCFG2      0x12 // ���ƽ��������2. Modem configuration  
#define CCxxx0_MDMCFG1      0x13 // ���ƽ��������1. Modem configuration  
#define CCxxx0_MDMCFG0      0x14 // ���ƽ��������0. Modem configuration  
#define CCxxx0_DEVIATN      0x15 // ���ƽ����ƫ���趨. Modem deviation setting  
#define CCxxx0_MCSM2        0x16 // ��ͨ�ſ���״̬������2. Main Radio Control State Machine configuration  
#define CCxxx0_MCSM1        0x17 // ��ͨ�ſ���״̬������1. Main Radio Control State Machine configuration  
#define CCxxx0_MCSM0        0x18 // ��ͨ�ſ���״̬������0. Main Radio Control State Machine configuration  
#define CCxxx0_FOCCFG       0x19 // Ƶ��ƫ�Ʋ�������. Frequency Offset Compensation configuration  
#define CCxxx0_BSCFG        0x1A // λͬ������. Bit Synchronization configuration  
#define CCxxx0_AGCCTRL2     0x1B // AGC����2. AGC control  
#define CCxxx0_AGCCTRL1     0x1C // AGC����1. AGC control  
#define CCxxx0_AGCCTRL0     0x1D // AGC����0. AGC control  
#define CCxxx0_WOREVT1      0x1E // ��8λ �¼�0��ʱ. High u8 Event 0 timeout  
#define CCxxx0_WOREVT0      0x1F // ��8λ �¼�0��ʱ. Low u8 Event 0 timeout  
#define CCxxx0_WORCTRL      0x20 // �������ߵ����. Wake On Radio control  
#define CCxxx0_FREND1       0x21 // ǰ��RX����1. Front end RX configuration  
#define CCxxx0_FREND0       0x22 // ǰ��RX����0. Front end TX configuration  
#define CCxxx0_FSCAL3       0x23 // Ƶ�ʺϳ���У׼3. Frequency synthesizer calibration  
#define CCxxx0_FSCAL2       0x24 // Ƶ�ʺϳ���У׼2. Frequency synthesizer calibration  
#define CCxxx0_FSCAL1       0x25 // Ƶ�ʺϳ���У׼1. Frequency synthesizer calibration  
#define CCxxx0_FSCAL0       0x26 // Ƶ�ʺϳ���У׼0. Frequency synthesizer calibration  
#define CCxxx0_RCCTRL1      0x27 // RC��������1. RC oscillator configuration  
#define CCxxx0_RCCTRL0      0x28 // RC��������1. RC oscillator configuration  
#define CCxxx0_FSTEST       0x29 // Ƶ�ʺϳ���У׼����. Frequency synthesizer calibration control  
#define CCxxx0_PTEST        0x2A // ��Ʒ����. Production test  
#define CCxxx0_AGCTEST      0x2B // AGC����. AGC test  
#define CCxxx0_TEST2        0x2C // ���ֲ�������. Various test settings  
#define CCxxx0_TEST1        0x2D // Various test settings  
#define CCxxx0_TEST0        0x2E // Various test settings  
// Strobe commands   �����˲�����
#define CCxxx0_SRES         0x30 // (����оƬ)Reset chip
#define CCxxx0_SFSTXON      0x31 // (������У׼Ƶ�ʺϳ���)Enable and calibrate frequency synthesizer (if MCSM0.FS_AUTOCAL=1). 
// If in RX/TX: Go to a wait state where only the synthesizer is  
// running (for quick RX / TX turnaround).  
#define CCxxx0_SXOFF        0x32 // (�رվ�������)Turn off crystal oscillator.
#define CCxxx0_SCAL         0x33 // (У׼Ƶ�ʺϳ���������ر�)Calibrate frequency synthesizer and turn it off  
// (enables quick start).  
#define CCxxx0_SRX          0x34 // (����RX)Enable RX. Perform calibration first if coming from IDLE and  
// MCSM0.FS_AUTOCAL=1.  
#define CCxxx0_STX          0x35 // (����״̬������TX)In IDLE state: Enable TX. Perform calibration first if  
// MCSM0.FS_AUTOCAL=1. If in RX state and CCA is enabled:  
// Only go to TX if channel is clear.  
#define CCxxx0_SIDLE        0x36 // (�뿪RX/TX)Exit RX / TX, turn off frequency synthesizer and exit  
// Wake-On-Radio mode if applicable.  
#define CCxxx0_SAFC         0x37 // (Ƶ�ʺϳ�����AFC����)Perform AFC adjustment of the frequency synthesizer  
#define CCxxx0_SWOR         0x38 // (�Զ�RXѡ�����У���Ų����)Start automatic RX polling sequence (Wake-on-Radio)  
#define CCxxx0_SPWD         0x39 // (��CSnΪ��ʱ���빦�ʽ���ģʽ )Enter power down mode when CSn goes high.  
#define CCxxx0_SFRX         0x3A // (��ϴRX FIFO����)Flush the RX FIFO buffer.  
#define CCxxx0_SFTX         0x3B // (��ϴTX FIFO����)Flush the TX FIFO buffer.  
#define CCxxx0_SWORRST      0x3C // (����������ʵʱ��ʱ��)Reset real time clock.  
#define CCxxx0_SNOP         0x3D // (�޲���)No operation. May be used to pad strobe commands to two  
// u8s for simpler software.  
//**״̬�Ĵ�������**
#define CCxxx0_PARTNUM      0x30 // CC2550����ɲ�����Ŀ************/ 
#define CCxxx0_VERSION      0x31 // ��ǰ�汾��**********************/ 
#define CCxxx0_FREQEST      0x32 // ��ƫ�ƹ���**********************/ 
#define CCxxx0_LQI          0x33 // �������Ľ��������**************/ 
#define CCxxx0_RSSI         0x34 // �����ź�ǿ��ָʾ****************/ 
#define CCxxx0_MARCSTATE    0x35 // ����״̬��״̬******************/ 
#define CCxxx0_WORTIME1     0x36 // WOR��ʱ�����ֽ�*****************/
#define CCxxx0_WORTIME0     0x37 // WOR��ʱ�����ֽ�*****************/ 
#define CCxxx0_PKTSTATUS    0x38 // ��ǰGDOx״̬�����ݰ�״̬********/ 
#define CCxxx0_VCO_VC_DAC   0x39 // PLLУ׼ģ��ĵ�ǰ�趨***********/ 
#define CCxxx0_TXBYTES      0x3A // TX FIFO�е�����ͱ�����*********/ 
#define CCxxx0_RXBYTES      0x3B // RX FIFO�е�����ͱ�����*********/ 
#define CCxxx0_PATABLE      0x3E // ���÷��书��, ��һ��8�ֽڵı�
#define CCxxx0_TXFIFO       0x3F // ���ֽڷ��� TX FIFO
#define CCxxx0_RXFIFO       0x3F // ���ֽڷ��� TX FIFO

#define WRITE_BURST         0x40 //����д��
#define READ_SINGLE         0x80 //��
#define READ_BURST          0xC0 //������
#define BYTES_IN_RXFIFO     0x7F //���ջ���������Ч�ֽ���
#define CRC_OK              0x80 //CRCУ��ͨ��λ��־

#define CC1101_SPI_BUFLEN 	64

struct cc1101_dev{
	dev_t ccid;
	int major;
	int minor;
    struct cdev chd;
	struct class *cls; 
	struct device *dev;
};
/*
 * Some registers must be read back to modify.
 * To save time we cache them here in memory.
 */
struct cc1101_data {
    int gpio_rdy;	// �� cc1101 �� GD0 ע��Ϊ �жϹܽ�
    int irq;
	int recvflag;	// crc У��ֵ
	int workflag; 	// work ִ�б�־
	int alreadySent;	// �Ƿ��͹����ݵı��
	
	struct cc1101_dev   cc_dev;
    struct spi_device   *spi;
	struct spi_message  msg;
    struct spi_transfer xfer;
	struct mutex        dev_lock;

	struct work_struct work;
	struct workqueue_struct *workqueue;
	unsigned char spi_rxbuf[CC1101_SPI_BUFLEN];
	unsigned char spi_txbuf[CC1101_SPI_BUFLEN];

	int spi_recvlen; // spi���ܶ����ֽ�	
};

#endif    /* CC110X_H */
