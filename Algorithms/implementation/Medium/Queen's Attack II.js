'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the queensAttack function below.
function queensAttack(n, k, r_q, c_q, obstacles) {
    var right_row  = n - c_q, left_row = c_q - 1;
    var up_col     = n - r_q, down_col = r_q - 1;
    var right_diag = n - Math.max(r_q,c_q);
    var left_diag  = Math.min(r_q, c_q) - 1;
    var right_inv =  Math.min(c_q - 1, n - r_q);
    var left_inv = Math.min(n - c_q, r_q - 1);

    for (let i = 0; i < k; i++)
    {
        var row = obstacles[i][0], col = obstacles[i][1]; 
        if (row == r_q)
        {
            if (col > c_q)
                right_row = Math.min(right_row, col - c_q - 1);
            else
                left_row = Math.min(left_row, c_q - col - 1);
        } else if (col == c_q)
        {
            if (row > r_q)
                up_col = Math.min(up_col, row - r_q - 1);
            else
                down_col = Math.min(down_col, r_q - row - 1);
        } else if (r_q - row == c_q - col)
        {
            if (r_q - row < 0)
                right_diag = Math.min(right_diag, row - r_q - 1);
            else
                left_diag = Math.min(left_diag, r_q - row - 1);
        } else if (r_q - row == -(c_q - col)) {
            if (r_q - row < 0)
                right_inv = Math.min(right_inv, row - r_q - 1);
            else
                left_inv = Math.min(left_inv, r_q - row - 1);
        }
    }

    return right_row + left_row + up_col + down_col + right_diag + left_diag + right_inv + left_inv;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nk = readLine().split(' ');

    const n = parseInt(nk[0], 10);

    const k = parseInt(nk[1], 10);

    const r_qC_q = readLine().split(' ');

    const r_q = parseInt(r_qC_q[0], 10);

    const c_q = parseInt(r_qC_q[1], 10);

    let obstacles = Array(k);

    for (let i = 0; i < k; i++) {
        obstacles[i] = readLine().split(' ').map(obstaclesTemp => parseInt(obstaclesTemp, 10));
    }

    let result = queensAttack(n, k, r_q, c_q, obstacles);

    ws.write(result + "\n");

    ws.end();
}
