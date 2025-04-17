#include<reg51.h>
#include<timer.h>
#include<lcd.h>
#include<string.h>


void printName(char *str)
  {
		Set_LCD_Command(0x80); //Force cursor to the beginning ( 1st line)
		Set_LCD_String(str);
		//Set_LCD_Char('A');
		Set_LCD_Command(0xC0); //	Force cursor to the beginning ( 2nd line)
		Set_LCD_String("Goliys");
	//	Set_LCD_Char('B');
	}
	

	
void intToStr(int num, char *str) {
    int i = 0, j, rem;
    char temp;

    // Extract digits and store them in reverse order
    do {
        rem = num % 10;      // Get the last digit
        str[i++] = rem + '0'; // Convert digit to ASCII
        num /= 10;           // Remove the last digit
    } while (num > 0);

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string
    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void formatTime(int hours, int minutes, int seconds, char *timeStr) {
    char temp[3]; // Temporary buffer for each component

    // Format hours
    if (hours < 10) {
        temp[0] = '0';         // Add leading zero
        temp[1] = hours + '0'; // Convert to ASCII
        temp[2] = '\0';
    } else {
        temp[0] = (hours / 10) + '0';  // Tens place
        temp[1] = (hours % 10) + '0';  // Units place
        temp[2] = '\0';
    }
    strcpy(timeStr, temp);     // Copy hours to the result string
    strcat(timeStr, ":");      // Add colon separator

    // Format minutes
    if (minutes < 10) {
        temp[0] = '0';
        temp[1] = minutes + '0';
        temp[2] = '\0';
    } else {
        temp[0] = (minutes / 10) + '0';
        temp[1] = (minutes % 10) + '0';
        temp[2] = '\0';
    }
    strcat(timeStr, temp);     // Add minutes to the result string
    strcat(timeStr, ":");      // Add colon separator

    // Format seconds
    if (seconds < 10) {
        temp[0] = '0';
        temp[1] = seconds + '0';
        temp[2] = '\0';
    } else {
        temp[0] = (seconds / 10) + '0';
        temp[1] = (seconds % 10) + '0';
        temp[2] = '\0';
    }
    strcat(timeStr, temp);     // Add seconds to the result string
}





void main()
	{
		int seconds = 0;
		char strSeconds[6];
		Init_LCD();
		config_25msec();
		printName(strSeconds);
		while(1)
			{


			

			overflow_check();
			if(counter==40)
				{
				//	strcpy(str, "125");
					intToStr(seconds, strSeconds);// working well
				//	printName(strSeconds);
					//formatTime(hours, minutes, seconds, timeStr);
					//formatTime(11, 03, 42, strSeconds);
					printName(strSeconds);
					if(seconds == 60)
					  {
							seconds = 0;
						}
					counter = 0;
					seconds++;
					P1 = ~P1;
				}
			}
	}