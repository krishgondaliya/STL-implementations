#include<iostream>
#include<vector>
#include<algorithm>

class minHeap{
    public:

    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop(){
        if(heap.empty()){
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()){
            heapifyDown(0);
        }
    }

    int peek() const{
        if(heap.empty()){
            return -1;
        }
        return heap[0];
    }

    int size() const {
        return static_cast<int>(heap.size());
    }


    private:
        std::vector<int> heap;

        int parent(int index) const{
            return (index - 1) / 2;
        }

        int leftChild(int index) const{
            return 2 * index + 1;
        }

        int rightChild(int index) const{
            return 2 * index + 2;
        }

        void heapifyUp(int index){
            while(index > 0 && heap[index] < heap[parent(index)]){
                std::swap(heap[index], heap[parent(index)]);
                index = parent(index);
            }
        }

        void heapifyDown(int index){
            int n = static_cast<int>(heap.size());

            while(true){
                int left = leftChild(index);
                int right = rightChild(index);
                int smallest = index;

                if(left < n && heap[left] < heap[smallest]){
                    smallest = left;
                }

                if(right < n && heap[right] < heap[smallest]){
                    smallest = right;
                }

                if(smallest == index){
                    break;
                }
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            }
        }

};

int main(){
    int q;
    std::cin >> q;

    minHeap heap;
    std::vector<int> output;

    for(int i = 0; i < q; i++)
    {
        int type;
        std::cin >> type;

        if(type == 1){
            int x;
            std::cin >> x;
            heap.push(x);
        }
        else if(type == 2){
            heap.pop();
        }
        else if(type == 3){
            output.push_back(heap.peek());
        }
        else if(type == 4){
            output.push_back(heap.size());
        }
    }

    for(int value: output){
        std::cout << value << " ";
    }

    return 0;
}