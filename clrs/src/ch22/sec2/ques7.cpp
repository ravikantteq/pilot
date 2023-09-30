/*
 * 22.2-7
 * There are two types of professional wrestlers: “babyfaces” (“good guys”) and
 * “heels” (“bad guys”). Between any pair of professional wrestlers, there may or
 * may not be a rivalry. Suppose we have n professional wrestlers and we have a list
 * of r pairs of wrestlers for which there are rivalries. Give an O.n C r/-time algo-
 * rithm that determines whether it is possible to designate some of the wrestlers as
 * babyfaces and the remainder as heels such that each rivalry is between a babyface
 * and a heel. If it is possible to perform such a designation, your algorithm should
 * produce it.
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class WrestlerDesignationChecker {
    public:
    bool is_possible(int n, vector<vector<int>> rivalry_pairs) {
        vector<vector<int>> graph(n, vector<int>(0));
        for (int i = 0; i < rivalry_pairs.size(); i++) {
            int u = rivalry_pairs[i][0];
            int v = rivalry_pairs[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        bool visited[n] = {0};
        string type[n];
        q.push(0);
        visited[0] = true;
        type[0] = "babyface";
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            cout << "vertex:" << u << "type:" << type[u] << endl;
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (type[v] == type[u]) return false;
                else if (visited[v] == false) {
                    q.push(v);
                    visited[v] = true;
                    if (type[u] == "babyface") type[v] = "heel";
                    else type[v] = "babyface";
                }
            }
        }
        return true;
    }

};

int test_main() {
    vector<vector<int>> p = 
    {
        {0,1},
        {1,2},
        {2,3},
        {2,4},
        {1,4}
    };
    WrestlerDesignationChecker designationChecker;
    bool result = designationChecker.is_possible(5, p);
    cout << "Wrestler Designation is possible: " << result << endl;
}
