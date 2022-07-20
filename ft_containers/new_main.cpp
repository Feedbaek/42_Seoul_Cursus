#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

/* for check time */
#include <stdlib.h>
#include <ctime>
#include <chrono>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

/* subject main mutant stack */
template<typename T>
class StdMutantStack : public std::stack<T>
{
public:
	StdMutantStack() {}
	StdMutantStack(const StdMutantStack<T>& src) { *this = src; }
	StdMutantStack<T>& operator=(const StdMutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~StdMutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template<typename T>
class FtMutantStack : public ft::stack<T>
{
public:
	FtMutantStack() {}
	FtMutantStack(const FtMutantStack<T>& src) { *this = src; }
	FtMutantStack<T>& operator=(const FtMutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~FtMutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

/*
 ** Map Test Start
 */
template <class T1, class T2>
void PrintElement(ft::map<T1, T2> ftMap, std::ofstream& fout){
    size_t ftSize = ftMap.size();

    fout << "|  ft map |" << " size = " << ftSize << " | key = ";
    for (typename ft::map<T1, T2>::iterator ftIt = ftMap.begin(); ftIt != ftMap.end(); ftIt++){
        fout << "\'" <<ftIt->first  << "\'" << " ";
    }
    fout << "| value = ";
    for (typename ft::map<T1, T2>::iterator ftIt = ftMap.begin(); ftIt != ftMap.end(); ftIt++){
        fout << ftIt->second << " ";
    }
}

template <class T1, class T2>
void PrintElement(std::map<T1, T2> stdMap, std::ofstream& fout){
    size_t stdSize = stdMap.size();

    fout << "| std map |" << " size = " << stdSize << " | key = ";
    for (typename std::map<T1, T2>::iterator stdIt = stdMap.begin(); stdIt != stdMap.end(); stdIt++){
        fout << "\'" << stdIt->first << "\'" << " ";
    }
    fout << "| value = ";
    for (typename std::map<T1, T2>::iterator stdIt = stdMap.begin(); stdIt != stdMap.end(); stdIt++){
        fout << stdIt->second << " ";
    }
}

template <class T1, class T2>
void PrintMap(std::map<T1, T2> stdMap, ft::map<T1, T2> ftMap, std::ofstream& fout){
    size_t stdSize = stdMap.size();
    size_t ftSize = ftMap.size();

    fout << "| std map |" << " size = " << stdSize << " | key = ";
    for (typename std::map<T1, T2>::iterator stdIt = stdMap.begin(); stdIt != stdMap.end(); stdIt++){
        fout << "\'" << stdIt->first << "\'" << " ";
    }
    fout << "| value = ";
    for (typename std::map<T1, T2>::iterator stdIt = stdMap.begin(); stdIt != stdMap.end(); stdIt++){
        fout << stdIt->second << " ";
    }
    fout << std::endl;

    fout << "|  ft map |" << " size = " << ftSize << " | key = ";
    for (typename ft::map<T1, T2>::iterator ftIt = ftMap.begin(); ftIt != ftMap.end(); ftIt++){
        fout << "\'" << ftIt->first << "\'" << " ";
    }
    fout << "| value = ";
    for (typename ft::map<T1, T2>::iterator ftIt = ftMap.begin(); ftIt != ftMap.end(); ftIt++){
        fout << ftIt->second << " ";
    }
    fout << std::endl;
}


void MapTest(void){
    std::ofstream fout("MapTest.log");

    std::map<char, int> stdMap;
    ft::map<char, int> ftMap;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(50) << "Default Constructor" << std::setw(30) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMap, ftMap, fout);

    char j = 'a';
    for (int i = 1; i < 6; i++){
        stdMap.insert(std::make_pair(j, i));
        j++;
    }
    j = 'a';
    for (int i = 1; i < 6; i++){
        ftMap.insert(ft::make_pair(j, i));
        j++;
    }
    std::map<char, int> stdMapRange(stdMap.begin(), stdMap.end());
    ft::map<char, int> ftMapRange(ftMap.begin(), ftMap.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(49) << "Range Constructor" << std::setw(31) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapRange, ftMapRange, fout);

    std::map<char, int> stdMapCopy(stdMapRange);
    ft::map<char, int> ftMapCopy(ftMapRange);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(49) << "Copy Constructor" << std::setw(31) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapCopy, ftMapCopy, fout);
    stdMapCopy.insert(std::make_pair('f', 6));
    ftMapCopy.insert(ft::make_pair('f', 6));
    fout << "|" << std::setw(43) << "Origin" << std::setw(37) << "|" << std::endl;
    PrintMap(stdMapRange, ftMapRange, fout);
    fout << "|" << std::setw(45) << "deep copy" << std::setw(35) << "|" << std::endl;
    PrintMap(stdMapCopy, ftMapCopy, fout);


    std::map<char, int> stdMapOper;
    ft::map<char, int> ftMapOper;
    stdMapOper = stdMapCopy;
    ftMapOper = ftMapCopy;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << " Operator= " << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapOper, ftMapOper, fout);
    stdMapOper.insert(std::make_pair('g', 7));
    ftMapOper.insert(ft::make_pair('g', 7));
    fout << "|" << std::setw(43) << "Origin" << std::setw(37) << "|" << std::endl;
    PrintMap(stdMapCopy, ftMapCopy, fout);
    fout << "|" << std::setw(45) << "deep copy" << std::setw(35) << "|" << std::endl;
    PrintMap(stdMapOper, ftMapOper, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(52) << "begin, end, rbegin, rend" << std::setw(28) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std map |  begin key = " << "\'" << stdMapOper.begin()->first << "\'" << " |  begin value = " << stdMapOper.begin()->second;
    fout << " |  end key = " << "\'" << (--stdMapOper.end())->first << "\'" << " |  end value = " << (--stdMapOper.end())->second << std::endl;
    fout << "| std map | rbegin key = " << "\'" << stdMapOper.rbegin()->first << "\'" << " | rbegin value = " << stdMapOper.rbegin()->second;
    fout << " | rend key = " << "\'" << (--stdMapOper.rend())->first << "\'" << " | rend value = " << (--stdMapOper.rend())->second << std::endl;
    fout << "|  ft map |  begin key = " << "\'" << ftMapOper.begin()->first << "\'" << " |  begin value = " << ftMapOper.begin()->second;
    fout << " |  end key = " << "\'" << (--ftMapOper.end())->first << "\'" << " |  end value = " << (--ftMapOper.end())->second << std::endl;
    fout << "|  ft map | rbegin key = " << "\'" << ftMapOper.rbegin()->first << "\'" << " | rbegin value = " << ftMapOper.rbegin()->second;
    fout << " | rend key = " << "\'" << (--ftMapOper.rend())->first << "\'" << " | rend value = " << (--ftMapOper.rend())->second << std::endl;

    std::map<char, int> stdMapEmpty;
    ft::map<char, int> ftMapEmpty;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "empty" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintElement(stdMapEmpty, fout);
    fout << "| empty = ";
    if (stdMapEmpty.empty()){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapEmpty, fout);
    fout << "| empty = ";
    if (ftMapEmpty.empty()){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    stdMapEmpty['c'] = 15;
    ftMapEmpty['c'] = 15;
    PrintElement(stdMapEmpty, fout);
    fout << "| empty = ";
    if (stdMapEmpty.empty()){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapEmpty, fout);
    fout << "| empty = ";
    if (ftMapEmpty.empty()){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "max size" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std map | max size = " << stdMapEmpty.max_size() << std::endl;
    fout << "|  ft map | max size = " << ftMapEmpty.max_size() << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "operator[]" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintElement(stdMapEmpty, fout);
    fout << " | map['c'] = " << stdMapEmpty['c'] << std::endl;
    PrintElement(ftMapEmpty, fout);
    fout << " | map['c'] = " << ftMapEmpty['c'] << std::endl;
    stdMapEmpty['a'];
    ftMapEmpty['a'];
    fout << "|" << std::setw(48) << "after map['a'];" << std::setw(32) << "|" << std::endl;
    PrintElement(stdMapEmpty, fout);
    fout << " | map['a'] = " << stdMapEmpty['a'] << std::endl;
    PrintElement(ftMapEmpty, fout);
    fout << " | map['a'] = " << ftMapEmpty['a'] << std::endl;
    stdMapEmpty['e'] = 8;
    ftMapEmpty['e'] = 8;
    fout << "|" << std::setw(50) << "after map['e'] = 8;" << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapEmpty, fout);
    fout << " | map['e'] = " << stdMapEmpty['e'] << std::endl;
    PrintElement(ftMapEmpty, fout);
    fout << " | map['e'] = " << ftMapEmpty['e'] << std::endl;
    stdMapEmpty['e'] = 5;
    ftMapEmpty['e'] = 5;
    fout << "|" << std::setw(50) << "after map['e'] = 5;" << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapEmpty, fout);
    fout << " | map['e'] = " << stdMapEmpty['e'] << std::endl;
    PrintElement(ftMapEmpty, fout);
    fout << " | map['e'] = " << ftMapEmpty['e'] << std::endl;

    std::map<char, int> stdMapInsert;
    ft::map<char, int> ftMapInsert;
    std::pair<std::map<char, int>::iterator, bool> stdResult;
    ft::pair<ft::map<char, int>::iterator, bool> ftResult;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(52) << "insert (single element)" << std::setw(28) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(48) << "current status" << std::setw(32) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);
    stdResult = stdMapInsert.insert(std::make_pair('a', 1));
    ftResult = ftMapInsert.insert(ft::make_pair('a', 1));
    fout << "|" << std::setw(49) << "after <'a', 1> " << std::setw(31) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdResult.first->first << "\'" << " | it->second = " << stdResult.first->second;
    fout << " | bool = ";
    if (stdResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftResult.first->first << "\'" << " | it->second = " << ftResult.first->second;
    fout << " | bool = ";
    if (ftResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    stdResult = stdMapInsert.insert(std::make_pair('a', 1));
    ftResult = ftMapInsert.insert(ft::make_pair('a', 1));
    fout << "|" << std::setw(49) << "again <'a', 1> " << std::setw(31) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdResult.first->first << "\'" << " | it->second = " << stdResult.first->second;
    fout << " | bool = ";
    if (stdResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftResult.first->first << "\'" << " | it->second = " << ftResult.first->second;
    fout << " | bool = ";
    if (ftResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    stdResult = stdMapInsert.insert(std::make_pair('a', 11));
    ftResult = ftMapInsert.insert(ft::make_pair('a', 11));
    fout << "|" << std::setw(55) << "second chanege <'a', 11> " << std::setw(25) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdResult.first->first << "\'" << " | it->second = " << stdResult.first->second;
    fout << " | bool = ";
    if (stdResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftResult.first->first << "\'" << " | it->second = " << ftResult.first->second;
    fout << " | bool = ";
    if (ftResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    stdResult = stdMapInsert.insert(std::make_pair('b', 123));
    ftResult = ftMapInsert.insert(ft::make_pair('b', 123));
    fout << "|" << std::setw(50) << "after <'b', 123> " << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdResult.first->first << "\'" << " | it->second = " << stdResult.first->second;
    fout << " | bool = ";
    if (stdResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftResult.first->first << "\'" << " | it->second = " << ftResult.first->second;
    fout << " | bool = ";
    if (ftResult.second){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    std::map<char, int>::iterator stdHintResult;
    ft::map<char, int>::iterator ftHintResult;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(49) << "insert (with hint)" << std::setw(31) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    stdHintResult = stdMapInsert.insert(stdMapInsert.begin(), std::make_pair('c', 31));
    ftHintResult = ftMapInsert.insert(ftMapInsert.begin(), ft::make_pair('c', 31));
    fout << "|" << std::setw(50) << "after <'c', 31> " << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdHintResult->first << "\'" << " | it->second = " << stdHintResult->second << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftHintResult->first << "\'" << " | it->second = " << ftHintResult->second << std::endl;

    stdHintResult = stdMapInsert.insert(stdMapInsert.end(), std::make_pair('c', 31));
    ftHintResult = ftMapInsert.insert(ftMapInsert.end(), ft::make_pair('c', 31));
    fout << "|" << std::setw(50) << "again <'c', 31> " << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdHintResult->first << "\'" << " | it->second = " << stdHintResult->second << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftHintResult->first << "\'" << " | it->second = " << ftHintResult->second << std::endl;

    stdHintResult = stdMapInsert.insert(stdMapInsert.end(), std::make_pair('c', -10));
    ftHintResult = ftMapInsert.insert(ftMapInsert.end(), ft::make_pair('c', -10));
    fout << "|" << std::setw(58) << "second change <'c', -10> " << std::setw(22) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdHintResult->first << "\'" << " | it->second = " << stdHintResult->second << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftHintResult->first << "\'" << " | it->second = " << ftHintResult->second << std::endl;

    stdHintResult = stdMapInsert.insert(stdMapInsert.begin(), std::make_pair('d', -11));
    ftHintResult = ftMapInsert.insert(ftMapInsert.begin(), ft::make_pair('d', -11));
    fout << "|" << std::setw(50) << "after <'d', -11> " << std::setw(30) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << stdHintResult->first << "\'" << " | it->second = " << stdHintResult->second << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | it->first = " << "\'" << ftHintResult->first << "\'" << " | it->second = " << ftHintResult->second << std::endl;

    std::map<char, int> stdForInsert1;
    ft::map<char, int> ftForInsert1;
    char c = 'z';
    for (int i = 10; i < 15; i++){
        stdForInsert1.insert(std::make_pair(c, i));
        ftForInsert1.insert(ft::make_pair(c, i));
        c--;
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(47) << "insert (range)" << std::setw(33) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(49) << "map to be inserted" << std::setw(31) << "|" << std::endl;
    PrintMap(stdForInsert1, ftForInsert1, fout);
    stdMapInsert.insert(stdForInsert1.begin(), stdForInsert1.end());
    ftMapInsert.insert(ftForInsert1.begin(), ftForInsert1.end());
    fout << "|" << std::setw(46) << "after insert" << std::setw(34) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    std::map<char, int> stdForInsert2;
    ft::map<char, int> ftForInsert2;
    fout << "|" << std::setw(46) << "empty insert" << std::setw(34) << "|" << std::endl;
    stdMapInsert.insert(stdForInsert2.begin(), stdForInsert2.end());
    ftMapInsert.insert(ftForInsert2.begin(), ftForInsert2.end());
    PrintMap(stdMapInsert, ftMapInsert, fout);

    std::map<char, int> stdForInsert3;
    ft::map<char, int> ftForInsert3;
    c = 'a';
    for (int i = -100; i < -97; i++){
        c--;
        stdForInsert3.insert(std::make_pair(c, i));
        ftForInsert3.insert(ft::make_pair(c, i));
    }
    fout << "|" << std::setw(46) << "after insert" << std::setw(34) << "|" << std::endl;
    stdMapInsert.insert(stdForInsert3.begin(), stdForInsert3.end());
    ftMapInsert.insert(ftForInsert3.begin(), ftForInsert3.end());
    PrintMap(stdMapInsert, ftMapInsert, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(47) << "erase (iter)" << std::setw(33) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    stdMapInsert.erase(stdMapInsert.find('a'));
    ftMapInsert.erase(ftMapInsert.find('a'));
    fout << "|" << std::setw(46) << "erase 'a'" << std::setw(34) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    stdMapInsert.erase(stdMapInsert.find('v'));
    ftMapInsert.erase(ftMapInsert.find('v'));
    fout << "|" << std::setw(46) << "erase 'v'" << std::setw(34) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    size_t stdEraseResult = 0;
    size_t ftEraseResult = 0;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(47) << "erase (key) " << std::setw(33) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    stdEraseResult = stdMapInsert.erase('z');
    ftEraseResult = ftMapInsert.erase('z');
    fout << "|" << std::setw(46) << "erase 'z'" << std::setw(34) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | return value = " << stdEraseResult << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | return value = " << ftEraseResult << std::endl;

    stdEraseResult = stdMapInsert.erase('z');
    ftEraseResult = ftMapInsert.erase('z');
    fout << "|" << std::setw(46) << "erase 'z'" << std::setw(34) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | return value = " << stdEraseResult << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | return value = " << ftEraseResult << std::endl;

    stdEraseResult = stdMapInsert.erase('x');
    ftEraseResult = ftMapInsert.erase('x');
    fout << "|" << std::setw(46) << "erase 'x'" << std::setw(34) << "|" << std::endl;
    PrintElement(stdMapInsert, fout);
    fout << std::endl << "|         | return value = " << stdEraseResult << std::endl;
    PrintElement(ftMapInsert, fout);
    fout << std::endl << "|         | return value = " << ftEraseResult << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(51) << "erase (iter, iter) " << std::setw(29) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    stdMapInsert.erase(stdMapInsert.find('`'), stdMapInsert.find('d'));
    ftMapInsert.erase(ftMapInsert.find('`'), ftMapInsert.find('d'));
    fout << "|" << std::setw(48) << "erase '`' ~ 'd'" << std::setw(32) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    stdMapInsert.erase(stdMapInsert.find('^'), stdMapInsert.find('d'));
    ftMapInsert.erase(ftMapInsert.find('^'), ftMapInsert.find('d'));
    fout << "|" << std::setw(48) << "erase '^' ~ 'd'" << std::setw(32) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    stdMapInsert.erase(stdMapInsert.find('w'), stdMapInsert.end());
    ftMapInsert.erase(ftMapInsert.find('w'), ftMapInsert.end());
    fout << "|" << std::setw(48) << "erase 'w' ~ end" << std::setw(32) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    stdMapInsert.erase(stdMapInsert.begin(), stdMapInsert.end());
    ftMapInsert.erase(ftMapInsert.begin(), ftMapInsert.end());
    fout << "|" << std::setw(50) << "erase begin ~ end" << std::setw(30) << "|" << std::endl;
    PrintMap(stdMapInsert, ftMapInsert, fout);

    std::map<char, int> stdMapSwap1;
    std::map<char, int> stdMapSwap2;
    ft::map<char, int> ftMapSwap1;
    ft::map<char, int> ftMapSwap2;
    c = 'a';
    for (int i = 1; i < 7; i++){
        stdMapSwap1.insert(std::make_pair(c, i));
        ftMapSwap1.insert(ft::make_pair(c, i));
        c++;
    }
    c = 'z';
    for (int i = -5; i < 0; i++){
        stdMapSwap2.insert(std::make_pair(c, i));
        ftMapSwap2.insert(ft::make_pair(c, i));
        c--;
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "map::swap " << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintElement(stdMapSwap1, fout);
    fout << "<- before " << std::endl;
    PrintElement(stdMapSwap2, fout);
    fout << "<- target " << std::endl;
    stdMapSwap1.swap(stdMapSwap2);
    fout << "|" << std::setw(47) << "after swap " << std::setw(33) << "|" << std::endl;
    PrintElement(stdMapSwap1, fout);
    fout << "<- after " << std::endl;
    PrintElement(stdMapSwap2, fout);
    fout << "<- target " << std::endl;

    fout << "|" << std::setw(80) << "|" << std::endl;

    PrintElement(ftMapSwap1, fout);
    fout << "<- before " << std::endl;
    PrintElement(ftMapSwap2, fout);
    fout << "<- target " << std::endl;
    ftMapSwap1.swap(ftMapSwap2);
    fout << "|" << std::setw(47) << "after swap " << std::setw(33) << "|" << std::endl;
    PrintElement(ftMapSwap1, fout);
    fout << "<- after " << std::endl;
    PrintElement(ftMapSwap2, fout);
    fout << "<- target " << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(43) << "clear" << std::setw(37) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(47) << "before clear" << std::setw(33) << "|" << std::endl;
    PrintMap(stdMapSwap1, ftMapSwap1, fout);
    stdMapSwap1.clear();
    ftMapSwap1.clear();
    fout << "|" << std::setw(47) << " after clear" << std::setw(33) << "|" << std::endl;
    PrintMap(stdMapSwap1, ftMapSwap1, fout);

    std::map<char, int>::iterator stdFindResult;
    ft::map<char, int>::iterator ftFindResult;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(43) << "find " << std::setw(37) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapSwap2, ftMapSwap2, fout);
    fout << "|" << std::setw(46) << " find 'c' " << std::setw(34) << "|" << std::endl;
    stdFindResult = stdMapSwap2.find('c');
    fout << "| std map | findIter first = " << "\'" << stdFindResult->first << "\'" << " | findIter second = " << stdFindResult->second << std::endl;
    ftFindResult = ftMapSwap2.find('c');
    fout << "|  ft map | findIter first = " << "\'" << ftFindResult->first << "\'" << " | findIter second = " << ftFindResult->second << std::endl;

    fout << "|" << std::setw(46) << " find 'f' " << std::setw(34) << "|" << std::endl;
    stdFindResult = stdMapSwap2.find('f');
    fout << "| std map | findIter first = " << "\'" << stdFindResult->first << "\'" << " | findIter second = " << stdFindResult->second << std::endl;
    ftFindResult = ftMapSwap2.find('f');
    fout << "|  ft map | findIter first = " << "\'" << ftFindResult->first << "\'" << " | findIter second = " << ftFindResult->second << std::endl;

    size_t stdCountResult = 0;
    size_t ftCountResult = 0;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(43) << "count" << std::setw(37) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapSwap2, ftMapSwap2, fout);
    fout << "|" << std::setw(56) << " count 'c', count 'e', count 'z', count 'f' " << std::setw(24) << "|" << std::endl;
    stdCountResult = stdMapSwap2.count('c');
    fout << "| std map | result = " << stdCountResult;
    stdCountResult = stdMapSwap2.count('e');
    fout << " result = " << stdCountResult;
    stdCountResult = stdMapSwap2.count('z');
    fout << " result = " << stdCountResult;
    stdCountResult = stdMapSwap2.count('f');
    fout << " result = " << stdCountResult << std::endl;

    ftCountResult = ftMapSwap2.count('c');
    fout << "|  ft map | result = " << ftCountResult;
    ftCountResult = ftMapSwap2.count('e');
    fout << " result = " << ftCountResult;
    ftCountResult = ftMapSwap2.count('z');
    fout << " result = " << ftCountResult;
    ftCountResult = ftMapSwap2.count('f');
    fout << " result = " << ftCountResult << std::endl;

    std::map<char, int> stdMapBound;
    ft::map<char, int> ftMapBound;
    std::map<char, int>::iterator stdBoundResult;
    ft::map<char, int>::iterator ftBoundResult;
    c = 'a';
    for (int i = 1; i < 12; i++){
        if (i % 2 == 1){
            stdMapBound.insert(std::make_pair(c, i));
            ftMapBound.insert(ft::make_pair(c, i));
        }
        c++;
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "lower bound" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapBound, ftMapBound, fout);
    fout << "|" << std::setw(46) << "bound 'A'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.lower_bound('A');
    ftBoundResult = ftMapBound.lower_bound('A');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    fout << "|" << std::setw(46) << "bound 'd'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.lower_bound('d');
    ftBoundResult = ftMapBound.lower_bound('d');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    fout << "|" << std::setw(46) << "bound 'g'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.lower_bound('g');
    ftBoundResult = ftMapBound.lower_bound('g');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    // fout << "|" << std::setw(46) << "bound 'z'" << std::setw(34) << "|" << std::endl;
    // stdBoundResult = stdMapBound.lower_bound('z');
    // ftBoundResult = ftMapBound.lower_bound('z');
    // fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    // fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "upper bound" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapBound, ftMapBound, fout);
    fout << "|" << std::setw(46) << "bound 'C'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.upper_bound('C');
    ftBoundResult = ftMapBound.upper_bound('C');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    fout << "|" << std::setw(46) << "bound 'a'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.upper_bound('a');
    ftBoundResult = ftMapBound.upper_bound('a');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    fout << "|" << std::setw(46) << "bound 'h'" << std::setw(34) << "|" << std::endl;
    stdBoundResult = stdMapBound.upper_bound('h');
    ftBoundResult = ftMapBound.upper_bound('h');
    fout << "| std map | result first = " << "\'" << stdBoundResult->first << "\'" << " | result second = " << stdBoundResult->second << std::endl;
    fout << "|  ft map | result first = " << "\'" << ftBoundResult->first << "\'" << " | result second = " << ftBoundResult->second << std::endl;

    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> stdEqualRangeResult;
    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ftEqualRangeResult;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "equal range" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintMap(stdMapBound, ftMapBound, fout);
    fout << "|" << std::setw(46) << "param 'A'" << std::setw(34) << "|" << std::endl;
    stdEqualRangeResult = stdMapBound.equal_range('A');
    ftEqualRangeResult = ftMapBound.equal_range('A');
    fout << "| std map | pair first  : iter->first = " << "\'" << stdEqualRangeResult.first->first << "\'" << " | iter->second = " << stdEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << stdEqualRangeResult.second->first << "\'" << " | iter->second = " << stdEqualRangeResult.second->second << std::endl;
    fout << "|  ft map | pair first  : iter->first = " << "\'" << ftEqualRangeResult.first->first << "\'" << " | iter->second = " << ftEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << ftEqualRangeResult.second->first << "\'" << " | iter->second = " << ftEqualRangeResult.second->second << std::endl;

    fout << "|" << std::setw(46) << "param 'd'" << std::setw(34) << "|" << std::endl;
    stdEqualRangeResult = stdMapBound.equal_range('d');
    ftEqualRangeResult = ftMapBound.equal_range('d');
    fout << "| std map | pair first  : iter->first = " << "\'" << stdEqualRangeResult.first->first << "\'" << " | iter->second = " << stdEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << stdEqualRangeResult.second->first << "\'" << " | iter->second = " << stdEqualRangeResult.second->second << std::endl;
    fout << "|  ft map | pair first  : iter->first = " << "\'" << ftEqualRangeResult.first->first << "\'" << " | iter->second = " << ftEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << ftEqualRangeResult.second->first << "\'" << " | iter->second = " << ftEqualRangeResult.second->second << std::endl;

    fout << "|" << std::setw(46) << "param 'i'" << std::setw(34) << "|" << std::endl;
    stdEqualRangeResult = stdMapBound.equal_range('i');
    ftEqualRangeResult = ftMapBound.equal_range('i');
    fout << "| std map | pair first  : iter->first = " << "\'" << stdEqualRangeResult.first->first << "\'" << " | iter->second = " << stdEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << stdEqualRangeResult.second->first << "\'" << " | iter->second = " << stdEqualRangeResult.second->second << std::endl;
    fout << "|  ft map | pair first  : iter->first = " << "\'" << ftEqualRangeResult.first->first << "\'" << " | iter->second = " << ftEqualRangeResult.first->second << std::endl;
    fout << "|         | pair second : iter->first = " << "\'" << ftEqualRangeResult.second->first << "\'" << " | iter->second = " << ftEqualRangeResult.second->second << std::endl;

    std::map<char, int> stdMapOperator1;
    std::map<char, int> stdMapOperator2;
    ft::map<char, int> ftMapOperator1;
    ft::map<char, int> ftMapOperator2;
    c = 'a';
    for (int i = 10; i < 21; i++){
        if (i % 2 == 0){
            stdMapOperator1.insert(std::make_pair(c, i));
            stdMapOperator2.insert(std::make_pair(c, i));
            ftMapOperator1.insert(ft::make_pair(c, i));
            ftMapOperator2.insert(ft::make_pair(c, i));
            c++;
        }
    }
    stdMapOperator2.insert(std::make_pair('z', 30));
    ftMapOperator2.insert(ft::make_pair('z', 30));
    bool stdMapOperatorResult;
    bool ftMapOperatorResult;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator 6" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintElement(stdMapOperator1, fout);
    fout << std::endl;
    PrintElement(stdMapOperator2, fout);
    fout << std::endl;
    PrintElement(ftMapOperator1, fout);
    fout << std::endl;
    PrintElement(ftMapOperator2, fout);
    fout << std::endl;
    fout << "|" << std::setw(47) << "Operator == " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 == stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 == ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "|" << std::setw(47) << "Operator != " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 != stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 != ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "|" << std::setw(47) << "Operator <  " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 < stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 < ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "|" << std::setw(47) << "Operator <= " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 <= stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 <= ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "|" << std::setw(47) << "Operator >  " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 > stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 > ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "|" << std::setw(47) << "Operator >= " << std::setw(33) << "|" << std::endl;
    stdMapOperatorResult = (stdMapOperator1 >= stdMapOperator2);
    ftMapOperatorResult = (ftMapOperator1 >= ftMapOperator2);
    fout << "| std map | result = ";
    if (stdMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft map | result = ";
    if (ftMapOperatorResult){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "ft::swap" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintElement(stdMapOperator1, fout);
    fout << "<- before " << std::endl;
    PrintElement(stdMapOperator2, fout);
    fout << "<- target " << std::endl;
    std::swap(stdMapOperator1, stdMapOperator2);
    fout << "|" << std::setw(47) << "after swap " << std::setw(33) << "|" << std::endl;
    PrintElement(stdMapOperator1, fout);
    fout << "<- after " << std::endl;
    PrintElement(stdMapOperator2, fout);
    fout << "<- target " << std::endl;

    fout << "|" << std::setw(80) << "|" << std::endl;

    PrintElement(ftMapOperator1, fout);
    fout << "<- before " << std::endl;
    PrintElement(ftMapOperator2, fout);
    fout << "<- target " << std::endl;
    ft::swap(ftMapOperator1, ftMapOperator2);
    fout << "|" << std::setw(47) << "after swap " << std::setw(33) << "|" << std::endl;
    PrintElement(ftMapOperator1, fout);
    fout << "<- after " << std::endl;
    PrintElement(ftMapOperator2, fout);
    fout << "<- target " << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(43) << "time" << std::setw(37) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    std::map<int, int> stdMapInt;
    std::chrono::system_clock::time_point stdStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; ++i){
        stdMapInt.insert(std::make_pair(rand(), rand()));
    }
    int stdSum = 0;
    for (int i = 0; i < 10000; ++i){
        int access = rand();
        stdSum += stdMapInt[access];
    }
    fout << "should be constant with the same seed: " << stdSum << std::endl;
    {
        std::map<int, int> copy = stdMapInt;
    }
    std::chrono::system_clock::time_point stdEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds stdTime = stdEnd - stdStart;
    fout << "| std map | time = " << stdTime.count() << std::endl;

    ft::map<int, int> ftMapInt;
    std::chrono::system_clock::time_point ftStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; ++i){
        ftMapInt.insert(ft::make_pair(rand(), rand()));
    }
    int ftSum = 0;
    for (int i = 0; i < 10000; ++i){
        int access = rand();
        ftSum += ftMapInt[access];
    }
    fout << "should be constant with the same seed: " << ftSum << std::endl;
    {
        ft::map<int, int> copy = ftMapInt;
    }
    std::chrono::system_clock::time_point ftEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds ftTime = ftEnd - ftStart;
    fout << "|  ft map | time = " << ftTime.count() << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout.close();
}

// /*
//  ** Map Test End
//  */

// /*****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************
//  *****************************************************************************************************************/

// /*
//  ** Stack Test Start
//  */

template <class T>
void PrintElement(std::stack<T> stdStack, std::ofstream& fout){
    size_t stdSize = stdStack.size();
    int stdTemp[stdSize];
    int i = 1;
    fout << " | element = ";
    while (!stdStack.empty()){
        stdTemp[stdSize - i] = stdStack.top();
        i++;
        stdStack.pop();
    }
    for(size_t i = 0; i < stdSize; i++){
        fout << stdTemp[i] << " ";
    }
    fout << std::endl;
}

template <class T>
void PrintElement(ft::stack<T> ftStack, std::ofstream& fout){
    size_t ftSize = ftStack.size();
    int ftTemp[ftSize];
    int i = 1;
    fout << " | element = ";
    while (!ftStack.empty()){
        ftTemp[ftSize - i] = ftStack.top();
        i++;
        ftStack.pop();
    }
    for(size_t i = 0; i < ftSize; i++){
        fout << ftTemp[i] << " ";
    }
    fout << std::endl;
}

/* Print element like iterator */
template <class T>
void PrintStack(std::stack<T> stdStack, ft::stack<T> ftStack, std::ofstream& fout){
    size_t stdSize = stdStack.size();
    size_t ftSize = ftStack.size();
    int stdTemp[stdSize];
    int ftTemp[ftSize];
    int i = 1;

    fout << "| std stack | size = " << stdStack.size() << " | element = ";
    while (!stdStack.empty()){
        stdTemp[stdSize - i] = stdStack.top();
        i++;
        stdStack.pop();
    }
    for(size_t i = 0; i < stdSize; i++){
        fout << stdTemp[i] << " ";
    }
    fout << std::endl;

    i = 1;
    fout << "|  ft stack | size = " << ftStack.size() << " | element = ";
    while (!ftStack.empty()){
        ftTemp[ftSize - i] = ftStack.top();
        i++;
        ftStack.pop();
    }
    for(size_t i = 0; i < ftSize; i++){
        fout << ftTemp[i] << " ";
    }
    fout << std::endl;
}

void StackTest(void){
    std::ofstream fout("StackTest.log");

    std::stack<int> stdStack;
    ft::stack<int> ftStack;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(50) << "Default Constructor" << std::setw(30) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintStack(stdStack, ftStack, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "empty case1" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStack.empty()){
        fout << "true";
    }
    else {
        fout << "false";
    }
    fout << std::endl;
    fout << "|  ft stack | result = ";
    if (ftStack.empty()){
        fout << "true";
    }
    else {
        fout << "false";
    }
    fout << std::endl;

    stdStack.push(1);
    ftStack.push(1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "empty case2" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStack.empty()){
        fout << "true";
    }
    else {
        fout << "false";
    }
    fout << std::endl;
    fout << "|  ft stack | result = ";
    if (ftStack.empty()){
        fout << "true";
    }
    else {
        fout << "false";
    }
    fout << std::endl;

    for(int i = 3; i < 10; i++){
        if (i % 2 == 1){
            stdStack.push(i);
            ftStack.push(i);
        }
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "top case1" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | top element = " << stdStack.top() << " | size = " << stdStack.size();
    PrintElement(stdStack, fout);
    fout << "|  ft stack | top element = " << ftStack.top() << " | size = " << ftStack.size();
    PrintElement(ftStack, fout);

    stdStack.top() += 2;
    ftStack.top() += 2;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "top case2" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | top element = " << stdStack.top() << " | size = " << stdStack.size();
    PrintElement(stdStack, fout);
    fout << "|  ft stack | top element = " << ftStack.top() << " | size = " << ftStack.size();
    PrintElement(ftStack, fout);

    stdStack.pop();
    ftStack.pop();
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "top case3" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | top element = " << stdStack.top() << " | size = " << stdStack.size();
    PrintElement(stdStack, fout);
    fout << "|  ft stack | top element = " << ftStack.top() << " | size = " << ftStack.size();
    PrintElement(ftStack, fout);

    stdStack.push(9);
    ftStack.push(9);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "push" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintStack(stdStack, ftStack, fout);

    stdStack.push(11);
    ftStack.push(11);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "push" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintStack(stdStack, ftStack, fout);

    stdStack.pop();
    ftStack.pop();
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "pop" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintStack(stdStack, ftStack, fout);

    stdStack.pop();
    ftStack.pop();
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "pop" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintStack(stdStack, ftStack, fout);


    std::stack<int> stdStackNonmember1;
    std::stack<int> stdStackNonmember2;
    ft::stack<int> ftStackNonmember1;
    ft::stack<int> ftStackNonmember2;
    for (int i = 1; i < 6; i++){
        stdStackNonmember1.push(i);
        stdStackNonmember2.push(i);
        ftStackNonmember1.push(i);
        ftStackNonmember2.push(i);
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator ==" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 == stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 == ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator !=" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 != stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 != ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }


    stdStackNonmember2.push(6);
    ftStackNonmember2.push(6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator <" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 < stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 < ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator >" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 > stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 > ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator <=" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 <= stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 <= ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Operator >=" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std stack | result = ";
    if (stdStackNonmember1 >= stdStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    fout << "|  ft stack | result = ";
    if (ftStackNonmember1 >= ftStackNonmember2){
        fout << "true" << std::endl;
    }
    else{
        fout << "false" << std::endl;
    }
    /* another container can instantiate object */
    std::stack<Buffer, std::deque<Buffer> > stdStackDeqBuffer;
    ft::stack<Buffer, std::deque<Buffer> > ftStackDeqBuffer;

    std::stack<Buffer, std::list<Buffer> > stdStackListBuffer;
    ft::stack<Buffer, std::list<Buffer> > ftStackListBuffer;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(47) << "subject main " << std::setw(33) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    StdMutantStack<char> stdIterableStack;
    for (char letter = 'a'; letter <= 'z'; letter++){
        stdIterableStack.push(letter);
    }
    fout << "| std stack | ";
    for (StdMutantStack<char>::iterator it = stdIterableStack.begin(); it != stdIterableStack.end(); it++){
        fout << *it << " ";
    }
    fout << std::endl;

    FtMutantStack<char> ftIterableStack;
    for (char letter = 'a'; letter <= 'z'; letter++){
        ftIterableStack.push(letter);
    }
    fout << "| std stack | ";
    for (FtMutantStack<char>::iterator it = ftIterableStack.begin(); it != ftIterableStack.end(); it++){
        fout << *it << " ";
    }
    fout << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "time" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    std::stack<int> stdStackInt;
    std::chrono::system_clock::time_point stdStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++){
        stdStackInt.push(rand());
    }
    for (int i = 0; i < COUNT; i++){
        stdStackInt.pop();
    }
    std::chrono::system_clock::time_point stdEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds stdTime = stdEnd - stdStart;
    fout << "| std stack | time = " << stdTime.count() << std::endl;

    ft::stack<int> ftStackInt;
    std::chrono::system_clock::time_point ftStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++){
        ftStackInt.push(rand());
    }
    for (int i = 0; i < COUNT; i++){
        ftStackInt.pop();
    }
    std::chrono::system_clock::time_point ftEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds ftTime = ftEnd - ftStart;
    fout << "|  ft stack | time = " << ftTime.count() << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout.close();
}

/*
** Stack Test End
*/

/*****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************
 *****************************************************************************************************************/

/*
** Vector Test Start
*/
template <class T>
void PrintVectorIterator(std::vector<T>& stdVec, ft::vector<T>& ftVec, std::ofstream& fout){
    fout << "| std vec | begin = " << *(stdVec.begin()) << " end = " << *(stdVec.end() - 1) << " rbegin = " << *(stdVec.rbegin()) << " rend = " << *(stdVec.rend() - 1) << std::endl;
    fout << "|  ft vec | begin = " << *(ftVec.begin()) << " end = " << *(ftVec.end() - 1) << " rbegin = " << *(ftVec.rbegin()) << " rend = " << *(ftVec.rend() - 1) << std::endl;
}

template <class T>
void PrintElement(std::vector<T>& stdVec, std::ofstream& fout){
    typename std::vector<T>::iterator stdIt = stdVec.begin();
    fout << " | vec element = ";
    for (; stdIt != stdVec.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
}

template <class T>
void PrintElement(ft::vector<T>& ftVec, std::ofstream& fout){
    typename ft::vector<T>::iterator ftIt = ftVec.begin();
    fout << " | vec element = ";
    for (; ftIt != ftVec.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
}

template <class T>
void PrintVector(std::vector<T>& stdVec, ft::vector<T>& ftVec, std::ofstream& fout){
    typename std::vector<T>::iterator stdIt = stdVec.begin();
    typename ft::vector<T>::iterator ftIt = ftVec.begin();
    fout << "| std vec | size = " << stdVec.size() << " | capacity = " << stdVec.capacity() << " | element = ";
    for (; stdIt != stdVec.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;

    fout << "|  ft vec | size = " << ftVec.size() << " | capacity = " << ftVec.capacity() << " | element = ";
    for (; ftIt != ftVec.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
}

void VectorTest(void){
    std::ofstream fout("VectorTest.log");

    std::vector<int> stdVecDefault;
    ft::vector<int> ftVecDefault;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Default Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecDefault, ftVecDefault, fout);

    std::vector<int> stdVecFill(5, 5);
    ft::vector<int> ftVecFill(5, 5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Fill Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecFill, ftVecFill, fout);

    std::vector<int> stdVecRange(stdVecFill.begin() + 2, stdVecFill.end());
    ft::vector<int> ftVecRange(ftVecFill.begin() + 2, ftVecFill.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Range Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecRange, ftVecRange, fout);

    std::vector<int> stdVecCopy(stdVecRange);
    ft::vector<int> ftVecCopy(ftVecRange);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Copy Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecCopy, ftVecCopy, fout);
    stdVecCopy.push_back(7);
    ftVecCopy.push_back(7);
    fout << "|" << std::setw(38) << "Origin" << std::setw(42) << "|" << std::endl;
    PrintVector(stdVecRange, ftVecRange, fout);
    fout << "|" << std::setw(40) << "deep copy" << std::setw(40) << "|" << std::endl;
    PrintVector(stdVecCopy, ftVecCopy, fout);

    std::vector<int> stdVecOper;
    ft::vector<int> ftVecOper;
    stdVecOper = stdVecCopy;
    ftVecOper = ftVecCopy;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "Operator =" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecOper, ftVecOper, fout);
    stdVecOper.push_back(9);
    ftVecOper.push_back(9);
    fout << "|" << std::setw(38) << "Origin" << std::setw(42) << "|" << std::endl;
    PrintVector(stdVecCopy, ftVecCopy, fout);
    fout << "|" << std::setw(40) << "deep copy" << std::setw(40) << "|" << std::endl;
    PrintVector(stdVecOper, ftVecOper, fout);


    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(50) << "begin, end, rbegin, rend" << std::setw(30) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVectorIterator(stdVecOper, ftVecOper, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "max size" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | max size = " << stdVecOper.max_size() << std::endl;
    fout << "|  ft vec | max size = " << ftVecOper.max_size() << std::endl;

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> stdVecResize(arr, arr + 7);
    ft::vector<int> ftVecResize(arr, arr + 7);
    /* smaller than the current container size */
    stdVecResize.resize(5);
    ftVecResize.resize(5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container size */
    stdVecResize.resize(6);
    ftVecResize.resize(6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container capacity */
    stdVecResize.resize(8);
    ftVecResize.resize(8);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container capacity * 2 */
    stdVecResize.resize(30);
    ftVecResize.resize(30);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    stdVecResize.resize(6);
    ftVecResize.resize(6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 5" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "empty" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | empty case = " << stdVecDefault.empty() << " | !empty case = " << stdVecResize.empty() << std::endl;
    fout << "|  ft vec | empty case = " << ftVecDefault.empty() << " | !empty case = " << ftVecResize.empty() << std::endl;

    stdVecResize.reserve(5);
    ftVecResize.reserve(5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    stdVecResize.reserve(40);
    ftVecResize.reserve(40);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    try{
        stdVecResize.reserve(stdVecResize.max_size() + 1);
    }
    catch (std::exception& e){
        fout << "| std vec | ";
        fout << e.what() << std::endl;
    }
    try{
        ftVecResize.reserve(ftVecResize.max_size() + 1);
    }
    catch (std::exception& e){
        fout << "|  ft vec | ";
        fout << e.what() << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator []" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    for(int i = 0; i < 5; i++){
        fout << "vec[" << i << "]=" << stdVecResize[i] << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | ";
    for(int i = 0; i < 5; i++){
        fout << "vec[" << i << "]=" << ftVecResize[i] << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case1" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    for(int i = 0; i < 5; i++){
        fout << "at[" << i << "]=" << stdVecResize.at(i) << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | ";
    for(int i = 0; i < 5; i++){
        fout << "at[" << i << "]=" << ftVecResize.at(i) << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case2" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    try {
        fout << stdVecResize.at(7);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }
    fout << "|  ft vec | ";
    try {
        fout << ftVecResize.at(7);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "front" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | front = " << stdVecResize.front();
    PrintElement(stdVecResize, fout);
    fout << "|  ft vec | front = " << ftVecResize.front();
    PrintElement(ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "back" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | back = " << stdVecResize.back();
    PrintElement(stdVecResize, fout);
    fout << "|  ft vec | back = " << ftVecResize.back();
    PrintElement(ftVecResize, fout);

    std::vector<int> stdVecAssign;
    ft::vector<int> ftVecAssign;
    stdVecAssign.assign(stdVecResize.begin(), stdVecResize.end() - 1);
    ftVecAssign.assign(ftVecResize.begin(), ftVecResize.end() - 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(2, 6);
    ftVecAssign.assign(2, 6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(7, 1);
    ftVecAssign.assign(7, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(0, 2);
    ftVecAssign.assign(0, 2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    std::vector<int> stdVecPushback;
    ft::vector<int> ftVecPushback;
    for (int i = 0; i < 6; i++){
        if (i % 2 == 1){
            stdVecPushback.push_back(i);
            ftVecPushback.push_back(i);
        }
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "push_back case1" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPushback, ftVecPushback, fout);

    for (int i = 6; i < 10; i++){
        if (i % 2 == 1){
            stdVecPushback.push_back(i);
            ftVecPushback.push_back(i);
        }
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "push_back case2" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPushback, ftVecPushback, fout);

    std::vector<int> stdVecPopback(stdVecPushback);
    ft::vector<int> ftVecPopback(ftVecPushback);
    for (int i = 0; i < 2; i++){
        stdVecPopback.pop_back();
        ftVecPopback.pop_back();
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "pop_back case1" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPopback, ftVecPopback, fout);

    for (int i = 0; i < 2; i++){
        stdVecPopback.pop_back();
        ftVecPopback.pop_back();
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "pop_back case2" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPopback, ftVecPopback, fout);

    std::vector<int> stdVecInsert(1, 1);
    ft::vector<int> ftVecInsert(1, 1);
    stdVecInsert.insert(stdVecInsert.end(), 4);
    ftVecInsert.insert(ftVecInsert.end(), 4);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case1" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 0);
    ftVecInsert.insert(ftVecInsert.begin(), 0);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case2" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 2, -1);
    ftVecInsert.insert(ftVecInsert.begin(), 2, -1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case3" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin() + 4, 2, 2);
    ftVecInsert.insert(ftVecInsert.begin() + 4, 2, 2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case4" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.end(), 3, 5);
    ftVecInsert.insert(ftVecInsert.end(), 3, 5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case5" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    std::vector<int> stdVecInsertTemp;
    ft::vector<int> ftVecInsertTemp;
    for (int i = 11; i < 16; i++){
        if (i % 2 == 1){
            stdVecInsertTemp.push_back(i);
            ftVecInsertTemp.push_back(i);
        }
    }
    stdVecInsert.insert(stdVecInsert.begin(), stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.begin(), ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case6" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin() + 7, stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.begin() + 7, ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case7" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.end(), stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.end(), ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case8" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 50, 0);
    ftVecInsert.insert(ftVecInsert.begin(), 50, 0);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case9" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin(), stdVecInsert.begin() + 50);
    ftVecInsert.erase(ftVecInsert.begin(), ftVecInsert.begin() + 50);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin() + 3, stdVecInsert.begin() + 6);
    ftVecInsert.erase(ftVecInsert.begin() + 3, ftVecInsert.begin() + 6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.end() - 2, stdVecInsert.end());
    ftVecInsert.erase(ftVecInsert.end() - 2, ftVecInsert.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin());
    ftVecInsert.erase(ftVecInsert.begin());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin() + 3);
    ftVecInsert.erase(ftVecInsert.begin() + 3);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case5" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.end() - 1);
    ftVecInsert.erase(ftVecInsert.end() - 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case6" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    std::vector<int> stdVecSwap(5, 1);
    ft::vector<int> ftVecSwap(5, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "swap" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std before | size = " << stdVecSwap.size() << " | capacity = " << stdVecSwap.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecSwap.begin(); stdIt != stdVecSwap.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft before | size = " << ftVecSwap.size() << " | capacity = " << ftVecSwap.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecSwap.begin(); ftIt != ftVecSwap.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std insert | size = " << stdVecInsert.size() << " | capacity = " << stdVecInsert.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecInsert.begin(); stdIt != stdVecInsert.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft insert | size = " << ftVecInsert.size() << " | capacity = " << ftVecInsert.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecInsert.begin(); ftIt != ftVecInsert.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    stdVecSwap.swap(stdVecInsert);
    ftVecSwap.swap(ftVecInsert);
    fout << "| std after  | size = " << stdVecSwap.size() << " | capacity = " << stdVecSwap.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecSwap.begin(); stdIt != stdVecSwap.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft after  | size = " << ftVecSwap.size() << " | capacity = " << ftVecSwap.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecSwap.begin(); ftIt != ftVecSwap.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std insert | size = " << stdVecInsert.size() << " | capacity = " << stdVecInsert.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecInsert.begin(); stdIt != stdVecInsert.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft insert | size = " << ftVecInsert.size() << " | capacity = " << ftVecInsert.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecInsert.begin(); ftIt != ftVecInsert.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;

    stdVecSwap.clear();
    ftVecSwap.clear();
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "clear" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecSwap, ftVecSwap, fout);

    std::vector<int> stdVecNonMember1(5, 1);
    std::vector<int> stdVecNonMember2(5, 1);
    ft::vector<int> ftVecNonMember1(5, 1);
    ft::vector<int> ftVecNonMember2(5, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator ==" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 == stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 == ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator !=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 != stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 != ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    stdVecNonMember2.push_back(2);
    ftVecNonMember2.push_back(2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator <" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 < stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 < ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator >" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 > stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 > ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator <=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 <= stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 <= ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator >=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 >= stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 >= ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "ft::swap" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std before | size = " << stdVecNonMember1.size() << " | capacity = " << stdVecNonMember1.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember1.begin(); stdIt != stdVecNonMember1.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft before | size = " << ftVecNonMember1.size() << " | capacity = " << ftVecNonMember1.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember1.begin(); ftIt != ftVecNonMember1.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std target | size = " << stdVecNonMember2.size() << " | capacity = " << stdVecNonMember2.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember2.begin(); stdIt != stdVecNonMember2.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft target | size = " << ftVecNonMember2.size() << " | capacity = " << ftVecNonMember2.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember2.begin(); ftIt != ftVecNonMember2.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    std::swap(stdVecNonMember1, stdVecNonMember2);
    ft::swap(ftVecNonMember1, ftVecNonMember2);
    fout << "| std after  | size = " << stdVecNonMember1.size() << " | capacity = " << stdVecNonMember1.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember1.begin(); stdIt != stdVecNonMember1.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft after  | size = " << ftVecNonMember1.size() << " | capacity = " << ftVecNonMember1.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember1.begin(); ftIt != ftVecNonMember1.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std target | size = " << stdVecNonMember2.size() << " | capacity = " << stdVecNonMember2.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember2.begin(); stdIt != stdVecNonMember2.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft target | size = " << ftVecNonMember2.size() << " | capacity = " << ftVecNonMember2.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember2.begin(); ftIt != ftVecNonMember2.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(41) << "time" << std::setw(39) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    std::vector<Buffer> stdVecBuf;
    std::chrono::system_clock::time_point stdStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++){
        stdVecBuf.push_back(Buffer());
    }
    for (int i = 0; i < COUNT; i++){
        const int idx = rand() % COUNT;
        stdVecBuf[idx].idx = 5;
    }
    std::vector<Buffer>().swap(stdVecBuf);
    try{
        for (int i = 0; i < COUNT; i++){
            const int idx = rand() % COUNT;
            stdVecBuf.at(idx);
            fout << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
        }
    }
    catch (const std::exception& e){

    }
    std::chrono::system_clock::time_point stdEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds stdTime = stdEnd - stdStart;
    fout << "| std vec | time = " << stdTime.count() << std::endl;

    ft::vector<Buffer> ftVecBuf;
    std::chrono::system_clock::time_point ftStart = std::chrono::system_clock::now();
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++){
        ftVecBuf.push_back(Buffer());
    }
    for (int i = 0; i < COUNT; i++){
        const int idx = rand() % COUNT;
        ftVecBuf[idx].idx = 5;
    }
    ft::vector<Buffer>().swap(ftVecBuf);
    try{
        for (int i = 0; i < COUNT; i++){
            const int idx = rand() % COUNT;
            ftVecBuf.at(idx);
            fout << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
        }
    }
    catch (const std::exception& e){

    }
    std::chrono::system_clock::time_point ftEnd = std::chrono::system_clock::now();
    std::chrono::nanoseconds ftTime = ftEnd - ftStart;
    fout << "|  ft vec | time = " << ftTime.count() << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout.close();
}
/*
** Vector Test End
*/

int main(void){
    VectorTest();
    StackTest();
    MapTest();
    system("leaks test");
    return (0);
}
