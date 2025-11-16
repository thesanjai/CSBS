BEGIN{ s=0; r=0;}
{
if ($1=="+" && $7 ~ /A/){r++;}
if ($1=="+" && $5 == "tcp"){s++;}
}
END{
print "Routing Updates :" r
print "Total Packets Sent :" s
}

