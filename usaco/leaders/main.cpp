#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int n;
char cowTypes[100000];
int e[100000];

int countH;
int countG;

vector<int> countHs;
vector<int> countGs;

struct Cow
{
    int index;
    char type;
    int friendsCount;
    int sameTypeFriendsCount;

    Cow(int index, char type, int friendsCount, int sameTypeFriendsCount)
        : index(index), type(type), friendsCount(friendsCount), sameTypeFriendsCount(sameTypeFriendsCount) {}

public:
    bool hasAllSameType() const
    {
        if (type == 'H')
            return sameTypeFriendsCount == countH;
        else
            return sameTypeFriendsCount == countG;
    }
};

vector<Cow> cows;
unordered_set<int> leadersH;
unordered_set<int> leadersG;

unordered_map<int, int> idx2Hs;
unordered_map<int, int> idx2Gs;

int main()
{

    cin >> n;
    cin >> cowTypes;

    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
        e[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        if (cowTypes[i] == 'H')
            countH++;
        else
            countG++;
        countHs.push_back(countH);
        countGs.push_back(countG);
    }

    for (int i = 0; i < n; i++)
    {
        cows.push_back(Cow(i, cowTypes[i], e[i] - i + 1,
                           (cowTypes[i] == 'H' ? countHs[e[i]] - countHs[i] : countGs[e[i]] - countGs[i]) + 1));
    }

    for (const auto &cow : cows)
    {
        if (cow.hasAllSameType())
        {
            if (cow.type == 'H')
                leadersH.insert(cow.index);
            else
                leadersG.insert(cow.index);
        }
    }

    int result = 0;
    result += leadersH.size() * leadersG.size();

    for (const auto &cow : cows)
    {
        if (!cow.hasAllSameType())
        {
            if (cow.type == 'H')
            {
                for (int j = cow.index; j < cow.index + cow.friendsCount; j++)
                {
                    idx2Hs[j]++;
                }
            }
            else
            {
                for (int j = cow.index; j < cow.index + cow.friendsCount; j++)
                {
                    idx2Gs[j]++;
                }
            }
        }
    }

    for (const auto &hLeader : leadersH)
    {
        result += idx2Gs[hLeader];
    }

    for (const auto &gLeader : leadersG)
    {
        result += idx2Hs[gLeader];
    }

    cout << result << endl;
}