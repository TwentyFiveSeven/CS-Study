function solution(n, results) {
    const graph = Array.from({length:n}, ()=>Array(n).fill(Infinity));
    let answer = 0;
    graph.forEach((value,idx) => graph[idx][idx] = 0);
    results.forEach((result,idx)=>{
        const [win,loose] = result;
        graph[win-1][loose-1] = 0;
    });
    for(let k = 0; k<n;k++){
        for(let i=0 ;i<n;i++){
            if(i === k || graph[i][k] === Infinity) continue;
            for(let j=0;j<n;j++){
                if(i === j || j === k || graph[k][j] === Infinity) continue;
                graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    graph.forEach((values,idx)=>{
        let count = 0;
        values.forEach((value,i)=>{
            if( i === idx ) return;
            count += (value === 0 ? 1 : 0);
        });
        for(let j=0;j<n;j++){
            if( j === idx) continue;
            count += (graph[j][idx] === 0 ? 1 : 0);
        }
        answer += (count === n-1 ? 1 : 0);
    });
    return answer;
}
