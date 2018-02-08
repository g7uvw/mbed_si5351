#include "mbed.h"
#include "si5351.h"

Serial pc(SERIAL_TX, SERIAL_RX);
Si5351 si5351;

void loop(void);

int main() {

bool i2c_found;
uint64_t freq_a = 1000000000ULL;
uint64_t freq_b = 17500000000ULL;
pc.printf("Hello World!\n");

// Start serial and initialize the Si5351
    i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
    if(!i2c_found)
    {
        pc.printf("\nSI5351 Device found on I2C bus!\n");
    }
    else
    {
      pc.printf("\nDevice not found on I2C bus!\n");
      pc.printf("Entering do-nothing loop\n");
      for(;;);
    }

  // Set CLK0 to output 10 MHz
  si5351.set_freq(freq_a, SI5351_CLK0);

  // Set CLK1 to output 175 MHz
  si5351.set_ms_source(SI5351_CLK1, SI5351_PLLB);
  si5351.set_freq_manual(freq_b, 70000000000ULL, SI5351_CLK1);

loop();

}

void loop(void)
{
  loop_start:
// Read the Status Register and print it every 10 seconds
 si5351.update_status();
 pc.printf("SYS_INIT: %d \n", si5351.dev_status.SYS_INIT);
 //pc.printf(si5351.dev_status.SYS_INIT);
 pc.printf("  LOL_A: %d \n", si5351.dev_status.LOL_A);
 //pc.printf(si5351.dev_status.LOL_A);
 pc.printf("  LOL_B: %d \n", si5351.dev_status.LOL_B);
 //pc.printf(si5351.dev_status.LOL_B);
 pc.printf("  LOS: %d \n", si5351.dev_status.LOS);
 //pc.printf(si5351.dev_status.LOS);
 pc.printf("  REVID: %d \n", si5351.dev_status.REVID);
 //pc.printf(si5351.dev_status.REVID);

 wait(5);
 goto loop_start;
}
