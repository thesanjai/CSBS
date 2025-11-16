
BEGIN {
    sent = 0;
    received = 0;
    dropped = 0;
    start_time = -1;
    end_time = 0;
    total_bytes = 0;
}

{
    event = $1;
    time = $2;
    src = $3;
    dst = $4;
    pkt_size = $6;
    flow_id = $8;

    # Record start time
    if (start_time == -1 && $1 == "+") {
        start_time = $2;
    }

    # Sent packet
    if ($1 == "+" && $3 == "0") {
        sent++;
    }

    # Received packet
    if ($1 == "r" && $4 == "1") {
        received++;
        total_bytes += pkt_size;
        end_time = $2;
    }

    # Dropped packet
    if ($1 == "d") {
        dropped++;
    }
}

END {
    print "Simulation Analysis Report";
    print "--------------------------";
    print "Total Packets Sent: ", sent;
    print "Total Packets Received: ", received;
    print "Total Packets Dropped: ", dropped;
    print "Packet Delivery Ratio (%): ", (received / sent) * 100;
    print "Packet Drop Ratio (%): ", (dropped / sent) * 100;
    print "Throughput (Kbps): ", (total_bytes * 8) / (end_time - start_time) / 1000;
}
