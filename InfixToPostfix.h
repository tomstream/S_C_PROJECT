#include <string>
#include <stack>
using namespace std;

string infixToPostfix(string s);

int stringToInt(string s);

int typePriority(string c);

int typePriority(char c);

int checkString(string s);

bool bracketCheck(string s);

bool checkOperater(string s);

bool unknownCharacterCheck(string s);

void handleNegativeAndPositiveSymbol(string &s);