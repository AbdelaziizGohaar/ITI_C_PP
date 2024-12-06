#include <iostream>
#include <cstring>
using namespace std;

class String_O {
private:
    char *str;
    char *ptrBegin;
    char *ptrCurrent;
    char *ptrEnd;
    int arrSize;

public:
    String_O() {
        str = NULL;
        ptrBegin = NULL;
        ptrCurrent = NULL;
        ptrEnd = NULL;
        arrSize = 0;
    }

//////////////////////////////////////// Copy Constructor
    String_O(String_O& s)   {
        arrSize = s.arrSize;
        if (arrSize > 0) {
            str = new char[arrSize + 1]; 
            for (int i = 0; i < arrSize; ++i) {
                str[i] = s.str[i];
            }
            str[arrSize] = '\0'; 
        } else {
            str = NULL;
        }

        ptrBegin = str;
        ptrCurrent = str;
        ptrEnd = str + arrSize;
    }


    ~String_O() {
        delete[] str;
    }

    int getLength() {
        return arrSize;
    }

    void print() {
        if (ptrBegin == NULL || arrSize == 0) {
            cout << "String is empty!" << endl;
            return;
        }
        for (int i = 0; i < arrSize; ++i) {
            cout << ptrBegin[i];
        }
        cout << endl;
    }

    void StringConcat(char *newStr) {
        int appendSize = stringLength(newStr);
        int newSize = arrSize + appendSize;

        char *newBuffer = new char[newSize + 1]; // +1 for null terminator

        // Copy old string data
        if (str != NULL) {
            for (int i = 0; i < arrSize; ++i) {
                newBuffer[i] = ptrBegin[i];
            }
        }

        // Append new string data
        for (int i = 0; i < appendSize; ++i) {
            newBuffer[arrSize + i] = newStr[i];
        }

        newBuffer[newSize] = '\0'; // Null terminate

        // Delete old memory and update pointers
        delete[] str;
        str = newBuffer;
        ptrBegin = str;
        ptrCurrent = str + arrSize;
        ptrEnd = str + newSize;
        arrSize = newSize;
    }

    void toLower() {
        if (ptrBegin == NULL) return;

        ptrCurrent = ptrBegin;
        for (int i = 0; i < arrSize; ++i) {
            if (ptrCurrent[i] >= 'A' && ptrCurrent[i] <= 'Z') {
                ptrCurrent[i] += 32;
            }
        }
    }

    void toUpper() {
        if (ptrBegin == NULL) return;

        ptrCurrent = ptrBegin;
        for (int i = 0; i < arrSize; ++i) {
            if (ptrCurrent[i] >= 'a' && ptrCurrent[i] <= 'z') {
                ptrCurrent[i] -= 32;
            }
        }
    }


    int stringLength(const char *s) {
        int length = 0;
        while (s[length] != '\0') {
            ++length;
        }
        return length;
    }



    void copyString(char *sourceStr) {
    int newSize = stringLength(sourceStr);

    // Resize the array if needed
    if (newSize >= arrSize) {
        char *newBuffer = new char[newSize + 1]; // +1 for null terminator

        if (str != NULL) {
            delete[] str; // Delete old buffer
        }

        str = newBuffer;
        ptrBegin = str;
        ptrCurrent = ptrBegin;
        ptrEnd = ptrBegin + newSize;
        arrSize = newSize;
    }

    // Copy characters
    for (int i = 0; i < newSize; ++i) {
        ptrBegin[i] = sourceStr[i];
    }

    ptrBegin[newSize] = '\0'; // Null terminate the string
}

int strCompare(String_O &other) {
    if (arrSize != other.arrSize) {
        return arrSize < other.arrSize ? -1 : 1;
    }

    for (int i = 0; i < arrSize; ++i) {
        if (ptrBegin[i] != other.ptrBegin[i]) {
            return ptrBegin[i] < other.ptrBegin[i] ? -1 : 1;
        }
    }

    return 0; /////////////// Strings are equal
}


//////////////////////////////////////// Comparison operators in String_O class
bool operator==(String_O &s) {
    return strCompare(s) == 0;
}

bool operator!=(String_O &s) {
    return strCompare(s) != 0;
}

bool operator<(String_O &s) {
    return strCompare(s) < 0;
}

bool operator<=(String_O &s) {
    return strCompare(s) <= 0;
}

bool operator>(String_O &s) {
    return strCompare(s) > 0;
}

bool operator>=(String_O &s) {
    return strCompare(s) >= 0;
}


 };


int main() {


    String_O Goo;

///////////////////////////////////////////////////////copystring method
    cout << "testing copystring m:" << endl;
    Goo.copyString("Hello");
    Goo.print();

////////////////////////////////////////////////////// stringConcat method
    cout << "testing  Concating method:" << endl;
    Goo.StringConcat(", World!");
    Goo.print();

////////////////////////////////////////////////////////////toupper
    cout << "testing changing toupper " << endl;
    Goo.toUpper();
    Goo.print();

////////////////////////////////////////////////////////////tolower method
    cout << "testing toLower method:" << endl;
    Goo.toLower();
    Goo.print();

///////////////////////////////////////////////////////////////// getLength
    cout << "test  getLength method:" << endl;
    cout << "Length of this Goo string is  " << Goo.getLength() << endl;

/////////////////////////////////////////////////////////////////comparison
    String_O zezo;
    zezo.copyString("Hello, world!");

    cout << "Testing strCompare method:" << endl;
    int comparisonResult = Goo.strCompare(zezo);
    if (comparisonResult == 0) {
        cout << "Strings are equal." << endl;
    } else if (comparisonResult < 0) {
        cout << "First string is less than the second string." << endl;
    } else {
        cout << "First string is greater than the second string." << endl;
    }

    return 0;
}
