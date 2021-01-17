function solution(n) {
    const arr = new Array(n).fill(0), mod = 1234567;
    arr[0] = 1, arr[1] = 2;
    for(let i=2;i<n;i++){
        arr[i] = (arr[i-2] + arr[i-1])%mod;
    }
    return arr[n-1];
}
