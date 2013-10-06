#!/usr/bin/perl
use strict;
use warnings;
use v5.12;
use Carp;
use Data::Dumper;
use File::Temp 'tempfile';
use IO::Pty::Easy;

use Exporter 'import';
our @EXPORT = qw/run_data run is_run unpretty slurp/;

sub stdin { local $/; <> }
sub run {
    my $bin = $ENV{GOLF_BIN};
    die "enviornment variable GOLF_BIN not set" unless $bin;

    my $buf = unpretty(shift);
    say "'$_'" for $buf =~ /(.{80})/g;
    my ($in, $tmp_in) = tempfile('tmpXXXXX', UNLINK => 1);
    print $in $buf;
    close $in;

    my $pty = IO::Pty::Easy->new;
    $pty->spawn("$bin < $tmp_in 2>/dev/null");

    my $out = '';
    $out .= $pty->read while $pty->is_active;
    return split "\n", $out;
}

sub is_run {
    my ($prog, @want) = @_;
    my $name = pop @want;
    main::ok(main::eq_array([ run($prog) ], \@want), $name);
}

sub run_data {
    local $/;
    my ($caller) = caller;
    no strict 'refs';
    run(readline *{"$caller\::DATA"});
}

sub unpretty {
    my ($buf) = @_;
    my $result = '';

    # XXX re-entrance
    return $buf if length $buf == 2000 and $buf !~ /\n/m;

    my @ops = $buf =~ /([^\n]{0,80})\s*\n/gm;
    for (@ops) {
        my $fill = ' ' x (80 - length $_);
        $result .= $_ . $fill;
    }
    
    return $result . (' ' x (80 * 25 - 80 * @ops));
}

sub slurp { my $fh = shift; local $/; <$fh> }
sub dd { say Dumper @_ }
