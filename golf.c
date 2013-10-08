#define c(a,x) case a: x; break;
#define o(a,r) c(a, *--s = *s r *(s+1))
t[2000];
main(d) {
    char q[2001],*p=q,*s=t;
    gets(p);
    for (;;) {
        switch (*p) {
            c(46, printf("%d\n", *s--))
            c(118, d = 80)
            c(94, d = -80)
            c(62, d = 1)
            c(60, d = -1)
            c(124, d = *s-- ? -80 : 80)
            c(95, d = *s-- ? -1 : 1)
            o(43, +)
            o(45, -)
            o(47, /)
            o(42, *)
            c(32, )
            default:
                *++s = *p - '0';
                break;
            c(64, return 0)
        }
        p += d;
    }
}
