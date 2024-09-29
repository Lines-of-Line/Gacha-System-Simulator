#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

// Gacha Item Structure
struct GachaItem {
    std::string name;
    std::string rarity;
};

// Function to simulate a gacha pull
GachaItem pullGacha() {
    // Define the pool of items with rarity
    std::vector<GachaItem> items = {
        {"Item A", "Normal"},
        {"Item B", "Normal"},
        {"Item C", "Normal"},
        {"Item D", "Normal"},
        {"Item E", "Normal"},
        {"Item F", "Normal"},
        {"Item G", "Normal"},
        {"Item H", "Normal"},
        {"Item I", "Rare"},
        {"Item J", "Rare"},
        {"Item K", "Rare"},
        {"Item L", "Rare"},
        {"Item M", "Rare"},
        {"Item O", "Rare"},
        {"Item P", "Elite"},
        {"Item Q", "Elite"},
        {"Item R", "Elite"},
        {"Item S", "Elite"},
        {"Item T", "Super Rare"},
        {"Item U", "Super Rare"},
        {"Item V", "Ultra Rare"}
    };

    // Define probability rates (in percentage) for each rarity
    double NormalRate = 28.8; //28.8% for Normal items
    double RareRate = 51; //51% for Rare items
    double EliteRate = 12; //12% for Elite items
    double SuperRareRate = 7; //7% for Super Rare items
    double UltraRareRate = 1.2; //1.2 for Ultra Rare items


    // Generate a random number between 1 and 100
    int randNum = rand() % 100 + 1;

    // Determine the rarity based on the random number
    if (randNum <= NormalRate) {
        // Common item (Choose randomly from Normal items)
        double randIndex = rand() % 8; // 8 Normal items
        return items[randIndex];
    } else if (randNum <= NormalRate + RareRate) {
        // Rare item (Choose randomly from Rare items)
        double randIndex = 8 + rand() % 6; // 6 Rare items
        return items[randIndex];
    } else if (randNum <= NormalRate + RareRate + EliteRate ) {
        // Ultra Rare item (Choose from Elite items)
        double randIndex = 8 + 6 + rand() % 4;
        return items[randIndex]; // Only 4 Elite items
    } else if (randNum <= NormalRate + RareRate + EliteRate + SuperRareRate ) {
        // Ultra Rare item (Choose from Super Rare items)
        double randIndex = 8 + 6 + 4 +rand() % 2;
        return items[randIndex]; // Only 2 Super Rare items
    } else {
        // Ultra Rare item (Choose from Ultra Rare item)
        return items[20]; // Only 1 Ultra Rare item
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int pulls;
    std::cout << "Enter the number of gacha pulls: ";
    std::cin >> pulls;

    for (int i = 0; i < pulls; ++i) {
        GachaItem result = pullGacha();
        std::cout << "Pull " << i + 1 << ": " << result.name << " (" << result.rarity << ")" << std::endl;
    }

    return 0;
}