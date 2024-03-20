#include<tm4c123gh6pge.h>
#include<stdint.h>
#define true 1
#define false 0
int i;

int main(void)
{    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
     GPIO_PORTG_DEN_R  |= 0x000000FF;
     GPIO_PORTG_DIR_R  |= 0x000000FF;
    while(1){

    GPIO_PORTG_DATA_R |= 0x00000001;
    for(i=0;i<16000000;i++){
    }

    GPIO_PORTG_DATA_R &= ~0x00000001;
    for(i=0;i<16000000;i++){
        }
    };

}
