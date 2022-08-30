#define private public
#include "note.h"
#include "rhythm.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

using std::cout;
using std::endl;

TEST_CASE("write piece in 4/4")
{
    RhythmicPiece rp(orff_signature(4,4));

    SECTION( "16ths and dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        cout << rp.write() << endl;
    }

    SECTION( "quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false, true),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false, true),
        };
        rp.append(bar);
        cout << rp.write() << endl;
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
        cout << rp.write() << endl;
    }

    SECTION( "dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false)
        };
        rp.append(bar);
        cout << rp.write() << endl;
    }
}

TEST_CASE( "write piece in 3/4" )
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
    }
}

TEST_CASE( "write piece in 2/2 time signature" )
{
    RhythmicPiece rp(orff_signature(2,2));

    SECTION( "half notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::half, false),
            Note(Note::NoteType::half, false)
        };
        rp.append(bar);
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
    }
}

TEST_CASE("write piece in 6/8")
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
    }
}

TEST_CASE("write piece in 12/8")
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
    }
}
