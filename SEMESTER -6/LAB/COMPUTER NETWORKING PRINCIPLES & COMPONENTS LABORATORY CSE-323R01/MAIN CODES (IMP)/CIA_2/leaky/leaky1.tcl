# Create simulator
set ns [new Simulator]

# Trace files
set tf [open leaky.tr w]
set nf [open leaky.nam w]
$ns trace-all $tf
$ns namtrace-all $nf

# Nodes
set n0 [$ns node]
set n1 [$ns node]

# Link with limited queue size (emulating leaky bucket)
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns queue-limit $n0 $n1 10

# UDP Agent
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

# Traffic generator
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.004
$cbr attach-agent $udp

# Null sink
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null

# Simulation events
$ns at 0.1 "$cbr start"
$ns at 4.9 "$cbr stop"
$ns at 5.0 "finish"

# Finish procedure
proc finish {} {
    global ns tf nf
    $ns flush-trace
    close $tf
    close $nf
    exec nam leaky.nam &
    exec awk -f analysis.awk leaky.tr > leaky_analysis.txt &
    exit 0
}

$ns run

