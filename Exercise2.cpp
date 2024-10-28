// Arda Barak
// 300129340

#include <iostream>
#include <string>
#include <vector>

class User {
private:
    std::string username;
    int userId;
    std::string accessLevel;
    static int userCount;

public:
    User(std::string username, int id, std::string acesslevel) : username(username), userId(id), accessLevel(acesslevel) { //constructor
        userCount++;
    }
    ~User() { //destructor
        userCount--;
    }
    static int getUserCount() {//get user count
        return userCount;
    }
    friend bool compareAccess(const User& user1, const User& user2);//friend
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    void displayInfo() const { //user info
        std::cout << "Username: " << username << ", ID: " << userId << ", Access Level: " << accessLevel << std::endl;
    }
};

int User::userCount = 0;

bool compareAccess(const User& user1, const User& user2) { //friend funct for two users
    return user1.accessLevel == user2.accessLevel;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "(name)" << user.username << ", (id)" << user.userId << ", (access)" << user.accessLevel;
    return os;
}

int main() {
    std::vector<User> users;
    users.reserve(3);
    for (int i = 0; i < 3; ++i) { //inputing users
        std::string username, accessLevel;
        int id;
        std::cout << "\nEnter details for user " << i + 1 << ":\n";
        std::cout << "Username      : ";
        std::cin >> username;
        std::cout << "ID            : ";
        std::cin >> id;
        std::cout << "Access Level  : ";
        std::cin >> accessLevel;
        users.emplace_back(username, id, accessLevel);
        // User user(username, id, accessLevel);
    }

    for (int i = 0; i < 3; i++) {
        users[i].displayInfo();
    }
    std::cout << "Do " << users[0] << " and " << users[1] << " have the same access level? "  << (compareAccess(users[0], users[1]) ? "Yes" : "No") << std::endl;
    std::cout << "Do " << users[1] << " and " << users[2] << " have the same access level? "  << (compareAccess(users[1], users[2]) ? "Yes" : "No") << std::endl;
    std::cout << "Total users   : " << User::getUserCount() << std::endl;
    return 0;
}
