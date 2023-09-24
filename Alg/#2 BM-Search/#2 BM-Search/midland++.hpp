#pragma once

int bmSearch(const std::string string, const std::string subString);
//БМ-Поиск. Возвращает первое вхождение подстроки в строку

std::vector<int> bmSearchAllOccurrences(const std::string string, const std::string subString);
//БМ-Поиск. Возвращает все вхождения подстроки в строку

std::vector<int> bmSearchOccurrencesInDiapason(const std::string string, const std::string subString,
                                               const int start, const int stop);
//БМ-Поиск. Возвращает вхождения подстроки в строку в диапазоне от start до stop

void printVector(const std::vector<int> nums);
//Выводит вектор
