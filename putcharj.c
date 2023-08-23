#include "main.h"

int putcharj(char c)
{
	return write(1, &c, 1);
}
