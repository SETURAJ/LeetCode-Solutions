// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

class Solution {
public:
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2)
            return node1;
        int n=edges.size();
        vector<int>visited(n,0);
        int res1=0,res2=0;
        
        int trace=node1;
        
        while((edges[node1] != node1) && (edges[node1] != -1) && (visited[node1] == 0) && (node1 != node2))
        {
            visited[node1]++;
            node1 = edges[node1];
            res1++;
        }
        visited[node1]++;
        while((edges[node2] != node2) && (edges[node2] != -1) && (visited[node2] != 2) && (node1 != node2))
        {
            visited[node2]++;
            node2 = edges[node2];
            res2++;
        }
        if(node1 != node2) return -1;
        if((edges[node1] == -1) && (visited[node2] == 1)) return -1;
        if(edges[node2] == -1) return -1;
        if(res1 > res2)
            return node2;
        else
            return trace;
    }
};