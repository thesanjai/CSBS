BEGIN {
    query_count = 0
    response_count = 0
    total_delay = 0
    completed = 0
}

{
    # DNS query packet: look for 'cbr' (client -> server)
    if ($1 == "+" && $5 == "cbr") {
        query_count++
        send_time[$11] = $2
    }

    # DNS reply received at server (simulate DNS response delay tracking)
    if ($1 == "r" && $5 == "cbr") {
            delay = $2 - send_time[$11]
            total_delay += delay
            completed++
    }
}

END {
    print "DNS Simulation Analysis Report:"
    print "Total DNS Queries Sent: " query_count
    print "Total DNS Responses Received: " completed
    print "Packet Loss: " (query_count - completed)
    if (completed > 0) {
        print "Average DNS Response Delay: " total_delay / completed " sec"
    } else {
        print "No successful responses to compute delay."
    }
}
