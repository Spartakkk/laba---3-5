#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "Main_One_List.cpp"

TEST_CASE() {

	OneList<int> line;
	
	REQUIRE(line.empty() == true);
	REQUIRE(line.size() == 0);
	//REQUIRE(line.front() == NULL);
	//REQUIRE(line.back() == nullptr);
}

TEST_CASE() {

	OneList<int> line;
	line.push_front(5);
	
	REQUIRE(line.front() == 5);
	REQUIRE(line.back() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_front(5);
	line.push_front(10);

	REQUIRE(line.front() == 10);
	REQUIRE(line.back() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);

	REQUIRE(line.front() == 5);
	REQUIRE(line.back() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(10);

	REQUIRE(line.front() == 5);
	REQUIRE(line.back() == 10);
}

TEST_CASE() {

	OneList<int> line;
	
	line.insert(0, 5);
	REQUIRE(line.front() == 5);

	line.push_back(10);
	line.insert(0, 10);
	REQUIRE(line.front() == 10);
	

}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(10);
	line.pop_front();
	
	REQUIRE(line.front() == 10);
	REQUIRE(line.back() == 10);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(10);
	line.pop_back();

	REQUIRE(line.front() == 5);
	REQUIRE(line.back() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(25);
	line.push_back(2);
	line.remove(25);
	REQUIRE(line.front() == 5);
	REQUIRE(line.back() == 2);

	line.push_back(3);
	line.remove(5);
	REQUIRE(line.front() == 2);
	REQUIRE(line.back() == 3);
	
	line.push_back(4);
	line.remove(4);
	
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);


	REQUIRE(line.front() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);


	REQUIRE(line.back() == 5);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(25);
	
	REQUIRE(line.size() == 2);
}

TEST_CASE() {

	OneList<int> line;
	line.push_back(5);
	line.push_back(25);

	REQUIRE(line[0]->data == 5);
	REQUIRE(line[1]->data == 25);
}


