 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 /**
  * _strdup - returns pointer to new alloc'd space in mem containing string
  * @str: sting
  *
  * Return: NULL if string is NULL
  */
 char *_strdup(char *str)
 {
         char *ptr;
         int i, len = 0;

         if (str == NULL)
         {
                 return (NULL);
         }
         else
         {
                 while (str[len] != '\0')
                 {
                         len++;
                 }

         ptr = malloc(sizeof(char) * (len + 1));

         if (ptr == NULL)
         {
                 return (NULL);
         }

         for (i = 0; i < len + 1; i++)
         {
                 ptr[i] = str[i];
         }
         }
 return (ptr);
 }

int _strlen(char *str)
{
        int len = 0;

        while (str[len] != '\0')
        {       len++;  }

        return (len);
}

 char **tokenizer(char *str, const char *delim)
 {
         char *str2 = _strdup(str);
         char **buffer;
         char *token;
         int delim_count = 0, i, j;

         for (i = 0; str[i] != '\0'; i++)
         {       if (str[i] == *delim)
                 {       delim_count++;  }
         }

         buffer = malloc(sizeof(char) * (_strlen(str) + 1));

         if (buffer == NULL)
                 {       return (NULL);  }

         token = strtok(str2, delim);
          buffer[0] = malloc(sizeof(char) * (_strlen(token) + 1));
         for (j = 0; j <= _strlen(token); j++)
        {       buffer[0][j] = token[j];        }

        for (i = 1; i <= delim_count; i++)
        {
                token = strtok(NULL, delim);

                buffer[i] = malloc(sizeof(char) * (_strlen(token) + 1));

                for (i = 1, j = 0; j <= _strlen(token); j++)
                {
                        buffer[i][j] = token[j];
                }
        }
         free(str);
         return (buffer);
 }
 int print_string(char *str)
 {
         return (write(1, str, strlen(str)));
 }
 int main(void)
 {
         int i = 0;
         char **token_array = tokenizer("Hello papa smirf", " ");

         while (token_array[i] != NULL)
         {
                 printf("[%d]%s", i, token_array[i]);
                 i++;
                printf("\n");
        }

         free(token_array);

         return (0);
 }


