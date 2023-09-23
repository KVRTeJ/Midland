#pragma once

int bmSearch(std::string string, std::string subString);
//БМ-Поиск. Возвращает первое вхождение подстроки в строку

std::vector<int> bmSearchAllOccurrences(std::string string, std::string subString);
//БМ-Поиск. Возвращает все вхождения подстроки в строку

void printVector(std::vector<int> nums);
//Выводит вектор
