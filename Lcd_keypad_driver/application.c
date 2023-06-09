/****************************************************************
 * File name : application.c
 * Author: Sarah
 ***************************************************************/

#include "lcd.h"
#include "keypad.h"
#include <util/delay.h> /* For the delay functions */

int main(void)
{
	unsigned char key;
	LCD_init();

	LCD_displayStringRowColumn(0,0,"Challenge");
	LCD_displayStringRowColumn(1,0,"Keypad 4x4");
	LCD_displayStringRowColumn(2,0,"LCD");

	LCD_moveCursor(3,0); /* Move the cursor to the second row */

    while(1)
    {
    	/* Get the pressed key number, if any switch pressed for more than 500 ms it will considered more than one press */
		key = KEYPAD_getPressedKey();

		if((key <= 9) && (key >= 0))
		{
			LCD_intgerToString(key);   /* display the pressed keypad switch */
		}
		else
		{
			LCD_displayCharacter(key); /* display the pressed keypad switch */
		}

		_delay_ms(500); /* Press time */
    }
}
