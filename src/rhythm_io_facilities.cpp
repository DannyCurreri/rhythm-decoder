#include "rhythm.h"
#include <string>

using std::string;

const string one_count = " ";
const string two_count = " + ";
const string four_count = " e + a ";
const string three_count = "  la li ";
const string six_count = "  d  la d  li d  ";

string RhythmicPiece::write() const
{
    string res;
    string subcounts;

    switch (count_system()) {
        case CountSystem::one   :subcounts = one_count;   break;
        case CountSystem::two   :subcounts = two_count;   break;
        case CountSystem::three :subcounts = three_count; break;
        case CountSystem::four  :subcounts = four_count;  break;
        case CountSystem::six   :subcounts = six_count;   break;
    }

    // write a line with just the skeleton of the counts
    for (int i = 0; i != bars.size(); ++i) {
        for (int j = 0; j != beats_per_measure; ++j) {
            res += std::to_string(j + 1);
            res += subcounts;
        }
        res += "|";
    }

    res += "|\n";

    // then write a line underneath with Xs indicating where each note falls
    std::vector<std::pair<bool, int>> counts_ = counts();
    for (auto count: counts_) {
        if (count.first)
            res += "X";
        else
            res += " ";

        for (int i = 0; i != 2 * count.second - 1; ++i) {
            res += " ";
            if (subcounts == three_count || subcounts == six_count)
                res += " ";
        }
    }
    res += "||\n";

    return res;
}
