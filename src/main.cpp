#include "rhythm.h"
#include "rhythm_io_facilities.h"
#include <iostream>
#include <utility>
#include <string_view>

int main(int argc, char* argv[])
{
    std::pair<int, int> time_sig = parse_time_sig(argv[1]);
    RhythmicPiece rp(orff_signature(time_sig.first, time_sig.second));

    RhythmicPiece::Bar bar {};

    for (int i = 2; i < argc; ++i) {
        //std::cout << "arg " << i << " = " << argv[i] << std::endl;
        if (std::string_view(argv[i]) == "/") {
            rp.append(bar);
            bar = {};
        } else
            bar.push_back(parse_note(std::string_view(argv[i])));
    }

    std::cout << rp.write() << std::endl;

    return 0;
}
