#include <catch.hpp>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

TEST_CASE( "max", "[std] [algorithm] [min max]" ) {
    
    SECTION( "return max value" ) {
        int x = 0;
        int y = 1;

        const int max_value = max(x, y);

        REQUIRE( 1 == max_value );
    } 

    SECTION( "return max absolute value" ) {
        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const int abs_max_value = max(-10, 5, compare_abs);

        REQUIRE( -10 == abs_max_value );
    } 

    SECTION( "return max value as constexpr" ) {
        constexpr int max_value = max(0, 1);

        static_assert(1 == max_value, "max_value should be 1");
    }

    SECTION( "return max value in the initializer list" ) {
        const auto init_list = {1, 9, 3, 17}; 

        const int max_value = max(init_list);

        REQUIRE( 17 == max_value );
    }

    SECTION( "return max absolute value in the initializer list" ) {
        const auto init_list = {-100, 1, -9, 3, 17}; 

        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const int abs_max_value = max(init_list, compare_abs);

        REQUIRE( -100 == abs_max_value );
    }

    SECTION( "return max value in the initializer list as constexpr" ) {
        constexpr auto init_list = {1, 9, 3, 17}; 

        constexpr int max_value = max(init_list);

        static_assert(17 == max_value, "max_value should be 17");
    }

}

TEST_CASE( "max_element", "[std] [algorithm] [min max]" ) {
    
    SECTION( "return max element in the range" ) {
        const vector<int> vec{1, 9, 2, 10};

        const auto max_it = max_element(cbegin(vec), cend(vec));

        REQUIRE( 10 == *max_it );
    } 

    SECTION( "return absolute max element in the range" ) {
        const vector<int> vec{1, -15, 9, 2, 10};

        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const auto abs_max_it = max_element(cbegin(vec), cend(vec), compare_abs);

        REQUIRE( -15 == *abs_max_it );
    }

}

TEST_CASE( "min", "[std] [algorithm] [min max]" ) {
    
    SECTION( "return min value" ) {
        int x = 0;
        int y = 1;

        const int min_value = min(x, y);

        REQUIRE( 0 == min_value );
    } 

    SECTION( "return min absolute value" ) {
        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const int abs_min_value = min(-10, 5, compare_abs);

        REQUIRE( 5 == abs_min_value );
    } 

    SECTION( "return min value as constexpr" ) {
        constexpr int min_value = min(0, 1);

        static_assert(0 == min_value, "min_value should be 1");
    }

    SECTION( "return min value in the initializer list" ) {
        const auto init_list = {1, 9, 3, 17}; 

        const int min_value = min(init_list);

        REQUIRE( 1 == min_value );
    }

    SECTION( "return min absolute value in the initializer list" ) {
        const auto init_list = {-100, 1, -9, 3, 17}; 

        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const int abs_min_value = min(init_list, compare_abs);

        REQUIRE( 1 == abs_min_value );
    }

    SECTION( "return min value in the initializer list as constexpr" ) {
        constexpr auto init_list = {1, 9, 3, 17}; 

        constexpr int min_value = min(init_list);

        static_assert(1 == min_value, "min_value should be 17");
    }

}

TEST_CASE( "min_element", "[std] [algorithm] [min max]" ) {
    
    SECTION( "return min element in the range" ) {
        const vector<int> vec{5, 9, 2, 10};

        const auto min_it = min_element(cbegin(vec), cend(vec));

        REQUIRE( 2 == *min_it );
    } 

    SECTION( "return absolute min element in the range" ) {
        const vector<int> vec{1, -15, 9, 2, 10};

        auto compare_abs = [](int x, int y) { return abs(x) < abs(y); };

        const auto abs_min_it = min_element(cbegin(vec), cend(vec), compare_abs);

        REQUIRE( 1 == *abs_min_it );
    }

}