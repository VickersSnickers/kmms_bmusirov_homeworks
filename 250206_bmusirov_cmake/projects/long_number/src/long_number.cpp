#include <iostream>
#include "long_number.hpp"
using mbr::LongNumber;
		
LongNumber::LongNumber() {			// Конструктор по умолчанию
	numbers = nullptr;
	length = 0;
	sign = 0;
}

LongNumber::LongNumber(const char* const str) {		// Конструктор из строки
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

	length = get_length(str);
	numbers = new int[length];

	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = str[length - 1 - i + pos] - '0';
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

LongNumber::~LongNumber() {	
    if (numbers) {		// Деструктор
	    delete[] numbers;
    }
    numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {	// Оператор присваивания для строки
    if (numbers) {		// Деструктор
	    delete[] numbers;
    }

	if (!str) {
		numbers = nullptr;
		length = 0;
		sign = 0;
		return *this;
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

	length = get_length(str);
	numbers = new int[length];

	for (int i = length - 1; i >= 0; --i) {
		numbers[i] = str[length - 1 - i + pos] - '0';
	}
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {	
    if (*this == x) return;
    // Оператор присваивания
    
    if (numbers) {
	    delete[] numbers;
    }

	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; ++i) {
		numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
    if (numbers) {
	    delete[] numbers;
    }
    
	numbers = x.numbers;
    length = x.length;
    sign = x.sign;
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 0;

	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (length != x.length or sign != x.sign) return false;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) return false;
    }
    return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return not(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign > x.sign) return true;
	if (sign > x.sign) return false;
	if (length > x.length) return (sign == 1);
    if (length < x.length) return (sign == -1);
    
    for (int i = length - 1; i >= 0; --i) {
        if (numbers[i] > x.numbers[i]) return (sign == 1);
        if (numbers[i] < x.numbers[i]) return (sign == -1);
    }
    return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return not(*this > x or *this == x);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign == 0) return x;
    if (x.sign == 0) return *this;
    
    if (sign == x.sign) {
		int newlen;
		if (length > x.length) {
			newlen = length;
		} else {
			newlen = x.length;
		}

        int* res = new int[newlen + 1]();
        int forward = 0;
        
        for (int i = 0; i < newlen; ++i) {
			int a = 0, b = 0;
			if (i < length) {
				a = numbers[i];
			} else {
                a = 0;
            }

            if (i < x.length) {
                b = x.numbers[i];
			} else {
                b = 0;
            }
            
            int sum = a + b + forward;
            res[i] = sum % 10;
            forward = sum / 10;
        }
        
        if (forward > 0) {
            res[newlen] = forward;
            newlen++;
        }
        
        LongNumber temp;
        temp.numbers = res;
        temp.length = newlen;
        temp.sign = sign;
        
        return temp;

    } else {
        if (sign == -1) {
            LongNumber temp = *this;
            temp.sign = 1;
            return x - temp;
        } else {
            LongNumber temp = x;
            temp.sign = 1;
            return *this - temp;
        }
		
    }
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (sign == 0) {
        LongNumber temp = x;
        temp.sign = -temp.sign;
        return temp;
    }
    if (x.sign == 0) return *this;
    
    if (sign == x.sign) {
        if (*this == x) return LongNumber("0");
        
        bool bigger = true;
        if (length != x.length) {
            bigger = (length > x.length);
        } else {
            for (int i = length - 1; i >= 0; --i) {
                if (numbers[i] != x.numbers[i]) {
                    bigger = (numbers[i] > x.numbers[i]);
                    break;
                }
            }
        }
		const LongNumber* a;
		const LongNumber* b;
        if (bigger) {
			a = this;
			b = &x;
		} else {
			a = &x;
			b = this;
		}
        
        int newlen = a->length;
        int* res = new int[newlen]();
        int backward = 0;
        
		int num1 = 0, num2 = 0;
        for (int i = 0; i < newlen; ++i) {

			if (i < a->length) {
				num1 = a->numbers[i];
			} else {
				num1 = 0;
			}

			if (i < b->length) {
				num2 = b->numbers[i];
			} else {
				num2 = 0;
			}
            int diff = num1 - num2 - backward;
            
            if (diff < 0) {
                diff += 10;
                backward = 1;
            } else {
                backward = 0;
            }
            
            res[i] = diff;
        }
        
        while (newlen > 1 and res[newlen - 1] == 0) {
            newlen--;
        }
        
        LongNumber temp;
        temp.numbers = res;
        temp.length = newlen;
		if (bigger) {
			temp.sign = sign;
		} else {
			temp.sign = -sign;
		}
        
        return temp;

    } else {
        LongNumber temp = x;
        temp.sign = sign;
        return *this + temp;
    }
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
    if (sign == 0 or x.sign == 0) {
        return LongNumber("0");
    }

    int newlen = length + x.length;
    int* res = new int[newlen]();

    for (int i = 0; i < length; ++i) {
        int forward = 0;
        for (int j = 0; j < x.length; ++j) {
            int product = numbers[i] * x.numbers[j] + res[i + j] + forward;
            forward = product / 10;
            res[i + j] = product % 10;
        }
        if (forward > 0) {
            res[i + x.length] += forward;
        }
    }

    int new_len = newlen;
    while (new_len > 1 and res[new_len - 1] == 0) {
        new_len--;
    }

    LongNumber result;
    result.numbers = res;
    result.length = new_len;
    result.sign = sign * x.sign;

    return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    if (sign == 0) {
        return LongNumber("0");
    }
    
    LongNumber dividend = *this;
    dividend.sign = 1;
    LongNumber divisor = x;
    divisor.sign = 1;
    
    if (dividend < divisor) {
        return LongNumber("0");
    }
    
    LongNumber quotient("0"); 
    LongNumber remainder("0");
    LongNumber ten("10");
    
    for (int i = dividend.length - 1; i >= 0; --i) {
        remainder = remainder * ten;
        
        LongNumber now;
        now.numbers = new int[1]{dividend.numbers[i]};
        now.length = 1;
        now.sign = 1;
        
        remainder = remainder + now;
        
        int digit = 0;
        while (remainder > divisor or remainder == divisor) {
            remainder = remainder - divisor;
            digit++;
        }
        
        quotient = quotient * ten;
        
        LongNumber digitNum;
        digitNum.numbers = new int[1]{digit};
        digitNum.length = 1;
        digitNum.sign = 1;
        
        quotient = quotient + digitNum;
    }
    
    while (quotient.length > 1 and quotient.numbers[quotient.length - 1] == 0) {
        quotient.length--;
    }
    
    quotient.sign = sign * x.sign;
    
    return quotient;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	if (sign == 0) {
        return LongNumber("0");
    }


	LongNumber div = *this / x;
	LongNumber res = *this - div * x;

    if (res < 0) {
        if (x > 0) res = res + x;
        if (x < 0) res = res - x;
    }

	return res;
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	if (rank < 1) return -1;
	return numbers[length-rank];
}

bool LongNumber::is_negative() const noexcept {
	return (sign < 0);
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int pos = 0;
	if (str[0] == '-' or str[0] == '+') {
		++pos;
	}

	while (str[pos] == '0' and str[pos + 1] != '\0') pos++;

	int len = 0;
	for (int i = pos; str[i] != '\0'; ++i) ++len;

	return len;
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
