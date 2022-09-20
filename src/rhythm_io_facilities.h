#ifndef RHYTHM_IO_FACILITIES
#define RHYTHM_IO_FACILITIES

#include "rhythm.h"
#include "note.h"
#include <string>
#include <string_view>

std::pair<int, int> parse_time_sig(std::string);
Note parse_note(std::string_view);

class parse_timesig_err : public std::exception {
public:
    const char* what() {
        return "Could not parse time signature from string ";
    }
};

class bad_token : public std::exception {
public:
    bad_token(std::string_view token) :token{token} {}
    std::string_view what() {
        return token;
    }
private:
    std::string_view token;
};

#endif

