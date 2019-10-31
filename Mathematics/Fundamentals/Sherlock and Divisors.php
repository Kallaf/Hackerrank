<?php

/*
 * Complete the divisors function below.
 */
function divisors($n) {
    $count = 0;
    $i = 1; 
    for (; $i*$i <= $n; $i++) {
        if ($n % $i == 0) { 
            if ($i % 2 == 0)$count++;  
            if($n/$i != $i)
                if (($n / $i) % 2 == 0)$count++; 
        } 
    } 
    return $count;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $t);

for ($t_itr = 0; $t_itr < $t; $t_itr++) {
    fscanf($stdin, "%d\n", $n);

    $result = divisors($n);

    fwrite($fptr, $result . "\n");
}

fclose($stdin);
fclose($fptr);
