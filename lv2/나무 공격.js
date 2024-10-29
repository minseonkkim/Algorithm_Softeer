const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);
const matrix = [];
for(let i = 1; i <= n; i++){
    matrix.push(input[i].split(' ').map(Number));
}
const attack1 = input[n + 1].split(' ').map(Number);
const attack2 = input[n + 2].split(' ').map(Number);

for(let i = attack1[0] - 1; i < attack1[1]; i++){
    for(let j = 0; j <= m; j++){
        if(matrix[i][j] === 1){
            matrix[i][j] = 0;
            break;
        }
    }
}

for(let i = attack2[0] - 1; i < attack2[1]; i++){
    for(let j = 0; j <= m; j++){
        if(matrix[i][j] === 1){
            matrix[i][j] = 0;
            break;
        }
    }
}

let count = 0;
for(let i = 0; i < n; i++){
    for(let j = 0; j < m; j++){
        if(matrix[i][j] === 1) count++;
    }
}
console.log(count);
