// https://leetcode.com/problems/seat-reservation-manager

class SeatManager {
public:
    int sz;
    vector<bool> v;
    int top=1;
    SeatManager(int n) {
        v.resize(n,false);   
        sz = n;
    }
    
    int reserve() {
        int res = top++;
        while(top<sz && v[top])
            top++;
        v[res]= true;
        return res;
            
    }
    
    void unreserve(int seatNumber) {
        v[seatNumber] = false;
        if(top>seatNumber)
            top = seatNumber;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */