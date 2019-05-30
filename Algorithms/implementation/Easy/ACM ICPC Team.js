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

// Complete the acmTeam function below.
function acmTeam(topic) {
    var count = 0, max = -1;
    for (let i = 0; i < topic.length; i++)
    {
        for (let j = i + 1; j < topic.length; j++)
        {
            var union = 0;
            for (let k = 0; k < topic[i].length; k++)
                if (topic[i][k] === '1' || topic[j][k] == '1') 
                    union++;
            
            if (union > max)
            {
                max = union;
                count = 0;
            }
            if (union === max) count++;
        }
    }
    return [ max, count ];
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nm = readLine().split(' ');

    const n = parseInt(nm[0], 10);

    const m = parseInt(nm[1], 10);

    let topic = [];

    for (let i = 0; i < n; i++) {
        const topicItem = readLine();
        topic.push(topicItem);
    }

    let result = acmTeam(topic);

    ws.write(result.join("\n") + "\n");

    ws.end();
}
