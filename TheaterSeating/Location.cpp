#include "stdafx.h"
#include "Location.h"

#include <sstream>

using namespace std;

static void skipWhile(istream& stream, const char ch) {
	while (stream.peek() == ch) {
		stream.ignore();
	}
}

static void throwParseException(const streamoff position) {
	ostringstream errorMessage;
	errorMessage << "Error processing content at index #";
	errorMessage << position;
	errorMessage << ".";

	throw ParseException(errorMessage.str());
}

/// <summary>
/// Parses the specified location.
/// </summary>
/// <param name="location">The location.</param>
/// <returns></returns>
Location Location::parse(const std::string& location) {
	stringstream stream(location);
	int row;
	int col;
	streamoff posn;

	skipWhile(stream, ' ');

	posn = stream.tellg();
	if (!(stream >> row)) {
		throwParseException(posn);
	}

	skipWhile(stream, ' ');
	skipWhile(stream, ',');
	skipWhile(stream, ' ');

	posn = stream.tellg();
	if (!(stream >> col)) {
		throwParseException(posn);
	}

	return Location(row, col);
}

/// <summary>
/// Overloads the stream redirection operator.
/// </summary>
/// <param name="stream">The stream.</param>
/// <param name="location">The location.</param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& stream, const Location& location) {
	stream << location.getRow() << "," << location.getColumn();
	return stream;
}

