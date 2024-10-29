const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, k] = input[0].split(' ').map(Number);
const score = input[1].split(' ').map(Number);
const panel = [];
for(let i = 2; i <= 2 + k - 1; i++){
    let [start, end] = input[i].split(' ').map(Number);
    let sum = 0;
    for(let j = start; j <= end; j++){
        sum += score[j - 1];
    }
    console.log((sum / (end - start + 1)).toFixed(2));
}
