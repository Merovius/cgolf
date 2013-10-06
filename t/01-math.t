use Test::More;
use Harness;

my $t = slurp(*DATA);

my $t_plus = $t;
(my $t_minus = $t) =~ s'\+'-'g;
(my $t_div = $t) =~ s'\+'/'g;
(my $t_mult = $t) =~ s'\+'*'g;

is_run($t_plus, 3, 'plus');
is_run($t_minus, -1, 'minus');
is_run($t_div, 0, 'divide');
is_run($t_mult, 2, 'multiplication');

done_testing;
__DATA__
v
1   @
>2+.^
