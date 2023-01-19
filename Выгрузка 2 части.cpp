#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

class igrok {
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
    int roll;
    std::vector<std::string> buildings;
};

class Sovetnik {
public:
    std::string name;
    std::string playerName;
};

class Game_Nakhimov {
public:
    std::vector<igrok> players;
    std::vector<Sovetnik> sovetniki;
    int year;
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
    void rollDice();
    void changePlayerOrder();
    void influenceAdvisers();
    void getAdviserHelp();
    void buildBuilding();
    void applyBuildingEffect();

    void applyBattleResults(igrok& player, int battleResult, std::vector<Sovetnik>& advisers, int year, std::string enemy);
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
        igrok player;
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> player.name;
        player.zoloto = 5;
        player.derevo = 5;
        player.tokeni = 5;
        player.cube1 = 0;
        player.cube2 = 0;
        player.cube3 = 0;
        player.zapasnoycube = 0;
        player.imeetSovetnika = false;
        player.voenniyRegistr = 0;
        player.pobedniyeochki = 0;
        players.push_back(player);
    }
}

void Game_Nakhimov::phase2() {
    std::cout << "Phase 2: Hire Advisers and Roll Dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].zoloto >= 2 && players[i].tokeni >= 1) {
            std::cout << "Advisers available for hire: King, Trader, Builder" << std::endl;
            std::cout << "Enter the name of the advisor you want to hire: ";
            std::string advisorName;
            std::cin >> advisorName;

            bool advisorAvailable = false;
            for (int j = 0; j < sovetniki.size(); j++) {
                if (sovetniki[j].name == advisorName && sovetniki[j].playerName.empty()) {
                    advisorAvailable = true;
                    break;
                }
            }

            if (advisorAvailable) {
                players[i].zoloto -= 2;
                players[i].tokeni -= 1;
                players[i].imeetSovetnika = true;

                Sovetnik advisor;
                advisor.name = advisorName;
                advisor.playerName = players[i].name;
                sovetniki.push_back(advisor);
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
            for (int j = 0; j < players[i].buildings.size(); j++) {
                if (players[i].buildings[j] == buildingName) {
                    buildingAvailable = true;
                    break;
                }
            }

            if (!buildingAvailable) {
                players[i].zoloto -= 2;
                players[i].derevo -= 1;
                players[i].buildings.push_back(buildingName);
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
    std::cout << "Phase 4: Build Buildings and Roll Dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();
    buildBuilding();
    applyBuildingEffect();


    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        bool hasSawmill = false;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Sawmill") {
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

        bool hasSmithy = false;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Smithy") {
                hasSmithy = true;
                break;
            }
        }

        if (hasSmithy) {
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
            int numSoldiers;
            std::cin >> numSoldiers;

            players[i].zoloto -= 2;
            players[i].tokeni -= 1;
            players[i].voenniyRegistr += numSoldiers;
            std::cout << numSoldiers << " soldiers recruited successfully!" << std::endl;
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
        for (int j = 0; j < sovetniki.size(); j++) {
            if (sovetniki[j].playerName == players[i].name && sovetniki[j].name == "King") {
                defenseValue += 2;
                break;
            }
        }
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Wall") {
                defenseValue++;
            }
        }

        int battleResult = rand() % 2; 
        applyBattleResults(players[i], battleResult, sovetniki, year, vrag);

        std::cout << std::endl;
    }
}


void Game_Nakhimov::phase6() {
    std::cout << "Phase 6: Build Buildings and Roll Dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();
    buildBuilding();
    applyBuildingEffect();

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

                applyBattleResults(players[i], battleResult, sovetniki, year, vrag);
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

    year++;
    std::cout << "Year " << year << " has ended." << std::endl;
    
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


void Game_Nakhimov::applyBattleResults(igrok& player, int battleResult, std::vector<Sovetnik>& advisers, int year, std::string enemy) {
    if (battleResult == 0) {
        std::cout << "Battle lost. Defense value: " << player.voenniyRegistr << std::endl;
        player.voenniyRegistr = std::max(0, player.voenniyRegistr - 1);
    }
    else {
        std::cout << "Battle won. Defense value: " << player.voenniyRegistr << std::endl;
        player.pobedniyeochki++;
    }
}

void Game_Nakhimov::rollDice() {
    std::cout << "Rolling dice..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        int roll = std::rand() % 6 + 1;
        std::cout << players[i].name << " rolled a " << roll << std::endl;
    }
}

