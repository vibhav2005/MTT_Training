#include<tm4c123gh6pge.h>
#include<stdint.h>
static int B_o = 0,B_n , x;


int button_read(){
    return ((GPIO_PORTG_DATA_R & 0x80)!=0 ?1:0);
}
int main(void)
{
    SYSCTL_RCGCGPIO_R |=  SYSCTL_RCGCGPIO_R6;
    GPIO_PORTG_DEN_R  |= 0xFF;
    GPIO_PORTG_DIR_R  |= 0x7F;
    GPIO_PORTG_DATA_R |= 0x40;
    GPIO_PORTG_PDR_R  |= 0x80;
    x = 0;
    while(1){
        if(x==0){
        B_n = button_read();
        x=10000;
        }

        else{
        if(B_o == 0 && B_n == 1 ){
            GPIO_PORTG_DATA_R ^= 0x1;
       }
       B_o = B_n;
       --x;
      }

     }
  }


