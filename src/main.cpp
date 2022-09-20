#include "rhythm.h"
#include "note.h"
#include "rhythm_io_facilities.h"
#include <iostream>
#include <utility>
#include <string_view>
#include <stdexcept>

int main(int argc, char* argv[])
{
    std::string current_bar {}; // for error reporting

    try {
        std::pair<int, int> time_sig = parse_time_sig(argv[1]);
        RhythmicPiece rp(orff_signature(time_sig.first, time_sig.second));
        RhythmicPiece::Bar bar {};

        for (int i = 2; i < argc; ++i) {
            if (std::string_view(argv[i]) == "/") {
                rp.append(bar);
                bar = {};
                current_bar = "";
            } else {
                bar.push_back(parse_note(std::string_view(argv[i])));
                current_bar += argv[i];
                current_bar += " ";
            }
        }

        std::cout << rp.write() << std::endl;
        return 0;
    }
    catch (parse_timesig_err e) {
        std::cerr << e.what() << "\"" << argv[1] << "\"" << std::endl;
        return 1;
    }
    catch (unsupported_timesig e) {
        std::cerr << e.what() << "\"" << argv[1] << "\"" << std::endl;
        return 2;
    }
    catch (bad_token e) {
        std::cerr << "Bad token: " << e.what() << std::endl;
        return 3;
    }
    catch (invalid_bar e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "/ " << current_bar << "/" << std::endl;
        return 4;
    }
}
