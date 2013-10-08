#define c(a,x) case a: x; break;
s[2000],i=-1;
main(d) {
    char q[2001],*p=q;
    gets(p);
    for (;;) {
        switch (*p) {
            c(46, printf("%d\n", s[i--]))
            c(118, d = 80)
            c(94, d = -80)
            c(62, d = 1)
            c(60, d = -1)
            c(124, d = s[i--] ? -80 : 80)
            c(95, d = s[i--] ? -1 : 1)
            c(43, s[--i] = s[i] + s[i+1])
            c(45, s[--i] = s[i] - s[i+1])
            c(47, s[--i] = s[i] / s[i+1])
            c(42, s[--i] = s[i] * s[i+1])
            c(32, )
            default:
                s[++i] = *p - '0';
                break;
            c(64, return 0)
        }
        p += d;
    }
}
