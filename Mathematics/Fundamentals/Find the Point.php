<?php

/*
 * Complete the findPoint function below.
 */
function findPoint($px, $py, $qx, $qy) {
    return array(2*$qx - $px,2*$qy - $py);
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $n);

for ($n_itr = 0; $n_itr < $n; $n_itr++) {
    fscanf($stdin, "%[^\n]", $pxPyQxQy_temp);
    $pxPyQxQy = explode(' ', $pxPyQxQy_temp);

    $px = intval($pxPyQxQy[0]);

    $py = intval($pxPyQxQy[1]);

    $qx = intval($pxPyQxQy[2]);

    $qy = intval($pxPyQxQy[3]);

    $result = findPoint($px, $py, $qx, $qy);

    fwrite($fptr, implode(" ", $result) . "\n");
}

fclose($stdin);
fclose($fptr);
