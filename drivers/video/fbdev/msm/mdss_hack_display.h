typedef struct {
	int panel_frame_rate;
	int panel_width;
	int panel_height;
	int dsi_h_back_porch;
	int dsi_h_front_porch;
	int dsi_h_pulse_width;
	int dsi_h_sync_skew;
	int dsi_v_back_porch;
	int dsi_v_front_porch;
	int dsi_v_pulse_width;
} hack_display_data;

void print_hack_display_data(hack_display_data *display) {
    pr_info("%s:%d, [endcredits], hack display enabled, ready to override properties:\n"
            "\tpanel_frame_rate = %d, panel_width = %d, panel_height = %d,\n"
            "\tdsi_h_back_porch = %d, dsi_h_front_porch = %d, dsi_h_pulse_width = %d,\n"
            "\tdsi_h_sync_skew = %d, dsi_v_back_porch = %d, dsi_v_front_porch = %d, dsi_v_pulse_width = %d\n",
            __func__, __LINE__,
            display->panel_frame_rate,
            display->panel_width,
            display->panel_height,
            display->dsi_h_back_porch,
            display->dsi_h_front_porch,
            display->dsi_h_pulse_width,
            display->dsi_h_sync_skew,
            display->dsi_v_back_porch,
            display->dsi_v_front_porch,
            display->dsi_v_pulse_width);
}