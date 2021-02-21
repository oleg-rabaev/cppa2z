// back_inserter
// front_inserter
// inserter
// make_move_iterator
// make_reverse_iterator

#include <catch.hpp>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <set>
#include <list>
#include <deque>

using namespace std;

TEST_CASE( "back_inserter", "[std] [iterator] [adaptor]" ) {
    
    SECTION( "insert values at the end of the vector" ) {
              vector<int>       to;
        const vector<int> expected{1, 2, 3};

        auto output_it = back_inserter(to);

        *output_it = 1;
        *output_it = 2;
        *output_it = 3;

        REQUIRE( to == expected );
    }

    SECTION( "insert values at the end of the vector using copy algorithm" ) {
        const vector<int>     from{1, 2, 3};
              vector<int>       to;
        const vector<int> expected{1, 2, 3};

        auto output_it = back_inserter(to);

        copy(cbegin(from), cend(from), output_it);

        REQUIRE( to == expected );
    }

}

TEST_CASE( "front_inserter", "[std] [iterator] [adaptor]" ) {
    
    SECTION( "insert values at the front of the dequeu" ) {
              deque<int>         to;
        const deque<int>   expected{3, 2, 1};

        auto output_it = front_inserter(to);

        *output_it = 1;
        *output_it = 2;
        *output_it = 3;

        REQUIRE( to == expected );
    }

    SECTION( "copy values from vector to list in reverse order" ) {
        const vector<int>   from{1, 2, 3};
              list<int>       to;
        const list<int> expected{3, 2, 1};

        auto output_it = front_inserter(to);

        copy(cbegin(from), cend(from), output_it);

        REQUIRE( to == expected );
    }
    
}

TEST_CASE( "inserter", "[std] [iterator] [adaptor]" ) {
    
    SECTION( "insert values into the set using insert_iterator" ) {
        const vector<int>     from{3, 4, 2, 5, 1};
              set<int>          to;
        const set<int>    expected{1, 2, 3, 4, 5};

        auto output_it = inserter(to, end(to));

        copy(cbegin(from), cend(from), output_it);

        REQUIRE( to == expected );
    } 

    SECTION( "insert values into the list using insert_iterator" ) {
        const vector<int>     from{1, 2, 3, 4, 5};
              list<int>         to;
        const list<int>   expected{1, 2, 3, 4, 5};

        auto output_it = inserter(to, end(to));

        copy(cbegin(from), cend(from), output_it);

        REQUIRE( to == expected );
    }

    SECTION( "insert values into the middle of list using insert_iterator" ) {
        const vector<int>     from{   2, 3, 4   };
              list<int>         to{1,          5};
        const list<int>   expected{1, 2, 3, 4, 5};

        auto insert_after = next(begin(to));
        auto output_it = inserter(to, insert_after);

        copy(cbegin(from), cend(from), output_it);

        REQUIRE( to == expected );
    }

}

TEST_CASE( "make_move_iterator", "[std] ] [iterator] [adaptor]") {
    
    SECTION( "use move iterator to move(copy) strings from one vector to another" ) {
              vector<string>     from{"one", "two", "three"};
              vector<string>       to;
        const vector<string> expected{"one", "two", "three"};

        copy(
	     make_move_iterator(begin(from))
           , make_move_iterator(end(from))
           , back_inserter(to)
        );

        REQUIRE( to == expected );
        REQUIRE( 3 == from.size() );
    } 

}

TEST_CASE( "make_reverse_iterator", "[std] ] [iterator] [adaptor]" ) {
    
    SECTION( "use move iterator to move(copy) strings from one vector to another" ) {
        const vector<int>     vec{1, 2, 3};
        
        auto reverse_it = make_reverse_iterator(end(vec));

        REQUIRE( 3 == *reverse_it );

        ++reverse_it;
        REQUIRE( 2 == *reverse_it );

        ++reverse_it;
        REQUIRE( 1 == *reverse_it );
    } 

}
