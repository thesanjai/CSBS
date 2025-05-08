BEGIN{
	s=0;
	r=0;
	d=0;
	total=0;
	delay=0;
	end=0; 
}

$1 == "+"{
	s++;
	time[$11]=$2;
}
$1 == "r"{
	r++;
	total+=$6;
	end=$2;
}
time[$11]{
	delay+=($2-time[$11]);
}
$1=="d"{
	d++;
}

END{ 
	print "Sent: " s "	Received : " r "	Dropped : " d
	print "PDR: " (r/s)*100 "%"
	print "PLR: " (d/s)*100 "%"
	print "Delay: " (delay/r) "sec"
	print "Throughput: " (total*8)/(end*1000000) "Mbps"
}