void Game_Nakhimov::changePlayerOrder() {
    std::cout << "Changing player order..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        players[i].roll = std::rand() % 6 + 1;
    }
    std::vector<igrok> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const igrok& p1, const igrok& p2) {
        return p1.roll > p2.roll;
        });
    players = sortedPlayers;
    std::cout << "New player order: ";
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " ";
    }
    std::cout << std::endl;
}

void Game_Nakhimov::getAdviserHelp() {
    std::cout << "Getting adviser help..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is getting adviser help..." << std::endl;
    }
}

void Game_Nakhimov::buildBuilding() {
    std::cout << "Building buildings..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is building a building..." << std::endl;
    }
}

void Game_Nakhimov::applyBuildingEffect() {
    std::cout << "Applying building effects..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is applying building effects..." << std::endl;
    }
}


void Game_Nakhimov::influenceAdvisers() {
    std::cout << "Influencing advisers..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is influencing advisers..." << std::endl;
    }
}


int main() {
    srand(time(0));
    Game_Nakhimov game;
    game.start();
    return 0;
}

/*
Game_Nakhimov::start() : Этот метод является точкой входа в игру и вызывает различные фазы игры в определенном порядке.
Game_Nakhimov::phase1() : Этот метод отвечает за фазу инициализации игры, где он предлагает пользователю ввести количество игроков и создает объекты игрока со значениями по умолчанию.
Game_Nakhimov::phase2() : Этот метод отвечает за фазу найма консультантов в игре, где игроки могут нанимать консультантов, на этой фазе вызываются методы rollDice, changePlayerOrder, influenceAdvisers, helpAdvisers, constructBuildings, applyBuildingEffects.
Game_Nakhimov::phase3() : Этот метод отвечает за боевую фазу игры, где игроки участвуют в сражениях и результаты применяются к игрокам.
Game_Nakhimov::phase4() : Этот метод отвечает за фазу влияния советников игры, где игроки могут влиять на королевских советников, на этой фазе вызываются методы rollDice, changePlayerOrder, influenceAdvisers, helpAdvisers, constructBuildings, applyBuildingEffects.
Game_Nakhimov::phase5() : Этот метод отвечает за фазу сбора ресурсов в игре, где игроки собирают ресурсы.
Game_Nakhimov::phase6() : Этот метод отвечает за фазу помощи консультантам игры, где игроки могут помогать своим консультантам, на этой фазе вызываются методы rollDice, changePlayerOrder, influenceAdvisers, helpAdvisers, constructBuildings, applyBuildingEffects.
Game_Nakhimov::phase7() : Этот метод отвечает за фазу конца года игры, где применяется механика конца года и увеличивается счетчик года.
Game_Nakhimov::phase8() : Этот метод отвечает за фазу проверки победы в игре, где он проверяет, добился ли игрок победы, и начинает следующий год, если ни один игрок еще не выиграл.
Game_Nakhimov::rollDice() : Этот метод отвечает за бросание кубиков для игроков в игре.
Game_Nakhimov::changePlayerOrder() : Этот метод отвечает за изменение порядка ходов игроков в игре, он сортирует вектор игроков на основе их броска.
Game_Nakhimov::influenceAdvisors() : Этот метод отвечает за то, чтобы игроки влияли на королевских советников в игре.
Game_Nakhimov::helpAdvisors() : Этот метод отвечает за то, чтобы игроки помогали советникам в игре.
Game_Nakhimov::constructBuildings() : Этот метод отвечает за то, что игроки строят здания в игре.
Game_Nakhimov::applyBuildingEffects() : Этот метод отвечает за применение эффектов зданий к игрокам в игре.
*/
