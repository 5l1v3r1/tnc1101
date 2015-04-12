#ifndef _MAIN_H_
#define _MAIN_H_

#include <inttypes.h>
#include <termios.h> 

#include "msp430_interface.h"

#define ALLOW_VAR_BLOCKS 0
#define ALLOW_REAL_TIME  1

typedef enum tnc_mode_e {
    TNC_BULK_TX = 0,
    TNC_BULK_RX,
    TNC_KISS,
    TNC_SLIP,
    TNC_TEST_USB_ECHO,
    TNC_RADIO_STATUS,
    TNC_RADIO_INIT,
    TNC_TEST_TX,
    TNC_TEST_RX,
    TNC_TEST_ECHO_TX,
    TNC_TEST_ECHO_RX,
    TNC_TEST_TX_PACKET,
    TNC_TEST_RX_PACKET,
    TNC_TEST_RX_PACKET_NON_BLOCKING,
    NUM_TNC
} tnc_mode_t;

extern char *tnc_mode_names[];
extern char *modulation_names[];

typedef enum rate_e {
    RATE_50,
    RATE_110,
    RATE_300,
    RATE_600,
    RATE_1200,
    RATE_2400,
    RATE_4800,
    RATE_9600,
    RATE_14400,
    RATE_19200,
    RATE_28800,
    RATE_38400,
    RATE_57600,
    RATE_76800,
    RATE_115200,
    RATE_250K,
    RATE_500K,
    NUM_RATE
} rate_t;

extern uint32_t rate_values[];

typedef enum preamble_e {
    PREAMBLE_2,
    PREAMBLE_3,
    PREAMBLE_4,
    PREAMBLE_6,
    PREAMBLE_8,
    PREAMBLE_12,
    PREAMBLE_16,
    PREAMBLE_24,
    NUM_PREAMBLE
} preamble_t;

extern uint8_t nb_preamble_bytes[];

typedef enum power_e {
    POWER_N30,
    POWER_N20,
    POWER_N15,
    POWER_N10,
    POWER_0,
    POWER_5,
    POWER_7,
    POWER_10,
    NUM_POWER
} power_t;

extern int power_values[];

typedef struct arguments_s {
    uint8_t            verbose_level;        // Verbose level
    uint8_t            print_long_help;      // Print a long help and exit
    char               *bulk_filename;       // File name for bulk transfer
    // --- USB link TNC ---
    char               *usbacm_device;       // TNC USB ttyACMx device (real) 
    speed_t            usb_speed;            // TNC USB serial speed (physical, Baud)
    uint32_t           usb_speed_n;          // TNC USB serial speed as a number (physical)
    // --- serial link TNC ---
    char               *serial_device;       // Virtual TNC AX.25 serial device (virtual)
    speed_t            serial_speed;         // Virtual TNC AX.25 serial speed (physical, Baud)
    uint32_t           serial_speed_n;       // Virtual TNC AX.25 serial speed as a number (physical)
    uint8_t            slip;                 // 1: use a SLIP interface. This effectively de-activates the KISS command parsing.
    // --- radio parameters ---
    uint8_t            print_radio_status;   // Print radio status and exit
    radio_modulation_t modulation;     // Radio modulation scheme
    rate_t             rate;                 // Data rate (Baud)
    float              rate_skew;            // Data rate skew multiplier from nominal
    float              modulation_index;     // Modulation index
    double             freq_offset_ppm;      // Frequency offset compensation in ppm
    power_t            power_index;          // Power index corresponding to PATABLE setting of CC1101 (see p.60 of documentation)
    uint32_t           freq_hz;              // Frequency in Hz
    uint32_t           if_freq_hz;           // Intermediate frequency in Hz
    uint8_t            packet_length;        // Fixed packet length
    uint16_t           large_packet_length;  // Composed large packet length
    uint8_t            variable_length;      // Set variable length packet mode. Fixed packet argument becomes maximum packet size
    tnc_mode_t         tnc_mode;             // TNC mode of operation 
    char               *test_phrase;         // Test phrase to transmit
    uint8_t            test_rx;              // Reception test. Exits after receiving number of repetition packets
    uint8_t            repetition;           // Repetition factor
    uint8_t            fec;                  // Activate FEC
    uint8_t            whitening;            // Activate whitening
    preamble_t         preamble;             // Preamblescheme (number of preamble bytes)
    uint32_t           block_delay;         // Delay before sending packet on serial or radio in microseconds
    uint32_t           tnc_serial_window;    // Time window in microseconds for concatenating serial frames (0: no concatenation)
    uint32_t           tnc_radio_window;     // Time window in microseconds for concatenating radio frames (0: no concatenation)
    uint32_t           tnc_keyup_delay;      // TNC keyup delay in microseconds
    uint32_t           tnc_keydown_delay;    // TNC keydown delay in microseconds
    uint32_t           tnc_switchover_delay; // TNC Rx/Tx switchover delay in microseconds
    uint8_t            real_time;            // Engage so called "real time" scheduling
} arguments_t;

#endif
