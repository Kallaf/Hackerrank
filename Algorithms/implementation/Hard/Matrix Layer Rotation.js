'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function getAfterRotate(n,m,i,j,r)
{
    var up = false, right = false, down = false, left = false;
    if (i == 0 && j != n - 1) up = true;
    else if (i != m - 1 && j == n - 1) right = true;
    else if (i == m - 1 && j != 0) down = true;
    else if (i != 0 && j == 0) left = true;
    while (r)
    {
        if (up)
        {
            if (j + r > n - 1) {
                r = j + r - (n - 1);
                j = n - 1;
                up = false;
                right = true;
            } else {
                j += r;
                r = 0;
            }  
        } else if (right)
        {
            if (i + r > m - 1) {
                r = i + r - (m - 1);
                i = m - 1;
                right = false;
                down = true;
            } else {
                i += r;
                r = 0;
            }
        } else if (down)
        {
            if (j - r < 0) {
                r = r - j;
                j = 0;
                down = false;
                left = true;
            } else {
                j -= r;
                r = 0;
            }
        } else
        {
            if (i - r < 0) {
                r = r - i;
                i = 0;
                left = false;
                up = true;
            } else {
                i -= r;
                r = 0;
            }
        }
    }

    
    return [i, j];

}

// Complete the matrixRotation function below.
function matrixRotation(matrix, r) {
    var m = matrix.length,n=matrix[0].length;
    const fs = require('fs');
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    for (let i = 0; i < m; i++)
    {
        var row = []
        for (let j = 0; j < n; j++)
        {
            var x = Math.min(i, j, m - 1 - i, n - 1 - j);
            var arr = getAfterRotate(n - 2*x, m - 2*x, i-x, j-x, r % (2 * (n - 2*x) + 2 * (m - 2*x) - 4));
            row.push(matrix[arr[0]+x][arr[1]+x]);
        }
        ws.write(row.join(" ") + "\n");
    }
    ws.end();
}

function main() {
    const mnr = readLine().replace(/\s+$/g, '').split(' ');

    const m = parseInt(mnr[0], 10);

    const n = parseInt(mnr[1], 10);

    const r = parseInt(mnr[2], 10);

    let matrix = Array(m);

    for (let i = 0; i < m; i++) {
        matrix[i] = readLine().replace(/\s+$/g, '').split(' ').map(matrixTemp => parseInt(matrixTemp, 10));
    }

    matrixRotation(matrix, r);
}
