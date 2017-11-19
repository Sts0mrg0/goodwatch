/*! \file radio.h
  \brief RF1A Radio Module Driver
  
*/

//! Standard radio settings structure from RF Studio.
typedef struct S_RF_SETTINGS {
    unsigned char fsctrl1;   // Frequency synthesizer control.
    unsigned char fsctrl0;   // Frequency synthesizer control.
    unsigned char freq2;     // Frequency control word, high byte.
    unsigned char freq1;     // Frequency control word, middle byte.
    unsigned char freq0;     // Frequency control word, low byte.
    unsigned char mdmcfg4;   // Modem configuration.
    unsigned char mdmcfg3;   // Modem configuration.
    unsigned char mdmcfg2;   // Modem configuration.
    unsigned char mdmcfg1;   // Modem configuration.
    unsigned char mdmcfg0;   // Modem configuration.
    unsigned char channr;    // Channel number.
    unsigned char deviatn;   // Modem deviation setting (when FSK modulation is enabled).
    unsigned char frend1;    // Front end RX configuration.
    unsigned char frend0;    // Front end RX configuration.
    unsigned char mcsm0;     // Main Radio Control State Machine configuration.
    unsigned char foccfg;    // Frequency Offset Compensation Configuration.
    unsigned char bscfg;     // Bit synchronization Configuration.
    unsigned char agcctrl2;  // AGC control.
    unsigned char agcctrl1;  // AGC control.
    unsigned char agcctrl0;  // AGC control.
    unsigned char fscal3;    // Frequency synthesizer calibration.
    unsigned char fscal2;    // Frequency synthesizer calibration.
    unsigned char fscal1;    // Frequency synthesizer calibration.
    unsigned char fscal0;    // Frequency synthesizer calibration.
    unsigned char fstest;    // Frequency synthesizer calibration control
    unsigned char test2;     // Various test settings.
    unsigned char test1;     // Various test settings.
    unsigned char test0;     // Various test settings.
    unsigned char fifothr;   // RXFIFO and TXFIFO thresholds.
    unsigned char iocfg2;    // GDO2 output pin configuration
    unsigned char iocfg0;    // GDO0 output pin configuration
    unsigned char pktctrl1;  // Packet automation control.
    unsigned char pktctrl0;  // Packet automation control.
    unsigned char addr;      // Device address.
    unsigned char pktlen;    // Packet length.
} RF_SETTINGS;


//! Set to 1 if the watch has a radio.
extern int has_radio;

//! Called at boot.  Gracefully fails if no radio.
void radio_init();

//! Turns the radio on.  Returns zero on failure.
int radio_on();

//! Restarts the radio.  (Call this after radio_on().)
void radio_resetcore();

//! Turns the radio off.
int radio_off();


//! Read a register from the radio.
uint8_t radio_readreg(uint8_t addr);
//! Write to a register in the radio.
void radio_writereg(uint8_t addr, uint8_t value);
//! Strobe a radio register.
uint8_t radio_strobe(uint8_t strobe);

//! Writes a radio settings structure.
void radio_writesettings(RF_SETTINGS *pRfSettings);

//! Writes one value to the power table.
void radio_writepower(unsigned char value);
