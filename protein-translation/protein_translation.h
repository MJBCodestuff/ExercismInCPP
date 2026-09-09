#pragma once
#include <map>
#include <vector>
#include <string>
#include <array>

namespace protein_translation {

std::vector<std::string> proteins(std::string rna);

inline std::map<std::string, std::string> protein_lookup {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},

    };
inline std::array<std::string, 3> stopconditions {{"UAA", "UAG", "UGA"}};

}  // namespace protein_translation
