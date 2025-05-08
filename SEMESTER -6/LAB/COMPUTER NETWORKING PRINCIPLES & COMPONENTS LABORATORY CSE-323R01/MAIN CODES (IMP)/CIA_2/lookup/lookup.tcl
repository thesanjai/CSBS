# dns_simulation.tcl

# Create simulator
set ns [new Simulator]

# Open trace and nam files
set tracefile [open dns.tr w]
set namfile [open dns.nam w]
$ns trace-all $tracefile
$ns namtrace-all $namfile

# Create nodes
set c [$ns node]
set s [$ns node]

# Link nodes
$ns duplex-link $c $s 1Mb 10ms DropTail

# Define client and server agents (UDP for DNS simulation)
set udpC [new Agent/UDP]
set udpS [new Agent/UDP]
$ns attach-agent $c $udpC
$ns attach-agent $s $udpS

# Attach traffic generator to client (simulate DNS query)
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 50
$cbr set interval_ 0.2 ;# simulate queries every 200ms
$cbr attach-agent $udpC

# Attach null sink to server (simulate DNS reply handler)
set null [new Agent/Null]
$ns attach-agent $s $null

# Connect client to server
$ns connect $udpC $null

# Start and stop traffic
$ns at 0.5 "$cbr start"
$ns at 4.5 "$cbr stop"
$ns at 5.0 "finish"

# Finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam dns.nam &
    exit 0
}

# Run simulation
$ns run
