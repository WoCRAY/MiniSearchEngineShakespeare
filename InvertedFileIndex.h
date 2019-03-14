#ifndef __INVERTEDFILEINDEX_H__
#define __INVERTEDFILEINDEX_H__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

struct Postlist
{
    std::vector<int> docID;                     // Documents[docID] is the filename
    int freq;
};

class InvertedFileIndex
{
public:
    InvertedFileIndex();
    bool GetStopWord();                         // Run a word count and identify the stop words
    bool UpdateIndex();                         // Create inverted index over the Shakespeare set with word stemming.
                                                // The stop words in the set Stopword must not be included.
//    void CompressIndex();  Compress ��ֱ�Ӳ����ˣ������ڶ����汾��ʱ���ٿ���
    std::vector<string> QuerySearch(std::string query, float threshold); // return names of the files containing the query after thresholding
    ~InvertedFileIndex();
private:
    std::map<std::string, Postlist*> InvertedIndex;
    std::set<std::string> StopWord;             // Updated by GetStopWord()
    std::vector<string> Documents;              // Updated by GetStopWord()
};

#endif
