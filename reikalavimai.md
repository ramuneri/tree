# 1-as lab. darbas
Atliktame darbe turėtų būti `LFF.docx` -- užpildyta laiko forma.

`ReadMe.md` -- trumpas darbo apibūdinimas.

`Go.cmd` arba `Go.bat` -- komandų failas testo sutransliavimui ir įvykdymui.

`Makefile` -- transliavimo make failas.
## ReadMe.md
Trumpas darbo apibūdinimas laisva forma. Jei tai pernelyg sudėtinga, perkopijuokite užduoties formulavimą iš `1uzduotis.docx` (tik savo variantą).

## Go.cmd arba Go.bat
Iš esmės **arba**. Jei pateiktas `Go.cmd`, tuomet `Go.bat` nereikalingas. Tuo ar kitu atveju, reikia parodyti, kad fakultetinis PC, kažkuo skiriasi nuo asmeninio, pvz.

```cmd
if .%USERDOMAIN% == .SavasPC goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau
:savasPC
make
:toliau
test.exe > test.txt
```
## Makefile
Iš esmės **transliavimo make failas**, todėl visokie kitokie **make failai** (tipo, šiukšlių išvalymui, sutransliuotos programos vykdymas, etc.) tinkami tik į `KaipSau` darbo direktoriją.

Šiame faile būtina parodyti supratimą, jog parašytas funkcijas galima sutransliuoti atskirai, nuo testinės programos, pvz.:

```makefile
test.exe : main.c stack.h stack.o
	gcc -std=c99 -o test.exe main.c stack.o
stack.o : stack.c stack.h
	gcc -c -std=c99 stack.c
