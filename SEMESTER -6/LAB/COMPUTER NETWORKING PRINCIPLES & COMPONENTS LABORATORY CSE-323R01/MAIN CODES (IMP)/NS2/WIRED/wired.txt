# Create a simulator instance
set ns [new Simulator]

# Define trace files
set tracefile [open out.tr w]
$ns trace-all $tracefile

set namfile [open out.nam w]
$ns namtrace-all $namfile

# Define nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

# Create wired links (with 10ms delay and 1Mb bandwidth)
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

# Setup queue monitor
$ns queue-limit $n0 $n1 10
$ns queue-limit $n1 $n2 10

# Define TCP connection between n0 and n2
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink

# Create a traffic source
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

# Schedule events
$ns at 0.1 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"

# Finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}

# Run the simulation
$ns run
