# Create a new simulator object
set ns [new Simulator]

# Open a file for tracing
set tracefile [open "output.tr" w]
$ns trace-all $tracefile

set nf [open "dhcp.nam" w]
$ns namtrace-all $nf

# Define nodes for clients and the DHCP server
set c1 [$ns node]
set c2 [$ns node]
set dS [$ns node]

# Create links between clients and DHCP server
$ns duplex-link $c1 $dS 10Mb 20ms DropTail
$ns duplex-link $c2 $dS 10Mb 20ms DropTail

# Define UDP agents for DHCP message exchange
set uC1 [new Agent/UDP]
set uC2 [new Agent/UDP]
set uS [new Agent/Null]
$ns attach-agent $c1 $uC1
$ns attach-agent $c2 $uC2
$ns attach-agent $dS $uS
$ns connect $uC1 $uS
$ns connect $uC2 $uS

# Create traffic generator for DHCP Discover (client sends broadcast request)
set dhcpDiscover1 [new Application/Traffic/Exponential]
$dhcpDiscover1 set packetSize_ 100   ;# DHCP Discover message size
$dhcpDiscover1 set burst_time_ 0.5   ;# Time burst lasts
$dhcpDiscover1 set idle_time_ 0.1    ;# Idle time between bursts
$dhcpDiscover1 attach-agent $uC1

# Second client sends a DHCP Discover message later
set dhcpDiscover2 [new Application/Traffic/Exponential]
$dhcpDiscover2 set packetSize_ 100   ;# DHCP Discover message size
$dhcpDiscover2 set burst_time_ 0.5
$dhcpDiscover2 set idle_time_ 0.1
$dhcpDiscover2 attach-agent $uC2

# Schedule DHCP Discover messages from the clients
$ns at 1.0 "$dhcpDiscover1 start"
$ns at 2.0 "$dhcpDiscover2 start"

# Simulate DHCP Offer, Request, and Acknowledge (Server sends back response)
# We will use a basic message to simulate this interaction
set dhcpOffer [new Application/Traffic/Exponential]
$dhcpOffer set packetSize_ 200   ;# DHCP Offer message size
$dhcpOffer attach-agent $uS

# DHCP server responds with an IP offer after receiving Discover messages
$ns at 1.5 "$dhcpOffer start"
$ns at 2.5 "$dhcpOffer start"

# Define a finish procedure
proc finish {} {
    global ns tracefile
    exec nam dhcp.nam &
    $ns flush-trace
    close $tracefile
    exit 0
}

# Schedule simulation to end at 5.0 seconds
$ns at 5.0 "finish"

# Run the simulation
$ns run
