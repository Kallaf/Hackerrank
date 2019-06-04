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

// Complete the encryption function below.
function encryption(s) {
    var left = Math.floor(Math.sqrt(s.length)), right = Math.ceil(Math.sqrt(s.length));
    var row, col;
    if (left * left >= s.length)
    {
        row = left;
        col = left;
    } else if(left*right >= s.length) {
        row = left;
        col = right;
    } else
    {
        row = right;
        col = right;
    }
    var result = "";
    for (let i = 0; i < col; i++)
    {
        for (let j = 0; j < row && i + j*col < s.length; j++)
            result += s[i + j*col];
        result += " ";
    }
    return result;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    let result = encryption(s);

    ws.write(result + "\n");

    ws.end();
}
