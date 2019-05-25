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

// Complete the cutTheSticks function below.
function cutTheSticks(arr) {
    var ans = [];
    var cut = 0;
    while (true)
    {
        for (let i = 0; i < arr.length; i++)
            if (arr[i])
                arr[i] -= cut;
        cut = 10000;
        var counter = 0;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i])
            {
                cut = Math.min(cut, arr[i]);
                counter++;
            }
        }
        if (!counter) break;
        ans.push(counter);
    }
    return ans;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    let result = cutTheSticks(arr);

    ws.write(result.join("\n") + "\n");

    ws.end();
}
