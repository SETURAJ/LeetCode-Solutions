// https://leetcode.com/problems/seat-reservation-manager

class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    int top;
    SeatManager(int n) : sz(n),top(1) {
    }
    
    int reserve() {
        if(pq.empty())
            return top++;
        else
        {
            int x = pq.top();
            pq.pop();
            return x;
        }
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */