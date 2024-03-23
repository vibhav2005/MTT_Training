#include<tm4c123gh6pge.h>
#include <stdint.h>
#define true 1
#define false 0
int main(void)
{
 SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
 GPIO_PORTG_DEN_R  |= 0x000000FF;
 GPIO_PORTG_DIR_R  |= 0x000000FF;
 GPIO_PORTG_DATA_R  |= 0x00000040;
 while(1){};
 }
