#include "rhythm.h"
#include <stdexcept>

std::pair<int, Note> orff_signature(int top, int bottom)
{
    int beats_per_measure;
    Note::NoteType note_type;
    bool compound;

    if (top == 3 || top % 3 != 0) { // simple meter
        beats_per_measure = top;
        compound = false;
        switch (bottom) {
            case 2: note_type = Note::NoteType::half;    break;
            case 4: note_type = Note::NoteType::quarter; break;
            case 8: note_type = Note::NoteType::eigth;   break;
            default:
                throw(std::range_error("Unsupported time signature"));
        }
    } else { // compound meter
        beats_per_measure = top / 3;
        compound = true;
        switch (bottom) {
            case 8: note_type = Note::NoteType::quarter; break;
            default:
                throw(std::range_error("Unsupported time signature"));
        }
    }

    Note beat(note_type, compound);
    return std::make_pair(beats_per_measure, beat);
}

RhythmicPiece::RhythmicPiece(std::pair<int, Note> sig)
    :beats_per_measure{sig.first}, beat{sig.second}
{}

void RhythmicPiece::append(Bar bar)
{
    int sum = 0;
    for (auto& note: bar)
        sum += note.duration();
    if (sum != beat.duration() * beats_per_measure)
        throw(std::runtime_error("not a valid bar"));
    bars.push_back(bar);
}

int RhythmicPiece::key() const
{
    int beat_dur = beat.duration();
    int res = beat_dur;
    for (const auto& bar: bars) {
    for (const auto& note: bar) {
        int dur = note.duration();
        if (dur < beat_dur) {
            if (beat_dur % dur == 0)
                res = dur;
            else
                res = is_compound() ? dur / 2 : dur / 3;
        } else if (dur > beat_dur && dur % beat_dur != 0)
            res = is_compound() ? dur / 2 : dur / 3;
    }}
    return res;
}
