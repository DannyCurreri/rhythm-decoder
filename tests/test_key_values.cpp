#define private public
#include "note.h"
#include "rhythm.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("4/4 time signature")
{
    RhythmicPiece rp(orff_signature(4,4));

    SECTION( "16ths and dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::quarter, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

}

TEST_CASE( "3/4 time signature" )
{
    RhythmicPiece rp(orff_signature(3,4));

    SECTION( "16th notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}

TEST_CASE( "2/2 time signature" )
{
    RhythmicPiece rp(orff_signature(2,2));

    SECTION( "half notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::half, false),
            Note(Note::NoteType::half, false)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::half, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::quarter, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::quarter, true),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}

TEST_CASE("6/8 time signature")
{
    RhythmicPiece rp(orff_signature(6,8));

    SECTION( "16th and dotted eighth note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "dotted eighth note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::eighth, true),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "quarter and eighth note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::quarter, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}

TEST_CASE("12/8 time signature")
{
    RhythmicPiece rp(orff_signature(12,8));

    SECTION( "dotted quarter note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "undotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eighth, false)
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::eighth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }

    SECTION( "16th and dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        Note correct_key(Note::NoteType::sixteenth, false);
        REQUIRE( rp.key() == correct_key.duration() );
    }
}
