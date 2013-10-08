#include <stdio.h>
#include <unistd.h>

int main() {
    char q[2000],*p=q;
    int d = 1;
    read(0,p,2000);
    int s[2000],i=-1,a,b;
    for (;;) {
        switch (*p) {
            case '.':
                printf("%d\n", s[i--]);
                break;
            case 'v':
                d = 80;
                break;
            case '^':
                d = -80;
                break;
            case '>':
                d = 1;
                break;
            case '<':
                d = -1;
                break;
            case '|':
                d = s[i--] ? -80 : 80;
                break;
            case '_':
                d = s[i--] ? -1 : 1;
                break;
            case '+':
                a = s[i--];
                b = s[i--];
                s[++i] = b + a;
                break;
            case '-':
                a = s[i--];
                b = s[i--];
                s[++i] = b - a;
                break;
            case '/':
                a = s[i--];
                b = s[i--];
                s[++i] = b / a;
                break;
            case '*':
                a = s[i--];
                b = s[i--];
                s[++i] = b * a;
                break;
            case ' ':
                break;
            default:
                s[++i] = *p - '0';
                break;
            case '@':
                return 0;
        }
        p += d;
    }
}
