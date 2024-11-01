const fs = require('fs');
const [a, b, d] = fs.readFileSync('/dev/stdin', 'utf8').trim().split(' ');

const go = d % a === 0 ? Math.floor(d / a) * a + (Math.floor(d / a) - 1) * b : Math.floor(d / a) * a + Math.floor(d / a) * b + (d % a);
const back = d % b === 0 ? (Math.floor(d / b) - 1) * a + Math.floor(d / b) * b : Math.floor(d / b) * a + Math.floor(d / b) * b + (d % b);
console.log(go + back);
