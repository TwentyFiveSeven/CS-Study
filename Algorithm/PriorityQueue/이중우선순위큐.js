class PriorityQueue{
    constructor(){
        this.arr = [];
    }
    enqueue(value){
        this.arr.push(value);
    }
    dequeueMax(){
        if(this.arr.length === 0 ) return;
        let save = -1, Max = -2000000000;
        this.arr.forEach((elem,idx)=>{
            if(elem > Max){
                Max = elem;
                save = idx;
            }
        });
        return this.arr.splice(save,1);
    }

    dequeueMin(){
        if(this.arr.length === 0 ) return;
        let save = -1, Min = 2000000000;
        this.arr.forEach((elem,idx)=>{
            if(elem < Min){
                Min = elem;
                save = idx;
            }
        });
        return this.arr.splice(save,1);
    }

    returnAnswer(){
        if(this.arr.length == 0 ) return [0,0];
        const Max = this.dequeueMax();
        const Min = this.dequeueMin();
        return [...Max, ...Min];
    }
}

function solution(operations) {
    const pq = new PriorityQueue();

    function parsing(str){
        const list = str.split(' ');
        return { cmd: list[0], val: parseInt(list[1])};
    }

    function execution(cmd, val){
        switch(cmd){
            case 'I':
                pq.enqueue(val);
                break;
            case 'D':
                if(val == 1) pq.dequeueMax();
                else pq.dequeueMin();
                break;
        }
    }
    operations.forEach((oper)=>{
        const { cmd, val } = parsing(oper);
        execution(cmd,val);
    });
    return pq.returnAnswer();
}
