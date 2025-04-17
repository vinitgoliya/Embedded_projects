SET PATH=C:\Users\user\embedded_development\ARM\ARMCC\bin\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Users\user\development\sdks\flutter\bin;%USERPROFILE%\AppData\Local\Microsoft\WindowsApps;
SET CPU_TYPE=LPC2148
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x03938700
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmAsm" --Via "..\bin\startup._ia"
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmCC" --Via "..\bin\main.__i"
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmCC" --Via "..\bin\delay.__i"
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmCC" --Via "..\bin\pll0.__i"
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmCC" --Via "..\bin\uart0.__i"
"C:\Users\user\embedded_development\ARM\ARMCC\bin\ArmLink" --Via "..\bin\arm_uart.lnp"
C:\Users\user\embedded_development\ARM\ARMCC\bin\fromelf.exe "..\bin\arm_uart.axf" --i32combined --output "..\bin\arm_uart.hex"
