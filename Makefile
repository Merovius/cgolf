all:
	$(CC) -D'c(a,x)=*p+3==*#a?x:' -D'o(a,r)=c(a,(*++s=*s r*(s-1),d))' -o golf golf.c
