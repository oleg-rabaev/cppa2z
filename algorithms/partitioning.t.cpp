#include <catch.hpp>
#include <vector>

using namespace std;

TEST_CASE( "is_partitioned(C++11)", "[std] [algorithm] [partitioning]" ) {
    
    SECTION( "the range is partitioned with first group less than 3" ) {
        const vector<int> vec{2, 0, 1,    3, 5, 4, 7};

        auto less_than_3 = [](int x) { return x < 3; };

        REQUIRE( is_partitioned(cbegin(vec), cend(vec), less_than_3) );
    } 

    SECTION( "the range is not partitioned with first group less than 3" ) {
        const vector<int> vec{3, 0, 1, 3, 5, 4, 7};

        auto less_than_3 = [](int x) { return x < 3; };

        REQUIRE_FALSE( is_partitioned(cbegin(vec), cend(vec), less_than_3) );
    }

}

TEST_CASE( "partition", "[std] [algorithm] [partitioning]" ) {
    
    SECTION( "partition the range with first group less than 3" ) {
        vector<int> vec{4, 2, 5, 3, 1, 0, 2};

        auto less_than_3 = [](int x) { return x < 3; };

        const auto first_it_in_second_group = partition(begin(vec), end(vec), less_than_3);

        REQUIRE( first_it_in_second_group != cend(vec) );
        REQUIRE( *first_it_in_second_group >= 3);

        REQUIRE( all_of(begin(vec), first_it_in_second_group, less_than_3) );
        REQUIRE( none_of(first_it_in_second_group, end(vec), less_than_3) );
    } 

    SECTION( "partition the range, there is only second group" ) {
        vector<int> vec{4, 7, 5, 3, 4, 4};

        auto less_than_3 = [](int x) { return x < 3; };

        const auto first_it_in_second_group = partition(begin(vec), end(vec), less_than_3);

        REQUIRE( first_it_in_second_group == cbegin(vec) );
    }

    SECTION( "partition the range, there is only first group" ) {
        vector<int> vec{1, 0, 2, 2, 1, 0};

        auto less_than_3 = [](int x) { return x < 3; };

        const auto first_it_in_second_group = partition(begin(vec), end(vec), less_than_3);

        REQUIRE( first_it_in_second_group == cend(vec) );
    }
}

TEST_CASE( "partition_copy(C++11)", "[std] [algorithm] [partitioning] [copy]" ) {

    SECTION( "copy the range partitioning elements into two groups" ) {
        const vector<int>    vec{4, 2, 5, 3, 1, 0, 2};
              vector<int>  first;
              vector<int> second;

        auto less_than_3 = [](int x) { return x < 3; };

        partition_copy(
              cbegin(vec)
            , cend(vec)
            , back_inserter(first)
            , back_inserter(second)
            , less_than_3
        );

        REQUIRE ( first.size() == 4 );
        REQUIRE ( all_of(cbegin(first), cend(first), less_than_3) );

        REQUIRE ( second.size() == 3 );
        REQUIRE ( none_of(cbegin(second), cend(second), less_than_3) );
    } 

}

TEST_CASE( "partition_point(C++11)", "[std] [algorithm] [partitioning]" ) {
    
    SECTION( "partition point found" ) {
        const vector<int> vec{2, 0, 1,   3, 5, 4, 7};

        auto less_than_3 = [](int x) { return x < 3; };

        const auto it = partition_point(cbegin(vec), cend(vec), less_than_3);

        REQUIRE ( it != cend(vec) );

        const auto partition_pos = distance(cbegin(vec), it);        
        REQUIRE ( partition_pos == 3 ); 
    } 

    SECTION( "all elements are less than 3" ) {
        const vector<int> vec{1, 2, 1, 0, 2};

        auto less_than_3 = [](int x) { return x < 3; };
        
        const auto it = partition_point(cbegin(vec), cend(vec), less_than_3);

        REQUIRE ( it == cend(vec) );
    }

}

TEST_CASE( "stable_partition", "[std] [algorithm] [partitioning] [copy]" ) {
    
    SECTION( "partition the range preserving original relative order of elements" ) {
              vector<int>    vec{4, 2, 5, 3, 1, 0, 2};
        const vector<int>  first{2, 1, 0, 2};
        const vector<int> second{4, 5, 3};

        auto less_than_3 = [](int x) { return x < 3; };

        const auto first_it_in_second_group = stable_partition(begin(vec), end(vec), less_than_3);
        
        bool first_as_expected = equal(cbegin(first), cend(first), cbegin(vec));
        REQUIRE ( first_as_expected  );

        bool second_as_expected = equal(cbegin(second), cend(second), first_it_in_second_group);
        REQUIRE ( first_as_expected  );
    } 

}
