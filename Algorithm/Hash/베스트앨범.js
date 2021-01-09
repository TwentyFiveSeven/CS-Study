function solution(genres, plays) {
    var answer = [];
    let map = {}, genresSum = {};
    genres.forEach((genre,idx)=>{
        if(!map[genre]){
            map[genre] = [[idx, plays[idx]]];
            genresSum[genre] = plays[idx];
        }else{
            map[genre] = [...map[genre], [idx, plays[idx]]];
            genresSum[genre] += plays[idx];
        }
    });
    const keys = Object.keys(genresSum);
    let order = [];
    keys.forEach((key)=>{
        order.push([key, genresSum[key]]);
    });
    order.sort((a,b)=> b[1] - a[1]);
    order.forEach((key)=>{
        key = key[0];
        let list = map[key].sort((a,b)=>{ return a[1] === b[1] ? a[0] - b[0] : b[1] - a[1]});
        answer.push(list[0][0]);
        if(list.length == 1) return;
        answer.push(list[1][0]);
    })
    return answer;
}
