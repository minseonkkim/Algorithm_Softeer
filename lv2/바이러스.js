const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split(' ').map(BigInt);
solve(input);

function solve(input){
    const mod = BigInt(1000000007)
    let answer = input[0];
    while(input[2] > 0){
        answer = (answer * input[1]) % mod;
        input[2]--;
    }
    console.log(parseInt(answer));
}
