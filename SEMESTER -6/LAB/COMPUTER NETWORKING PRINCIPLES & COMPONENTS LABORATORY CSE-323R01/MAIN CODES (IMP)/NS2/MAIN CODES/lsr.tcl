set ns [new Simulator]
set tf [open lsr.tr w]
$ns trace-all $tf
set nf [open lsr.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n1 10Mb 15ms DropTail
$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n3 10Mb 15ms DropTail
$ns duplex-link $n2 $n3 10Mb 10ms DropTail

$ns node-config -adhocRouting OLSR

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $tcp
$cbr set packetsize 512
$cbr set interval_ 0.5

$ns at 0.1 "$cbr start"

proc finish {} {
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam lsr.nam &
exit 0
}

$ns at 25.0 "finish"
$ns run
