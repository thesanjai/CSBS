set ns [new Simulator]
set tf [open sliding.tr w]
$ns trace-all $tf
set nf [open sliding.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

$ns queue-limit $n1 $n2 2

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set window_ 5

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $tcp
$cbr set packetsize 512
$cbr set rate_ 1Mb
$cbr set interval_ 0.001

$ns at 0.1 "$cbr start"
$ns at 1.0 "$cbr stop"

proc finish {} {
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam sliding.nam &
exit 0
}

$ns at 1.1 "finish"
$ns run
