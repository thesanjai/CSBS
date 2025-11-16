BEGIN {
    route_updates = 0;
    data_packets = 0;
}

# Count routing table updates
$1 == "+" && $7~/A/ {
    route_updates++;
}

# Count data packets sent
$1 == "+" && $5 == "tcp" {
    data_packets++;
}

END {
    printf("Total routing updates: %d\n", route_updates);
    printf("Total data packets sent: %d\n", data_packets);
}
