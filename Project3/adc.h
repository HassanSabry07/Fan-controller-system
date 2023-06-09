 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek updated by Hassan Sabry
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{

	AREF,AVCC,Reserved,Internal_Voltage

}ADC_ReferenceVolatge;

typedef enum{

	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024

}ADC_Prescaler;


/*The ADC_ConfigType structure to set volt and prescaler*/
typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
