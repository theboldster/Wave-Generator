# Wave-Generator
Hardware: Arduino Uno/Nano and DollaTek AD9833 Module
The module has AD9833 Waveform generator, a MCP41010 programmable potentiometer and an AD8051 op-amp.
The MCP41010 programmable potentiometer is used to control gain op-amp.

In square wave mode, the WFG produces approx 5V output on both outputs
In sine and triangle Mode the raw output is around 600mV. At the amplified output to around 3,6V at max level.

Based on code DFG-ArdAD9833 from ilneill (Github)

Uses Arduino Libraries MCP_POT and AD9833 from RobTillaart (Github). These libraries are designed to use the chips in standalalone mode.

Pins (X = no connection): <br/>
AD9833 - Arduino <br/>
VCC - 5V <br/>
GND - GND <br/>
FSY - D10 -> Chip select for waveform generator <br/>
CLK - D13 -> Used by both the waveform generator and programmable potentiometer <br/>
DAT - D11 -> Used by both the waveform generator and programmable potentiometer <br/>
CS - D9 -> Chip select for programmable potentiometer <br/>

Output: <br/>
PGA - X -> Module waveform output after amplification <br/>
Vout - X -> Module waveform output direct from AD9833 (before amplification) <br/>
GND - X -> Ground for outputs

On Arduino: <br/>
X - D8, D7 -> Not used on WFG module. Needed for the MCP_POT Library for the potentiometer parameters reset and shutdown functions

