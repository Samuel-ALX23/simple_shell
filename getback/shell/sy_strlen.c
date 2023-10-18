#include "shell.h"
/**
 * my_strlen - initialize a pointer ptr to the start of the given string
 * @str: given string
 *
 * Return: size_t value Always (success)
 */

size_t my_strlen(const char* str)
{
    const char* ptr = str;

    while (*ptr)
        ptr++;

    return (ptr - str);
}
