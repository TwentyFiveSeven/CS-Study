function solution(triangle) {
    const size = triangle.length;
    for(let i=size-2;i>=0;i--){
        for(let j=0;j<triangle[i].length;j++){
            triangle[i][j] += triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];
        }
    }
    let answer = triangle[0][0];
    return answer;
}
