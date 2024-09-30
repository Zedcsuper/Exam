#include <stdlib.h>
#include <stdio.h>

int count_word(char *s)
{
    int i = 0;
    int count = 0;

    while (s[i])
    {
        if (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
            i++;
        else
        {
            count++;
            while (s[i] != '\t' && s[i] != '\n' && s[i] != ' ' && s[i])
                i++;
        }
    }
    return count;
}

char *ft_strncpy(char *dst, char *src, int len)
{
    while (len--)
        *dst++ = *src++;
    *dst = '\0';
    return dst;
}

char *create_word(int *index, char *str)
{
    int i = *index;
    char *word;

    while (str[*index] != ' ' && str[*index] != '\t' && str[*index] != '\n' && str[*index])
        (*index)++;
    word = malloc(sizeof(char) * (*index - i + 1));
    if (!word)
        return NULL;
    ft_strncpy(word, &str[i], (*index) - i);  // Copy the word correctly
    return word;
}

char **ft_split(char *str)
{
    int index = 0;
    int wc = count_word(str);
    char **arr = malloc(sizeof(char *) * (wc + 1));
    int i = 0;

    if (!arr)
        return NULL;

    while (i < wc)
    {
        while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t')
            index++;
        if (str[index])
            arr[i++] = create_word(&index, str);
    }
    arr[i] = NULL;
    return arr;
}

int main(void)
{
    char *s = "abc efg";
    int wc = count_word(s);
    int i = 0;
    char **ar = ft_split(s);

    while (i < wc)
        printf("%d: %s\n", i, ar[i++]);

    // Free memory allocated for the array
    for (i = 0; i < wc; i++)
        free(ar[i]);
    free(ar);

    return 0;
}

