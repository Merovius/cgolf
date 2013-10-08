#define c(a,x) case a: x; break;
#define o(a,r) c(a, s[--i] = s[i] r s[i+1])
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
            o(43, +)
            o(45, -)
            o(47, /)
            o(42, *)
            c(32, )
            default:
                s[++i] = *p - '0';
                break;
            c(64, return 0)
        }
        p += d;
    }
}
