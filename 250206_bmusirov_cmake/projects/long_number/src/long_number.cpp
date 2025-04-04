#include "long_number.hpp"

using mbr::LongNumber;
		
LongNumber::LongNumber() {			// Конструктор по умолчанию
	numbers = nullptr;
	length = 0;
	sign = 0;
}

LongNumber::LongNumber(const char* const str) {	
	// Конструктор из строки

	if (!str) {
		numbers = nullptr;
		length = 0;
		sign = 0;
		return;
	}

	int pos = 0;
	if (str[0] == '-') {
		sign = -1;
		++pos;
	} else if (str[0] == '+') {
		sign = 1;
		++pos;
	} else {
		sign = 1;
	}

	while (str[pos] == '0' and str[pos + 1] != '\0') pos++;

	length = 0;
	for (int i = pos; str[i] != '\0'; ++i) ++length;
	numbers = new int[length];

	int start = pos;
	for (int i = length - 1; i >= 0; --i) {
		numbers[start++] = str[i] - '0';
	}

}

LongNumber::LongNumber(const LongNumber& x) {		// Конструктор копирования
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; ++i) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {			// Конструктор перемещения
	numbers = x.numbers;
    length = x.length;
    sign = x.sign;
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 0;
}

LongNumber::~LongNumber() {			// Деструктор
	delete[] numbers;
}

LongNumber& LongNumber::operator = (const char* const str) {	// Оператор присваивания для строки
	// TODO
}

LongNumber& LongNumber::operator = (const LongNumber& x) {		// Оператор присваивания
	// TODO
}

LongNumber& LongNumber::operator = (LongNumber&& x) {			// Оператор перемещения
	// TODO
}

bool LongNumber::operator == (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator != (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator > (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator < (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	return numbers[length-rank];
}

bool LongNumber::is_negative() const noexcept {
	return (sign < 0);
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	// TODO
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace mbr {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {			// Оператор вывода
		if (x.sign == -1) {
			os << '-';
		}
		for (int i = x.length - 1; i >= 0; i--) {
			os << x.numbers[i];
		}
		return os;
	}
}
