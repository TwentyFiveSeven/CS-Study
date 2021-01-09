const list = [];
function dfs(arr, next, m = ['ICN']){
    if(arr.length === 0){
        list.push(m);
        return;
    }
    for(let i=0; i<arr.length; i++){
        if(arr[i][0] === next){
            let now = [...arr];
            now.splice(i,1);
            dfs(now, arr[i][1], [...m,arr[i][1]]);
        }
    }
}

function solution(tickets) {
    dfs(tickets, 'ICN');
    return list.sort()[0];
}
