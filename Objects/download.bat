set JFlashFilePath="D:\Program Files (x86)\SEGGER\JLink_V630k\JFlash.exe"
set DataFilePath=%cd%
%JFlashFilePath% -openprj%DataFilePath%\STM32F103C8.jflash -open%DataFilePath%stm32f1xx_demo.hex -erasechip -programverify -startapp -exit
