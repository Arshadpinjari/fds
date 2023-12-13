#include <iostream>
#include <string>

using namespace std;

struct ClubMember {
    int PRN;
    string name;
    ClubMember* next;
};

class ClubMemberList {
public:
    ClubMember* head, *president, *secretary;

    ClubMemberList() : head(nullptr), president(nullptr), secretary(nullptr) {}

    void addMember(int PRN, string name) {
        ClubMember* newMember = new ClubMember{PRN, name, nullptr};
        if (head == nullptr) head = president = secretary = newMember;
        else secretary->next = newMember, secretary = newMember;
        cout << "Member with PRN " << PRN << " and Name " << name << " has been added." << endl;
    }

    void deleteMember(int PRN) {
        ClubMember* current = head, *prev = nullptr;

        while (current != nullptr && current->PRN != PRN) prev = current, current = current->next;

        if (current == nullptr) cout << "Member with PRN " << PRN << " not found." << endl;
        else {
            if (current == president) president = president->next;
            if (current == secretary) secretary = prev;
            if (prev != nullptr) prev->next = current->next;
            else head = current->next;
            delete current;
            cout << "Member with PRN " << PRN << " has been removed." << endl;
        }
    }

    int getTotalMembers() {
        int count = 0;
        ClubMember* current = head;

        while (current != nullptr) count++, current = current->next;
        return count;
    }

    void displayMembers() {
        ClubMember* current = head;

        if (current == nullptr) cout << "The club has no members." << endl;
        else {
            cout << "Club Members:" << endl;
            while (current != nullptr) cout << "PRN: " << current->PRN << ", Name: " << current->name << endl, current = current->next;
        }
    }
};

int main() {
    ClubMemberList mainClub;
    int choice, PRN;
    string name;

    do {
        cout << "Menu:" << endl << "1. Add a member\n2. Delete a member\n3. Compute total number of members\n4. Display members\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> PRN;
                cout << "Enter Name: ";
                cin >> name;
                mainClub.addMember(PRN, name);
                break;
            case 2:
                cout << "Enter PRN to delete: ";
                cin >> PRN;
                mainClub.deleteMember(PRN);
                break;
            case 3:
                cout << "Total number of members in the main club: " << mainClub.getTotalMembers() << endl;
                break;
            case 4:
                mainClub.displayMembers();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

