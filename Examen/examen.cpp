#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>



class Igrok {
public:
    std::string name;
    int zoloto;
    int derevo;
    int tokeni;
    int kub1;
    int kub2;
    int kub3;
    int dopolnitelniyKub;
    bool imeetSovetnika;
    int voenniyregister;
    int pobedaPoints;
    std::vector<std::string> buildings;
};

class Sovetnik {
public:
    std::string name;
    std::string playerName;
};

class Game_Nakhimov {
public:
    std::vector<Igrok> players;
    std::vector<Sovetnik> advisers;
    int year;
    int phase;
    std::string enemy;
    void phase1();
    void phase2();
    void phase3();
    void phase4();
    void phase5();
    void phase6();
    void phase7();
    void phase8();
    void RezultatiVoyni(Igrok& player, int RezultatiVoyni, std::vector<Sovetnik>& advisers, int year, std::string enemy);
    void start();
};

void Game_Nakhimov::start() {
    phase1();
    phase3();
    phase5();
}

void Game_Nakhimov::phase1() {
    std::cout << "Faza 1: Initializatsiya:" << std::endl;
    std::cout << "Vvedite kol-vo igrokov: ";
    int numPlayers;
    std::cin >> numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        Igrok Igrokk;
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> Igrokk.name;
        Igrokk.zoloto = 5;
        Igrokk.derevo = 5;
        Igrokk.tokeni = 5;
        Igrokk.kub1 = 0;
        Igrokk.kub2 = 0;
        Igrokk.kub3 = 0;
        Igrokk.dopolnitelniyKub = 0;
        Igrokk.imeetSovetnika = false;
        Igrokk.voenniyregister = 0;
        Igrokk.pobedaPoints = 0;
        players.push_back(Igrokk);
    }
}

void Game_Nakhimov::phase2() {
    std::cout << "Faza2: Nanyat Konsultantov: " << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        if (players[i].zoloto >= 2 && players[i].tokeni >= 1) {
            std::cout << "Sovetniki Dostupnie dlya Nayma: King, Trader, Builder: " << std::endl;
            std::cout << "Vvedite imya sovetnika, kotorogo vi hotite nanyat: ";
            std::string advisorName;
            std::cin >> advisorName;
            bool advisorAvailable = false;
            for (int j = 0; j < advisers.size(); j++) {
                if (advisers[j].name == advisorName && advisers[j].playerName.empty()) {
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
                advisers.push_back(advisor);
                std::cout << "Sovetnik uspeshno prinyat na rabotu: " << std::endl;
            }
            else {
                std::cout << "Sovetnik nedostupen, nanyat ne udalos: " << std::endl;
            }
        }
        else {
            std::cout << "Nedostatochno resursov dlya nayma: " << std::endl;
        }
        std::cout << std::endl;
    }
}
void Game_Nakhimov::phase3() {
    std::cout << "Faza 3: Stroitelstvo: " << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        if (players[i].zoloto >= 2 && players[i].derevo >= 1) {
            std::cout << "Zdaniya dostupniye dlya stroitelstva: Market, Sawmill, Smithy: " << std::endl;
            std::cout << "Vvedite nazvanie zdanie kotoroe vi hotite postroit: ";
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
                std::cout << "Ura, lord, Zdanie Postroeno: " << std::endl;
            }
            else {
                std::cout << "Takoe zdanie uje postroeno: " << std::endl;
            }
        }
        else {
            std::cout << "Nedostatochno resursov dlya postroyki zdaniya: " << std::endl;
        }

        std::cout << std::endl;
    }
}
void Game_Nakhimov::phase4() {
    std::cout << "Faza 4: Proizvodstvo: " << std::endl;
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
            std::cout << "1 token dobito, na lesopilnom zavode" << std::endl;
        }
        else {
            std::cout << "Lesopilka ne postroyena, token ne dobito" << std::endl;
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
            std::cout << "1 token, izgotovlenniy v kuznitse" << std::endl;
        }
        else {
            std::cout << "Kuznitsa ne postroena, Tokeni ne proizvodyatsa" << std::endl;
        }

        std::cout << std::endl;
    }
}
