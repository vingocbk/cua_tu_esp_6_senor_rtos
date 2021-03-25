#ifndef ESP_6_SENSOR_H
#define ESP_6_SENSOR_H

#include "AppDebug.h"
#include <Arduino.h>
#include "WebServer.h"
#include "WiFi.h"
#include "EEPROM.h"
#include <ESP32CAN.h>
#include <CAN_config.h>
#include "EspOTA.h"
#include "ArduinoJson.h"
#include "config.h"

#include "soc/soc.h"  //Brownout detector was triggered
#include "soc/rtc_cntl_reg.h"

struct CanVariables
{
    /* data */
    int deviceIdReceiveCan;
    int modeRunReceiveCan;
    int timeReturReceiveCan;
    int percentLowInReceiveCan;
    int percentLowOutReceiveCan;
	int timeDelayAnalogReceiveCan;
	int valueErrorAnalogReceiveCan;
	int stopSpeedReceiveCan;
}CanVar;

struct SystemVariables
{
	/* data */
	//for control motor
	int sensor_hall_duplicate;	//exception 1 1 2 2 3 -> 1 2 3
	volatile int count_pul_FG;				//current position
	int count_pul_distant;		//all distant
	int pul_speed;
	int pre_pul_speed;
	int count_first_run;
	int mode_run;
	int time_return;
	int percent_low_in;
	int percent_low_out;
	int device_id;
	int time_delay_analog;
	int value_error_analog;
	int pre_value_error_analog;
	uint32_t time_check_analog;
	int define_error_analog;
	int define_time_auto_close;
	uint32_t time_auto_close;
	int stop_speed;
	
	float speed_velectory;

	bool forward;
	bool daytay;
	bool status_stop;
	bool normal_mode;
	bool is_save_distant;
	bool first_run;
	bool flag_auto_close;
	bool hall_sensor_1;
	bool hall_sensor_2;
	bool hall_sensor_3;
	bool hall_sensor_4;
	bool hall_sensor_5;
	bool hall_sensor_6;

	//for control led
	/* data */
	int red_after;
	int green_after;
	int blue_after;
	int red_before;
	int green_before;
	int blue_before;
	int count_change_led;
	bool status_led;

	//for button config click
	/* data */
  	uint32_t time_click_button_config;
	
}SystemVar;

WebServer server(HTTP_PORT);
CAN_device_t CAN_cfg;               // CAN Config
const int rx_queue_size = 10;       // Receive Queue size

#endif
