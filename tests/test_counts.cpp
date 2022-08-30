#define private public
#include "note.h"
#include "rhythm.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("count in 4/4")
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::four );
        REQUIRE( rp.counts()[0].second == 1 );
        REQUIRE( rp.counts()[1].second == 3 );
        REQUIRE( rp.counts()[2].second == 1 );
        REQUIRE( rp.counts()[3].second == 3 );
        REQUIRE( rp.counts()[4].second == 6 );
        REQUIRE( rp.counts()[5].second == 2 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::one );
        for (const auto& count: rp.counts())
            REQUIRE ( count.second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::two );
        for (const auto& count: rp.counts())
            REQUIRE ( count.second == 1 );
    }

    SECTION( "dotted quarter notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, true),
            Note(Note::NoteType::quarter, false)
        };
        rp.append(bar);
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::two );
        REQUIRE( rp.counts()[0].second == 3 );
        REQUIRE( rp.counts()[1].second == 3 );
        REQUIRE( rp.counts()[2].second == 2 );
    }
}

TEST_CASE( "count in 3/4" )
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::four );
        REQUIRE( rp.counts()[0].second == 1 );
        REQUIRE( rp.counts()[4].second == 2 );
    }
}

TEST_CASE( "count in 2/2 time signature" )
{
    RhythmicPiece rp(orff_signature(2,2));

    SECTION( "half notes" )
    {
        RhythmicPiece::Bar bar = {
            Note(Note::NoteType::half, false),
            Note(Note::NoteType::half, false)
        };
        rp.append(bar);
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::one );
        REQUIRE( rp.counts()[0].second == 1 );

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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::two );
        REQUIRE( rp.counts()[0].second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::four );
        REQUIRE( rp.counts()[0].second == 3 );
        REQUIRE( rp.counts()[1].second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::four );
        for (const auto& count: rp.counts()) {
            REQUIRE( count.second == 1 );
        }
    }
}

TEST_CASE("count in 6/8 time signature")
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::six );
        REQUIRE( rp.counts()[0].second == 3 );
        REQUIRE( rp.counts()[1].second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::six );
        REQUIRE( rp.counts()[0].second == 3 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::three );
        REQUIRE( rp.counts()[0].second == 2 );
        REQUIRE( rp.counts()[1].second == 1 );
    }
}

TEST_CASE("count in 12/8 time signature")
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::three );
        REQUIRE( rp.counts()[0].second == 3 );
        REQUIRE( rp.counts()[1].second == 3 );
        REQUIRE( rp.counts()[2].second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::three );
        for (const auto& count: rp.counts()) {
            REQUIRE( count.second == 1 );
        }
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::three );
        REQUIRE( rp.counts()[0].second == 2 );
        REQUIRE( rp.counts()[1].second == 1 );
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
        REQUIRE( rp.count_system() == RhythmicPiece::CountSystem::six );
        REQUIRE( rp.counts()[0].second == 2 );
        REQUIRE( rp.counts()[1].second == 3 );
        REQUIRE( rp.counts()[2].second == 1 );
    }
}
