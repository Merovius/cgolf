use Test::More;
use Harness;

my $t_right = <<'RIGHT';
0   v
v 2 _ 1 v
>       > .@
RIGHT

is_run($t_right, 1, 'turn right if 0');
(my $t_left = $t_right) =~ s/0/3/g;
is_run($t_left, 2, 'turn left unless 0');

my $t_down = <<'DOWN';
v > v
0 2 .
> | @
  1 .
  > ^
DOWN

is_run($t_down, 1, 'turn down if 0');
(my $t_up = $t_down) =~ s/0/3/g;
is_run($t_up, 2, 'turn up unless 0');

done_testing;
