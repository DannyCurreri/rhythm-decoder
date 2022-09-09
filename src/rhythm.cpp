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
            case 8: note_type = Note::NoteType::eighth;   break;
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
    // SPECIAL CASE: full measure whole note rest.
    // A whole note rest can represent a full measure rest
    // in different time signatures, so its duration is not
    // necessarily equal to a whole note's usual duration.
    // We can thank Bach for this complication.
    if (bar.size() == 1
            && bar[0].type() == Note::NoteType::whole
            && bar[0].rest()) {
        Bar full_measure_rest;
        for (int i = 0; i != beats_per_measure; ++i) {
            full_measure_rest.push_back(
                {Note(beat.type(), is_compound(), true)});
        }
        bars.push_back(full_measure_rest);
        return;
    }

    // General case: not a whole note rest
    int sum = 0;
    for (auto& note: bar)
        sum += note.duration();
    if (sum != beat.duration() * beats_per_measure)
        throw(std::runtime_error("not a valid bar"));
    bars.push_back(bar);
}

RhythmicPiece::CountSystem RhythmicPiece::count_system() const
{
    switch (beat.duration() / key()) {
        case 1: return CountSystem::one;
        case 2: return CountSystem::two;
        case 3: return CountSystem::three;
        case 4: return CountSystem::four;
        case 6: return CountSystem::six;
        default:
            throw std::runtime_error(
                "Cannot determine a valid count system for this piece");
    }
}

std::vector<std::pair<bool, int>> RhythmicPiece::counts() const
{
    std::vector<std::pair<bool, int>> res;
    auto key_ = key();
    for (const auto& bar: bars) {
    for (const auto& note: bar) {
        int count = note.duration() / key_;
        res.push_back(std::make_pair(!note.rest(), count));
    }}
    return res;
}

int RhythmicPiece::key() const
{
    if (is_compound()) return compound_key();
    return simple_key();
}

int RhythmicPiece::compound_key() const
{
    int beat_dur = beat.duration();
    int res = beat_dur;
    for (const auto& bar: bars) {
    for (const auto& note: bar) {
        int dur = note.duration();
        if (dur < res) {
            if (beat_dur % dur == 0) {
                // for dotted eighth notes in a compound meter, the
                // duration evenly divides the beat but this should *not*
                // be the key note.
                // this is an unideal solution.
                if (note.dotted())
                    res = dur / 3;
                else
                    res = dur;
            }
            else
                res = dur / 2;
        } else if (dur > beat_dur && dur % beat_dur != 0) {
            res = (dur / 2 < res) ? dur / 2 : res;
        }
    }}
    return res;
}

int RhythmicPiece::simple_key() const
{
    int beat_dur = beat.duration();
    int res = beat_dur;
    for (const auto& bar: bars) {
    for (const auto& note: bar) {
        int dur = note.duration();
        if (dur < res) {
            if (beat_dur % dur == 0) {
                res = dur;
            }
            else
                res = dur / 3;
        } else if (dur > beat_dur && dur % beat_dur != 0) {
            res = (dur / 3 < res) ? dur / 3 : res;

        }
    }}
    return res;
}
