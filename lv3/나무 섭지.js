const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);
const map = input.slice(1).map(line => line.split(''));

const dx = [-1, 0, 0, 1];
const dy = [0, -1, 1, 0];


let namouQueue = [];
let ghostQueue = [];
const visited = Array.from({ length: n }, () => Array(m).fill(false));
const ghostDist = Array.from({ length: n }, () => Array(m).fill(Infinity));

for(let i = 0; i < n; i++){
    for(let j = 0; j < m; j++){
        if(map[i][j] === 'N'){
            namouQueue.push([i, j, 0]);
            visited[i][j] = true;
        } else if(map[i][j] === 'G'){
            ghostDist[i][j] = 0;
            ghostQueue.push([i, j]);
        }
    }
}

for(let index = 0; index < ghostQueue.length; index++){
    let [cx, cy] = ghostQueue[index];
    let curDist = ghostDist[cx][cy];

    for(let i = 0; i < 4; i++){
        let nx = cx + dx[i];
        let ny = cy + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(ghostDist[nx][ny] <= curDist + 1) continue;

        ghostDist[nx][ny] = curDist + 1;
        ghostQueue.push([nx, ny]);
    }
}

let exit = false;
for(let index = 0; index < namouQueue.length; index++){
    let [cx, cy, curDist] = namouQueue[index];
    if(map[cx][cy] == 'D'){
        exit = true;
        break;
    }

    for(let i = 0; i < 4; i++){
        let nx = cx + dx[i];
        let ny = cy + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(map[nx][ny] === '#' || visited[nx][ny] || ghostDist[nx][ny] <= curDist + 1) continue;

        namouQueue.push([nx, ny, curDist + 1]);
        visited[nx][ny] = true;
    }
}
console.log(exit ? 'Yes' : 'No');
