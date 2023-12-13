/**
 * custom_Strlen - Checks the length of a string
 *
 * @str: the character for the length check
 *
 * Return: the length of the string
 */
int custom_Strlen(const char *str)
{
        int len = 0;

        while (str[len] != '\0')
        {
                len++;
        }
        return (len);
}
