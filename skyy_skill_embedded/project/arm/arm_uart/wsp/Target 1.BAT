SET PATH=E:\installed\Keil_v5\ARM\ARMCC\bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Users\Lenovo\AppData\Local\Microsoft\WindowsApps;C:\Users\Lenovo\AppData\Local\GitHubDesktop\bin
SET CPU_TYPE=LPC2148
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x03938700
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmAsm" --Via "..\bin\startup._ia"
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\bin\main.__i"
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\bin\delay.__i"
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\bin\pll0.__i"
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\bin\uart0.__i"
"E:\installed\Keil_v5\ARM\ARMCC\bin\ArmLink" --Via "..\bin\arm_uart.lnp"
E:\installed\Keil_v5\ARM\ARMCC\bin\fromelf.exe "..\bin\arm_uart.axf" --i32combined --output "..\bin\arm_uart.hex"
