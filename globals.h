#pragma once
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80

bool Same(const std::string& a, const std::string& b);
bool Same(const char* a, const std::string& b);
bool Same(const std::string& a, const char* b);
void Tokenize(const std::string& line, std::vector<std::string>& arguments);


