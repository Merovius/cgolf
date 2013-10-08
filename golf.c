#include <stdio.h>
#include <unistd.h>

int main() {
    char q[2000],*p=q;
    int d = 1;
    read(0,p,2000);
    int s[2000],i=-1,a,b;
    for (;;) {
        switch (*p) {
            case 46:
                printf("%d\n", s[i--]);
                break;
            case 118:
                d = 80;
                break;
            case 94:
                d = -80;
                break;
            case 62:
                d = 1;
                break;
            case 60:
                d = -1;
                break;
            case 124:
                d = s[i--] ? -80 : 80;
                break;
            case 95:
                d = s[i--] ? -1 : 1;
                break;
            case 43:
                a = s[i--];
                b = s[i--];
                s[++i] = b + a;
                break;
            case 45:
                a = s[i--];
                b = s[i--];
                s[++i] = b - a;
                break;
            case 47:
                a = s[i--];
                b = s[i--];
                s[++i] = b / a;
                break;
            case 42:
                a = s[i--];
                b = s[i--];
                s[++i] = b * a;
                break;
            case 32:
                break;
            default:
                s[++i] = *p - '0';
                break;
            case 64:
                return 0;
        }
        p += d;
    }
}
