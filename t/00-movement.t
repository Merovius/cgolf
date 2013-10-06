use Test::More;
use Harness;
is_run("@\n", (), 'exit');

my @moves = run(<<'moves');
v   > v
1   .      
.   4      
    ^           @.5 <
    .
    3
>2. ^ >             ^
moves
trail(@moves);

@moves = run(<<'stack');
v
5
4   @.  <
3       .
2
1       ^
.       .
>.      ^
stack
trail(@moves);

sub trail {
    is shift(@moves), 1, 'move down';
    is shift(@moves), 2, 'then left';
    is shift(@moves), 3, 'and up';
    is shift(@moves), 4, 'up';
    is shift(@moves), 5, 'left';
}

sub is_move { is shift(@moves), @_; }
done_testing;

