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

// Complete the organizingContainers function below.
function organizingContainers(container) {
    var colorsCount = new Array(110).fill(0);
    var containersCount = new Array(110).fill(0);
    var isUsed = new Array(110).fill(false);
    for (let i = 0; i < container.length; i++)
    {
        for (let j = 0; j < container.length; j++)
        {
            colorsCount[i] += container[j][i];
            containersCount[i] += container[i][j];
        }
    }

    for (let i = 0; i < container.length; i++) {
        var match = false;
        for (let j = 0; j < container.length; j++) {
            if (!isUsed[j] && containersCount[i] == colorsCount[j])
            {
                isUsed[j] = true;
                match = true;
                break;
            }
        }
        if (!match) return "Impossible";
    }

    return "Possible";
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const q = parseInt(readLine(), 10);

    for (let qItr = 0; qItr < q; qItr++) {
        const n = parseInt(readLine(), 10);

        let container = Array(n);

        for (let i = 0; i < n; i++) {
            container[i] = readLine().split(' ').map(containerTemp => parseInt(containerTemp, 10));
        }

        let result = organizingContainers(container);

        ws.write(result + "\n");
    }

    ws.end();
}
