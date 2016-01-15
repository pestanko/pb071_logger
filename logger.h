/*
 * Jednoduchy nastroj na vypisovanie pomocnych (debugovacich) hlasok. 
 * Pri odovzdani ulohy, kontr pouzije vlastnu implementaciu. 
 * Ta vsetky volania logovacich funkcii ignoruje 
 *
 */ 

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define UNUSED(a) ((a) = (a))

/*
 * Parameter udava, kam sa bude vypisovat vystup -> ("stdout", "stderr")
 */
#define SL_OUT "stdout"

/*
 * Ak je toto makro definovane - funkcie nic nevykonaju
 */
// #define SL_NO_OUT


static inline void _intern_logPrint(FILE *output, 
    const char *format, 
    va_list args)
{
    UNUSED(output);
    UNUSED(format);
    UNUSED(args);

#ifndef SL_NO_OUT
    FILE *desc = NULL;
    if (output == NULL)  { // Output not passed
        // Case that output is set to stdout
        if (!strcmp("stdout", SL_OUT)) {
            output = stdout; 
        }
        // Case that output is set to stderr
        else if (!strcmp("stderr", SL_OUT)) {
            output = stderr;
        }
        // dafult case - append to file
        else {
            desc = fopen(SL_OUT, "a");
            if (!desc) {
                output = stdout; // if file was not succesfuly opened !
            }
            else {
                output = desc;
            } 
        }
        
    }
    
    vfprintf(output, format, args);
    
    va_end(args);
    
    if (desc) {
        fclose(desc);
    }

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


#undef UNUSED


#endif
