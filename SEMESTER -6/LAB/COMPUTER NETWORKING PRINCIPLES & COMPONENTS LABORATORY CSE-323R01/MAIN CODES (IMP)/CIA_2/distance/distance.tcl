# Create a new simulator object
set ns [new Simulator]

# Open a file for tracing
set tracefile [open "output.tr" w]
$ns trace-all $tracefile

set nf [open "dv.nam" w]
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

# Define the distance vector routing protocol using a base agent (similar to AODV)
# We use AODV here to simulate the behavior of a distance vector protocol
set ragent [new Agent/AODV]

# Attach the routing agent to the nodes
$ns attach-agent $n0 $ragent
$ns attach-agent $n1 $ragent
$ns attach-agent $n2 $ragent
$ns attach-agent $n3 $ragent
$ns attach-agent $n4 $ragent

# Define TCP agents and CBR traffic to simulate data transmission
set tcp0 [new Agent/TCP]
set sink [new Agent/TCPSink]
$ns attach-agent $n0 $tcp0
$ns attach-agent $n4 $sink
$ns connect $tcp0 $sink

# Generate traffic from node 0 to node 4 (to observe routing table updates)
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 512
$cbr set interval_ 0.5
$cbr attach-agent $tcp0

# Start the traffic
$ns at 1.0 "$cbr start"

# Run the simulation for 20 seconds
$ns at 20.0 "finish"

# Define the finish procedure
proc finish {} {
    global ns tracefile
    $ns flush-trace
    exec nam dv.nam &
    close $tracefile
    exit 0
}

# Run the simulation
$ns run
