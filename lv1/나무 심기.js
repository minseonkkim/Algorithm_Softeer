const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, inform] = input;
solve(n, inform);

function solve(n, inform){
    const sorted = inform.split(' ').map(Number).sort((a, b) => a - b);
    const positive = sorted[sorted.length - 1] * sorted[sorted.length - 2];
    const negative = sorted[0] * sorted[1];
    console.log(Math.max(positive, negative));
}
