set ns [new Simulator]
$ns color 1 Blue
$ns color 2 Red
set tf [open wired.tr w]
$ns trace-all $tf
set nf [open wired.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail

$ns queue-limit $n2 $n3 10

$ns duplex-link-op $n2 $n3 queuePos 0.5

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packetsize 100
$cbr set interval 0.1

$ns at 0.1 "$ftp start"
$ns at 0.5 "$cbr start"
$ns at 2.0 "$ftp stop"
$ns at 2.5 "$cbr stop"

proc finish {} {
global ns nf tf 
$ns flush-trace
close $nf
close $tf 
exec nam wired.nam & 
exit 0
}

$ns at 2.6 "finish"
$ns run 
