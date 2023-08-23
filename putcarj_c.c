#include "main.h"

int putcarj_c(char c)
{
    return write(1, &c, 1);
}
