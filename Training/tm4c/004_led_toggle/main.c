#include<tm4c123gh6pge.h>
#include<stdint.h>
#include<stdbool.h>
static int B_o = 0,B_n , x;//initialing variables as button old state as B_o and similarly new state
bool button_read(){
    return (GPIO_PORTG_DATA_R & 0x80);//creating a function to read button state
}
int main(void)
{
    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
    GPIO_PORTG_DEN_R  |= 0xFF;//initializing all pins as digital
    GPIO_PORTG_DIR_R  |= 0x7F;//initializing some pins as output and one pin as input to take input
    GPIO_PORTG_DATA_R |= 0x40;//setting one pin high to toggle the input pin using hit switch
    GPIO_PORTG_PDR_R  |= 0x80;////pulling down the input pin
    x = 0;//setting x as 0 to read button for the first time
    while(1){
        if(x==0){
        B_n = button_read();
        x=10000;//resetting its value to act as a debouncing delay
        }
        if(B_o == 0 && B_n == 1 ){
            GPIO_PORTG_DATA_R ^= 0x1;//using xor logic for toggling
       B_o = B_n; //updating the old state of button
       --x;
      }
    }
  }


