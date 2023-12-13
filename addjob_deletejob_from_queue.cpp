#include <iostream>
#include <queue>

using namespace std;

void addJob(queue<string>& jobQueue, const string& job) {
    jobQueue.push(job);
    cout << "Job '" << job << "' added to the queue." << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<string>& jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job '" << jobQueue.front() << "' deleted from the queue." << endl;
        jobQueue.pop();
    } else {
        cout << "Queue is empty. No job to delete." << endl;
    }
}

// Function to display the current job queue
void displayQueue(const queue<string>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Job Queue: ";
        queue<string> tempQueue = jobQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
}

int main() {
    queue<string> jobQueue;

    int choice;
    string job;

    // Menu-driven program loop
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch statement to handle user choices
        switch (choice) {
            case 1:
                cout << "Enter the job name: ";
                cin >> job;
                addJob(jobQueue, job);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayQueue(jobQueue);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
