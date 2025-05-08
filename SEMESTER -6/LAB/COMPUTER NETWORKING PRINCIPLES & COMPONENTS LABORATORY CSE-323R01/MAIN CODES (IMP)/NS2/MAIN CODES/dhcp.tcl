set ns [new Simulator]
set tf [open dhcp.tr w]
$ns trace-all $tf
set nf [open dhcp.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 10ms DropTail

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp0 $null
$ns connect $udp1 $null

set d0 [new Application/Traffic/Exponential]
$d0 attach-agent $udp0
$d0 set packetsize 100
$d0 set idle_time 0.1
$d0 set burst_time 0.2

set d1 [new Application/Traffic/Exponential]
$d1 attach-agent $udp1
$d1 set packetsize 100
$d1 set idle_time 0.1
$d1 set burst_time 0.3

set d2 [new Application/Traffic/Exponential]
$d2 attach-agent $null
$d2 set packetsize 200

$ns at 0.1 "$d0 start"
$ns at 0.5 "$d2 start"
$ns at 0.6 "$d1 start"
$ns at 1.0 "$d2 start"

proc finish {} {
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam dhcp.nam &
exit 0
}

$ns at 1.1 "finish"
$ns run
