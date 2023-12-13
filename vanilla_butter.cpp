#include <iostream>
#include <unordered_set>

using namespace std;

struct Student {
    int rollNumber;
    bool likesVanilla;
    bool likesButterscotch;
    Student* next;
};

void insertStudent(Student*& head, int rollNumber, bool likesVanilla, bool likesButterscotch) {
    Student* newStudent = new Student;
    newStudent->rollNumber = rollNumber;
    newStudent->likesVanilla = likesVanilla;
    newStudent->likesButterscotch = likesButterscotch;
    newStudent->next = head;
    head = newStudent;
}

void studentsLikeBoth(Student* setA, Student* setB) {
    unordered_set<int> likeBoth;

    while (setA != nullptr) {
        if (setA->likesVanilla && setA->likesButterscotch) {
            likeBoth.insert(setA->rollNumber);
        }
        setA = setA->next;
    }

    while (setB != nullptr) {
        if (setB->likesVanilla && setB->likesButterscotch) {
            likeBoth.insert(setB->rollNumber);
        }
        setB = setB->next;
    }

    cout << "Students who like both vanilla and butterscotch: ";
    for (int rollNumber : likeBoth) {
        cout << rollNumber << " ";
    }
    cout << endl;
}

void studentsLikeEitherOrNotBoth(Student* setA, Student* setB) {
    unordered_set<int> eitherOrNotBoth;

    while (setA != nullptr) {
        if ((setA->likesVanilla || setA->likesButterscotch) && !(setA->likesVanilla && setA->likesButterscotch)) {
            eitherOrNotBoth.insert(setA->rollNumber);
        }
        setA = setA->next;
    }

    while (setB != nullptr) {
        if ((setB->likesVanilla || setB->likesButterscotch) && !(setB->likesVanilla && setB->likesButterscotch)) {
            eitherOrNotBoth.insert(setB->rollNumber);
        }
        setB = setB->next;
    }

    cout << "Students who like either vanilla or butterscotch or not both: ";
    for (int rollNumber : eitherOrNotBoth) {
        cout << rollNumber << " ";
    }
    cout << endl;
}

void studentsLikeNeither(Student* setA, Student* setB) {
    unordered_set<int> likeNeither;

    while (setA != nullptr) {
        if (!setA->likesVanilla && !setA->likesButterscotch) {
            likeNeither.insert(setA->rollNumber);
        }
        setA = setA->next;
    }

    while (setB != nullptr) {
        if (!setB->likesVanilla && !setB->likesButterscotch) {
            likeNeither.insert(setB->rollNumber);
        }
        setB = setB->next;
    }

    cout << "Number of students who like neither vanilla nor butterscotch: " << likeNeither.size() << endl;
}

int main() {
    Student* setA = nullptr;
    Student* setB = nullptr;

    insertStudent(setA, 101, true, false); // Student 101 likes Vanilla
    insertStudent(setA, 102, false, true); // Student 102 likes Butterscotch
    insertStudent(setA, 103, true, true);  // Student 103 likes both
    insertStudent(setB, 101, true, false); // Student 101 likes Vanilla
    insertStudent(setB, 104, false, true); // Student 104 likes Butterscotch
    insertStudent(setB, 103, true, true);  // Student 103 likes both

    studentsLikeBoth(setA, setB);
    studentsLikeEitherOrNotBoth(setA, setB);
    studentsLikeNeither(setA, setB);

    return 0;
}
