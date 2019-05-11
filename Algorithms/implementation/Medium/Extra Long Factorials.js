'use strict';

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

// Complete the extraLongFactorials function below.
function extraLongFactorials(n) {
    var result = BigInt(n);
    for (let i = n - 1; i > 0; i--)
        result *= BigInt(i);
    console.log(result.toString())
}

function main() {
    const n = parseInt(readLine(), 10);

    extraLongFactorials(n);
}
