// Arda Barak
// 300129340
// Exercise 3

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Feedback {
    string comment;
    unordered_multiset<string> tags;
};

class FeedbackAnalyzer {
private:
    vector<Feedback> feedbacks;
    unordered_multiset<string> tagCounts;

public:
    void addFeedback(const string& comment, const unordered_multiset<string>& tags) {//adding new feedback entry
        Feedback newFeedback{comment, tags};
        feedbacks.push_back(newFeedback);
        for (const auto& tag : tags) {tagCounts.insert(tag);}
        cout << "Feedback added successfully\n";
    }

    void getFeedbackByTag(const string& tag) const {//getting tags feedback
        bool found = false;
        cout << "\nFeedback for tag '" << tag << "' :\n";
        for (const auto& feedback : feedbacks) {
            if (feedback.tags.find(tag) != feedback.tags.end()) {
                cout  << feedback.comment << "\n";
                found = true;}
        }
        if (!found) {cout << "No feedback found for tag : " << tag << "\n";}
    }

    void getTagStatistics() const {//showimg tags stats
        if (tagCounts.empty()) {cout << "No tags available for statistics.\n";  return;}
        auto tagFrequency = [](const auto& a, const auto& b, const unordered_multiset<string>& counts) {return counts.count(a) < counts.count(b);};
        auto mostCommonTag = *max_element(tagCounts.begin(), tagCounts.end(), [&](const string& a, const string& b)  { return tagFrequency(a, b, tagCounts); });
        auto leastCommonTag = *min_element(tagCounts.begin(), tagCounts.end(), [&](const string& a, const string& b) { return tagFrequency(a, b, tagCounts); });
        cout << "\nTag Statistics:\n";
        cout << "Most common tag    : '" << mostCommonTag  << "' (Count : " << tagCounts.count(mostCommonTag)  << ")\n";
        cout << "Least common tag   : '" << leastCommonTag << "' (Count : " << tagCounts.count(leastCommonTag) << ")\n";
    }
};

unordered_multiset<string> parseTags(const string& tagsInput) {//helper parsing csv tags
    unordered_multiset<string> tags;
    stringstream ss(tagsInput);
    string tag;
    while (getline(ss, tag, ',')) {
        tag.erase(0, tag.find_first_not_of(' ')); //trimming head
        tag.erase(tag.find_last_not_of(' ') + 1); //trimming tail
        if (!tag.empty()) {tags.insert(tag);}
    }
    return tags;
}

int main() {
    FeedbackAnalyzer analyzer;
    bool exit = false;

    while (!exit) {
        cout << "\n1. Add Feedback\n2. View Feedback by Tag\n3. Display Tag Statistics\n4. Exit\n";
        cout << "Enter your choice  : ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: {
            string comment, tagInput;
            cout << "Enter feedback text    : ";
            getline(cin, comment);
            cout << "Enter tags (csv)       : ";
            getline(cin, tagInput);
            unordered_multiset<string> tags = parseTags(tagInput);
            analyzer.addFeedback(comment, tags);
            break;
        }
        case 2: {
            string tag;
            cout << "Enter tag to search feedback   : ";
            cin >> tag;
            analyzer.getFeedbackByTag(tag);
            break;}
        case 3: {analyzer.getTagStatistics(); break;}
        case 4: {exit = true;                 break;}
        default: {cout << "Invalid option please try again\n";}
        }
    }
    return 0;
}
