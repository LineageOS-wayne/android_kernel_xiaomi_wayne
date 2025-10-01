/*
 * HX83102E Panel Initialization Sequence
 * Converted from HX83102E_10.95HSD_1200X1920 initialization code
 * 
 * Copyright (C) 2024 EndCredits
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 */

#include <linux/delay.h>
#include "mdss_dsi.h"

extern int mdss_dsi_panel_power_ctrl(struct mdss_panel_data *pdata,
	int power_state);

/**
 * hx83102e_panel_full_init - Send complete initialization sequence to HX83102E panel
 * @ctrl: DSI controller data
 *
 * This function sends the complete initialization sequence to the HX83102E panel,
 * overriding any bootloader initialization settings that may conflict with
 * the new panel configuration.
 */
static void hx83102e_panel_full_init(struct mdss_dsi_ctrl_pdata *ctrl)
{
	struct dsi_cmd_desc cmd;
	struct dcs_cmd_req cmdreq;

	pr_err("HX83102E: Starting complete panel initialization sequence");

	// Helper macro to simplify command sending
	#define SEND_CMD(payload_data, payload_len, delay_ms) \
	do { \
		cmd.dchdr.dtype = DTYPE_DCS_LWRITE; \
		cmd.dchdr.last = 1; \
		cmd.dchdr.wait = 0; \
		cmd.dchdr.vc = 0; \
		cmd.dchdr.ack = 1; \
		cmd.dchdr.dlen = payload_len; \
		cmd.payload = (char *)payload_data; \
		memset(&cmdreq, 0, sizeof(cmdreq)); \
		cmdreq.cmds = &cmd; \
		cmdreq.cmds_cnt = 1; \
		cmdreq.flags = CMD_REQ_COMMIT | CMD_REQ_LP_MODE; \
		cmdreq.rlen = 0; \
		cmdreq.cb = NULL; \
		mdss_dsi_cmdlist_put(ctrl, &cmdreq); \
		if (delay_ms > 0) msleep(delay_ms); \
	} while (0)

	// B9 83 10 2E
	{
		char data[] = {0xB9, 0x83, 0x10, 0x2E};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E9 CD
	{
		char data[] = {0xE9, 0xCD};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BB 01
	{
		char data[] = {0xBB, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E9 00
	{
		char data[] = {0xE9, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D1 67 0C FF 05
	{
		char data[] = {0xD1, 0x67, 0x0C, 0xFF, 0x05};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B1 10 FA AF AF 29 29 B1 6B 31 36 36 36 36 22 21 15 00
	{
		char data[] = {0xB1, 0x10, 0xFA, 0xAF, 0xAF, 0x29, 0x29, 0xB1, 
			      0x6B, 0x31, 0x36, 0x36, 0x36, 0x36, 0x22, 0x21, 0x15, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B2 00 B0 47 80 00 26 E0 29 13 00 00 00 15 20 D7 00
	{
		char data[] = {0xB2, 0x00, 0xB0, 0x47, 0x80, 0x00, 0x26, 0xE0, 
			      0x29, 0x13, 0x00, 0x00, 0x00, 0x15, 0x20, 0xD7, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B4 6A 70 6A 70 6A 90 6A 90 01 9F 01 58 00 FF 00 FF FF
	{
		char data[] = {0xB4, 0x6A, 0x70, 0x6A, 0x70, 0x6A, 0x90, 0x6A, 
			      0x90, 0x01, 0x9F, 0x01, 0x58, 0x00, 0xFF, 0x00, 0xFF, 0xFF};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D2 29 29
	{
		char data[] = {0xD2, 0x29, 0x29};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B6 5A 5A E3
	{
		char data[] = {0xB6, 0x5A, 0x5A, 0xE3};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BF FC 85 80 9C 36 00 04
	{
		char data[] = {0xBF, 0xFC, 0x85, 0x80, 0x9C, 0x36, 0x00, 0x04};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D3 (long sequence)
	{
		char data[] = {0xD3, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xE8, 0x00, 0x00, 0x00, 
			      0x37, 0x37, 0x33, 0x0F, 0x26, 0x26, 0x04, 0x00, 0x32, 0x10, 
			      0x24, 0x00, 0x24, 0x32, 0x17, 0xA8, 0x07, 0xA8, 0x32, 0x10, 
			      0x08, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x50, 0xB6, 0xC8, 0x2C, 
			      0x4F, 0xB6, 0xC8, 0x0F};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 01
	{
		char data[] = {0xBD, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// CB 80 36 12 16 C0 28 54 84 02 34
	{
		char data[] = {0xCB, 0x80, 0x36, 0x12, 0x16, 0xC0, 0x28, 0x54, 0x84, 0x02, 0x34};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D3 01 00 FC 00 00 11 10 00 0A 00 01
	{
		char data[] = {0xD3, 0x01, 0x00, 0xFC, 0x00, 0x00, 0x11, 0x10, 0x00, 0x0A, 0x00, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 02
	{
		char data[] = {0xBD, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B4 4E 00 33 11 33 88
	{
		char data[] = {0xB4, 0x4E, 0x00, 0x33, 0x11, 0x33, 0x88};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BF F2 00 02
	{
		char data[] = {0xBF, 0xF2, 0x00, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// C0 33 33 22 11 A2 17 00 80 00 00 08 00 63 63
	{
		char data[] = {0xC0, 0x33, 0x33, 0x22, 0x11, 0xA2, 0x17, 0x00, 0x80, 0x00, 0x00, 0x08, 0x00, 0x63, 0x63};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D5 (very long sequence)
	{
		char data[] = {0xD5, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
			      0x18, 0x19, 0x19, 0x18, 0x18, 0x1A, 0x1A, 0x1B, 0x1B, 0x00, 
			      0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x20, 0x21, 0x24, 
			      0x25, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
			      0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D6 (very long sequence)
	{
		char data[] = {0xD6, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
			      0x18, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1A, 0x1B, 0x1B, 0x07, 
			      0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x25, 0x24, 0x21, 
			      0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
			      0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E0 (very long sequence)
	{
		char data[] = {0xE0, 0x00, 0x08, 0x15, 0x1E, 0x27, 0x49, 0x63, 0x6F, 0x73, 
			      0x6F, 0x88, 0x8C, 0x90, 0x9D, 0x99, 0xA0, 0xA7, 0xB8, 0xB5, 
			      0x58, 0x60, 0x69, 0x73, 0x00, 0x08, 0x15, 0x1E, 0x27, 0x49, 
			      0x63, 0x6F, 0x73, 0x6F, 0x88, 0x8C, 0x90, 0x9D, 0x99, 0xA0, 
			      0xA7, 0xB8, 0xB5, 0x58, 0x60, 0x69, 0x73};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D0 07 04 05
	{
		char data[] = {0xD0, 0x07, 0x04, 0x05};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E7 (long sequence)
	{
		char data[] = {0xE7, 0x12, 0x13, 0x02, 0x02, 0x55, 0x00, 0x0E, 0x0E, 0x00, 
			      0x26, 0x29, 0x72, 0x1C, 0x72, 0x01, 0x27, 0x00, 0x00, 0x00, 
			      0x00, 0x17, 0x00, 0x68};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 01
	{
		char data[] = {0xBD, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E7 01 30 01 94 0D B5 0E
	{
		char data[] = {0xE7, 0x01, 0x30, 0x01, 0x94, 0x0D, 0xB5, 0x0E};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 02
	{
		char data[] = {0xBD, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E7 (long sequence with special delays)
	{
		char data[] = {0xE7, 0xFF, 0x01, 0xFD, 0x01, 0x00, 0x00, 0x22, 0x00, 0x00, 
			      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			      0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x02, 0x40};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D8 (sequence 1)
	{
		char data[] = {0xD8, 0xAA, 0xAB, 0xEA, 0xAA, 0xAA, 0xA0, 0xAA, 0xAB, 0xEA, 0xAA, 0xAA, 0xA0};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 01
	{
		char data[] = {0xBD, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D8 (sequence 2)
	{
		char data[] = {0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 02
	{
		char data[] = {0xBD, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D8 (sequence 3)
	{
		char data[] = {0xD8, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0xF0};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 03
	{
		char data[] = {0xBD, 0x03};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D8 (sequence 4 - very long)
	{
		char data[] = {0xD8, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x55, 0x55, 0x55, 
			      0x55, 0x55, 0x50, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x55, 
			      0x55, 0x55, 0x55, 0x55, 0x50};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// CC 02
	{
		char data[] = {0xCC, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BA 70 03 A8 83 F2 80 C0 0D
	{
		char data[] = {0xBA, 0x70, 0x03, 0xA8, 0x83, 0xF2, 0x80, 0xC0, 0x0D};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// C8 00 04 04 00 00 02 13 FF
	{
		char data[] = {0xC8, 0x00, 0x04, 0x04, 0x00, 0x00, 0x02, 0x13, 0xFF};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// CB 00 13 08 02 25
	{
		char data[] = {0xCB, 0x00, 0x13, 0x08, 0x02, 0x25};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 02
	{
		char data[] = {0xBD, 0x02};
		SEND_CMD(data, sizeof(data), 5);
	}

	// CB 00 03 00 01 7E
	{
		char data[] = {0xCB, 0x00, 0x03, 0x00, 0x01, 0x7E};
		SEND_CMD(data, sizeof(data), 5);
	}

	// BD 00
	{
		char data[] = {0xBD, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// C7 30 B0 C2 08 10 42 04
	{
		char data[] = {0xC7, 0x30, 0xB0, 0xC2, 0x08, 0x10, 0x42, 0x04};
		SEND_CMD(data, sizeof(data), 5);
	}

	// D1 67 0C 0F
	{
		char data[] = {0xD1, 0x67, 0x0C, 0x0F};
		SEND_CMD(data, sizeof(data), 5);
	}

	// E1 00 01
	{
		char data[] = {0xE1, 0x00, 0x01};
		SEND_CMD(data, sizeof(data), 5);
	}

	// B9 00 00 00
	{
		char data[] = {0xB9, 0x00, 0x00, 0x00};
		SEND_CMD(data, sizeof(data), 5);
	}

	// Now send the final commands with proper delays
	
	// Sleep Out (0x11) with 120ms delay
	{
		struct dsi_cmd_desc sleep_cmd = {
			.dchdr = {DTYPE_DCS_WRITE, 1, 0, 0, 120, 1},  // 120ms delay
			.payload = (char[]){0x11}
		};
		memset(&cmdreq, 0, sizeof(cmdreq));
		cmdreq.cmds = &sleep_cmd;
		cmdreq.cmds_cnt = 1;
		cmdreq.flags = CMD_REQ_COMMIT | CMD_REQ_LP_MODE;
		cmdreq.rlen = 0;
		cmdreq.cb = NULL;
		mdss_dsi_cmdlist_put(ctrl, &cmdreq);
		// No manual msleep needed as delay is built into command
	}

	// Display On (0x29) with 20ms delay
	{
		struct dsi_cmd_desc display_cmd = {
			.dchdr = {DTYPE_DCS_WRITE, 1, 0, 0, 20, 1},   // 20ms delay
			.payload = (char[]){0x29}
		};
		memset(&cmdreq, 0, sizeof(cmdreq));
		cmdreq.cmds = &display_cmd;
		cmdreq.cmds_cnt = 1;
		cmdreq.flags = CMD_REQ_COMMIT | CMD_REQ_LP_MODE;
		cmdreq.rlen = 0;
		cmdreq.cb = NULL;
		mdss_dsi_cmdlist_put(ctrl, &cmdreq);
		// No manual msleep needed as delay is built into command
	}

	pr_err("HX83102E: Complete initialization sequence sent successfully");
	
	#undef SEND_CMD
}

/**
 * hx83102e_force_panel_reinit_work - Work function to force panel re-initialization
 * @work: Work structure
 *
 * This function performs a complete power cycle and re-initialization of the
 * HX83102E panel to overcome bootloader initialization conflicts.
 */
static void hx83102e_force_panel_reinit_work(struct mdss_dsi_ctrl_pdata *ctrl)
{
    char display_off_cmd[] = {0x28};  // Display Off
    char sleep_in_cmd[] = {0x10};    // Sleep In

    struct dsi_cmd_desc cmds[] = {
        {
            .dchdr = {DTYPE_DCS_WRITE, 1, 0, 0, 20, 1},   // Display Off with 20ms delay
            .payload = display_off_cmd
        },
        {
            .dchdr = {DTYPE_DCS_WRITE, 1, 0, 0, 120, 1},  // Sleep In with 120ms delay
            .payload = sleep_in_cmd
        }
    };

    struct dcs_cmd_req cmdreq = {
        .cmds = cmds,
        .cmds_cnt = 2,
        .flags = CMD_REQ_COMMIT | CMD_REQ_LP_MODE,
        .rlen = 0,
        .cb = NULL
    };

	pr_err("HX83102E: Forcing complete panel re-initialization to fix ghosting");

	// Step 1: Wait for image transmission
	ctrl->ctrl_state &= ~CTRL_STATE_MDP_ACTIVE;
	msleep(36);

    //Step 2:  Define and send Display Off + Sleep In
    mdss_dsi_cmdlist_put(ctrl, &cmdreq);

    mdss_dsi_clk_ctrl(ctrl, ctrl->dsi_clk_handle, MDSS_DSI_ALL_CLKS, MDSS_DSI_CLK_OFF);

    msleep(10);

	// Step 3: Complete power cycle to simulate manual screen off/on
	mdss_dsi_panel_power_ctrl(&ctrl->panel_data, MDSS_PANEL_POWER_OFF);
	mdss_dsi_clk_ctrl(ctrl, ctrl->dsi_clk_handle, MDSS_DSI_ALL_CLKS, MDSS_DSI_CLK_OFF);
	
	// Ensure complete power down
	msleep(200);
	
	// Step 4: Power up and re-initialize hardware
	mdss_dsi_panel_power_ctrl(&ctrl->panel_data, MDSS_PANEL_POWER_ON);
	mdss_dsi_clk_ctrl(ctrl, ctrl->dsi_clk_handle, MDSS_DSI_ALL_CLKS, MDSS_DSI_CLK_ON);
	
	// Step 5: Send complete initialization sequence
	hx83102e_panel_full_init(ctrl);
	
	// Step 6: Clean up
	mdss_dsi_clk_ctrl(ctrl, ctrl->dsi_clk_handle, MDSS_DSI_ALL_CLKS, MDSS_DSI_CLK_OFF);
	
	// Step 7: Update controller state
	ctrl->ctrl_state &= ~CTRL_STATE_PANEL_INIT;
	ctrl->ctrl_state |= (CTRL_STATE_DSI_ACTIVE | CTRL_STATE_PANEL_INIT);
	
	pr_err("HX83102E: Forced panel re-initialization completed");
}