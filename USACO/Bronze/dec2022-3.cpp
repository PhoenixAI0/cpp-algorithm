#include <bits/stdc++.h>
using namespace std;

bool test(int N, vector<pair<string, char>> examples) {
    unordered_map<string, char> input_output_map;
    for(auto &example : examples){
        const string &input = example.first;
        char output = example.second;
        if(input_output_map.find(input) != input_output_map.end()){
            if(input_output_map[input] != output) {
                return false;
            }
        }
        else{
            input_output_map[input] = output;
        }
    }

    vector<pair<string, char>> unique_examples;
    for(auto &[input, output] : input_output_map){
        unique_examples.emplace_back(input, output);
    }

    while(!unique_examples.empty()){
        bool found_condition = false;
        for(int e = 0; e < unique_examples.size(); e++){
            string current_input = unique_examples[e].first;
            char current_output = unique_examples[e].second;

            for(int bit = 0; bit < N; bit++){
                char bit_value = current_input[bit];
                bool valid = true;

                for(auto &ex : unique_examples){
                    if(ex.first[bit] == bit_value && ex.second != current_output){
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    vector<pair<string, char>> remaining;
                    for(auto &ex : unique_examples){
                        if(!(ex.first[bit] == bit_value)){
                            remaining.emplace_back(ex);
                        }
                    }
                    unique_examples = move(remaining);
                    found_condition = true;
                    break;
                }
            }

            if(found_condition){
                break;
            }
        }

        if(!found_condition){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<pair<string, char>> examples(M);
        for(int i = 0; i < M; i++){
            cin >> examples[i].first >> examples[i].second;
        }

        bool result = test(N, examples);
        if(result){
            cout << "OK\n";
        }
        else{
            cout << "LIE\n";
        }
    }
}