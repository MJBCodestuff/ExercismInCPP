#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};


    int preparationTime(const std::vector<std::string>& layers, int averagePreparationTime = 2);
    amount quantities(const std::vector<std::string>& layers);
    void addSecretIngredient(std::vector<std::string>& myRecipe, const std::vector<std::string>& friendsRecipe);
    void addSecretIngredient(std::vector<std::string>& myRecipe, const std::string& secretIngredient);
    std::vector<double> scaleRecipe (const std::vector<double>& amountsForTwo, int portions);
}  // namespace lasagna_master
