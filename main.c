#include "logger.h"
#include "test.h"
int main()
{
    logPrint("Ahoj svet !\n");
    logPrint("Ahoj svet %d \n", 15);
    logPrintFile(stderr, "FRPNT %d\n", 10);
    
    printer();

    return 0;
}


