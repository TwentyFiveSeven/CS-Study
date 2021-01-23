function solution(dirs) {
    var answer = 0;
    function Person(){
        let x = 5, y=5;
        const check = Array.from({ length: 11 }, () => Array.from({ length: 11 }, () => Array.from({ length: 11 }, () => Array(11).fill(0))));

        this.move = function(dir){
            const [xi,yi] = this.dist(dir);
            const nx = x+xi, ny = y+yi;
            if(nx <0 || nx>10 || ny<0 || ny>10 ) return;
            if(!check[x][y][nx][ny] || !check[nx][ny][x][y]){
                check[x][y][nx][ny] = 1;
                check[nx][ny][x][y] = 1;
                answer++;
            }
            x = nx, y=ny;
        },

        this.dist =function(dir){
            let xi = 0, yi=0;
            switch(dir){
                case 'U':
                    return [-1,0];
                case 'D':
                    return [1,0];
                case 'R':
                    return [0,1];
                case 'L':
                    return [0,-1];
            }
        }
    }
    const person = new Person();
    const size = dirs.length;
    for(let i=0;i<size;i++){
        person.move(dirs[i]);
    }
    return answer;
}
