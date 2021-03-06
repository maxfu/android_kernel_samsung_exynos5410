/*
 * Copyright (C) 2010 Samsung Electronics.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MODEM_VARIATION_H__
#define __MODEM_VARIATION_H__

#include <linux/platform_data/modem_if.h>

#define DECLARE_MODEM_INIT(type)	\
	int type ## _init_modemctl_device(struct modem_ctl *mc,	\
				struct modem_data *pdata)
#define DECLARE_MODEM_INIT_DUMMY(type)	\
	static DECLARE_MODEM_INIT(type) { return 0; }

#define DECLARE_LINK_INIT(type)	\
		struct link_device *type ## _create_link_device(	\
		struct platform_device *pdev)
#define DECLARE_LINK_INIT_DUMMY(type)	\
	static DECLARE_LINK_INIT(type) { return NULL; }

#define MODEM_INIT_CALL(type)	type ## _init_modemctl_device
#define LINK_INIT_CALL(type)	type ## _create_link_device

/* add declaration of modem & link type */
/* modem device support */
DECLARE_MODEM_INIT_DUMMY(dummy)

#ifdef CONFIG_UMTS_MODEM_XMM6260
DECLARE_MODEM_INIT(xmm6260);
#else
DECLARE_MODEM_INIT_DUMMY(xmm6260)
#endif

#ifdef CONFIG_UMTS_MODEM_XMM6262
DECLARE_MODEM_INIT(xmm6262);
#else
DECLARE_MODEM_INIT_DUMMY(xmm6262)
#endif

#ifdef CONFIG_CDMA_MODEM_CBP71
DECLARE_MODEM_INIT(cbp71);
#else
DECLARE_MODEM_INIT_DUMMY(cbp71)
#endif

#ifdef CONFIG_CDMA_MODEM_CBP72
DECLARE_MODEM_INIT(cbp72);
#else
DECLARE_MODEM_INIT_DUMMY(cbp72)
#endif

#ifdef CONFIG_CDMA_MODEM_CBP82
DECLARE_MODEM_INIT(cbp82);
#else
DECLARE_MODEM_INIT_DUMMY(cbp82)
#endif

#ifdef CONFIG_LTE_MODEM_CMC220
DECLARE_MODEM_INIT(cmc220);
#else
DECLARE_MODEM_INIT_DUMMY(cmc220)
#endif

#ifdef CONFIG_LTE_MODEM_CMC221
DECLARE_MODEM_INIT(cmc221);
#else
DECLARE_MODEM_INIT_DUMMY(cmc221)
#endif

#ifdef CONFIG_UMTS_MODEM_SS222
DECLARE_MODEM_INIT(ss222);
#else
DECLARE_MODEM_INIT_DUMMY(ss222)
#endif

#ifdef CONFIG_CDMA_MODEM_MDM6600
DECLARE_MODEM_INIT(mdm6600);
#else
DECLARE_MODEM_INIT_DUMMY(mdm6600)
#endif

#ifdef CONFIG_GSM_MODEM_ESC6270
DECLARE_MODEM_INIT(esc6270);
#else
DECLARE_MODEM_INIT_DUMMY(esc6270)
#endif

#ifdef CONFIG_CDMA_MODEM_QSC6085
DECLARE_MODEM_INIT(qsc6085);
#else
DECLARE_MODEM_INIT_DUMMY(qsc6085)
#endif

#ifdef CONFIG_TDSCDMA_MODEM_SPRD8803
DECLARE_MODEM_INIT(sprd8803);
#else
DECLARE_MODEM_INIT_DUMMY(sprd8803)
#endif

/* link device support */
DECLARE_LINK_INIT_DUMMY(undefined)

#ifdef CONFIG_LINK_DEVICE_MIPI
DECLARE_LINK_INIT(mipi);
#else
DECLARE_LINK_INIT_DUMMY(mipi)
#endif

#ifdef CONFIG_LINK_DEVICE_USB
DECLARE_LINK_INIT(usb);
#else
DECLARE_LINK_INIT_DUMMY(usb)
#endif

#ifdef CONFIG_LINK_DEVICE_HSIC
DECLARE_LINK_INIT(hsic);
#else
DECLARE_LINK_INIT_DUMMY(hsic)
#endif

#ifdef CONFIG_LINK_DEVICE_DPRAM
DECLARE_LINK_INIT(dpram);
#else
DECLARE_LINK_INIT_DUMMY(dpram)
#endif

#ifdef CONFIG_LINK_DEVICE_PLD
DECLARE_LINK_INIT(pld);
#else
DECLARE_LINK_INIT_DUMMY(pld)
#endif

#ifdef CONFIG_LINK_DEVICE_C2C
DECLARE_LINK_INIT(c2c);
#else
DECLARE_LINK_INIT_DUMMY(c2c)
#endif

#ifdef CONFIG_LINK_DEVICE_SHMEM
DECLARE_LINK_INIT(shmem);
#else
DECLARE_LINK_INIT_DUMMY(shmem)
#endif

#ifdef CONFIG_LINK_DEVICE_SPI
DECLARE_LINK_INIT(spi);
#else
DECLARE_LINK_INIT_DUMMY(spi)
#endif

typedef int (*modem_init_call)(struct modem_ctl *, struct modem_data *);
static modem_init_call modem_init_func[MAX_MODEM_TYPE] = {
	[IMC_XMM6260] = MODEM_INIT_CALL(xmm6260),
	[IMC_XMM6262] = MODEM_INIT_CALL(xmm6262),
	[VIA_CBP71] = MODEM_INIT_CALL(cbp71),
	[VIA_CBP72] = MODEM_INIT_CALL(cbp72),
	[VIA_CBP82] = MODEM_INIT_CALL(cbp82),
	[SEC_CMC220] = MODEM_INIT_CALL(cmc220),
	[SEC_CMC221] = MODEM_INIT_CALL(cmc221),
	[SEC_SS222] = MODEM_INIT_CALL(ss222),
	[QC_MDM6600] = MODEM_INIT_CALL(mdm6600),
	[QC_ESC6270] = MODEM_INIT_CALL(esc6270),
	[QC_QSC6085] = MODEM_INIT_CALL(qsc6085),
	[SPRD_SC8803] = MODEM_INIT_CALL(sprd8803),
	[DUMMY] = MODEM_INIT_CALL(dummy),
};

typedef struct link_device *(*link_init_call)(struct platform_device *);
static link_init_call link_init_func[LINKDEV_MAX] = {
	[LINKDEV_UNDEFINED] = LINK_INIT_CALL(undefined),
	[LINKDEV_MIPI] = LINK_INIT_CALL(mipi),
	[LINKDEV_USB] = LINK_INIT_CALL(usb),
	[LINKDEV_HSIC] = LINK_INIT_CALL(hsic),
	[LINKDEV_DPRAM] = LINK_INIT_CALL(dpram),
	[LINKDEV_PLD] = LINK_INIT_CALL(pld),
	[LINKDEV_C2C] = LINK_INIT_CALL(c2c),
	[LINKDEV_SHMEM] = LINK_INIT_CALL(shmem),
	[LINKDEV_SPI] = LINK_INIT_CALL(spi),
};

static int call_modem_init_func(struct modem_ctl *mc, struct modem_data *pdata)
{
	if (modem_init_func[pdata->modem_type])
		return modem_init_func[pdata->modem_type](mc, pdata);
	else
		return -ENOTSUPP;
}

static struct link_device *call_link_init_func(struct platform_device *pdev,
			enum modem_link link_type)
{
	if (link_init_func[link_type])
		return link_init_func[link_type](pdev);
	else
		return NULL;
}

#endif
