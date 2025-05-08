# Create the simulator object
set ns [new Simulator]

# Open the trace file for writing
set tracefile [open "output.tr" w]
$ns trace-all $tracefile

set nf [open "slide.nam" w]
$ns namtrace-all $nf

# Define nodes (n0 as sender, n1 as receiver)
set n0 [$ns node]
set n1 [$ns node]

# Set up a duplex link between the sender and receiver
$ns duplex-link $n0 $n1 10Mb 20ms DropTail

# Set up TCP agent on sender (n0) and TCPSink on receiver (n1)
set tcp [new Agent/TCP]
$tcp set window_ 5   ;# Window size set to 5 to simulate Go-Back-N
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink

# Connect TCP source and sink agents
$ns connect $tcp $sink

# Create a CBR (Constant Bit Rate) traffic source to generate data
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500   ;# Packet size of 500 bytes
$cbr set rate_ 1Mb         ;# Sending rate
$cbr attach-agent $tcp

# Schedule the start and stop of the CBR traffic
$ns at 0.5 "$cbr start"
$ns at 4.5 "$cbr stop"

# Define a finish procedure
proc finish {} {
    global ns tracefile
    exec nam slide.nam & 
    $ns flush-trace
    close $tracefile
    exit 0
}

# Schedule the end of the simulation
$ns at 5.0 "finish"

# Run the simulation
$ns run

