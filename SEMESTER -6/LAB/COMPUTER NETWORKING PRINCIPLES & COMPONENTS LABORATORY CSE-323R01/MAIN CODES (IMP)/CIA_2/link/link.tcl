# Create a new simulator object
set ns [new Simulator]

# Open a file for tracing
set tracefile [open "output.tr" w]
$ns trace-all $tracefile

set nf [open "link.nam" w]
$ns namtrace-all $nf

# Define network topology and nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

# Create links between nodes with cost
$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n3 10Mb 15ms DropTail
$ns duplex-link $n2 $n4 10Mb 20ms DropTail
$ns duplex-link $n3 $n4 10Mb 25ms DropTail

# Enable OLSR (Link State Routing protocol)
$ns rtproto LS

# Create TCP agent and CBR traffic to simulate data transmission
set tcp0 [new Agent/TCP]
set sink [new Agent/TCPSink]
$ns attach-agent $n0 $tcp0
$ns attach-agent $n4 $sink
$ns connect $tcp0 $sink

# Define a CBR traffic generator for TCP
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 512
$cbr set interval_ 0.5
$cbr attach-agent $tcp0

# Start the CBR traffic
$ns at 1.0 "$cbr start"

# Schedule simulation end
$ns at 20.0 "finish"

# Define the finish procedure
proc finish {} {
    global ns tracefile
    exec nam link.nam &
    $ns flush-trace
    close $tracefile
    exit 0
}

# Run the simulation
$ns run
