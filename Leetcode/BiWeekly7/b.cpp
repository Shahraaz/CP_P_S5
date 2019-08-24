#include<bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

struct Node
{
    int value;
    map<string, Node *> Pointer;
    Node()
    {
        value = -1;
    }
};
class FileSystem
{
public:
    Node *root;
    FileSystem()
    {
        root = new Node;
    }

    bool create(string path, int value)
    {
        string prev;
        Node *Curr = root;
        for (auto c : path)
        {
            if (c == '/')
            {
                if (prev == "")
                    continue;
                if (Curr->Pointer.find(prev) == Curr->Pointer.end())
                {
                    return false;
                }
                Curr = Curr->Pointer[prev];
                prev = "";
            }
            else
            {
                prev += c;
            }
        }
        if (Curr->Pointer.find(prev) != Curr->Pointer.end())
            return false;
        Curr->Pointer[prev] = new Node;
        Curr = Curr->Pointer[prev];
        Curr->value = value;
        return true;
    }

    int get(string path)
    {
        string prev;
        Node *Curr = root;
        for (auto c : path)
        {
            if (c == '/')
            {
                if (prev == "")
                    continue;
                if (Curr->Pointer.find(prev) == Curr->Pointer.end())
                {
                    return -1;
                }
                Curr = Curr->Pointer[prev];
                prev = "";
            }
            else
            {
                prev += c;
            }
        }
        if (Curr->Pointer.find(prev) == Curr->Pointer.end())
            return -1;
        Curr = Curr->Pointer[prev];
        return Curr->value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */