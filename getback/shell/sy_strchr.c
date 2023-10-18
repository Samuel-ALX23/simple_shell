#include "shell.h"

/**
 * *my_strchr: function searches for the first occurrence of a character in a string
 * @*str: The string pointer to be searched
 * @c: The integer character to be searched for
 *
 * Return: pointer str always (sucess)

char *my_strchr(const char *str, int c)
{
  while (*str != '\0' && *str != c)
  {
    str++;
  }
  if (*str == '\0')
  {
    return (NULL);
  }
  else
  {
    return (char *)str;
  }
}
