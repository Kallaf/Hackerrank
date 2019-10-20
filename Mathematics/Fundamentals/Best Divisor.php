<?php

function dig_sum($n) {
    $res = 0;
    while($n)
    {
        $res += $n%10;
        $n/=10;
    }    
    return $res;
}

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);
$divisors = array();
for($i = 1;$i*2<=$n;$i++)
    if($n%$i == 0)
        array_push($divisors,$i);
array_push($divisors,$n);
$mx = dig_sum($divisors[0]);
$res = $divisors[0];

$m = count($divisors);
for($i = 1;$i<$m;$i++)
{
    $curr = dig_sum($divisors[$i]);
    if($curr > $mx)
    {
        $mx = $curr;
        $res = $divisors[$i];
    }
}
printf("%d\n",$res);

fclose($stdin);
