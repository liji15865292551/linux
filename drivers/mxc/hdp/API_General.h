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
 * API_General.h
 *
 ******************************************************************************
 */

#ifndef API_GENERAL_H_
#define API_GENERAL_H_

#include <linux/types.h>
#include <linux/string.h>
#include <linux/io.h>
#include "util.h"

#define GENERAL_TEST_ECHO_MAX_PAYLOAD 100
#define GENERAL_TEST_ECHO_MIN_PAYLOAD 1

/**
 * GENERAL_Read_Register response struct
 */
typedef struct {
	u32 addr;
	u32 val;
} GENERAL_Read_Register_response;

/**
 * \brief set up API, must be called before any other API call
 */
void CDN_API_Init(state_struct *state);

/**
 * \brief Loads firmware
 *
 * \param iMem - pointer to instruction memory
 * \param imemSize - size of instruction memory buffer
 * \param dMem - pointer to data memory
 * \param dmemSize - size of data memory buffer
 * \return 0 if success, 1 if apb error encountered, 2 if CPU isn't alive after loading firmware
 *
 * This function does not require initialisation by #CDN_API_Init
 */

CDN_API_STATUS CDN_API_LoadFirmware(state_struct *state, u8 *iMem,
				    int imemSize, u8 *dMem, int dmemSize);

/**
 * \brief debug echo command for APB
 * \param val - value to echo
 * \return status
 *
 * will return #CDN_ERROR if reply message doesn't match request
 */
CDN_API_STATUS CDN_API_General_Test_Echo(state_struct *state, u32 val,
					 CDN_BUS_TYPE bus_type);

/**
 * \brief blocking version of #CDN_API_General_Test_Echo
 */
CDN_API_STATUS CDN_API_General_Test_Echo_blocking(state_struct *state, u32 val,
						  CDN_BUS_TYPE bus_type);

/**
 * \brief Extended Echo test for mailbox.
 *
 * This test will send msg buffer to firmware's mailbox and receive it back to
 * the resp buffer. Received data will be check against data sent and status will
 * be returned as well as received data.
 *
 * \param msg - Pointer to a buffer to send.
 * \param resp - Pointer to buffer for receiving msg payload back.
 * \param num_bytes - Number of bytes to send and receive.
 * \param bus_type Bus type.
 * \return status
 *
 * will return #CDN_ERROR if reply message doesn't match request or if
 *  arguments are invalid.
 */
CDN_API_STATUS CDN_API_General_Test_Echo_Ext(state_struct *state,
					     u8 const *msg, u8 *resp,
					     u16 num_bytes,
					     CDN_BUS_TYPE bus_type);

/**
 * \brief blocking version of #CDN_API_General_Test_Echo_Ext
 */
CDN_API_STATUS CDN_API_General_Test_Echo_Ext_blocking(state_struct *state,
						      u8 const *msg, u8 *resp,
						      u16 num_bytes,
						      CDN_BUS_TYPE bus_type);

/**
 * \brief get current version
 * \param [out] ver - fw version
 * \param [out] libver - lib version
 * \return status
 *
 * this function does not require #CDN_API_Init
 */
CDN_API_STATUS CDN_API_General_getCurVersion(state_struct *state, u16 *ver,
					     u16 *verlib);

/**
 * \brief read event value
 * \param [out] event - pointer to store 32-bit events value
 * \return status
 *
 * this function does not require #CDN_API_Init
 */
CDN_API_STATUS CDN_API_Get_Event(state_struct *state, u32 *events);

/**
 * \brief read debug register value
 * \param [out] val - pointer to store 16-bit debug reg value
 * \return status
 *
 * this function does not require #CDN_API_Init
 */
CDN_API_STATUS CDN_API_Get_Debug_Reg_Val(state_struct *state, u16 *val);

/**
 * \brief check if KEEP_ALIVE register changed
 * \return #CDN_BSY if KEEP_ALIVE not changed, #CDN_OK if changed and #CDN_ERR if error occurred while reading
 */
CDN_API_STATUS CDN_API_CheckAlive(state_struct *state);

/**
 * \breif blocking version of #CDN_API_CheckAlive
 * blocks until KEEP_ALIVE register changes or error occurs while reading
 */
