#include <stdio.h>
#include <unistd.h>

int main() {
    char q[2000],*p=q;
    int d = 1;
    read(0,p,2000);
    int s[2000];
    int i=-1;
    int a,b;
    while (1) {
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
                if (s[i--] == 0) {
                    d = 80;
                } else {
                    d = -80;
                }
                break;
            case '_':
                if (s[i--] == 0) {
                    d = 1;
                } else {
                    d = -1;
                }
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
