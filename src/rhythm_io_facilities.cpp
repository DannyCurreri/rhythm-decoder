#include "rhythm.h"
#include "note.h"
#include <string>
#include <string_view>
#include <utility>
#include <iostream>

using std::string;
using std::cin;

const string one_count = " ";
const string two_count = " + ";
const string four_count = " e + a ";
const string three_count = "~ la li ";
const string six_count = "~ d~ la d~ li d~ ";

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
        res.pop_back(); // remove empty space after last count in bar
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

        int spaces = (subcounts == three_count || subcounts == six_count) ? 3 : 2;
        for (int i = 0; i != spaces * count.second - 1; ++i)
            res += " ";
    }
    res.pop_back(); // remove empty space after last count in bar
    res += "||";

    return res;
}

std::pair<int, int> parse_time_sig(string time_sig)
{
    string s1 {};
    string s2 {};
    int index {};

    for (index; index < time_sig.size(); ++index) {
        if (time_sig[index] != '/')
            s1 += time_sig[index];
        else {
            s2 = time_sig.substr(index + 1);
            break;
        }
    }

    int top = std::stoi(s1);
    int bottom = std::stoi(s2);

    return std::make_pair(top, bottom);
}

Note parse_note(std::string_view note) {
    if (note == "w") return Note(Note::NoteType::whole);
    if (note == "h") return Note(Note::NoteType::half);
    if (note == "q") return Note(Note::NoteType::quarter);
    if (note == "e") return Note(Note::NoteType::eighth);
    if (note == "s") return Note(Note::NoteType::sixteenth);

    if (note == "w.") return Note(Note::NoteType::whole, true);
    if (note == "h.") return Note(Note::NoteType::half, true);
    if (note == "q.") return Note(Note::NoteType::quarter, true);
    if (note == "e.") return Note(Note::NoteType::eighth, true);
    if (note == "s.") return Note(Note::NoteType::sixteenth, true);

    if (note == "rw") return Note(Note::NoteType::whole, false, true);
    if (note == "rh") return Note(Note::NoteType::half, false, true);
    if (note == "rq") return Note(Note::NoteType::quarter, false, true);
    if (note == "re") return Note(Note::NoteType::eighth, false, true);
    if (note == "rs") return Note(Note::NoteType::sixteenth, false, true);

    if (note == "rw.") return Note(Note::NoteType::whole, true, true);
    if (note == "rh.") return Note(Note::NoteType::half, true, true);
    if (note == "rq.") return Note(Note::NoteType::quarter, true, true);
    if (note == "re.") return Note(Note::NoteType::eighth, true, true);
    if (note == "rs.") return Note(Note::NoteType::sixteenth, true, true);

    throw std::runtime_error("invalid token");
}
