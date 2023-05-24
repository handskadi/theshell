#include "main.h"

/**
 * duplicate_string -  Duplicate String
 * Description: this fun will duplicate strings
 *	using string Length func.
 * @string: string to be duplicated.
 * Return: duplicate > a duplication of string
 */
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
	return (duplicate);
}

/**
 * string_compare - Compare strings
 * Description: this will compare between two strings,
 *	String 1 (s1) and String 2 (s2)
 * @str1: String 1
 * @str2: String2
 * Return: result of comarision between two strings
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * locate_char_str - Locate character String
 * Description: this will locate a character in astring
 *	using while loop to iterate and search for
 *	a specified char
 * @string: String
 * @character: character
 * Return: Null
 */
char *locate_char_str(char *string, char character)
{
	int x;

	while (1)
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
/**
 * string_compare_2 - Compare string V2
 * Description: this will compare between two strings
 *	using the length.
 * @s1: String 1
 * @s2: String 2
 * @len: Length
 * Return: 0 Always success.
 */
int string_compare_2(const char *s1, const char *s2, size_t len)
{
	size_t index;

	for (index = 0; index < len; index++)
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}

		if (s1[index] == '\0' || s2[index] == '\0')
		{
			break;
		}
	}
	return (0);
}

