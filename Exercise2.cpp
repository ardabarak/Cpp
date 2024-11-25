// Arda Barak
// 300129340
// Exercise 2

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class MessageSystem {
private:
    std::unordered_multimap<int, std::string> groupMessages;

public:
    void sendMessage(int groupId, const std::string& message) { //posting message to a group
        groupMessages.emplace(groupId, message);
        std::cout << "Message posted to group " << groupId << " : " << message << std::endl;
    }

    std::vector<std::string> getMessages(int groupId) { //retrieving all messages from a group
        std::vector<std::string> messages;
        auto range = groupMessages.equal_range(groupId);
        for (auto it = range.first; it != range.second; ++it) {messages.push_back(it->second);}
        return messages;
    }

    void clearGroup(int groupId) {  //clearing messages of a group
        groupMessages.erase(groupId);
        std::cout << "All messages cleared for group " << groupId << std::endl;
    }
};

int main() {
    MessageSystem messageSystem;
    //posting messages to groups
    messageSystem.sendMessage(1, "Hello Group 1!");
    messageSystem.sendMessage(1, "Second message Group 1!");
    messageSystem.sendMessage(2, "Hello Group 2!");
    //getting messages from gr 1
    std::vector<std::string> group1Messages = messageSystem.getMessages(1);
    std::cout << "Messages of Group 1 :\n";
    for (const auto& message : group1Messages) {std::cout << message << std::endl;}
    //clearing messages of group 1
    messageSystem.clearGroup(1);
    //from gr 2
    std::vector<std::string> group2Messages = messageSystem.getMessages(2);
    for (const auto& message : group2Messages) {std::cout << message << std::endl;}
    //clearing messages of group 2
    messageSystem.clearGroup(2);
    return 0;
}
