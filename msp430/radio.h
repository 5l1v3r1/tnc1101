/******************************************************************************/
/* tnc1101  - Radio serial link using CC1101 module and MSP430                */
/*                                                                            */
/* Radio link definitions                                                     */
/*                                                                            */
/*                      (c) Edouard Griffiths, F4EXB, 2015                    */
/*                                                                            */
/******************************************************************************/

#ifndef _RADIO_H_
#define _RADIO_H_

#include <stdint.h>

#include "TI_CC_spi.h"
#include "TI_CC_CC1100-CC2500.h"
#include "msp430_interface.h"

#define TX_FIFO_REFILL 60 // With the default FIFO thresholds selected this is the number of bytes to refill the Tx FIFO
#define RX_FIFO_UNLOAD 59 // With the default FIFO thresholds selected this is the number of bytes to unload from the Rx FIFO

#define RADIO_BUFSIZE  (TI_CCxxx0_PACKET_SIZE+2)

void    init_radio_spi();
void    init_radio(msp430_radio_parms_t *radio_parms);
void    get_radio_status(uint8_t *status_regs);
uint8_t send_setup(uint8_t *dataBlock);
uint8_t send_more(uint8_t *dataBlock);
void    start_tx();

#endif // _RADIO_H_