#include "lasagna_master.h"

namespace lasagna_master {
 int preparationTime(const std::vector<std::string>& layers, int averagePreparationTime)
 {
  return averagePreparationTime * layers.size();
 }

 amount quantities(const std::vector<std::string>& layers)
 {
  amount quantities_{0, 0};
  for (std::string layer : layers)
  {
   if (layer == "noodles")
    quantities_.noodles += 50;
   else if (layer == "sauce")
     quantities_.sauce += 0.2;


  }
  return quantities_;

 }

 void addSecretIngredient(std::vector<std::string>& myRecipe, const std::vector<std::string>& friendsRecipe)
 {
  myRecipe.at(myRecipe.size()-1) = friendsRecipe.at(friendsRecipe.size() - 1);
 }

 void addSecretIngredient(std::vector<std::string>& myRecipe, const std::string& secretIngredient)
 {
  myRecipe.at(myRecipe.size() -1 ) = secretIngredient;
 }

 std::vector<double> scaleRecipe(const std::vector<double>& amountsForTwo, int portions)
 {
  std::vector<double> scaledAmounts {amountsForTwo};
  for (int i = 0; i < static_cast<int>(scaledAmounts.size()); ++i)
  {
    scaledAmounts.at(i) = scaledAmounts.at(i) / 2 * portions;
  }
  return  scaledAmounts;
 }
}  // namespace lasagna_master
