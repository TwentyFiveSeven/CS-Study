function solution(n, times) {
    let answer = 1000000000*1000000000, size = times.length,start = 1;
    let end = answer;
    if(size === 1) return n*times[0];
    times.sort();
    function binary(start,end){
        if( start > end ) return;
        let mid = parseInt((start+end)/2);
        let count = 0;
        times.forEach((time)=>{
            count += parseInt(mid/time);
            if(count>=n){
                answer = mid < answer ? mid : answer;
                return;
            }
        });
        if(count >= n) binary(start, mid-1);
        else binary(mid+1, end);
    }
    binary(1, 1000000000*1000000000)
    return answer;
}
