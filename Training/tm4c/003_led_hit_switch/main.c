#include<tm4c123gh6pge.h>
#include<stdint.h>
int main(void)
{    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
     GPIO_PORTG_DEN_R  |= 0xFF;
     GPIO_PORTG_DIR_R  |= 0x7F;
     GPIO_PORTG_DATA_R |= 0x40;
     GPIO_PORTG_PDR_R  |= 0x80;
     while(1){
         ((GPIO_PORTG_DATA_R &0x80)!=0) ? ( GPIO_PORTG_DATA_R |=  0x01) : (GPIO_PORTG_DATA_R &= ~(0x01));
     }
}


