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

// Complete the biggerIsGreater function below.
function biggerIsGreater(w) {
    for (let i = w.length - 1; i > 0; i--)
    {
        if (w[i] > w[i - 1])
        {
            var s = "";
            for (let j = 0; j < i-1; j++)
                s += w[j];
            var replace = 'z',replace_j;
            for (let j = i; j < w.length; j++)
                if (w[j] > w[i - 1] && w[j] <= replace)
                {
                    replace = w[j];
                    replace_j = j;
                }

            s += replace;
            var str = w[i-1];
            for (let j = i; j < w.length; j++)
                if(j!=replace_j)
                    str += w[j];
            return s + str.split("").sort().join("");
        }
    }
    return "no answer";
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const T = parseInt(readLine(), 10);

    for (let TItr = 0; TItr < T; TItr++) {
        const w = readLine();

        let result = biggerIsGreater(w);

        ws.write(result + "\n");
    }

    ws.end();
}
