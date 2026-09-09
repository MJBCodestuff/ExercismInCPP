#include "protein_translation.h"


namespace protein_translation {

    std::vector<std::string> proteins(std::string rna) {
        std::vector<std::string> decoded {};
        for (int i = 0; i < static_cast<int>(rna.length()); i+= 3) {
            std::string temp {rna.substr(i, 3)};
            if (!(std::find(stopconditions.begin(),
                stopconditions.end(), temp) == stopconditions.end()))
                break;
            decoded.emplace_back(protein_lookup.at(temp));
        }
        return decoded;
    }
}  // namespace protein_translation
