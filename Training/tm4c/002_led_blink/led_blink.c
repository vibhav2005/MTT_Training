#include<tm4c123gh6pge.h>
#include<stdint.h>
#define true 1
#define false 0
static int i,j;
void delay(){
    for(i=0;i<300000;i++){};};
int main(void)
{    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
     GPIO_PORTG_DEN_R  |= 0x000000FF;
     GPIO_PORTG_DIR_R  |= 0x000000FF;
    while(1){
        for(j=7;j>=0;j--){
        GPIO_PORTG_DATA_R = (GPIO_PORTG_DATA_R &(~(0x000000FF))) + (1<<j) + (1<<(7-j));
        delay();

        };
    };
}




