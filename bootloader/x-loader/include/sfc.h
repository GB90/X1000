/*
 *  Copyright (C) 2016 Ingenic Semiconductor Co.,Ltd
 *
 *  X1000 series bootloader for u-boot/rtos/linux
 *
 *  Zhang YanMing <yanming.zhang@ingenic.com, jamincheung@126.com>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under  the terms of the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef SFC_H
#define SFC_H

struct jz_sfc {
    unsigned int  addr;
    unsigned int  len;
    unsigned int  cmd;
    unsigned int  addr_plus;
    unsigned int  sfc_mode;
    unsigned char daten;
    unsigned char addr_len;
    unsigned char pollen;
    unsigned char phase;
    unsigned char dummy_bits;
};

struct spi_mode_peer {
    int controller_mode;
    int device_mode;
};

enum {
    SPI_MODE_STANDARD = 7,
    SPI_MODE_STANDARD2,
    SPI_MODE_QUAD,
};

#ifdef CONFIG_SFC_DEBUG
#define sfc_debug(fmt, args...)         \
    do {                    \
        printf(fmt, ##args);        \
    } while (0)
#else
#define sfc_debug(fmt, args...)         \
    do {                    \
    } while (0)
#endif

#define SFC_GLB               (0x0000)
#define SFC_DEV_CONF          (0x0004)
#define SFC_STA_EXP           (0x0008)
#define SFC_DEV_STA_RT        (0x000c)
#define SFC_DEV_STA_MSK       (0x0010)
#define SFC_TRAN_CONF(n)      (0x0014 + (n * 4))
#define SFC_DEV_ADDR(n)       (0x0030 + (n * 4))
#define SFC_DEV_ADDR_PLUS(n)  (0x0048 + (n * 4))
#define SFC_TRAN_LEN          (0x002c)
#define SFC_MEM_ADDR          (0x0060)
#define SFC_TRIG              (0x0064)
#define SFC_SR                (0x0068)
#define SFC_SCR               (0x006c)
#define SFC_INTC              (0x0070)
#define SFC_FSM               (0x0074)
#define SFC_CGE               (0x0078)
#define SFC_DR                (0x1000)

//For SFC_GLB
#define TRAN_DIR                (1 << 13)
#define GLB_TRAN_DIR_WRITE      (1)
#define GLB_TRAN_DIR_READ       (0)
#define THRESHOLD_OFFSET        (7)
#define THRESHOLD_MSK           (0x3f << THRESHOLD_OFFSET)
#define OP_MODE                 (1 << 6)
#define PHASE_NUM_OFFSET        (3)
#define PHASE_NUM_MSK           (0x7 << PHASE_NUM_OFFSET)
#define WP_EN                   (1 << 2)
#define BURST_MD_OFFSET         (0)
#define BURST_MD_MSK            (0x3 << BURST_MD_OFFSET)

//For SFC_DEV_CONF
#define SMP_DELAY_OFFSET        (16)
#define SMP_DELAY_MSK           (0x3 << SMP_DELAY_OFFSET)
#define CMD_TYPE                (1 << 15)
#define STA_TYPE_OFFSET         (13)
#define STA_TYPE_MSK            (1 << STA_TYPE_OFFSET)
#define THOLD_OFFSET            (11)
#define THOLD_MSK               (0x3 << THOLD_OFFSET)
#define TSETUP_OFFSET           (9)
#define TSETUP_MSK              (0x3 << TSETUP_OFFSET)
#define TSH_OFFSET              (5)
#define TSH_MSK                 (0xf << TSH_OFFSET)
#define CPHA                    (1 << 4)
#define CPOL                    (1 << 3)
#define CEDL                    (1 << 2)
#define HOLDDL                  (1 << 1)
#define WPDL                    (1 << 0)

//For SFC_TRAN_CONFx
#define TRAN_MODE_OFFSET            (29)
#define TRAN_MODE_MSK               (0x7 << TRAN_MODE_OFFSET)
#define ADDR_WIDTH_OFFSET           (26)
#define ADDR_WIDTH_MSK              (0x7 << ADDR_WIDTH_OFFSET)
#define TRAN_CONF_DMYBITS_OFFSET    (17)
#define TRAN_CONF_DMYBITS_MSK       (0x3f << DMYBITS_OFFSET)
#define TRAN_SPI_STANDARD           (0x0)
#define TRAN_SPI_DUAL               (0x1)
#define TRAN_SPI_QUAD               (0x5)
#define TRAN_SPI_IO_QUAD            (0x6)
#define POLLEN                      (1 << 25)
#define CMDEN                       (1 << 24)
#define FMAT                        (1 << 23)
#define DMYBITS_OFFSET              (17)
#define DMYBITS_MSK                 (0x3f << DMYBITS_OFFSET)
#define DATEEN                      (1 << 16)
#define CMD_OFFSET                  (0)
#define CMD_MSK                     (0xffff << CMD_OFFSET)

//For SFC_TRIG
#define FLUSH           (1 << 2)
#define STOP            (1 << 1)
#define START           (1 << 0)

//For SFC_SR
#define FIFONUM_OFFSET  (16)
#define FIFONUM_MSK     (0x7f << FIFONUM_OFFSET)
#define BUSY_OFFSET     (5)
#define BUSY_MSK        (0x3 << BUSY_OFFSET)
#define END             (1 << 4)
#define TRAN_REQ        (1 << 3)
#define RECE_REQ        (1 << 2)
#define OVER            (1 << 1)
#define UNDER           (1 << 0)

//For SFC_SCR
#define CLR_END         (1 << 4)
#define CLR_TREQ        (1 << 3)
#define CLR_RREQ        (1 << 2)
#define CLR_OVER        (1 << 1)
#define CLR_UNDER       (1 << 0)

//For SFC_INTC
#define MASK_END        (1 << 4)
#define MASK_TREQ       (1 << 3)
#define MASK_RREQ       (1 << 2)
#define MASK_OVER       (1 << 1)
#define MASK_UNDR       (1 << 0)

//For SFC_FSM
#define FSM_AHB_OFFSET      (16)
#define FSM_AHB_MSK         (0xf << FSM_AHB_OFFSET)
#define FSM_SPI_OFFSET      (11)
#define FSM_SPI_MSK         (0x1f << FSM_SPI_OFFSET)
#define FSM_CLK_OFFSET      (6)
#define FSM_CLK_MSK         (0xf << FSM_CLK_OFFSET)
#define FSM_DMAC_OFFSET     (3)
#define FSM_DMAC_MSK        (0x7 << FSM_DMAC_OFFSET)
#define FSM_RMC_OFFSET      (0)
#define FSM_RMC_MSK         (0x7 << FSM_RMC_OFFSET)

//For SFC_CGE
#define CG_EN           (1 << 0)
#define SFC_FIFO_LEN    (63)
#define THRESHOLD       (31)

#define DEF_TCHSH       5
#define DEF_TSLCH       5
#define DEF_TSHSL_R     20
#define DEF_TSHSL_W     50

#define  SFC_MODE_GENERATE(sfc, a)    do{                                       \
        if ((a >= SPI_MODE_STANDARD) && (a <= SPI_MODE_QUAD)){                  \
            ((struct jz_sfc *)sfc)->cmd = spi_mode_local[a].device_mode;        \
        }                                                                       \
        if((((struct jz_sfc *)sfc)->daten == 1)                                 \
        && (((struct jz_sfc *)sfc)->addr_len != 0)){                            \
            if (a == SPI_MODE_QUAD)                                             \
                ((struct jz_sfc *)sfc)->sfc_mode = spi_mode_local[a].controller_mode; \
            else                                                                \
                ((struct jz_sfc *)sfc)->sfc_mode = 0;                           \
        } else {                                                                \
            ((struct jz_sfc *)sfc)->sfc_mode = 0;                               \
        }                                                                       \
} while(0)

#define  SFC_SEND_COMMAND(sfc, a, b, c, d, e, f, g)   do{                       \
        ((struct jz_sfc *)sfc)->cmd = a;                                        \
        ((struct jz_sfc *)sfc)->len = b;                                        \
        ((struct jz_sfc *)sfc)->addr = c;                                       \
        ((struct jz_sfc *)sfc)->addr_len = d;                                   \
        ((struct jz_sfc *)sfc)->addr_plus = 0;                                  \
        ((struct jz_sfc *)sfc)->dummy_bits = e;                                \
        ((struct jz_sfc *)sfc)->daten = f;                                      \
        SFC_MODE_GENERATE(sfc, a);                                              \
        sfc_send_cmd(sfc, g);                                                   \
} while(0)

#define  SFC_SEND_COMMAND_QUAD(sfc, a, b, c, d, e, f, g)   do{                 \
        ((struct jz_sfc *)sfc)->cmd = a;                                        \
        ((struct jz_sfc *)sfc)->len = b;                                        \
        ((struct jz_sfc *)sfc)->addr = c;                                       \
        ((struct jz_sfc *)sfc)->addr_len = d;                                   \
        ((struct jz_sfc *)sfc)->addr_plus = 0;                                  \
        ((struct jz_sfc *)sfc)->dummy_bits = e;                                 \
        ((struct jz_sfc *)sfc)->daten = f;                                      \
        ((struct jz_sfc *)sfc)->sfc_mode = 5;                                   \
        sfc_send_cmd(sfc, g);                                                   \
} while(0)



void sfc_init(void);
int sfc_read_data(uint32_t *data, uint32_t length);
int sfc_write_data(uint32_t *data, uint32_t length);
void sfc_send_cmd(struct jz_sfc *sfc, uint8_t dir);

#endif /* SFC_H */
