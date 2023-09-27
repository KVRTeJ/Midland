#pragma once

void printVector(const std::vector<int> nums);
//Выводит вектор

void fillAsciiTab(int* tab, std::string subString);
//Заполняет таблицу символов

void getOccurrences(std::vector<int> &answer, const std::string string,
                    const std::string subString, int* tab, const int start, const int stop);
//Алгоритм БМ-поиска, который находит все перестаановки в диапазоне, работает с вектором answer

int bmSearch(const std::string string, const std::string subString);
//БМ-Поиск. Возвращает первое вхождение подстроки в строку

std::vector<int> bmSearchAllOccurrences(const std::string string,const std::string subString);
//БМ-Поиск. Возвращает все вхождения подстроки в строку

std::vector<int> bmSearchOccurrencesInRange(const std::string string, const std::string subString,
                                            const int start, const int stop);
//БМ-Поиск. Возвращает вхождения подстроки в строку в диапазоне от start до stop

