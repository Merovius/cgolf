s[2000],i=-1;
main(d) {
    char q[2000],*p=q;
    read(0,p,2000);
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
                s[--i] = s[i] + s[i+1];
                break;
            case 45:
                s[--i] = s[i] - s[i+1];
                break;
            case 47:
                s[--i] = s[i] / s[i+1];
                break;
            case 42:
                s[--i] = s[i] * s[i+1];
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
