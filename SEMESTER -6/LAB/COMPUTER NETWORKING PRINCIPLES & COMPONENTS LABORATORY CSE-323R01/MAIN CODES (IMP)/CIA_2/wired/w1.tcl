# Create a simulator instance
set ns [new Simulator]

# Define trace and NAM files
set tracefile [open out.tr w]
$ns trace-all $tracefile

set namfile [open out.nam w]
$ns namtrace-all $namfile

# Define Nodes
set n0 [$ns node]  ;# TCP Source
set n1 [$ns node]  ;# UDP Source
set n2 [$ns node]  ;# Router
set n3 [$ns node]  ;# TCP Destination
set n4 [$ns node]  ;# UDP Destination

# Define Links
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail
$ns duplex-link $n2 $n4 1Mb 10ms DropTail

# Set queue size (optional)
$ns queue-limit $n2 $n3 20
$ns queue-limit $n2 $n4 20

# Create TCP Agent and Attach to n0
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

# Attach FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

# Create UDP Agent and Attach to n1
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n4 $null
$ns connect $udp $null
$udp set fid_ 2

# Attach CBR over UDP
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packetSize_ 500
$cbr set interval_ 0.1

# Schedule Start and Stop Times
$ns at 0.5 "$ftp start"
$ns at 1.0 "$cbr start"
$ns at 4.5 "$ftp stop"
$ns at 5.0 "$cbr stop"

# Finish Procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}

# Schedule Finish
$ns at 6.0 "finish"

# Run the Simulation
$ns run
