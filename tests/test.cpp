#define private public
#include "note.h"
#include "rhythm.h"
#include <catch2/catch_test_macros.hpp>
#include <utility>

TEST_CASE("get 32nd note duration")
{
    Note note(Note::NoteType::thirty_second, false);
    REQUIRE( note.duration() == 6 );
}

TEST_CASE("get dotted 32nd note duration")
{
    Note note(Note::NoteType::thirty_second, true);
    REQUIRE( note.duration() == 9 );
}


TEST_CASE("get dotted whole note duration")
{
    Note note(Note::NoteType::whole, true);
    REQUIRE( note.duration() == 288 );
}

TEST_CASE("Orff Signature from 2/4")
{
    std::pair<int, Note> sig = orff_signature(2, 4);
    REQUIRE( sig.first == 2 );
    REQUIRE( sig.second.type == Note::NoteType::quarter );
    REQUIRE( !sig.second.dotted_ );
}

TEST_CASE("Orff Signature from 3/8")
{
    std::pair<int, Note> sig = orff_signature(3, 8);
    REQUIRE( sig.first == 3 );
    REQUIRE( sig.second.type == Note::NoteType::eighth );
    REQUIRE( !sig.second.dotted_ );
}

TEST_CASE("Orff Signature Simple Meter Invalid Bottom")
{
    REQUIRE_THROWS( orff_signature(2, 11) );
}

TEST_CASE("Orff Signature from 15/8")
{
    std::pair<int, Note> sig = orff_signature(15, 8);
    REQUIRE( sig.first == 5 );
    REQUIRE( sig.second.type == Note::NoteType::quarter );
    REQUIRE( sig.second.dotted_ );
}

TEST_CASE("Orff Signature Compound Meter Invalid Bottom")
{
    REQUIRE_THROWS( orff_signature(6, 5) );
}

TEST_CASE("Append valid bar")
{
    Note note(Note::NoteType::whole, false);
    RhythmicPiece::Bar bar = { note };
    RhythmicPiece rp(orff_signature(4,4));
    rp.append(bar);
    REQUIRE( rp.bars.size() == 1 );
}

TEST_CASE("Append invalid bar")
{
    Note wholenote(Note::NoteType::whole, false);
    RhythmicPiece::Bar too_big = { wholenote };
    RhythmicPiece rp1(orff_signature(2,4));
    REQUIRE_THROWS( rp1.append( too_big ) );

    Note halfnote(Note::NoteType::half, false);
    RhythmicPiece::Bar too_small = { halfnote };
    RhythmicPiece rp2(orff_signature(4,4));
    REQUIRE_THROWS( rp2.append( too_small ) );
}
