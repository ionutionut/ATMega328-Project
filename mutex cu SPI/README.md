Acest folder realizeaza o implementare de **mutex** pe baza proiectului anterior existent in folderul: "implementare mutex".

Astfel, se are in vedere comunicarea intre procesele "potentiometer" si "askPotentiometer"; ambele procese trebuie sa acceseze variabila *potentiometerValue*, care reprezinta **resursa critica**.


De asemenea se are in vedere receptia unor date primite prin SPI.

Componenta transmitatorului:
ATmega 8 + tranceiver nRF24L01+

Componenta receptorului:
ATmega 328 (functioneaza cu FreeRTOS)  + tranceiver nRF24L01+


