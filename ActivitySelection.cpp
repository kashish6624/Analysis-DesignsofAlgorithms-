#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
using namespace std;

struct Activity {
    int start_time;
    int finish_time;
};

// Sorting function to sort activities based on finish time
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish_time < b.finish_time;
}

// Function to select activities
void activitySelector(const vector<Activity>& activities) {
    vector<int> selectedIndices;
    if (activities.empty()) {
        cout << "No activities available.\n";
        return;
    }

    selectedIndices.push_back(0);
    int i = 0;
    for (size_t m = 1; m < activities.size(); ++m) {
        if (activities[m].start_time >= activities[selectedIndices[i]].finish_time) {
            selectedIndices.push_back(m);
            ++i;
        }
    }

    cout << "Selected activities:\n";
    for (const auto& index : selectedIndices) {
        cout << "Activity " << index + 1 << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter the start and finish times of activities:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Activity " << i + 1 << " start time: ";
        cin >> activities[i].start_time;
        cout << "Activity " << i + 1 << " finish time: ";
        cin >> activities[i].finish_time;
    }

    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compareActivities);

    // Select activities
    activitySelector(activities);

    return 0;
}
