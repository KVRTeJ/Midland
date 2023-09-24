#pragma once

int bmSearch(std::string string, std::string subString);
//БМ-Поиск. Возвращает первое вхождение подстроки в строку

std::vector<int> bmSearchAllOccurrences(std::string string, std::string subString);
//БМ-Поиск. Возвращает все вхождения подстроки в строку

std::vector<int> bmSearchOccurrencesInDiapason(std::string string, std::string subString, int start, int stop);

void printVector(std::vector<int> nums);
//Выводит вектор
