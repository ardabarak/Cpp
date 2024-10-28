// Arda Barak
// 300129340

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class SportsTeam {
private:
    std::string teamName;
    int wins;
    int loses;
    int draws;
    static int teamCount;

public:
    SportsTeam(std::string name, int w, int l, int d) : teamName(name), wins(w), loses(l), draws(d) {//constr
        teamCount++;
    }
    static int getTeamCount() {//get count
        return teamCount;
    }
    double getWinPercentage() const {// get W%
        int totalGames = wins + loses + draws;
        return (totalGames > 0) ? (static_cast<double>(wins) / totalGames) * 100 : 0.0;
    }
    friend bool operator<(const SportsTeam& team1, const SportsTeam& team2);    //overloading <
    friend bool operator>(const SportsTeam& team1, const SportsTeam& team2);    //overloading >

    void displayStats() const { //team stats
        std::cout << "Team          : " << teamName << ",\nWins          : " << wins << ",\nLoses         : " << loses << ",\nDraws         : " << draws << ",\nWin%          : " << std::fixed << std::setprecision(2) << getWinPercentage() << "\n" << std::endl;
    }
};

int SportsTeam::teamCount = 0;

bool operator<(const SportsTeam& team1, const SportsTeam& team2) {//overloading <
    return team1.getWinPercentage() < team2.getWinPercentage();
}
bool operator>(const SportsTeam& team1, const SportsTeam& team2) {//overloading >
    return team1.getWinPercentage() > team2.getWinPercentage();
}

int main() {
    std::vector<SportsTeam> teams;
    std::string name;
    int wins;
    int loses;
    int draws;
    int teamsNo;

    std::cout << "Enter the # of teams: ";
    std::cin >> teamsNo;
    for (int i = 0; i < teamsNo; ++i) {
        std::cout << "Enter name for team# " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter wins: ";
        std::cin >> wins;
        std::cout << "Enter lose: ";
        std::cin >> loses;
        std::cout << "Enter draw: ";
        std::cin >> draws;
        teams.emplace_back(name, wins, loses, draws);
    }
    std::sort(teams.begin(), teams.end(), std::greater<SportsTeam>());
    std::cout << "Teams sorted by winning %:" << std::endl;
    for (const auto& team : teams) {
        team.displayStats();
    }
    return 0;
}
