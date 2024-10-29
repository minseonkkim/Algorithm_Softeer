const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split(' ').map(Number);

[1, 2, 3, 4, 5, 6, 7, 8].every((val, idx) => val === input[idx]) ? console.log('ascending'):
    ([8, 7, 6, 5, 4, 3, 2, 1].every((val, idx) => val === input[idx]) ? console.log('descending') : console.log('mixed'));
