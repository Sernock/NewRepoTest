#include <stdio.h>
#define MAXLINE 100

int get_line(char *, int);
int strrindex(char src[], char pat[]);

char pattern[] = "pattern";

int main(void)
{
    char line[MAXLINE];
    int len;
    
    if ((len = get_line(line, MAXLINE)) > 0) {
        int pos = strrindex(line, pattern);
        printf("%d\n", pos);
    }
    return 0;
}

int get_line(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';  

    return s - start;
}

int strrindex(char src[], char pat[])
{
    int i, j, k;
    int last = -1;

    for (i = 0; src[i] != '\0'; ++i) {
        for (j = i, k = 0; pat[k] != '\0' && src[j++] == pat[k++]; )
            ;
        if (pat[k] == '\0')
        last = i;
    }
    return last;
}
