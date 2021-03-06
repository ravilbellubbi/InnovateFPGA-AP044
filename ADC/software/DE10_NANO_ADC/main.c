#include <stdio.h>
#include <io.h>
#include <unistd.h>
#include <math.h>

#include "system.h"

void main(void){
	int ch = 0;
	const int nReadNum = 10; // max 1024
	int i, Value=0;
	float R1 = 10000; //R1, c1,c2,c3 being constants for adc conversions
	float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;
	float logR2, R2, T;
	//printf("Enter the sensor value, 1 for temp sensor, 2 for eda, 3 for Gas, 4 for Light");

	while(1){
		ch = IORD(SW_BASE, 0x00) & 0x07;

		IOWR(ADC_LTC2308_BASE, 0x01, nReadNum);


		// start measure
		IOWR(ADC_LTC2308_BASE, 0x00, (ch << 1) | 0x00);
		IOWR(ADC_LTC2308_BASE, 0x00, (ch << 1) | 0x01);
		IOWR(ADC_LTC2308_BASE, 0x00, (ch << 1) | 0x00);
		usleep(1);

		// wait measure done
		while ((IORD(ADC_LTC2308_BASE,0x00) & 0x01) == 0x00);

		// read adc value
		for(i=0;i<nReadNum;i++){
			Value = IORD(ADC_LTC2308_BASE, 0x01);
			R2 = R1 * (1023.0 / (((float)Value/1000.0)*30)-1.0); //voltage to temp conversions
			logR2 = log(R2);
			T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
			T = T - 60;
			int("Value=%.3f /n",T);
		}
		if(T<=182.5){        //the treshold value for given flame sensor
			printf("No fire forest is safe\r\n");
		}
		else{
			printf("Fire save the forest!!!\r\n");
		}
		usleep(200*1000);
	} // while
}

