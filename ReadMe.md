# 1-as lab. darbas
### Trumpas darbo apibūdinimas laisva forma

## ADS - Dvejetainis paieškos medis
* Tai hierarchinė duomenų struktūra. Joje į kiekvieną `viršūnę`, išskyrus vieną (`šaknį`), yra tik vienintelė nuoroda iš kitos viršūnės.

* `Dvejetainiame` medyje iš kiekvienos viršūnės yra ne daugiau nei dvi nuorodos į kitas viršūnes.

* Šis medis turi `subalansavimo` funkciją. Tai reiškia, kad subalansuotas medis yra dvejetainis medis, kuriame visi lygiai, išskyrus paskutinį, yra pilnai užpildyti.
Subalansuotame medyje medžio viršūnės kairėje esantis pomedis laiko mažesnę reikšmę nei viršūnė, o esantis dešinėje - didesnę.

### Dvejetainį medį realizuojančios funkcijos:
* Tuščio medžio sukūrimas
* Naujos viršūnės sukūrimas
* Naujos viršūnės įterpimas
* Viršūnės su mažiausia reikšme radimas
* Viršūnės su didžiausia reikšme radimas
* Medžio klonavimas
* Viršūnės ištrinimas
* Medžio subalansavimas!
* Viso medžio sunaikinimas
* Viršūnių suskaičiavimas
* Medžio aukščio suskaičiavimas
* Medžio elemento lygio radimas
* Tikrinimas ar medis pilnas
* Tikrinimas ar medis tuščias
* Tikrinimas ar medis yra baigtas
* Viso medžio atspausdinimas


### Darbą sudarantys failai:
1. main.cpp, tree.cpph, tree.h - kodas, realizuota ADS.
2. ReadMe.md - trumpas darbo apibūdinimas.
3. Go.cmd arba Go.bat - transliavimo make failas.
4. Makefile - transliavimo make failas.
5. LFF.docx - užpildyta laiko forma.
