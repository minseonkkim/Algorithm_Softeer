const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = Number(input[0]);
const height = input[1].split(' ').map(Number);
let dp = new Array(n).fill(1);

for(let i = 1; i < n; i++){
    for(let j = 0; j < i; j++){
        if(height[i] > height[j]){
            dp[i] = Math.max(dp[i], dp[j] + 1);
        }
    }
}

console.log(Math.max(...dp));
