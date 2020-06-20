class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>max_heap;
    priority_queue< int,vector<int>,greater<int> >min_heap;
    double median;
    MedianFinder() {
        priority_queue<int>max_heap;
        priority_queue< int,vector<int>,greater<int> >min_heap;
    }
    
    void addNum(int num) {
        if(max_heap.size()==0 and min_heap.size()==0){
            max_heap.push(num);
        }else if(num<median){
            if(max_heap.size()<=min_heap.size()){
                max_heap.push(num);
            }else if(max_heap.size()>min_heap.size()){
                int num2=max_heap.top();
                max_heap.pop();
                min_heap.push(num2);
                max_heap.push(num);
            }
        }else{ // num is greater than or equal to the median.
            if(max_heap.size()>=min_heap.size()){
                min_heap.push(num);
            }else if(min_heap.size()>max_heap.size()){
                int num2=min_heap.top();
                min_heap.pop();
                max_heap.push(num2);
                min_heap.push(num);
            }
        }
    }
    
    double findMedian() {
         if(max_heap.size()==min_heap.size()){
            median=(max_heap.top()+min_heap.top())*0.5;
        }else if(max_heap.size()>min_heap.size()){
            median=max_heap.top();
        }else{
            median=min_heap.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */