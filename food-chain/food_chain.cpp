#include "food_chain.h"

#include <map>
#include <numeric>
#include <vector>

namespace food_chain {
    std::array<std::string, 8> creatures{{"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"}};
    std::array<std::string, 2> ending{
        {
            "I don't know why she swallowed the fly. Perhaps she'll die.\n",
            "She's dead, of course!\n"
        }
    };
    std::array<std::string, 8> uniqueParts{
        {
            "", "It wriggled and jiggled and tickled inside her.\n",
            "How absurd to swallow a bird!\n",
            "Imagine that, to swallow a cat!\n",
            "What a hog, to swallow a dog!\n",
            "Just opened her throat and swallowed a goat!\n",
            "I don't know how she swallowed a cow!\n", ""
        }
    };
    std::string start{"I know an old lady who swallowed a "};
    std::string spider_attribute{
        " that wriggled and jiggled and tickled inside her."
    };

    std::string verse(int verse_nr) {
        --verse_nr;
        std::string result{};
        result.append(start);
        result.append(creatures[verse_nr] + ".");
        result.append("\n");
        result.append(uniqueParts[verse_nr]);
        if (verse_nr < 7) {
            for (int i = 0; i < verse_nr; ++i) {
                result.append(
                    "She swallowed the " + creatures[verse_nr - i] + " to catch the " + creatures[verse_nr - i - 1]);
                if (i == verse_nr - 2 and verse_nr > 1 and verse_nr != 8)
                    result.append(spider_attribute);
                else
                    result.append(".");
                result.append("\n");
            }
        }
        result.append(ending[static_cast<int>(verse_nr / 7.0)]);
        return result;
    }


    std::string verses(int verse_start, int verse_end) {
        std::string result{};
        for (int i = verse_start; i <= verse_end; ++i) {
            result.append(verse(i));
            result.append("\n");
        }
        return result;
    }

    std::string sing() {
        return verses(1, 8);
    }
} // namespace food_chain
