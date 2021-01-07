#include "tests.h"

// Определение функции (function definiton)
void TestAdd() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");

        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };

        AssertEqual(empty, expected, "Add to empty");
    }

    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };

        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"a", "b"}}
        };

        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestCount() {
    {
        Synonyms empty;
        // Поскольку AssertEqual позволяет сравнивать переменные различных типов,
        // то вызывается предупреждение, 
        // так как GetSynonymsCount возвращает size_t, а 0 - это int'ое значение. 
        // Поэтому мы приводим 0 к безнаковому типу 0u
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "count for empty");
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "count for a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u, "count for b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "count for z");
    }
}

void TestCheck() {
    {
        Synonyms empty;
        Assert(!CheckSynonyms(empty, "a", "b"), "empty a b");
        Assert(!CheckSynonyms(empty, "b", "a"), "empty b a");
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };

        Assert(CheckSynonyms(synonyms, "a", "b"), "");
        Assert(CheckSynonyms(synonyms, "b", "a"), "");
        Assert(CheckSynonyms(synonyms, "a", "c"), "");
        Assert(CheckSynonyms(synonyms, "c", "a"), "");
        Assert(!CheckSynonyms(synonyms, "b", "c"), "");
        Assert(!CheckSynonyms(synonyms, "c", "b"), "");
    }
}

void TestAll() {
    TestRunner rt;

    // Передаем в качестве параметра функцию. 
    // (!) Скобки писать нельзя. Только имя самой функции
    rt.RunTest(TestCheck, "TestCheck");
    rt.RunTest(TestCount, "TestCount");
    rt.RunTest(TestAdd, "TestAdd");
}