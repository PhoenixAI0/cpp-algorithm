#include <bits/stdc++.h>
using namespace std;

struct Sentence {
    string text;
    int word_count;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int N, C, P;
        cin >> N >> C >> P;
        
        vector<string> nouns;
        vector<string> transitive_verbs;
        vector<string> intransitive_verbs;
        vector<string> conjunctions;
        
        for(int i=0; i<N; i++){
            string word, type;
            cin >> word >> type;
            if(type == "noun"){
                nouns.push_back(word);
            }
            else if(type == "transitive-verb"){
                transitive_verbs.push_back(word);
            }
            else if(type == "intransitive-verb"){
                intransitive_verbs.push_back(word);
            }
            else if(type == "conjunction"){
                conjunctions.push_back(word);
            }
        }
        
        vector<Sentence> sentences;
        
        while(!transitive_verbs.empty() && nouns.size() >=2 && C >=1 && conjunctions.size() >=1){
            int max_k = min({(int)(nouns.size() -1), C +1, (int)conjunctions.size()});
            if(max_k <2){
                break;
            }
            int k = max_k;
            
            string trans_verb = transitive_verbs.back(); transitive_verbs.pop_back();
            string subject = nouns.back(); nouns.pop_back();
            vector<string> objects;
            for(int j=0; j<k; j++){
                objects.push_back(nouns.back()); nouns.pop_back();
            }
            C -= (k -1);
            string conj = conjunctions.back(); conjunctions.pop_back();
            
            string sentence = subject + " " + trans_verb + " ";
            for(int j=0; j<k; j++){
                sentence += objects[j];
                if(j < k -2){
                    sentence += ", ";
                }
                else if(j == k -2){
                    sentence += ", ";
                }
                else{
                    sentence += " " + conj + " ";
                }
            }
            
            sentences.push_back(Sentence{sentence, 2 + k});
        }
        
        while(!transitive_verbs.empty() && nouns.size() >=2){
            string trans_verb = transitive_verbs.back(); transitive_verbs.pop_back();
            string subject = nouns.back(); nouns.pop_back();
            string obj = nouns.back(); nouns.pop_back();
            
            string sentence = subject + " " + trans_verb + " " + obj;
            
            sentences.push_back(Sentence{sentence, 3});
        }
        
        while(!intransitive_verbs.empty() && nouns.size() >=1){
            string iv_verb = intransitive_verbs.back(); intransitive_verbs.pop_back();
            string noun = nouns.back(); nouns.pop_back();
            
            string sentence = noun + " " + iv_verb;
            
            sentences.push_back(Sentence{sentence, 2});
        }
        
        int S = sentences.size();
        if(S ==0){
            cout << "0\n\n";
            continue;
        }
        
        int K1 = 0;
        for(auto &s: sentences){
            if(s.word_count >=3){
                if(s.word_count >3){
                    K1++;
                }
            }
        }
        
        int C_remaining = conjunctions.size();
        C_remaining -= K1;
        C_remaining = max(0, C_remaining);
        
        int K = max(0, S - P);
        K = min(K, C_remaining);
        K = min(K, S /2);
        
        sort(sentences.begin(), sentences.end(), [&](const Sentence &a, const Sentence &b) -> bool{
            return a.word_count > b.word_count;
        });
        
        for(int i=0; i<K; i++){
            if(sentences.size() <2){
                break;
            }
            Sentence s1 = sentences[0];
            Sentence s2 = sentences[1];
            sentences.erase(sentences.begin());
            sentences.erase(sentences.begin());
            if(conjunctions.empty()){
                break;
            }
            string merge_conj = conjunctions.back(); conjunctions.pop_back();
            string compound = s1.text + " " + merge_conj + " " + s2.text;
            sentences.push_back(Sentence{compound, s1.word_count + s2.word_count +1});
        }
        
        long long total_words=0;
        for(auto &s: sentences){
            total_words += s.word_count;
        }
        
        sort(sentences.begin(), sentences.end(), [&](const Sentence &a, const Sentence &b) -> bool{
            return a.word_count > b.word_count;
        });
        
        string output_text = "";
        for(int i=0; i<sentences.size(); i++){
            output_text += sentences[i].text + ".";
            if(i != sentences.size() -1){
                output_text += " ";
            }
        }
        
        cout << total_words << "\n" << output_text << "\n";
    }
}