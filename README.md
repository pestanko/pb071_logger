## Testovaci nastroj pre PB071

### Pouzitie:
* je potrebny len hlavickovy subor logger.h
* v nom su funkcie
 * logPrint(const char * format, ... ) - funkcia sa sprava rovnako ako printf
 * logPrintFile(FILE * file, const char * format, ...) - funkcia sa sprava rovnako ako fprintf

* MAKRA - Prefix SL -> Simple Logger
 * SL_NO_OUT - ak je toto makro definova - nic sa na vystup nevypisuje a funkcia sa len zavola bez toho ze by nieco robila
 * SL_OUT - nastavuje FILE ukazatel na vystup.



