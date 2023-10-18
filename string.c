#include "shell.h"

/**
 * str_len - function that checks length of string
 * @str: String to be checked
 *
 * Return: string length returns
 */

int str_len(char *str)
{
int length = 0;

while (str[length] != '\0')
{
length++;
}
return (length);
}


/**
 * mem_free - function that frees malloc buffer
 * @buffer: Buffer to free
 *
 * Return: nothing
 */
void mem_free(char **buffer)
{
size_t i;

for (i = 0; buffer[i]; i++)
{
free(buffer[i]);
}
free(buffer);
}

/**
 * _strd - function that duplicatesa string
 * @strng: Duplicated string
 *
 * Return: pointer to the new string
 */

char *_strd(char *strng)
{
int i, len;
char *f;
if (strng == NULL)
{
return (NULL);
}
len = str_len(strng);
f = malloc(sizeof(char) * (len + 1));
if (f == NULL)
{
return (NULL);
}
for (i = 0; i < len; i++)
{
f[i] = strng[i];
}
f[i] = '\0';
return (f);
}


/**
 * compare_str - function thatcompares two strings
 *
 * @s1: First string to compare,
 * @s2: Second string to compare,.
 *
 * Return: an interger.
 */
int compare_str(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] < s2[i])
{
return (s1[i] - s2[i]);
}
else if (s1[i] > s2[i])
return (s1[i] - s2[i]);
i++;
}
return (0);
}
