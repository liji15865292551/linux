/* SPDX-License-Identifier: GPL-2.0 */
/*
 * CAAM Error Reporting code header
 *
 * Copyright 2009-2011 Freescale Semiconductor, Inc.
 * Copyright 2018 NXP
 */

#ifndef CAAM_ERROR_H
#define CAAM_ERROR_H
#define CAAM_ERROR_STR_MAX 302

void caam_strstatus(struct device *dev, u32 status, bool qi_v2);

#define caam_jr_strstatus(jrdev, status) caam_strstatus(jrdev, status, false)
#define caam_qi2_strstatus(qidev, status) caam_strstatus(qidev, status, true)

void caam_dump_sg(const char *level, const char *prefix_str, int prefix_type,
		  int rowsize, int groupsize, struct scatterlist *sg,
		  size_t tlen, bool ascii);
#endif /* CAAM_ERROR_H */
