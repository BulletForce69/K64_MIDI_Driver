/*
 * MIDI.h
 *  V1.1
 *  Created on: Nov 15, 2022
 *      Author: Casas Ramírez, Luis Fernando
 * 
 *  MIDI Driver for k64
 */

#ifndef MIDI_H_
#define MIDI_H_

//#include "your_UART_driver.h"

#define MIDI_MSG_SIZE 3u

typedef enum{
	kMIDI_Channel1 = 0u,
	kMIDI_Channel2,
	kMIDI_Channel3,
	kMIDI_Channel4,
	kMIDI_Channel5,
	kMIDI_Channel6,
	kMIDI_Channel7,
	kMIDI_Channel8,
	kMIDI_Channel9,
	kMIDI_Channel10,
	kMIDI_Channel11,
	kMIDI_Channel12,
	kMIDI_Channel13,
	kMIDI_Channel14,
	kMIDI_Channel15,
	kMIDI_Channel16

} MIDI_Channels;

typedef struct{
	uint8_t code;
	uint8_t chanel;
	uint8_t param1;
	uint8_t param2;
}MIDI_DATA_t;


typedef enum{
	kMIDI_Note_Off = 0x8,
	kMIDI_Note_On,
	kMIDI_Note_Aftertouch,
	kMIDI_Controller,
	kMIDI_Program_Change,
	kMIDI_Channel_Pressure,
	kMIDI_Pitch_Bend,

}MIDI_Commands;

uint8_t *MIDI_Create_MSG(MIDI_DATA_t *DATA_IN);
void MIDI_Send_Data(uint8_t Data[MIDI_MSG_SIZE]);
void MIDI_PITCHBEND(void);


#endif /* MIDI_H_ */