function solution(s)
{
    function isPalindrome(str){
        const size = str.length;
        const end = Math.floor(size/2);
        for(let i=0;i<end;i++)
            if(str[i] !== str[size-i-1])
                return false;
        return true;
    }
    const answer = 0,size = s.length;
    for(let i =size;i>=2; i--){
        for(let j=0; j<size-i+1;j++){
            const tempString = s.slice(j,j+i);
            if(isPalindrome(tempString)) return i;
        }
    }
    return 1;
}
