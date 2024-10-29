const fs = require('fs');
const [n, ...graph] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n').map((v, i) => i == 0 ? parseInt(v) : v.split('').map(Number));

const dx = [-1, 0, 0, 1];
const dy = [0, -1, 1, 0];
let visited = new Array(n).fill(false).map(() => new Array(n).fill(false));

solve(n, graph);

function bfs(i, j){
    let cnt = 1;
    let queue = [];
    queue.push([i, j]);
    visited[i][j] = true;

    while(queue.length > 0){
        let [cx, cy] = queue.shift();
        for(let i = 0; i < 4; i++){
            let nx = cx + dx[i];
            let ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] || graph[nx][ny] === 0) continue;

            visited[nx][ny] = true;
            queue.push([nx, ny]);
            cnt++;
        }
    }
    return cnt;
}

function solve(n, graph){
    let blocknum = [];
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(graph[i][j] !== 0 && !visited[i][j]) {
                let cnt = bfs(i, j);
                blocknum.push(cnt);
            }
        }
    }
    blocknum.sort((a, b) => a - b);
    
    console.log(blocknum.length);
    for(let bn of blocknum){
        console.log(bn);
    }
}
