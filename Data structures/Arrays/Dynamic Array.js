'use strict';

const fs = require('fs');

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

// Complete the dynamicArray function below.
function dynamicArray(n, queries) {
    var result = "";
    var seq = new Array(n + 1);
    for (let i = 0; i < n; i++)
        seq[i] = []
    var lastAnswer = 0;
    for (let i = 0; i < queries.length; i++)
    {
        var x = queries[i][1], y = queries[i][2];
        var index = (x ^ lastAnswer) % n;
        if (queries[i][0] == 1) 
            seq[index].push(y);
        else {
            lastAnswer = seq[index][y % seq[index].length];
            result += lastAnswer + "\n";
        }
    }
    return result;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nq = readLine().replace(/\s+$/g, '').split(' ');

    const n = parseInt(nq[0], 10);

    const q = parseInt(nq[1], 10);

    let queries = Array(q);

    for (let i = 0; i < q; i++) {
        queries[i] = readLine().replace(/\s+$/g, '').split(' ').map(queriesTemp => parseInt(queriesTemp, 10));
    }

    const result = dynamicArray(n, queries);

    ws.write(result);

    ws.end();
}
