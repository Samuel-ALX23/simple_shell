#include "main.h"
/**
 * printout - print out
 * @s: char s
 */
void printout(char *s)
{
	write(1, s, _strlen(s));
}
