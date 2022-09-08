#include "note.h"
#include "rhythm.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

TEST_CASE("write piece in 4/4")
{
    RhythmicPiece rp(orff_signature(4,4));
    string EXPECTED;

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
        EXPECTED += "1 e + a 2 e + a 3 e + a 4 e + a ||\n";
        EXPECTED += "X X       X     X           X   ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1 2 3 4 ||\n";
        EXPECTED += "X   X   ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false)
        };
        rp.append(bar);
        EXPECTED += "1 + 2 + 3 + 4 + ||\n";
        EXPECTED += "X     X     X   ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1 + 2 + 3 + 4 + ||\n";
        EXPECTED += "X X X X X X X X ||";
        REQUIRE( rp.write() == EXPECTED );
    }

}

TEST_CASE( "write piece in 3/4" )
{
    RhythmicPiece rp(orff_signature(3,4));
    string EXPECTED;

    SECTION( "16th notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false)
        };
        rp.append(bar);
        EXPECTED += "1 e + a 2 e + a 3 e + a ||\n";
        EXPECTED += "X X   X   X   X   X   X ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 2/2 time signature" )
{
    RhythmicPiece rp(orff_signature(2,2));
    string EXPECTED;

    SECTION( "half notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::half, false, true),
            Note(Note::NoteType::half, false)
        };
        rp.append(bar);
        EXPECTED += "1 2 ||\n";
        EXPECTED += "  X ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "quarter notes with rests" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false, true),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false, true),
        };
        rp.append(bar);
        EXPECTED += "1 + 2 + ||\n";
        EXPECTED += "X   X   ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1 e + a 2 e + a ||\n";
        EXPECTED += "X     X X X     ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1 + 2 + ||\n";
        EXPECTED += "X X X X ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1 e + a 2 e + a ||\n";
        EXPECTED += "X X X X X X X X ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE("write piece in 6/8")
{
    RhythmicPiece rp(orff_signature(6,8));
    string EXPECTED;

    SECTION( "dotted quarter note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
        };
        rp.append(bar);
        EXPECTED += "1 2 ||\n";
        EXPECTED += "X X ||";
        REQUIRE( rp.write() == EXPECTED );
    }

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
        EXPECTED += "1  d  la d  li d  2  d  la d  li d  ||\n";
        EXPECTED += "X        X  X  X  X  X  X  X  X  X  ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1  d  la d  li d  2  d  la d  li d  ||\n";
        EXPECTED += "X        X        X        X        ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1  la li 2  la li ||\n";
        EXPECTED += "X     X  X  X     ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE("write piece in 12/8")
{
    RhythmicPiece rp(orff_signature(12,8));
    string EXPECTED;

    SECTION( "dotted quarter note" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1  la li 2  la li 3  la li 4  la li ||\n";
        EXPECTED += "X                 X  X  X  X     X  ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1  la li 2  la li 3  la li 4  la li ||\n";
        EXPECTED += "X     X     X  X     X     X     X  ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "undotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::quarter, false),
            Note(Note::NoteType::eighth, false)
        };
        rp.append(bar);
        EXPECTED += "1  la li 2  la li 3  la li 4  la li ||\n";
        EXPECTED += "X     X     X  X     X     X     X  ||";
        REQUIRE( rp.write() == EXPECTED );
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
        EXPECTED += "1  d  la d  li d  2  d  la d  li d  3  d  la d  li d  4  d  la d  li d  ||\n";
        EXPECTED += "X     X        X  X     X        X  X        X        X  X  X  X  X     ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 2/4" )
{
    RhythmicPiece rp(orff_signature(2,4));
    string EXPECTED;

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1 + 2 + ||\n";
        EXPECTED += "X X X X ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "16th and dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
        };
        rp.append(bar);
        EXPECTED += "1 e + a 2 e + a ||\n";
        EXPECTED += "X     X X X     ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 5/4" )
{
    RhythmicPiece rp(orff_signature(5,4));
    string EXPECTED;

    SECTION( "16th and eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1 e + a 2 e + a 3 e + a 4 e + a 5 e + a ||\n";
        EXPECTED += "X   X X X X X     X X     X   X   X X   ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 15/8" )
{
    RhythmicPiece rp(orff_signature(15,8));
    string EXPECTED;

    SECTION( "16th and dotted eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, true),
            Note(Note::NoteType::sixteenth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1  d  la d  li d  2  d  la d  li d  3  d  la d  li d  4  d  la d  li d  5  d  la d  li d  ||\n";
        EXPECTED += "X  X  X  X     X  X                                   X  X  X        X  X     X     X     ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 9/8" )
{
    RhythmicPiece rp(orff_signature(9,8));
    string EXPECTED;

    SECTION( "eighth notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::quarter, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false, true),
            Note(Note::NoteType::eighth, false),
            Note(Note::NoteType::eighth, false),
        };
        rp.append(bar);
        EXPECTED += "1  la li 2  la li 3  la li ||\n";
        EXPECTED += "X              X     X  X  ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "dotted notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::half, true),
            Note(Note::NoteType::quarter, true),
        };
        rp.append(bar);
        EXPECTED += "1 2 3 ||\n";
        EXPECTED += "X   X ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}

TEST_CASE( "write piece in 3/2" )
{
    RhythmicPiece rp(orff_signature(3,2));
    string EXPECTED;

    SECTION( "rest" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::whole, false, true),
        };
        rp.append(bar);
        EXPECTED += "1 2 3 ||\n";
        EXPECTED += "      ||";
        REQUIRE( rp.write() == EXPECTED );
    }

    SECTION( "eighth and quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::eighth),
            Note(Note::NoteType::quarter),
            Note(Note::NoteType::eighth),
            Note(Note::NoteType::eighth),
            Note(Note::NoteType::quarter),
            Note(Note::NoteType::eighth),
            Note(Note::NoteType::eighth),
            Note(Note::NoteType::quarter),
            Note(Note::NoteType::eighth),
        };
        rp.append(bar);
        EXPECTED += "1 e + a 2 e + a 3 e + a ||\n";
        EXPECTED += "X X   X X X   X X X   X ||";
        REQUIRE( rp.write() == EXPECTED );
    }
}
