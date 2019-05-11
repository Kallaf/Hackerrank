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

// Complete the appendAndDelete function below.
function appendAndDelete(s, t, k) {
    var n = s.length, m = t.length, matching = 0;
    for (let i = 0; i < n && i < m; i++)
    {
        if (s[i] != t[i])
            break;
        matching++;
    }
    var mismatching = (n - matching) + (m - matching);
    if (mismatching == k) return "Yes";
    if (mismatching < k)
    {
        if (!matching) return "Yes";
        if (!((k - mismatching) % 2)) return "Yes";
        if (mismatching + 2 * matching <= k) return "Yes";
    }
    return "No";
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    const t = readLine();

    const k = parseInt(readLine(), 10);

    let result = appendAndDelete(s, t, k);

    ws.write(result + "\n");

    ws.end();
}
