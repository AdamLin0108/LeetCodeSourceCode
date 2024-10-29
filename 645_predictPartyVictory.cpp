class Solution {
public:
    string predictPartyVictory(string senate) {
        // Queues to store the indices of each senator from Radiant (R) and Dire (D)
        queue<int> rad, dir;

        // Get the total number of senators
        int n = senate.length();

        // Loop through the senate string to separate Radiant and Dire senators into different queues
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                // If senator belongs to Radiant party, add their index to rad queue
                rad.push(i);
            } else {
                // If senator belongs to Dire party, add their index to dir queue
                dir.push(i);
            }
        }

        // Diagram illustrating initial queue states:
        // Senate: "RRDD"
        // Radiant Queue (R): [0, 1]
        // Dire Queue    (D): [2, 3]

        /*
            Initial queue states:
            Radiant Queue (R): [0, 3]
            Dire Queue    (D): [1, 2]

            Step 1:
            R0 vs D1: R0 bans D1
            Radiant Queue (R): [3, 4]
            Dire Queue    (D): [2]

            Step 2:
            R3 vs D2: D2 bans R3
            Radiant Queue (R): [4]
            Dire Queue    (D): []

            Final state:
            Winner: Radiant
        */

        // Process the queues while both parties still have senators left
        while (!rad.empty() && !dir.empty()) {
            // Compare the front senators from each party
            if (rad.front() < dir.front()) {
                // If the Radiant senator appears before the Dire senator, ban the Dire senator
                // Push the Radiant senator to the back of the queue with updated index (n++)
                rad.push(n++);
            } else {
                // Otherwise, the Dire senator bans the Radiant senator and pushes itself to the back
                dir.push(n++);
            }
            // Remove the processed senators from the front of their respective queues
            rad.pop();
            dir.pop();
        }

        // Return the winning party based on which queue is not empty
        return (rad.empty()) ? ("Dire") : ("Radiant");
    }
};
