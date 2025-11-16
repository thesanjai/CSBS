<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="TimeTable" content="width=device-width, initial-scale=1.0">
    <title>TimeTable</title>
</head>

<body>
    <?php
        $time_arr =["08:45-09:45","09:45-10:45","10:45-11:00","11:00-12:00","12:00-01:00","01:00-02:00","02:00-03:00","03:00:03:15","03:15-04:15","04:15-05:15"];
        $time_n= sizeof($time_arr);

        $mon_arr=["MON","INT316-N","MGT132-N","BREAK","CSE317-N,CSE321-N","LUNCH","MGT133-N","BREAK","MINOR","MINOR"];
        $tue_arr=["TUE","ENG315-N","CSE316-N","BREAK","MGT132-N","LUNCH","CSE320-N","MGT133-N","BREAK","","",""];
        $wed_arr=["WED","ENG315-N","INT316-N","BREAK","CSE317-N,CSE321-N","LUNCH","CSE316-N","BREAK","CSE320-N","",""];
        $thu_arr=["THU","MGT133-N","CSE316-N","BREAK","MINOR","LUNCH","ENG315-N","MGT132-N","BREAK","INT136-N","",""];
        $fri_arr=["FRI","CSE316-N","MGT132-N","BREAK","INT316-N","LUNCH","","","","",""];
        $sat_arr=["SAT","","","","","","","","","",""];

        $DATA= [$mon_arr,$tue_arr,$wed_arr,$thu_arr,$fri_arr,$sat_arr];
        $data_n = sizeof($DATA);
    ?>
    <table align="center" border="1"  width="100%" cellspacing="0" cellpadding="5">
        <caption style="background-color: #2d73a6; color:#FFFFFF; font-family: Arial, Helvetica, sans-serif;font: size 15px;font-weight:bold"><b>TIMETABLE</b></caption>
        <thead>
            <tr>
                <th style="background-color: #7da9c9; color:#FFFFFF;" rowspan="2"></th>
                    <?php
                    for($i=1;$i<=10;$i++) { ?>
                    <th style="background-color: #7da9c9; color:#FFFFFF;font-family:Arial, Helvetica, sans-serif" ><?php echo $i ?></th>
                    <?php } ?>
            </tr>
            <tr>
                    <?php
                     for($i=0;$i<$time_n;$i++) { ?>
                     <th cellspacing ="1px" cellpadding="5px" style="background-color: #2d73a6; color:#FFFFFF; font-family:Arial, Helvetica, sans-serif;font-weight:bold"><?php echo $time_arr[$i] ?></th>
                     <?php } ?>
            </tr>
        </thead>
        <tbody>
                <?php
                for($i=0;$i<$data_n;$i++) { ?>
                <tr align="center">
                    <td style="background-color: #7da9c9; color:#FFFFFF;" ><?php echo $DATA[$i][0] ?></td>
                    <?php
                        if($i%2 ==0){ ?>
                            <?php for($j=1 ; $j<$time_n;$j++) { ?>
                                <?php if($DATA[$i][$j]){ ?>
                                    <?php if($j==4){ ?>
                                        <td colspan="2" style="font-family: Arial, Helvetica, sans-serif;"> <font size="2"> <?php echo $DATA[$i][$j] ?></font></td>
                                    <?php }else { ?>
                                        <td style="font-family: Arial, Helvetica, sans-serif;"> <font size="2"> <?php echo $DATA[$i][$j] ?></font></td>
                                    <?php } ?>
                                <?php }else{
                                     echo "<td> </td>";
                                 } ?>
                            <?php } ?>
                        <?php }else{ ?>
                            <?php for($j=1 ; $j<=$time_n;$j++) { ?>
                                <?php if($DATA[$i][$j]){ ?>
                                  <td style="font-family: Arial, Helvetica, sans-serif;"> <font size="2"> <?php echo $DATA[$i][$j] ?></font></td>
                               <?php }else{
                                echo "<td></td>";
                               } ?>
                            <?php } ?>
                    <?php } ?>
                </tr>
                <?php } ?>
        </tbody>
    </table>
</body>
</html> 