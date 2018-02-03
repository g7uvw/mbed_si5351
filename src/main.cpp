#include "mbed.h"
#include "si5351.h"


Serial pc(SERIAL_TX, SERIAL_RX);
Si5351 si5351;

int main() {

bool i2c_found;
uint64_t freq_a = 1e7;
uint64_t freq_b = 1e5;
pc.printf("Hello World!\n");

// Start serial and initialize the Si5351
    i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
    if(!i2c_found) {
        pc.printf("\nDevice not found on I2C bus!\n");
    }
//loop_start:
  // Set CLK0 to output 14 MHz
  wait(1);
  si5351.set_freq(1400000000ULL, SI5351_CLK0);
  //si5351.set_freq(freq_a, SI5351_CLK0);
  si5351.update_status();

  //wait(1);
  //si5351.set_freq(freq_b, SI5351_CLK0);


  //wait(5);
  //si5351.set_freq(freq_b, SI5351_CLK0);
  // Set CLK1 to output 175 MHz
  //si5351.set_ms_source(SI5351_CLK1, SI5351_PLLB);
  //si5351.set_freq_manual(freq_b, 70000000000ULL, SI5351_CLK1);

    // Query a status update and wait a bit to let the Si5351 populate the
    // status flags correctly.
  //si5351.update_status();
  //wait(5);
  //goto loop_start;
}
