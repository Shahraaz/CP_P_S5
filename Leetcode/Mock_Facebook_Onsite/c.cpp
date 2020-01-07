#include <bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

bool exist[5001][26];
bool EndOfWord[5001][26];

struct Trie
{
    bool isEnd = false;
    vector<Trie *> next;
    Trie()
    {
        next.resize(26, nullptr);
    }
};

class WordDictionary
{
    Trie root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto curr = &root;
        for (auto c : word)
        {
            int dir = c - 'a';
            if (curr->next[dir] == nullptr)
                curr->next[dir] = new Trie();
            curr = curr->next[dir];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        // cout << "SearchStart " << word << '\n';
        auto t = &root;
        queue<pair<Trie *, int>> Q;
        Q.push({t, 0});
        while (!Q.empty())
        {
            auto top = Q.front();
            // cout << top << '\n';
            Q.pop();
            if (top.f == nullptr)
                continue;
            if (top.s == word.length())
            {
                // cout << "A\n";
                if (top.f->isEnd)
                {
                    // cout << "SearchEnd\n";
                    return true;
                }
                continue;
            }
            if (word[top.s] == '.')
            {
                for (size_t i = 0; i < 26; i++)
                    Q.push({top.f->next[i], top.s + 1});
            }
            else
            {
                if (top.f->next[word[top.s] - 'a'] != nullptr)
                    Q.push({top.f->next[word[top.s] - 'a'], top.s + 1});
            }
        }
        // cout << "SearchEnd\n";
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#ifdef LOCAL
int main()
{
    // Solution s();
    string str;
    cin >> str;
    cout << str << ' ' << str.length();
}
#endif
