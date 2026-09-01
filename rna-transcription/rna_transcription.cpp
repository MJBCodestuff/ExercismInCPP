#include "rna_transcription.h"

namespace rna_transcription {



    char to_rna(char input)
    {
        std::unordered_map<char, char> conversion = {
            {'C', 'G'},
            {'G', 'C'},
            {'T', 'A'},
            {'A', 'U'}
        };

        return conversion[input];

    }

    std::string to_rna(std::string to_convert)
    {
        for (int i = 0; i < static_cast<int>(to_convert.length()); ++i)
        {
            to_convert[i] = to_rna(to_convert[i]);
        }
        return to_convert;
    }
}  // namespace rna_transcription
