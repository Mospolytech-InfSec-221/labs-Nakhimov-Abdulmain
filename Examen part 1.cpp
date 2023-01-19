#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <locale.h>


class Igrok {
public:
    std::string name;
    int zoloto;
    int derevo;
    int tokeni;
    int cube1;
    int cube2;
    int cube3;
    int zapasnoycube;
    bool imeetSovetnika;
    int voenniyRegistr;
    int pobedniyeochki;
    std::vector<std::string> stroyeniya;
};

class Sovetnik {
public:
    std::string name;
    std::string playerName;
};

class Game_Nakhimov {
public:
    std::vector<Igrok> players;
    std::vector<Sovetnik> sovetnik;
    int God;
    int phase;
    std::string vrag;
    void phase1();
    void phase2();
    void phase3();
    void phase4();
    void phase5();
    void phase6();
    void phase7();
    void phase8();
    void applyBattleResults(Igrok& player, int battleResult, std::vector<Sovetnik>& advisers, int year, std::string enemy);
    void start();
};

void Game_Nakhimov::start() {
    phase1();
    phase3();
    phase5();
    phase6();
    phase7();
    phase8();
}

void Game_Nakhimov::phase1() {
    std::cout << "Phase 1: Start" << std::endl;
    std::cout << "Enter the number of players: ";
    int numIgrokov;
    std::cin >> numIgrokov;

    for (int i = 0; i < numIgrokov; i++) {
        Igrok igrokk;
        std::cout << "Enter a name for the player " << i + 1 << ": ";
        std::cin >> igrokk.name;
        igrokk.zoloto = 5;
        igrokk.derevo = 5;
        igrokk.tokeni = 5;
        igrokk.cube1 = 0;
        igrokk.cube2 = 0;
        igrokk.cube3 = 0;
        igrokk.zapasnoycube = 0;
        igrokk.imeetSovetnika = false;
        igrokk.voenniyRegistr = 0;
        igrokk.pobedniyeochki = 0;
        players.push_back(igrokk);
    }
}

