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

 char **tokenizer(char *str, char *delim)
 {
         char *str2 = _strdup(str);
         char **buffer;
         const char s[2] = " ";
         int delim_count = 0, i;

         for (i = 0; str[i] != '\0'; i++)
         {       if (str[i] == *delim)
                 {       delim_count++;  }
         }

         buffer = malloc(sizeof(char *) * (delim_count + 2));

         if (buffer == NULL)
                 {       return (NULL);  }

         i = 0;
         buffer[i] = strtok(str2, s);
         i++;
         while (i <= delim_count)
         {    
               buffer[i] = strtok(NULL, s);
               i++;
         }

         buffer[i] = NULL;

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
