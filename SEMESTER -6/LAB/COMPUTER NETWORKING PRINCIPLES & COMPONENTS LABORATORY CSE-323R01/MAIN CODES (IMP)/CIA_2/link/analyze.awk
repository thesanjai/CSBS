BEGIN {
    link_state_updates = 0;
    data_packets_sent = 0;
    data_packets_received = 0;
}

# Count OLSR link state updates
$1 == "+" && $7~/A/ {
    link_state_updates++;
}

# Count data packets sent
$1 == "+" && $5 == "tcp" {
    data_packets_sent++;
}

# Count data packets received
$1 == "r" && $5 == "tcp" {
    data_packets_received++;
}

END {
    printf("Total link state updates: %d\n", link_state_updates);
    printf("Total data packets sent: %d\n", data_packets_sent);
    printf("Total data packets received: %d\n", data_packets_received);
}
