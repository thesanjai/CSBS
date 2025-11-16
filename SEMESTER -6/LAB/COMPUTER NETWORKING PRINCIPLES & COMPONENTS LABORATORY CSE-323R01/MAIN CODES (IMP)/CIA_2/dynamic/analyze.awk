BEGIN {
    dhcp_discover_count = 0;
    dhcp_offer_count = 0;
    total_delay = 0;
}

# Count DHCP Discover packets (from clients)
$1 == "+" {
    dhcp_discover_count++;
    discover_time[$11] = $2;
}

# Count DHCP Offer packets (from server)
$1 == "r" {
    dhcp_offer_count++;
}

discover_time[$11]{
    (total_delay += $2 - discover_time[$11]);
}

END {
    # Print statistics
    printf("Total DHCP Discover messages: %d\n", dhcp_discover_count);
    printf("Total DHCP Offer messages: %d\n", dhcp_offer_count);
    printf("Average DHCP response delay: %.5f seconds\n", total_delay / dhcp_offer_count);
}
