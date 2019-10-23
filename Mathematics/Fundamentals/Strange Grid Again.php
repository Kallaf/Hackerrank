<?php

/*
 * Complete the strangeGrid function below.
 */
function strangeGrid($r, $c) {
    $r--;
    $rr = $r - $r % 2;
    $c--;
    return $rr * 5 + $c * 2 + $r % 2;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%[^\n]", $rc_temp);
$rc = explode(' ', $rc_temp);

$r = intval($rc[0]);

$c = intval($rc[1]);

$result = strangeGrid($r, $c);

fwrite($fptr, $result . "\n");

fclose($stdin);
fclose($fptr);
