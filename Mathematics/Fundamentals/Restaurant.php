<?php

/*
 * Complete the restaurant function below.
 */
function restaurant($l, $b) {
    $gcd = gmp_gcd($l,$b);
    return ($l/$gcd) * ($b/$gcd);
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $t);

for ($t_itr = 0; $t_itr < $t; $t_itr++) {
    fscanf($stdin, "%[^\n]", $lb_temp);
    $lb = explode(' ', $lb_temp);

    $l = intval($lb[0]);

    $b = intval($lb[1]);

    $result = restaurant($l, $b);

    fwrite($fptr, $result . "\n");
}

fclose($stdin);
fclose($fptr);
