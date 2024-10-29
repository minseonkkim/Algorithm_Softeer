const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
solve(input);

function solve(input){
    let answer = 0;
    for(let line of input){
        let start = Number(line.substr(0, 2)) * 60 + Number(line.substr(3, 2));
        let end = Number(line.substr(6, 2)) * 60 + Number(line.substr(9, 2));
        answer += (end - start);
    }
    console.log(answer);
}
