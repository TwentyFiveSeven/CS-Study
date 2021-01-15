function solution(n, money) {
    const mod = 1000000007;
    const size = money.length;
    const arr = new Array(n+1).fill(0);
    money.forEach((value)=>{
        arr[value] += 1;
        for(let i = value +1; i<=n;i++){
            arr[i] = (arr[i] + arr[i - value])%mod;
        }
    })
    return arr[n];
}
