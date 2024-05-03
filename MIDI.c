/*
 * MIDI.c
 *  V1.1
 *  Created on: Nov 14, 2022
 *      Author: Casas Ramírez, Luis Fernando
 * 
 *  MIDI Driver for k64
 */

#include "config.h"
#include "MIDI.h"


uint8_t MIDI_Data[3] = {0x91,64,100};

uint8_t *MIDI_Create_MSG(MIDI_DATA_t *DATA_IN){
	static uint8_t MSG [MIDI_MSG_SIZE];
	MSG[0] = DATA_IN->code << 4;
	MSG[0] += DATA_IN->chanel;
	MSG[1] = DATA_IN->param1;
	MSG[2] = DATA_IN->param2;

	return MSG;

}

uint8_t *MIDI_Create_MSG_from_keyboard(MIDI_DATA_t *DATA_IN){
	static uint8_t MSG [MIDI_MSG_SIZE];
	MSG[0] = DATA_IN->code ;
	//MSG[0] += DATA_IN->chanel;
	MSG[1] = DATA_IN->param1;
	MSG[2] = DATA_IN->param2;

	return MSG;

}

void MIDI_Send_Data(uint8_t Data[MIDI_MSG_SIZE]){
	UART_WriteBlocking(UART0, Data, MIDI_MSG_SIZE);
}

void MIDI_PITCHBEND(void){
	MIDI_DATA_t Data;
	uint8_t param_high = Get_Angle_For_MIDI() << 8;
	uint8_t param_low = Get_Angle_For_MIDI();
	param_high %= 60;
	param_low %= 120;
	Data.chanel = kMIDI_Channel1;
	Data.code = kMIDI_Note_On;
	Data.param1 = param_high;
	Data.param2 = param_low;
	MIDI_Send_Data(MIDI_Create_MSG(&Data));

}