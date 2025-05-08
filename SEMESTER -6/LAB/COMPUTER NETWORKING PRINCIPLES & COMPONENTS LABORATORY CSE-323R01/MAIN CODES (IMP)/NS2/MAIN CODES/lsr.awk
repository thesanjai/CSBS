BEGIN{ s=0; r=0; recv=0;}
{
if ($1=="+" && $7 ~ /A/){r++;}
if ($1=="+" && $5 == "tcp"){s++;}
if ($1=="r" && $5 == "tcp"){recv++;}
}
END{
print "Routing Updates :" r
print "Total Packets Sent :" s
print "Total Packets Received :" recv
}

