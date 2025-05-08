BEGIN{ s=0; r=0; d=0; delay=0;}
{
if ($1=="+"){s++; time[$11]=$2;}
if ($1=="r"){r++;}
if (time[$11]){delay+= ($2-time[$11]);}
}
END{
print "DHCP Discoveries " s 
print "DHCP Offers " r
print "Server Delay :" (delay/r) "sec"
}
