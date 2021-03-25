#include "cua_tu_esp_6_sensor_rtos.h"

void dirHall(int position){
        SystemVar.sensor_hall_duplicate = position;
        ECHOLN(position);
        if(SystemVar.forward){
            SystemVar.count_pul_FG++;
        }else{
            SystemVar.count_pul_FG--;
        }
}

void IRAM_ATTR dirhallSensor1(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 1){
        dirHall(1);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_2 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_2 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_6 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_6 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_1 = true;
            }
        }
    }
    
}

void IRAM_ATTR dirhallSensor2(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 2){
        dirHall(2);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_3 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_3 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_1 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_1 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_2 = true;
            }
        }
    }
    
}

void IRAM_ATTR dirhallSensor3(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 3){
        dirHall(3);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_4 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_4 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_2 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_2 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_3 = true;
            }
        }
    }
    
}

void IRAM_ATTR dirhallSensor4(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 4){
        dirHall(4);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_5 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_5 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_3 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_3 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_4 = true;
            }
        }
    }
    
}

void IRAM_ATTR dirhallSensor5(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 5){
        dirHall(5);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_6 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_6 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_4 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_4 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_5 = true;
            }
        }
    }
    
}

void IRAM_ATTR dirhallSensor6(){      //nhan du lieu tu cam bien ben ngoai
    if(SystemVar.sensor_hall_duplicate != 6){
        dirHall(6);
        if(SystemVar.daytay && SystemVar.status_stop){
            // SystemVar.sensor_hall_duplicate = 0;
            if(SystemVar.hall_sensor_1 == true){
                //cho dong co chay thuan
                SystemVar.hall_sensor_1 = false;
                // ECHOLN("open");
                // Open();
            }
            else if(SystemVar.hall_sensor_5 == true){
                //cho dong co chay nghich
                SystemVar.hall_sensor_5 = false;
                // ECHOLN("close");
                // Close();
            }
            else{
                SystemVar.hall_sensor_6 = true;
            }
        }
    }
    
}

void IRAM_ATTR inputSpeed(){
    if(SystemVar.forward){
        SystemVar.pul_speed++;
    }else{
        SystemVar.pul_speed--;
    }
    // ECHOLN(SystemVar.pul_speed);
}

/* this function will be invoked when additionalTask was created */
void ReceiveDataCan( void * parameter )
{
    CAN_frame_t rx_frame;
	/* loop forever */
	for(;;)
	{
        if (xQueueReceive(CAN_cfg.rx_queue, &rx_frame, 3 * portTICK_PERIOD_MS) == pdTRUE) {
            if (rx_frame.FIR.B.FF == CAN_frame_std) {
            ECHO("New standard frame");
            }
            else {
            ECHO("New extended frame");
            }

            if (rx_frame.FIR.B.RTR == CAN_RTR) {
            printf(" RTR from %d, DLC %d\r\n", rx_frame.MsgID,  rx_frame.FIR.B.DLC);
            }
            else {
            printf(" from %d, DLC %d, Data ", rx_frame.MsgID,  rx_frame.FIR.B.DLC);
            for (int i = 0; i < rx_frame.FIR.B.DLC; i++) {
                printf("%d ", rx_frame.data.u8[i]);
            }
            printf("\n");
            }
        }
	}
	/* delete a task when finish,
	this will never happen because this is infinity loop */
	vTaskDelete( NULL );
}

/* this function will be invoked when additionalTask was created */
void ControlMotor( void * parameter )
{
	for(;;){
        if(true){       //khi cho dong co chay
            float inside = ((float)SystemVar.percent_low_in/100)*SystemVar.count_pul_distant;
            float outside = ((100 - (float)SystemVar.percent_low_out)/100)*SystemVar.count_pul_distant;
        }
	}
	/* delete a task when finish,
	this will never happen because this is infinity loop */
	vTaskDelete( NULL );
}


void ControlLed(void *parameter){
	for(;;){
	}
    /* delete a task when finish,
	this will never happen because this is infinity loop */
	vTaskDelete( NULL );
}

void ConfigWifi(void *parameter){
	for(;;){
	}
    /* delete a task when finish,
	this will never happen because this is infinity loop */
	vTaskDelete( NULL );
}

void caculateSpeed(void *parameter){
	for(;;){
	}
    /* delete a task when finish,
	this will never happen because this is infinity loop */
	vTaskDelete( NULL );
}




void setup()
{	
	Serial.begin(112500);

	// pinMode(PIN_TEST, INPUT);
	// pinMode(PIN_LED, OUTPUT);

	// OEEVars.xQueue = xQueueCreate(MODBUS_MASTER_TELEGRAM, sizeof(MODBUSTELEGRAM));


    attachInterrupt(digitalPinToInterrupt(hallSensor1), dirhallSensor1, RISING);
    attachInterrupt(digitalPinToInterrupt(hallSensor2), dirhallSensor2, RISING);
    attachInterrupt(digitalPinToInterrupt(hallSensor3), dirhallSensor3, RISING);
    attachInterrupt(digitalPinToInterrupt(hallSensor4), dirhallSensor4, RISING);
    attachInterrupt(digitalPinToInterrupt(hallSensor5), dirhallSensor5, RISING);
    attachInterrupt(digitalPinToInterrupt(hallSensor6), dirhallSensor6, RISING);
    attachInterrupt(digitalPinToInterrupt(inputFG), inputSpeed, FALLING);


	/* we create a new task here */
	xTaskCreate(
	ReceiveDataCan, /* Task function. */
	"ReceiveDataCan", /* name of task. */
	10000, /* Stack size of task */
	NULL, /* parameter of the task */
	1, /* priority of the task */
	NULL); /* Task handle to keep track of created task */

	xTaskCreate(
	ControlMotor, /* Task function. */
	"ControlMotor", /* name of task. */
	10000, /* Stack size of task */
	NULL, /* parameter of the task */
	1, /* priority of the task */
	NULL); /* Task handle to keep track of created task */

	xTaskCreate(
	ControlLed, /* Task function. */
	"ControlLed", /* name of task. */
	10000, /* Stack size of task */
	NULL, /* parameter of the task */
	1, /* priority of the task */
	NULL); /* Task handle to keep track of created task */

    xTaskCreate(
	ConfigWifi, /* Task function. */
	"ConfigWifi", /* name of task. */
	10000, /* Stack size of task */
	NULL, /* parameter of the task */
	1, /* priority of the task */
	NULL); /* Task handle to keep track of created task */

    xTaskCreate(
	caculateSpeed, /* Task function. */
	"caculateSpeed", /* name of task. */
	10000, /* Stack size of task */
	NULL, /* parameter of the task */
	1, /* priority of the task */
	NULL); /* Task handle to keep track of created task */
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
	// Serial.println("this is ESP32 Task");
	// delay(1000);
	vTaskDelay(10/ portTICK_PERIOD_MS);
}
