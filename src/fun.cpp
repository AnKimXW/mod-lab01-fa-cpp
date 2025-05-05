// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cctype>

unsigned int faStr1(const char *str)
{
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    while (*str)
    {
        if (std::isspace(*str))
        {
            if (inWord && !hasDigit)
            {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else
        {
            if (!inWord)
            {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(*str))
            {
                hasDigit = true;
            }
        }
        ++str;
    }
    if (inWord && !hasDigit)
    {
        ++count;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    while (*str)
    {
        // Пропускаем пробелы
        while (*str && std::isspace(*str))
        {
            ++str;
        }
        if (!*str) break;
        bool correctWord = false;
        bool badWord = false;
        bool firstChar = true;
        while (*str && !std::isspace(*str))
        {
            if (firstChar)
            {
                if (std::isupper(*str) && std::isalpha(*str))
                {
                    correctWord = true;
                }
                else
                {
                    badWord = true;
                }
                firstChar = false;
            }
            else
            {
                if (!std::islower(*str) || !std::isalpha(*str))
                {
                    badWord = true;
                }
            }
            ++str;
        }
        if (correctWord && !badWord)
        {
            ++count;
        }
    }
    return count;
}
unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    while (*str)
    {
        while (*str && std::isspace(*str))
        {
            ++str;
        }
        if (!*str) break;
        unsigned int wordLength = 0;
        while (*str && !std::isspace(*str))
        {
            ++wordLength;
            ++str;
        }
        if (wordLength > 0)
        {
            totalLength += wordLength;
            ++wordCount;
        }
    }
    if (wordCount == 0)
    {
        return 0;
    }
    return (totalLength + wordCount / 2) / wordCount;
}
