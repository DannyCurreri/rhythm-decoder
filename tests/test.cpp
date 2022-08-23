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
    REQUIRE( !sig.second.dotted );
}

TEST_CASE("Orff Signature from 3/8")
{
    std::pair<int, Note> sig = orff_signature(3, 8);
    REQUIRE( sig.first == 3 );
    REQUIRE( sig.second.type == Note::NoteType::eigth );
    REQUIRE( !sig.second.dotted );
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
    REQUIRE( sig.second.dotted );
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

TEST_CASE("Calculate correct key value for a compound meter")
{
    RhythmicPiece rp(orff_signature(12,8));

    SECTION( "key is eighth note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::eigth, false),
            Note(Note::NoteType::eigth, false),
            Note(Note::NoteType::eigth, false),
            Note(Note::NoteType::quarter, true)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eigth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "contains undotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, true)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eigth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
    SECTION( "key is equal to beat" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::quarter, true);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}

TEST_CASE("Calculate correct key value for a simple meter")
{
    RhythmicPiece rp(orff_signature(4,4));

    SECTION( "handles dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eigth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "handles dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eigth, true),
            Note(Note::NoteType::eigth, true),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eigth, true),
            Note(Note::NoteType::eigth, true),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}
