const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split(' ');
solve(input);

function solve(input){
    const a = Number(input[0]);
    const b = Number(input[1]);
    console.log(a === b ? 'same' : (a > b ? 'A' : 'B'));
}
