/******************************************************************************
 *
 * Copyright (C) 2016-2017 Cadence Design Systems, Inc.
 * All rights reserved worldwide.
 *
 * Copyright 2017-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************
 *
 * This file was auto-generated. Do not edit it manually.
 *
 ******************************************************************************
 *
 * source_vif.h
 *
 ******************************************************************************
 */

#ifndef SOURCE_VIF_H_
#define SOURCE_VIF_H_

/* register BND_HSYNC2VSYNC */
#define BND_HSYNC2VSYNC 0
#define F_IP_DTCT_WIN(x) (((x) & ((1 << 12) - 1)) << 0)
#define F_IP_DTCT_WIN_RD(x) (((x) & (((1 << 12) - 1) << 0)) >> 0)
#define F_IP_DET_EN(x) (((x) & ((1 << 1) - 1)) << 12)
#define F_IP_DET_EN_RD(x) (((x) & (((1 << 1) - 1) << 12)) >> 12)
#define F_IP_VIF_BYPASS(x) (((x) & ((1 << 1) - 1)) << 13)
#define F_IP_VIF_BYPASS_RD(x) (((x) & (((1 << 1) - 1) << 13)) >> 13)

/* register HSYNC2VSYNC_F1_L1 */
#define HSYNC2VSYNC_F1_L1 1
#define F_IP_DTCT_HSYNC2VSYNC_F1(x) (((x) & ((1 << 16) - 1)) << 0)
#define F_IP_DTCT_HSYNC2VSYNC_F1_RD(x) (((x) & (((1 << 16) - 1) << 0)) >> 0)

/* register HSYNC2VSYNC_F2_L1 */
#define HSYNC2VSYNC_F2_L1 2
#define F_IP_DTCT_HSYNC2VSYNC_F2(x) (((x) & ((1 << 16) - 1)) << 0)
#define F_IP_DTCT_HSYNC2VSYNC_F2_RD(x) (((x) & (((1 << 16) - 1) << 0)) >> 0)

/* register HSYNC2VSYNC_STATUS */
#define HSYNC2VSYNC_STATUS 3
#define F_IP_DTCT_ERR(x) (((x) & ((1 << 1) - 1)) << 0)
#define F_IP_DTCT_ERR_RD(x) (((x) & (((1 << 1) - 1) << 0)) >> 0)
#define F_IP_DCT_IP(x) (((x) & ((1 << 1) - 1)) << 1)
#define F_IP_DCT_IP_RD(x) (((x) & (((1 << 1) - 1) << 1)) >> 1)
#define F_IP_DTCT_VJITTER(x) (((x) & ((1 << 1) - 1)) << 2)
#define F_IP_DTCT_VJITTER_RD(x) (((x) & (((1 << 1) - 1) << 2)) >> 2)
#define F_IP_DTCT_HJITTER(x) (((x) & ((1 << 1) - 1)) << 3)
#define F_IP_DTCT_HJITTER_RD(x) (((x) & (((1 << 1) - 1) << 3)) >> 3)

/* register HSYNC2VSYNC_POL_CTRL */
#define HSYNC2VSYNC_POL_CTRL 4
#define F_VPOL(x) (((x) & ((1 << 1) - 1)) << 2)
#define F_VPOL_RD(x) (((x) & (((1 << 1) - 1) << 2)) >> 2)
#define F_HPOL(x) (((x) & ((1 << 1) - 1)) << 1)
#define F_HPOL_RD(x) (((x) & (((1 << 1) - 1) << 1)) >> 1)
#define F_VIF_AUTO_MODE(x) (((x) & ((1 << 1) - 1)) << 0)
#define F_VIF_AUTO_MODE_RD(x) (((x) & (((1 << 1) - 1) << 0)) >> 0)

#endif //SOURCE_VIF
