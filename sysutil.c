#include "main.h"
/**
 * string_length - count string length
 * description: this fuction will return number
 *	of characters in a string
 * @str: string to be counted
 * Return: length - number of characters
 */
int string_length(const char *str)	
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * make_string_copy - makeopy of string
 * Description: This will make copy of string
 *	from source to destination
 * @destination: string destination
 * @source: source of string
 * Return: Destination
 */

char *make_string_copy(char *destination, char *source)
{
	int len, i;

	len = 0;
	while(source[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * __print - Print function
 * Description: This will print string using write
 *	without using string_length
 * @string: string to be printed
 * Return: string of chars
 */

void __print(const char *string)
{
	write(STDOUT_FILENO, string, string_length(string));
}
/**
 * _string_cat - string cancatonate
 * Description: it will cancatonate strings
 * @dest: destination
 * @src: source
 * Return: destination
 */

char *string_cat(char *dest, char *src)
{
	int i = 0;
	int dl = 0;

	while (dest[i++])
		dl++;
	for (i = 0; src[i]; i++)
		dest[dl++] = src[i];
	return (dest);
}
char *duplicate_string(const char *string)
{
	size_t length = string_length(string) + 1;
	char *duplicate = (char *)malloc(length * sizeof(char));
	size_t indx;

	if (duplicate != NULL)
	{
		for (indx = 0; indx < length; indx++)
		{
			duplicate[indx] = string[indx];
		}
	}
	return duplicate;
}

int string_compare(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

char *locate_char_str(char *string, char character)
{
	int x;
	while(1)
	{
		x = *string++;
		if (x == character)
		{
			return (string - 1);
		}
		if (x == 0)
		{
			return (NULL);
		}

	}
}

int string_compare_2(const char *s1, const char *s2, size_t len) 
{
	size_t index;
	for (index = 0; index < len; index++)
	{
		if (s1[index] != s2[index])
		{
			return s1[index] - s2[index];
		}
		
		if (s1[index] == '\0' || s2[index] == '\0')
		{
			break;
		}
	}
	return (0);
}
	


