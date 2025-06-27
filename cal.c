#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 100

enum { NO, YES };

int getline(char *s, int lim);
void reverse(char *s);
int is_containts_vowels(const char *s, char *list);
int is_palindrome(char *s);

char list[] = "aeiouAEIOU";

int main(void)
{
    char line[MAXLINE];
    int len;
    if ((len = getline(line, MAXLINE)) > 0) {
    char *ptr = strrchr(line, '\n');
    if (ptr != NULL)
        *ptr = '\0';
    printf("%d", is_palindrome(line));
    // puts(line);
    }
    return 0;
}

int getline(char *s, int lim)
{
    int c;
    char *st = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - st;
}

void reverse(char *s)
{
    char *ls = s + strlen(s) - 1;
    while (s < ls) {
        int temp = *s;
        *s = *ls;
        *ls = temp;
        ++s;
        --ls;
    }
}

int is_containts_vowels(const char *s, char *list)
{
    int count = 0;
    for (; *s; ++s) {
        char *p = list;
        for (; *p; ++p) {
            if (*s == *p) 
                ++count;
        }
    }
    return count;
}

int is_palindrome(char *s)
{
    char *st = s;
    char *ed = s + strlen(s) - 1;

    while (st < ed) {
        if (tolower(*st) != tolower(*ed)) {
            return NO;
        }
        ++st;
        --ed;
    }
    return YES; 
}
