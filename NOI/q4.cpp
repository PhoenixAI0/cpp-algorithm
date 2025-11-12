#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll id;
    ll size;
    int w;
    Node* prev;
    Node* next;
    Node(ll _id, ll _size, int _w)
        : id(_id), size(_size), w(_w), prev(nullptr), next(nullptr) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    Node* head = new Node(-1, 0, 0);
    Node* tail = new Node(-1, 0, 0);
    head->next = tail;
    tail->prev = head;

    unordered_map<ll, Node*> idToNode;
    idToNode.reserve(q);
    idToNode.max_load_factor(0.7f);

    ll joinCount = 0;

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            ll s;
            int w;
            cin >> s >> w;
            ++joinCount;
            Node* node = new Node(joinCount, s, w);
            node->prev = tail->prev;
            node->next = tail;
            tail->prev->next = node;
            tail->prev = node;
            idToNode[joinCount] = node;

        } else if(op == 2){
            ll i;
            cin >> i;
            Node* node = idToNode[i];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            idToNode.erase(i);
            delete node;

        } else {
            ll b;
            cin >> b;
            ll seatsRemaining = b;

            vector<pair<ll,ll>> boardedList;
            boardedList.reserve(1000);

            Node* cur = head->next;
            while(cur != tail && seatsRemaining > 0){
                ll groupSize = cur->size;
                if(groupSize <= seatsRemaining){
                    if(groupSize > 0){
                        boardedList.push_back({cur->id, groupSize});
                        seatsRemaining -= groupSize;
                    }
                    Node* toRemove = cur;
                    cur = cur->next;

                    toRemove->prev->next = toRemove->next;
                    toRemove->next->prev = toRemove->prev;
                    idToNode.erase(toRemove->id);
                    delete toRemove;
                }
                else {
                    if(cur->w == 1){
                        boardedList.push_back({cur->id, seatsRemaining});
                        cur->size = groupSize - seatsRemaining;
                        seatsRemaining = 0;
                        cur = cur->next;
                    }
                    else {
                        cur = cur->next;
                    }
                }
            }

            cout << boardedList.size() << "\n";
            if(!boardedList.empty()){
                for(auto &p : boardedList){
                    cout << p.first << " " << p.second << "\n";
                }
            }
        }
    }

    return 0;
}