/* Program name: main.cpp
 * Author: Adolphe Dimandja
 * Date last updated: 7/28/2024
 * Purpose: Main program to allow users to create a custom candy mix with unique flavor and color combinations, ensuring no duplicates.
 */

#include <iostream>
#include <vector>
#include "candy.h"

bool isUniqueCombination(const std::vector<Candy*>& candies, flavorType flavor, colorType color) {
    for (const auto& candy : candies) {
        if (candy->getFlavor() == flavor && candy->getColor() == color) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "=========================================================================================\n";
    std::cout << "                              Welcome to The Cavity Factory!\n";
    std::cout << "=========================================================================================\n";
    std::cout << "\n- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!\n";
    std::cout << "There's only one catch: To ensure that our customers explore their palate,\n";
    std::cout << "we only allow unique candy to be ordered. Don't think of it as a limitation, but as an EXPERIENCE!\n\n";

    int numCandies;
    std::cout << "How many candies will you be ordering today? (range: 1-25) ";
    std::cin >> numCandies;

    std::vector<Candy*> candies;

    for (int i = 0; i < numCandies; ++i) {
        int flavorChoice, colorChoice;
        flavorType flavor;
        colorType color;

        std::cout << "Candy #" << (i + 1) << " of " << numCandies << "\n";
        do {
            std::cout << "Choose a flavor you would like:\n";
            std::cout << "[1] Cotton Candy\n";
            std::cout << "[2] Watermelon Burst\n";
            std::cout << "[3] Papaya Bliss\n";
            std::cout << "[4] Citrus Splash\n";
            std::cout << "[5] Cola\n";
            std::cin >> flavorChoice;
            flavor = static_cast<flavorType>(flavorChoice - 1);

            std::cout << "Choose a color for your candy:\n";
            std::cout << "[1] Scarlet Blaze\n";
            std::cout << "[2] Azure Sky\n";
            std::cout << "[3] Emerald Mist\n";
            std::cout << "[4] Goldenrod Glow\n";
            std::cout << "[5] Amethyst Haze\n";
            std::cin >> colorChoice;
            color = static_cast<colorType>(colorChoice - 1);

            if (!isUniqueCombination(candies, flavor, color)) {
                std::cout << "But wait, this is not unique, try again.\n";
            }
        } while (!isUniqueCombination(candies, flavor, color));

        candies.push_back(new Candy(flavor, color));
        std::cout << candies.back()->flavorToString() << " " << candies.back()->colorToString() << " it is!\n";
        std::cout << "Marvelous! Your candy was added to the order.\n";

        std::cout << "\nYour order:\n";
        for (int j = 0; j <= i; ++j) {
            std::cout << "#" << (j + 1) << " " << candies[j]->colorToString() << " " << candies[j]->flavorToString() << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!\n";

    for (auto candy : candies) {
        delete candy;
    }

    return 0;
}
