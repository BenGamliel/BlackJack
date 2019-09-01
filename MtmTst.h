/*
* mtmtest.h
*/

#ifndef MTMTEST_H_
#define MTMTEST_H_

#include <fstream>
#include <iostream>
#include <sstream>

extern std::string location; // Used for finding the origin of an exception

#define FAIL(message) do { \
	std::ostringstream os; \
	os << __LINE__; \
	location = std::string(__FILE__) + ":" + os.str() + " " + message; \
	return false; \
} while (0)


#define ASSERT_EQUALS(expected,actual) do { \
if (!((expected) == (actual))) { \
	FAIL("values not equal"); \
} \
} while (0)
#define ASSERT_NO_THROW(command) do {\
	try { \
	(command); \
} \
catch (std::exception& e) { \
	FAIL("caught " + e.what()); \
} \
catch (...) { \
	FAIL("caught unknown object"); \
} \
} while (0)
#define ASSERT_THROW(exception_type,command) do {\
	try { \
	(command); \
	FAIL("missing exception"); \
	} \
	catch (exception_type&) { \
	} \
	catch (std::exception& e) { \
		FAIL("caught " + e.what()); \
	} \
	catch (...) { \
		FAIL("caught unknown object"); \
	} \
} while (0)
#define RUN_TEST(b) do {\
	try { \
	std::cerr << #b << ":"; \
		if (b()) std::cerr << "OK" << std::endl; \
		else std::cerr << "Failed (" << location << ")" << std::endl; \
		} \
		catch (...) { \
			std::cerr << "Failed (" << location << ")" << std::endl; \
		} \
	} while (0)
#define RUN_SETUP(c) do {\
	try { \
		if (!c) return false; \
	}\
	catch (...) { \
		return false; \
	} \
} while (0)

#define DEFINE_INPUT_TEST(b) bool b() { \
	std::ifstream input(std::string("input/") + #b + ".txt"); \
	if (!input) { \
		std::cerr << "input file missing" << std::endl; \
		return false; \
	}

#endif /* MTMTEST_H_ */
