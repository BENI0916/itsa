//題目18. QWERTY.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[2001];
    gets(str);


    // 根據每個字元輸出對應字元
    for(int idx = 0; idx < strlen(str); idx++)
    {
        if(isalpha(str[idx]))
            str[idx] = tolower(str[idx]);

        switch(str[idx])
        {
            case ' ':
                printf(" ");
                break;
            case '!':
                printf("@");
                break;
            case '"':
                printf("\"");
                break;
            case '#':
                printf("$");
                break;
            case '$':
                printf("%%");
                break;
            case '%':
                printf("^");
                break;
            case '&':
                printf("*");
                break;
            case '\'':
                printf("\'");
                break;
            case '(':
                printf(")");
                break;
            case ')':
                printf("_");
                break;
            case '*':
                printf("(");
                break;
            case '+':
                printf("+");
                break;
            case ',':
                printf(".");
                break;
            case '-':
                printf("=");
                break;
            case '.':
                printf("/");
                break;
            case '/':
                printf("/");
                break;
            case '0':
                printf("-");
                break;
            case '1':
                printf("2");
                break;
            case '2':
                printf("3");
                break;
            case '3':
                printf("4");
                break;
            case '4':
                printf("5");
                break;
            case '5':
                printf("6");
                break;
            case '6':
                printf("7");
                break;
            case '7':
                printf("8");
                break;
            case '8':
                printf("9");
                break;
            case '9':
                printf("0");
                break;
            case ':':
                printf("\"");
                break;
            case ';':
                printf("\'");
                break;
            case '<':
                printf(">");
                break;
            case '=':
                printf("=");
                break;
            case '>':
                printf("?");
                break;
            case '?':
                printf("?");
                break;
            case '@':
                printf("#");
                break;
            case 'a':
                printf("s");
                break;
            case 'b':
                printf("n");
                break;
            case 'c':
                printf("v");
                break;
            case 'd':
                printf("f");
                break;
            case 'e':
                printf("r");
                break;
            case 'f':
                printf("g");
                break;
            case 'g':
                printf("h");
                break;
            case 'h':
                printf("j");
                break;
            case 'i':
                printf("o");
                break;
            case 'j':
                printf("k");
                break;
            case 'k':
                printf("l");
                break;
            case 'l':
                printf(";");
                break;
            case 'm':
                printf(",");
                break;
            case 'n':
                printf("m");
                break;
            case 'o':
                printf("p");
                break;
            case 'p':
                printf("[");
                break;
            case 'q':
                printf("w");
                break;
            case 'r':
                printf("t");
                break;
            case 's':
                printf("d");
                break;
            case 't':
                printf("y");
                break;
            case 'u':
                printf("i");
                break;
            case 'v':
                printf("b");
                break;
            case 'w':
                printf("e");
                break;
            case 'x':
                printf("c");
                break;
            case 'y':
                printf("u");
                break;
            case 'z':
                printf("x");
                break;
            case '[':
                printf("]");
                break;
            case '\\':
                printf("\\");
                break;
            case ']':
                printf("\\");
                break;
            case '^':
                printf("&");
                break;
            case '_':
                printf("=");
                break;
            case '`':
                printf("1");
                break;
            case '{':
                printf("}");
                break;
            case '|':
                printf("|");
                break;
            case '}':
                printf("|");
                break;
            case '~':
                printf("!");
                break;
        }
    }

    printf("\n");

    return 0;
}