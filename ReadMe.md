# 1-as lab. darbas
### Trumpas darbo apibūdinimas laisva forma

## ADS - Dvejetainis paieškos medis
Tai hierarchinė duomenų struktūra. Joje į kiekvieną `viršūnę`, išskyrus vieną (`šaknį`), yra tik vienintelė nuoroda iš kitos viršūnės.

`Dvejetainiame` medyje iš kiekvienos viršūnės yra ne daugiau nei dvi nuorodos į kitas viršūnes.

Šis medis turi `subalansavimo` funkciją. Tai reiškia, kad subalansuotame medyje medžio viršūnės kairėje esantis pomedis laiko mažesnę reikšmę nei viršūnė, o esantis dešinėje - didesnę.

### Darbą sudarantys failai:
1. main.cpp, tree.h, tree.o - kodas, realizuota ADS.
2. ReadMe.md - trumpas darbo apibūdinimas.
3. Go.cmd arba Go.bat - transliavimo make failas.
4. Makefile - transliavimo make failas.
5. LFF.docx - užpildyta laiko forma.