void Game_Nakhimov::phase2() {
    std::cout << "Phase 2: Hire Advisers" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].zoloto >= 2 && players[i].tokeni >= 1) {
            std::cout << "Advisers available for hire: King, Trader, Builder" << std::endl;
            std::cout << "Enter the name of the advisor you want to hire: ";
            std::string imyaSovetnika;
            std::cin >> imyaSovetnika;

            bool imeetsaSovetnik = false;
            for (int j = 0; j < sovetnik.size(); j++) {
                if (sovetnik[j].name == imyaSovetnika && sovetnik[j].playerName.empty()) {
                    imeetsaSovetnik = true;
                    break;
                }
            }

            if (imeetsaSovetnik) {
                players[i].zoloto -= 2;
                players[i].tokeni -= 1;
                players[i].imeetSovetnika = true;

                Sovetnik advisor;
                advisor.name = imyaSovetnika;
                advisor.playerName = players[i].name;
                sovetnik.push_back(advisor);
                std::cout << "Advisor hired successfully!" << std::endl;
            }
            else {
                std::cout << "Advisor not available. Hiring failed." << std::endl;
            }
        }
        else {
            std::cout << "Not enough resources to hire an advisor." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Nakhimov::phase3() {
    std::cout << "Phase 3: Building" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].zoloto >= 2 && players[i].derevo >= 1) {
            std::cout << "Buildings available for construction: Market, Sawmill, Smithy" << std::endl;
            std::cout << "Enter the name of the building you want to construct: ";
            std::string buildingName;
            std::cin >> buildingName;

            bool buildingAvailable = false;
            for (int j = 0; j < players[i].stroyeniya.size(); j++) {
                if (players[i].stroyeniya[j] == buildingName) {
                    buildingAvailable = true;
                    break;
                }
            }

            if (!buildingAvailable) {
                players[i].zoloto -= 2;
                players[i].derevo -= 1;
                players[i].stroyeniya.push_back(buildingName);
                std::cout << "Building constructed successfully!" << std::endl;
            }
            else {
                std::cout << "Building already constructed." << std::endl;
            }
        }
        else {
            std::cout << "Not enough resources to construct a building." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Nakhimov::phase4() {
    std::cout << "Phase 4: Production" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        bool hasSawmill = false;
        for (int j = 0; j < players[i].stroyeniya.size(); j++) {
            if (players[i].stroyeniya[j] == "Sawmill") {
                hasSawmill = true;
                break;
            }
        }

        if (hasSawmill) {
            players[i].derevo++;
            std::cout << "1 wood produced at the sawmill." << std::endl;
        }
        else {
            std::cout << "Sawmill not constructed. No wood produced." << std::endl;
        }

        bool imeetKuznitsy = false;
        for (int j = 0; j < players[i].stroyeniya.size(); j++) {
            if (players[i].stroyeniya[j] == "Smithy") {
                imeetKuznitsy = true;
                break;
            }
        }

        if (imeetKuznitsy) {
            players[i].tokeni++;
            std::cout << "1 token produced at the smithy." << std::endl;
        }
        else {
            std::cout << "Smithy not constructed. No tokens produced." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Nakhimov::phase5() {
    std::cout << "Phase 5: Military" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].zoloto >= 2 && players[i].tokeni >= 1) {
            std::cout << "Enter the number of soldiers you want to recruit: ";
            int kolVoynov;
            std::cin >> kolVoynov;

            players[i].zoloto -= 2;
            players[i].tokeni -= 1;
            players[i].voenniyRegistr += kolVoynov;
            std::cout << kolVoynov << " soldiers recruited successfully!" << std::endl;
        }
        else {
            std::cout << "Not enough resources to recruit soldiers." << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "Enemy attack!" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        int defenseValue = players[i].voenniyRegistr;
        for (int j = 0; j < sovetnik.size(); j++) {
            if (sovetnik[j].playerName == players[i].name && sovetnik[j].name == "King") {
                defenseValue += 2;
                break;
            }
        }
        for (int j = 0; j < players[i].stroyeniya.size(); j++) {
            if (players[i].stroyeniya[j] == "Wall") {
                defenseValue++;
            }
        }

        int battleResult = rand() % 2; 
        applyBattleResults(players[i], battleResult, sovetnik, God, vrag);

        std::cout << std::endl;
    }
}


void Game_Nakhimov::phase6() {
    std::cout << "Phase 6: Battle" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].zoloto >= 5 && players[i].derevo >= 2) {
            std::cout << "Do you want to go to battle? (y/n): ";
            char answer;
            std::cin >> answer;

            if (answer == 'y') {
                players[i].zoloto -= 5;
                players[i].derevo -= 2;
                std::cout << "Enter the number of soldiers to send to battle: ";
                int numSoldiers;
                std::cin >> numSoldiers;

                int battleResult = std::rand() % 2; 

                applyBattleResults(players[i], battleResult, sovetnik, God, vrag);
            }
            else {
                std::cout << "Player chose not to go to battle." << std::endl;
            }
        }
        else {
            std::cout << "Not enough resources to go to battle." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Nakhimov::phase7() {
    std::cout << "Phase 7: Trade" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        std::cout << "Enter the resource you want to trade (gold/wood/tokens): ";
        std::string resource;
        std::cin >> resource;

        std::cout << "Enter the amount you want to trade: ";
        int amount;
        std::cin >> amount;

        if (resource == "gold") {
            players[i].zoloto -= amount;
            players[i].derevo += amount / 2;
            players[i].tokeni += amount / 2;
        }
        else if (resource == "wood") {
            players[i].derevo -= amount;
            players[i].zoloto += amount / 2;
            players[i].tokeni += amount / 2;
        }
        else if (resource == "tokens") {
            players[i].tokeni -= amount;
            players[i].zoloto += amount / 2;
            players[i].derevo += amount / 2;
        }
        else {
            std::cout << "Invalid resource entered." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Nakhimov::phase8() {
    std::cout << "Phase 8: End of Year" << std::endl;

    God++;
    std::cout << "Year " << God << " has ended." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        int points = players[i].zoloto + players[i].derevo + players[i].tokeni + players[i].cube1 + players[i].cube2 + players[i].cube3 + players[i].zapasnoycube;
        players[i].pobedniyeochki = points;
    }

    bool gameOver = false;
    std::string winner;
    int highestPoints = 0;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].pobedniyeochki > highestPoints) {
            gameOver = true;
            winner = players[i].name;
            highestPoints = players[i].pobedniyeochki;
        }
    }

    if (gameOver) {
        std::cout << "Game over! The winner is: " << winner << " with " << highestPoints << " victory points." << std::endl;
    }
    else {
        std::cout << "Next year..." << std::endl;
    }
}


void Game_Nakhimov::applyBattleResults(Igrok& player, int battleResult, std::vector<Sovetnik>& advisers, int year, std::string enemy) {
    if (battleResult == 0) {
        std::cout << "Battle lost. Defense value: " << player.voenniyRegistr << std::endl;
        player.voenniyRegistr = std::max(0, player.voenniyRegistr - 1);
    }
    else {
        std::cout << "Battle won. Defense value: " << player.voenniyRegistr << std::endl;
        player.pobedniyeochki++;
    }
}

int main() {
    srand(time(0));
    Game_Nakhimov game;
    game.start();
    return 0;
}

