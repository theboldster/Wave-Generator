#include "AD9833.h"
#include "MCP_POT.h"

// PINs work for Arduino Nano and Uno
#define WFG_SELECT 10
#define WFG_DATA 11
#define WFG_CLK 13
#define WFG_POTSEL 9
#define WFG_POTRES 8 // Not used but needed for the driver SW
#define WFG_POTSHUTD 7 // Not used but needed for the driver SW
#define WFG_FREQ 1000000.0

/*
//  MODE OPERANDI
#define AD9833_OFF                  0
#define AD9833_SINE                 1
#define AD9833_SQUARE1              2 // Assigned Frequency
#define AD9833_SQUARE2              3 // Half Frequancy
#define AD9833_TRIANGLE             4

#define MCP_POT_MIDDLE_VALUE 128
#define MCP_POT_MAX_VALUE 255
*/

AD9833 AD(WFG_SELECT, WFG_DATA, WFG_CLK);
MCP_POT pot(WFG_POTSEL, WFG_POTRES, WFG_POTSHUTD, WFG_DATA, WFG_CLK);

uint32_t start, stop;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("AD9833_LIB_VERSION: ");
  Serial.println(AD9833_LIB_VERSION);
  Serial.println();

  // SPI.begin();
  pot.begin();

  Serial.println(MCP_POT_MAX_VALUE);
  pot.setValue(0, MCP_POT_MAX_VALUE);
  Serial.print("Pot Resistance: ");
  Serial.println(pot.getValue());


  AD.begin();
  AD.setWave(AD9833_SINE);
  Serial.print("Waveform: ");
  Serial.println(AD.getWave());
  AD.setFrequency(WFG_FREQ, 0);
  Serial.print("Frequency: ");
  Serial.println(AD.getFrequency(0));
  AD.setFrequencyChannel(0);
}


void test_extremes()
{
  // Serial.println(__FUNCTION__);
  delay(10);

  // Serial.println("0");
  pot.setValue(0, 0);
  delay(20);

  // Serial.println(MCP_POT_MIDDLE_VALUE);
  pot.setValue(0, MCP_POT_MIDDLE_VALUE);
  delay(20);

  // Serial.println(MCP_POT_MAX_VALUE);
  pot.setValue(0, MCP_POT_MAX_VALUE);
  delay(20);
}

void loop() {
  // put your main code here, to run repeatedly:
 // test_extremes();
}