CDN_API_STATUS CDN_API_CheckAlive_blocking(state_struct *state);

/**
 * \brief set cpu to standby or active
 * \param [in] state - 1 for active, 0 for standby
 * \return status
 */
CDN_API_STATUS CDN_API_MainControl(state_struct *state, u8 mode, u8 *resp);

/**
 * \breif blocking version of #CDN_API_MainControl
 */
CDN_API_STATUS CDN_API_MainControl_blocking(state_struct *state, u8 mode,
					    u8 *resp);

/**
 * \brief settings for APB
 *
 * Sends GENERAL_APB_CONF Command via regular Mailbox.
 * @param dpcd_bus_sel Set DPCD to use selected bus (0 for APB or 1 for SAPB)
 * @param dpcd_bus_lock Lock bus type. Aftern that bus type cannot be changed
 * by using this function.
 * @param hdcp_bus_sel Same meaning as for DPCD but for HDCP.
 * @param hdcp_bus_lock Same meaning as for DPCD but for HDCP.
 * @param capb_bus_sel Same meaning as for DPCD but for Cipher APB.
 * @param capb_bus_lock Same meaning as for DPCD but for Cipher APB.
 * @param dpcd_resp [out] Status of the operation.
 * If set to zero then DPCD bus type was successfully changed.
 * If not then error occurred, most likely due to locked DPCD bus.
 * @param hdcp_resp [out] Same as for DPCD but for HDCP.
 * @param capb_resp [out] Same as for DPCD but for Cipher APB.
 *
 * \return status
 */
CDN_API_STATUS CDN_API_ApbConf(state_struct *state, u8 dpcd_bus_sel,
			       u8 dpcd_bus_lock, u8 hdcp_bus_sel,
			       u8 hdcp_bus_lock, u8 capb_bus_sel,
			       u8 capb_bus_lock, u8 *dpcd_resp, u8 *hdcp_resp,
			       u8 *capb_resp);

/**
 * blocking version of #CDN_API_MainControl
 */
CDN_API_STATUS CDN_API_ApbConf_blocking(state_struct *state, u8 dpcd_bus_sel,
					u8 dpcd_bus_lock,
					u8 hdcp_bus_sel,
					u8 hdcp_bus_lock,
					u8 capb_bus_sel,
					u8 capb_bus_lock,
					u8 *dpcd_resp,
					u8 *hdcp_resp, u8 *capb_resp);

/**
 * \brief set the  xtensa clk, write this api before turn on the cpu
 */
CDN_API_STATUS CDN_API_SetClock(state_struct *state, u8 MHz);

CDN_API_STATUS CDN_API_General_Read_Register(state_struct *state, u32 addr,
					     GENERAL_Read_Register_response *resp);
CDN_API_STATUS CDN_API_General_Read_Register_blocking(state_struct *state,
						      u32 addr, GENERAL_Read_Register_response *resp);
CDN_API_STATUS CDN_API_General_Write_Register(state_struct *state, u32 addr,
					      u32 val);
CDN_API_STATUS CDN_API_General_Write_Register_blocking(state_struct *state,
						       u32 addr, u32 val);
CDN_API_STATUS CDN_API_General_Write_Field(state_struct *state, u32 addr,
					   u8 startBit, u8 bitsNo, u32 val);
CDN_API_STATUS CDN_API_General_Write_Field_blocking(state_struct *state,
						    u32 addr, u8 startBit,
						    u8 bitsNo, u32 val);
CDN_API_STATUS CDN_API_General_Phy_Test_Access(state_struct *state, u8 *resp);
CDN_API_STATUS CDN_API_General_Phy_Test_Access_blocking(state_struct *state,
							u8 *resp);

/**
 * Read HPD state to check if plug is inserted or not.
 * @param state [out] Pointer to variable where state will be stored.
 *  Bit 0: 0 - plug not inserted, 1 - plug inserted.
 *  Bits 1..7: reserved.
 * @return status
 */
CDN_API_STATUS CDN_API_General_GetHpdState(state_struct *state, u8 *hpd_state);

/**
 * \breif blocking version of #CDN_API_General_GetHpdState
 */
CDN_API_STATUS CDN_API_General_GetHpdState_blocking(state_struct *state, u8 *hpd_state);

#endif
