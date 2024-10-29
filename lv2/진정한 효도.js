const fs = require('fs');
const [...graph] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n').map((v) => v.split(' ').map(Number));
solve(graph);

function solve(graph){
    let answer = Number.MAX_SAFE_INTEGER

     for(let i = 0; i < 3; i++){
         let a = graph[i][0];
         let b = graph[i][1];
         let c = graph[i][2];
         if(a === b === c) {
             console.log(0);
             return;
         }
         let mid = a + b + c - Math.min(a, b, c) - Math.max(a, b, c);
         answer = Math.min(answer, Math.abs(a - mid) + Math.abs(b - mid) + Math.abs(c - mid));
     }

    for(let i = 0; i < 3; i++){
        let a = graph[0][i];
        let b = graph[1][i];
        let c = graph[2][i];
        if(a === b === c) {
             console.log(0);
             return;
         }
         let mid = a + b + c - Math.min(a, b, c) - Math.max(a, b, c);
         answer = Math.min(answer, Math.abs(a - mid) + Math.abs(b - mid) + Math.abs(c - mid));
    }

    console.log(answer);
}      
