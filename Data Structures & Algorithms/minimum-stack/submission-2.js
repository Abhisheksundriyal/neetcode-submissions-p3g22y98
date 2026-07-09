class MinStack {
    constructor() {
        this.arr=[];
        this.min=[];
        this.arr.length=1000000;
        this.min.length=1000000;
        this.l=0;
    }
    /**
     * @param {number} val
     * @return {void}
     */
    push(val) {
        this.arr[this.l]=val;
        if(this.l==0)
            this.min[this.l]=val;
        else {
            if(val<this.min[this.l-1])
                this.min[this.l]=val;
            else
                this.min[this.l]=this.min[this.l-1];
        }
        this.l++;
    }

    /**
     * @return {void}
     */
    pop() {
        this.l--;
    }

    /**
     * @return {number}
     */
    top() {
        return this.arr[this.l-1];
    }

    /**
     * @return {number}
     */
    getMin() {
        return this.min[this.l-1];
    }
}
