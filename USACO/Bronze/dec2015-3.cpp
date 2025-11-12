#include <bits/stdc++.h>
using namespace std;

struct DrinkEvent {
    int person, milk, time;
};

struct SicknessEvent {
    int person, time;
};

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    
    vector<DrinkEvent> drinkingEvents(D);
    vector<SicknessEvent> sicknessEvents(S);
    
    for (int i = 0; i < D; ++i) {
        cin >> drinkingEvents[i].person >> drinkingEvents[i].milk >> drinkingEvents[i].time;
    }
    
    for (int i = 0; i < S; ++i) {
        cin >> sicknessEvents[i].person >> sicknessEvents[i].time;
    }
    
    set<int> possibleBadMilks;
    for (int m = 1; m <= M; ++m) {
        bool isBadMilk = true;
        for (const auto& sickness : sicknessEvents) {
            bool drankBeforeSickness = false;
            for (const auto& drink : drinkingEvents) {
                if (drink.person == sickness.person && drink.milk == m && drink.time < sickness.time) {
                    drankBeforeSickness = true;
                    break;
                }
            }
            if (!drankBeforeSickness) {
                isBadMilk = false;
                break;
            }
        }
        if (isBadMilk) {
            possibleBadMilks.insert(m);
        }
    }
    
    int maxAffected = 0;
    for (int badMilk : possibleBadMilks) {
        set<int> affectedPeople;
        for (const auto& drink : drinkingEvents) {
            if (drink.milk == badMilk) {
                affectedPeople.insert(drink.person);
            }
        }
        maxAffected = max(maxAffected, (int)affectedPeople.size());
    }
    
    cout << maxAffected << endl;
}