/*
 * Jednoduchy nastroj na vypisovanie pomocnych (debugovacich) hlasok. 
 * Pri odovzdani ulohy, kontr pouzije vlastnu implementaciu. 
 * Ta vsetky volania logovacich funkcii ignoruje 
 *
 */ 

#ifndef _PB071_SIMPLE_LOGGER_
#define _PB071_SIMPLE_LOGGER_

#include <stdio.h>
#include <stdarg.h>

/*
 * Makro, potrebne aby sa zabranilo warningom pri preklade
 */
#define UNUSED(a) ((a) = (a))

/*
 * Parameter udava, kam sa bude vypisovat vystup -> (stdout, stderr)
 */
#define SL_OUT stdout

/*
 * Ak je toto makro definovane - funkcie nic nevykonaju
 */
// #define SL_NO_OUT


static inline void _intern_logPrint(FILE * output, const char * format, va_list args)
{
    UNUSED(output);
    UNUSED(format);
    UNUSED(args);

#ifndef SL_NO_OUT

    if (output == NULL) {
        output = SL_OUT;
    }
    
    vfprintf(output, format, args);
    
    va_end(args);

#endif    
    
}



/*
 * Funkcia sa sprava podobne ako funkcia printf 
 * 
 */
static inline void logPrint(const char *format, ...)
{
    va_list args;
    va_start (args, format);
    _intern_logPrint(NULL, format, args);
}


/*
 * Funkcia sa sprava podobne ako funkcia fprintf
 */
static inline void logPrintFile(FILE * output, const char * format, ...)
{
    
    va_list args;
    va_start (args, format);
    _intern_logPrint(output, format, args);
}





#endif
